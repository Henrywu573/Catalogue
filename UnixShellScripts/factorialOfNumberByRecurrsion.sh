#!/bin/sh
#factorial using recurrsion
factorial(){
    if test $1 -eq 1; then
        echo 1;
    else
        x=$(echo "$1 - 1" | bc)
        echo "${1} * $(factorial $x)" | bc
    fi
}

#script actually is interpreted from here
echo "Enter the number"
read number;
echo "The factorial of ${number} is: $(factorial ${number})"
