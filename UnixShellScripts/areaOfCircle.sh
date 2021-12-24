#!/bin/sh
#Compute area of circle
readonly pi=3.14;
area(){
    echo "scale=5; ${pi} * ( ${1} * ${1} ) " | bc
}

#script actually is interpreted from here
echo "Enter the radius."
read radius;
areaIs=`area ${radius}`
echo "The area of circle with radius ${radius} is: ${areaIs}"
