#!/bin/bash

# Install: sudo apt install time bc git build-essential python3 python-is-python3

set +e
shopt -s globstar

declare -A summary_total
declare -A summary_passed

github_mode=false

function print_usage {
   echo "usage: $0 [-d] [-g] <source_file.(py|cpp) or directory>"
   echo
   echo "eval.sh evaluates code files for all .in files in their directory (recursively)"
   echo "and saves the output in the corresponding .ans file on the same path."
   echo
   echo "If a directory is provided, it processes all .py and .cpp files in that directory."
   echo
   echo " -d turn on debug-mode (adds -g and -DLOCAL flags during cpp compilation)"
   echo " -g enable GitHub mode (wraps output in <details> blocks)"
}

function process_params {
   debug=false
   while getopts ":dgh" option; do
       case $option in
           d) debug=true ;;
           g) github_mode=true ;;
           h) print_usage; exit ;;
           ?) echo "unknown option: -$OPTARG"; echo; print_usage; exit ;;
       esac
   done
   shift $((OPTIND-1))
   input_path="$1"
}

function compile_cpp {
   local source_file="$1"
   gpp_opts=(-x c++ -g -O2 -std=gnu++20 -static)
   $debug && gpp_opts+=( -g -DLOCAL )
   out_file="$source_file".out
   g++ -o "$out_file" "${gpp_opts[@]}" "$source_file"
}

function compile {
   local source_file="$1"
   local extension="${source_file##*.}"
   case $extension in
       ("cpp") compile_cpp "$source_file" ;;
       ("py") ;;
       (*) echo "error: extension .$extension is not recognized"; return 1 ;;
   esac
}

function process_time_output {
  read real user sys mem <<< "$1"
  cpu=$(echo "$user + $sys" | bc)
  mem_mb=$(echo "scale=1; $mem/1024" | bc)
  echo "$cpu $mem_mb"
}

function set_hard_limits {
  ulimit -t 10
  ulimit -v $((1024 * 1024 * 2))
  ulimit -s 65536
}

function check_answer_git {
    local ans_file="$1"
    if git diff -w --ignore-blank-lines --ignore-space-at-eol --quiet "$ans_file" 2>/dev/null; then
        printf "OK"
    else
        printf "WA"
    fi
}

function check_answer_teszter {
    local teszter_out="$1"
    local in_file="$2"
    local ans_file="$3"
    local sol_file="$4"
    
    "$teszter_out" <<< "$in_file"$'\n'"$ans_file"$'\n'"$sol_file"
    result_status=$?

    if [[ $result_status -eq 0 ]]; then
        printf "OK"
    else
        printf "WA"
    fi
}

function evaluate_file {
    local source_file="$1"
    local extension="${source_file##*.}"
    local dir
    dir="$(dirname "$source_file")"

    if [[ "$(basename "$source_file")" == "teszter.cpp" ]]; then
        return
    fi

    summary_total["$source_file"]=0
    summary_passed["$source_file"]=0

    if $github_mode; then
        echo "<details>"
        echo
        echo "\`\`\`"
    fi

    local teszter
    teszter=$(find "$dir" -type f -name "teszter.cpp" 2>/dev/null | head -n 1)
    local use_teszter=false
    local teszter_out

    if [[ -n "$teszter" ]]; then
        use_teszter=true
        teszter_out="${teszter}.out"
        compile_cpp "$teszter"
        g++ -o "$teszter_out" "$teszter"
    fi

    time_limit=5
    mem_limit=512
    
    compile "$source_file"
    
    for in_file in "$dir"/**/*.in; do
        [[ -f "$in_file" ]] || continue

        summary_total["$source_file"]=$(( summary_total["$source_file"] + 1 ))
        
        ans_file="${in_file%.*}.ans"
        if [[ $use_teszter == true ]]; then
          sol_file="${in_file%.*}.sol"
        else
          sol_file="$ans_file"
        fi

        time_output=$( (
            set_hard_limits
            case $extension in
                ("cpp")
                    /usr/bin/time -f "%e %U %S %M" ./"$out_file" <"$in_file" 2>&1 >"$sol_file"
                    exit ${PIPESTATUS[0]}
                    ;;
                ("py")
                    /usr/bin/time -f "%e %U %S %M" python3 "$source_file" <"$in_file" 2>&1 >"$sol_file"
                    exit ${PIPESTATUS[0]}
                    ;;
            esac
        ) )
        subshell_status=$?
        
        local result=""
        local cpu="-1"
        local mem_mb="-1"
        if [ $subshell_status -ne 0 ]; then
            result="RE"
        else
          read cpu mem_mb <<< "$(process_time_output "$time_output")"
          if (( $(echo "$cpu > $time_limit" | bc -l 2>/dev/null || echo "0") )); then
              result="TLE"
          elif (( $(echo "$mem_mb > $mem_limit" | bc -l 2>/dev/null || echo "0") )); then
              result="MLE"
          elif [[ $use_teszter == true ]]; then
              result=$(check_answer_teszter "$teszter_out" "$in_file" "$ans_file" "$sol_file")
          else
              result=$(check_answer_git "$sol_file")
          fi
        fi

        if [[ "$result" == "OK" ]]; then
            summary_passed["$source_file"]=$(( summary_passed["$source_file"] + 1 ))
        fi

        if [ "$cpu" = "-1" ]; then
          cpu="   ??"
          mem_mb="   ??"
        else
          cpu="$(printf "%5.2f" "$cpu")"
          mem_mb="$(printf "%5.2f" "$mem_mb")"
        fi
        printf "%3s | %s | TIME: %ss  MEM: %sMB\n" "$result" "$sol_file" "$cpu" "$mem_mb"
    done
    
    local status="OK"
    if [ "${summary_passed[$source_file]}" -ne "${summary_total[$source_file]}" ]; then
      status="!!"
    fi

    if $github_mode; then
      echo "\`\`\`"
      echo
      echo "<summary>"
    fi
    printf " %s %d/%d %s\n" "$status" "${summary_passed[$source_file]}" "${summary_total[$source_file]}" "$source_file"
    if $github_mode; then
      echo "</summary>"
      echo
      echo "</details>"
    fi

    [[ $extension == "cpp" ]] && [[ -f "$out_file" ]] && rm "$out_file"
    [[ -n "$teszter_out" ]] && [[ -f "$teszter_out" ]] && rm "$teszter_out" || true
    echo
}

function process_directory {
   local dir="$1"
   while IFS= read -r -d '' file; do
       evaluate_file "$file"
   done < <(find "$dir" -type f \( -name "*.py" -o -name "*.cpp" \) -print0 | sort -z)
}

function print_summary {
  echo "Summary:"
  for file in $(printf "%s\n" "${!summary_total[@]}" | sort); do
    total=${summary_total["$file"]}
    passed=${summary_passed["$file"]}
    status="OK"
    if [ "$passed" -ne "$total" ]; then
      status="!!"
    fi
    printf " %s %d/%d %s\n" "$status" "$passed" "$total" "$file"
  done
}

function print_manual {
  local dir="$1"
  echo
  process_params "$@"
  if $github_mode; then
    echo "## Manual check"
  else
    echo "Manual check:"
  fi
  while IFS= read -r -d '' file; do
    if [[ "$(basename "$file")" != "README.md" ]]; then
      printf " ?? --/-- %s\n" "$file"
    fi
   done < <(
    find "$dir" -type f \
      ! -name '*.cpp' \
      ! -name '*.py' \
      ! -name '*.in' \
      ! -name '*.ans' \
      ! -name '*.sol' \
      ! -name 'README.md' \
      -print0 \
    | sort -z
  )
}

function main {
  process_params "$@"
  if $github_mode; then
    echo "# Testing $input_path"
  else
    echo "Testing: $input_path"
  fi
  if [[ -d "$input_path" ]]; then
    process_directory "$input_path"
  elif [[ -f "$input_path" ]]; then
    evaluate_file "$input_path"
  else
    echo "Error: Input path does not exist"
    exit 1
  fi
  if ! $github_mode; then
    print_summary
  fi
  print_manual "$input_path"
}

main "$@"
