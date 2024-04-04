#!/bin/bash

if test "$#" -ne 2; then
    echo "Illegal number of parameters"
    echo "Example: ./task6.bash ./1.c ./helloworld"
fi

c_file=$1
exe_out_file=$2

gcc $c_file -o $exe_out_file 2>$errors

if test -z $errors
then
	echo "Errors orrured"
	echo $errors
fi

