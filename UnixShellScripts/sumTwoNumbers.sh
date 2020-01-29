#!/bin/sh
#sum 2 numbers using function or without
# sum(){
#     echo " ${1} + ${2} "| bc
# }

#script actually is interpreted from here
echo "Enter the ist number."
read num1;
echo "Enter the 2nd number."
read num2;
# sumIs=`sum ${num1} ${num2}`
sumIs=$(echo "${num1} + ${num2}" | bc)
echo "The sum of ${num1} + ${num2} = ${sumIs}"

