#!/bin/bash

. ./colorful_printf.sh

function run_test {
    input=$2
    expected=`printf "$3"`
    yellow_printf "Test # $nTest: "
    res=`printf "$input" | ./$1`
    if [[ $res = "$expected" ]]
    then
        green_printf "OK\n\n"
    else
        red_printf "Failed\n\n"
        printf "Args: $input\n\n"
        printf "Expected:\n$expected\n\n"
        printf "Result:\n$res\n\n"
    fi
    nTest=$(($nTest + 1))
}
nTest=1

function unit_test {
    file=$1
    program=$2
    delimiter=$3
    yellow_printf "Unit test for $program\n\n"
    OLD_IFS=$IFS
    IFS=$'\n'
    for test in `cat $file`
    do
        IFS=$delimiter
        run_test $program $test
    done
    IFS=$OLD_IFS
    yellow_printf "Unit test is over\n"
}
