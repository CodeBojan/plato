#!/bin/bash

CC=gcc
CFLAGS="-Wall"
RUN=""
NUMBER=""
MODULE=""
declare -A DICTIONARY
#if i want to test all, provide -all when running. if not, an interactive menu will pop up listing
#all of the tests and will ask for user input which one to run
#always compile the tests anew, since the I cannot know whether the implementation changed

scan_tests () {
    readarray -t ARRAY < <(find ./ -name "test_*.c")
    echo "Found ${#ARRAY[@]} test modules..."
    i=0
    for FILE_NAME in ${ARRAY[@]}
    do        
        #echo $FILE_NAME              
        ARRAY[$i]=$(echo "$FILE_NAME" | sed -E 's|.*/test_(.*)\.c|\1|')  #extract core name from test_<core>.c
        DICTIONARY["$i"]=${ARRAY[$i]}
        echo "$i) ${ARRAY[$i]}"
        ((i++))
    done
}

run_test () {
    echo "Compiling $1 module..."
    MODULE="test_$1"

    make single MODULE_NAME=$1
    ./$MODULE
    make single_clean MODULE_NAME=$1
}

scan_tests
TEST_EVERYTHING=0
for arg in "$@"; do
    if [ "$arg" = "--all" ]; then
        echo "Testing everything..."
        TEST_EVERYTHING=1
    fi
done

if [ $TEST_EVERYTHING == 1 ]; then
    for CORE_NAME in ${ARRAY[@]}
    do
        run_test $CORE_NAME
    done
else
    echo "Run (enter number):"
    read NUMBER
    for key in "${!DICTIONARY[@]}"; do
     echo "$key : ${DICTIONARY[$key]}"
   done
    run_test ${DICTIONARY["$NUMBER"]}
fi