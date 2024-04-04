#!/bin/bash

if test "$#" -ne 3; then
    echo "Illegal number of parameters"
    echo "Example: ./task7.bash 4 188 ~"
fi

min_s=$1
max_s=$2
dir_name=$3

for file_path in $dir_name/*
do
	if test -f "$file_path"
	then
		wc_out=`wc "$file_path" -c`	
		file_size=`echo -n $wc_out | awk '{print $1}'`
		if [[ $min_s -le $file_size ]] && [[ $file_size -le $max_s ]]
		then
			echo got it $file_path - $file_size
		fi
	fi
done
