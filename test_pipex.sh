#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

compile_and_check() {
    echo "Compiling..."
    make re > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo -e "${RED}Compilation failed!${RESET}"
        exit 1
    fi
}

run_test() {
    local infile="$1"
    local cmd1="$2"
    local cmd2="$3"
    local outfile="outfile.txt"
    local expected="expected.txt"

    ./pipex "$infile" "$cmd1" "$cmd2" "$outfile" 2> /dev/null
    < "$infile" $cmd1 | $cmd2 > "$expected" 2> /dev/null

    if diff "$outfile" "$expected" > /dev/null; then
        echo -e "${GREEN}Test Passed ✅${RESET} [$cmd1 | $cmd2]"
    else
        echo -e "${RED}Test Failed ❌${RESET} [$cmd1 | $cmd2]"
        echo "--- Expected ---"
        cat "$expected"
        echo "--- Got ---"
        cat "$outfile"
    fi

    rm -f "$outfile" "$expected"
}

run_failing_test() {
    local description="$1"
    local cmd="$2"

    echo -n "$description: "
    $cmd > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo -e "${GREEN}Handled ✅${RESET}"
    else
        echo -e "${RED}Not Handled ❌${RESET}"
    fi
}

prepare_inputs() {
    echo -e "hello world\nhello pipex\n42 Network\npipex test" > infile.txt
    echo -e "Zebra\nApple\napple\nBanana\nbanana\nZebra" > list.txt
    echo "secret content" > no_read.txt
    chmod 000 no_read.txt
}

cleanup() {
    rm -f infile.txt list.txt no_read.txt outfile.txt expected.txt
    chmod 644 no_read.txt 2>/dev/null
}

### MAIN ###
compile_and_check
prepare_inputs

echo -e "\nRunning valid tests...\n"
run_test "infile.txt" "grep hello" "wc -l"
run_test "infile.txt" "cat" "tr a-z A-Z"
run_test "list.txt" "sort" "uniq"
run_test "infile.txt" "cat" "rev"

echo -e "\nRunning edge case tests...\n"
run_failing_test "Non-existing input file" "./pipex nofile.txt 'cat' 'wc' outfile.txt"
run_failing_test "Command not found" "./pipex infile.txt 'nonexistentcmd' 'wc' outfile.txt"
run_failing_test "Permission denied on input" "./pipex no_read.txt 'cat' 'wc' outfile.txt"

echo -e "\nCleaning up..."
cleanup
echo -e "${GREEN}All done.${RESET}"
