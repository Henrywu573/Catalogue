#!/bin/sh
#even odd
#script actually is interpreted from here
echo "Enter the number"
read number;
bool=$(echo "${number} % 2" | bc )
if test $bool -eq 0; then
    echo "The number ${number} is Even."
else
    echo "The number ${number} is Odd."
fi
