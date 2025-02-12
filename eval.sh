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
   # Process options.
   debug=false
   while getopts ":dh" option; do
       case $option in
           d) debug=true ;;
           h) print_usage; exit ;;
           ?) echo "unknown option: -$OPTARG"; echo; print_usage; exit ;;
       esac
   done
   # Remove the options from the positional parameters.
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
   # Set 10 second CPU time limit (ulimit uses seconds)
   ulimit -t 10
   # Set 1GB memory limit (ulimit uses KB, so 1GB = 1024 * 1024 KB)
   ulimit -v $((1024 * 1024 * 2))
}

function evaluate_file {
    local source_file="$1"
    local extension="${source_file##*.}"
    local dir="$(dirname "$source_file")"
    time_limit=5
    mem_limit=512
    
    echo "Processing: $source_file"
    compile "$source_file"
    
    for in_file in "$dir"/**/*.in; do
        [[ -f "$in_file" ]] || continue # Skip if no .in files found
        ans_file="${in_file%.*}".ans
        
        # First run the program and capture its output and status
        time_output=$( (
            set_hard_limits
            case $extension in
                ("cpp")
                    /usr/bin/time -f "%e %U %S %M" ./"$out_file" <"$in_file" 2>&1 >"$ans_file"
                    exit ${PIPESTATUS[0]}
                    ;;
                ("py")
                    /usr/bin/time -f "%e %U %S %M" python3 "$source_file" <"$in_file" 2>&1 >"$ans_file"
                    exit ${PIPESTATUS[0]}
                    ;;
            esac
        ) )
        subshell_status=$?
        
        # First print the test case info
        printf "%s | " "$ans_file"
        
        if [ $subshell_status -ne 0 ]; then
            # If it's RE, we don't care about time/memory
            printf "RE\n"
            continue
        fi
        
        # Only process time/memory if it's not RE
        read cpu mem_mb <<< $(process_time_output "$time_output")
        printf "TIME: %.2fs MEM: %.1fMB | " $cpu $mem_mb
        
        # Then check other conditions
        if (( $(echo "$cpu > $time_limit" | bc -l 2>/dev/null || echo "0") )); then
            printf "TLE\n"
        elif (( $(echo "$mem_mb > $mem_limit" | bc -l 2>/dev/null || echo "0") )); then
            printf "MLE\n"
        elif git diff -w --ignore-blank-lines --ignore-space-at-eol --quiet "$ans_file" 2>/dev/null; then
            printf "OK\n"
        else
            printf "WA\n"
        fi
    done
    
    # Cleanup cpp output file if it exists
    [[ $extension == "cpp" ]] && [[ -f "$out_file" ]] && rm "$out_file"
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
