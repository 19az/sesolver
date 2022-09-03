#!/bin/bash

function test {
    input=$1
    expected=`printf $2`
    printf "Test # $nTest: "
    res=`printf "$input" | ./sesolver`
    if [[ $res = "$expected" ]]
    then
        printf "OK\n\n"
    else
        printf "Failed\n\n"
        printf "Args: $input\n\n"
        printf "Expected:\n$expected\n\n"
        printf "Result:\n$res\n\n"
    fi
    nTest=$(($nTest + 1))
}
nTest=1

file="test.txt"

make
printf "Unit test for sesolver\n\n"
OLD_IFS=$IFS
IFS=$'\n'
for test in `cat $file`
do
    IFS=$';'
    test $test
done
IFS=$OLD_IFS
echo "Unit test is over"
