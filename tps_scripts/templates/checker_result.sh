
# This file must be "source"d from "invoke_test.sh".
# This is the script for extracting the results from the checker outputs.
# You should modify this file if the checker is going to respond differently.

# Read all words of checker standard output into an array
#declare -a checker_stdout_words 
checker_stdout_words=()
while IFS= read -r word; do
    checker_stdout_words+=("${word}")
done < <(tr -s ' ' '\n' < "${checker_stdout}")

score="0"
verdict="Wrong Answer"
array_pointer=0
if [[ ${#checker_stdout_words[@]} -ge 1 ]]; then
    while [[ ${array_pointer} -lt ${#checker_stdout_words[@]} ]]; do
        word=${checker_stdout_words[${array_pointer}]}
        if [[ ${array_pointer} -eq 0 ]]; then
            # The first word of checker standard output will be zero if success.
            if [[ ${word} == "0" ]]; then
                score="100"
                verdict="Correct"
            fi
        else
            # Replace TIOJ specific instructions.
            if [[ ${word} == "SPECJUDGE_OVERRIDE_SCORE" ]]; then
                array_pointer=$((array_pointer + 1))
                word=${checker_stdout_words[${array_pointer}]}
                score=${word}
            elif [[ ${word} == "SPECJUDGE_OVERRIDE_VERDICT" ]]; then
                array_pointer=$((array_pointer + 1))
                word=${checker_stdout_words[${array_pointer}]}
                if [[ ${word} == "AC" ]]; then
                    verdict="Correct"
                elif [[ ${word} == "WA" ]]; then
                    verdict="Wrong Answer"
                fi
            fi
        fi
        array_pointer=$((array_pointer + 1))
    done
fi

# The verdict reason (checker message) is written on the first line of checker standard error.
reason="$(sed -n 1p "${checker_stderr}")"
