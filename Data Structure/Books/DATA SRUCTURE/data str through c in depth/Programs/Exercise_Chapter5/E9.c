/*E9*/
#include<stdio.h>
int func(int n); 
main() 
{ 
	printf("%d\n",func(14837) );
} 
int func(int n) 
{ 
	return (n)? n%10 + func(n/10) : 0; 
} 

