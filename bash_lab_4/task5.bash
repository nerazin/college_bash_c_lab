#!/bin/bash



if test "$#" -ne 3; then
    echo "Illegal number of parameters"
    echo "Example: ./task5.bash /dev/stdout /home/stepan py"
fi


out_file=$1
dir_path=$2
files_extension=$3

for filename in "$dir_path/*.$files_extension"; do 
	echo $filename
done

exit 0

