#!/bin/sh
#Script that counts lines in the file passed.
noOfLines=0;
if test -f $1; then
    while read line
    do
        noOfLines=$( echo " ${noOfLines} + 1" | bc )
    done < $1
    echo "The total no of lines are: ${noOfLines}"
fi

