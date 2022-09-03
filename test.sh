#!/bin/bash

cd unit_test
. ./unit_testing.sh
make
unit_test "test.txt" "sesolver" $';'
make clean
cd ../
