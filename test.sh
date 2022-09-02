#!/bin/bash

function test {
    echo -n "Test # $nTest: "
    expected=$4
    res=`echo $1 $2 $3 | ./sesolver`
    if [[ $res = "$expected" ]]
    then
        echo "OK"
    else
        echo "Failed"
        echo
        echo "Args: $1 $2 $3"
        echo
        echo "Expected:"
        echo "$expected"
        echo
        echo "Result:"
        echo "$res"
        echo
    fi
    nTest=$(($nTest + 1))
    echo
}
nTest=1

make unit_test
echo "Unit test for sesolver"
echo
test 0 0 0 $'Square equation solver\nEnter coefficients of equation: a b c\nAny number is a root'
test 1 1 1 $'Square equation solver\nEnter coefficients of equation: a b c\nEquation has no roots'
test 1 2 1 $'Square equation solver\nEnter coefficients of equation: a b c\nEquation has 1 root: -1'
test 1 3 2 $'Square equation solver\nEnter coefficients of equation: a b c\nEquation has 2 roots: -2, -1'
echo "Unit test is over"
