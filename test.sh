#!/bin/bash

. ./unit_test/colorful_printf.sh

function test {
    input=$1
    expected=`printf $2`
    yellow_printf "Test # $nTest: "
    res=`printf "$input" | ./sesolver`
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

file="unit_test/test.txt"

make
yellow_printf "Unit test for sesolver\n\n"
OLD_IFS=$IFS
IFS=$'\n'
for test in `cat $file`
do
    IFS=$';'
    test $test
done
IFS=$OLD_IFS
yellow_printf "Unit test is over\n"
