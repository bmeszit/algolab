#!/bin/bash
set +e
shopt -s globstar

function print_usage {
   echo "usage: $0 [-d] <source_file.(py|cpp) or directory>"
   echo
   echo "eval.sh evaluates code files for all .in files in their directory (recursively)"
   echo "and saves the output in the corresponding .ans file on the same path."
   echo
   echo "If a directory is provided, it processes all .py and .cpp files in that directory."
   echo
   echo " -d turn on debug-mode (adds -g and -DLOCAL flags during cpp compilation)"
}

function process_params {
   debug=false
   while getopts ":dh" option; do
       case $option in
           d) debug=true ;;
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
   g++ -o "$out_file" ${gpp_opts[@]} "$source_file"
}

function compile {
   local source_file="$1"
   local extension="${source_file##*.}"
   case $extension in
       ("cpp") compile_cpp "$source_file" ;;
       ("py") echo python ;;
       (*) echo "error: extension .$extension is not recognized"; return 1 ;;
   esac
}

function process_time_output {
  read real user sys mem <<< $1
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
        printf "OK\n"
    else
        printf "WA\n"
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
        printf "OK\n"
    else
        printf "WA\n"
    fi
}

function evaluate_file {
    local source_file="$1"
    local extension="${source_file##*.}"
    local dir="$(dirname "$source_file")"

    if [[ "$(basename "$source_file")" == "teszter.cpp" ]]; then
        return
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
    
    echo "Processing: $source_file"
    compile "$source_file"
    
    for in_file in "$dir"/**/*.in; do
        [[ -f "$in_file" ]] || continue
        
        ans_file="${in_file%.*}".ans
        if [[ $use_teszter == true ]]; then
          sol_file="${in_file%.*}".sol
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
        
        printf "%s | " "$sol_file"
        if [ $subshell_status -ne 0 ]; then
            printf "RE\n"
            continue
        fi
    
        read cpu mem_mb <<< $(process_time_output "$time_output")
        printf "TIME: %.2fs MEM: %.1fMB | " $cpu $mem_mb

        if (( $(echo "$cpu > $time_limit" | bc -l 2>/dev/null || echo "0") )); then
            printf "TLE\n"
        elif (( $(echo "$mem_mb > $mem_limit" | bc -l 2>/dev/null || echo "0") )); then
            printf "MLE\n"
        elif [[ $use_teszter == true ]]; then
            check_answer_teszter "$teszter_out" "$in_file" "$ans_file" "$sol_file"
        else
            check_answer_git "$sol_file"
        fi
    done
    
    [[ $extension == "cpp" ]] && [[ -f "$out_file" ]] && rm "$out_file"
    [[ -n "$teszter_out" ]] && [[ -f "$teszter_out" ]] && rm "$teszter_out" || true
}

function process_directory {
   local dir="$1"
   # Find all .py and .cpp files in the directory
   while IFS= read -r -d '' file; do
       evaluate_file "$file"
   done < <(find "$dir" -type f \( -name "*.py" -o -name "*.cpp" \) -print0 | sort -z)
}

function main {
   process_params "$@"
   if [[ -d "$input_path" ]]; then
       process_directory "$input_path"
   elif [[ -f "$input_path" ]]; then
       evaluate_file "$input_path"
   else
       echo "Error: Input path does not exist"
       exit 1
   fi
}

main "$@"
