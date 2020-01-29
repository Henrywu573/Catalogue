#!/bin/sh
#Primality test
#script actually is interpreted from here
echo "Enter the number"
read number;
count=2;
while test $count -lt $number;
do
    y=$(echo "${number} % ${count} " | bc)
    if test $y -eq 0; then
        echo "The number  ${number} is not prime"
        break;
    fi
    count=$(echo "${count} + 1" | bc) #i++
done

if test $count -ge $number; then
    echo "The number ${number} is Prime."
fi
