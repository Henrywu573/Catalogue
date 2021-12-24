/*P2.15 Program to show how to return more than one value from a function using call by reference*/
#include<stdio.h>
func(int x, int y, int *ps, int *pd, int *pp);
main( )
{
	int a, b, sum, diff, prod;
	a = 6;
	b = 4;
	func( a, b, &sum, &diff, &prod );
	printf("Sum = %d, Difference = %d, Product = %d\n", sum, diff, prod );
}
func(int x, int y, int *ps, int *pd, int *pp)
{
	*ps = x+y;
	*pd = x-y;  
	*pp = x*y; 	
}
