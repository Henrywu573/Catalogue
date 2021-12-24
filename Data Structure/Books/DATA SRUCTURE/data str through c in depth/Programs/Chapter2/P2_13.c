/*P2.13  Call by value*/
#include<stdio.h>
void value(int x, int y);
main( )
{
	int a=5, b=8;
	printf("Before calling the function, a = %d and b = %d\n", a, b);
	value(a, b);
	printf("After calling the function, a = %d and b = %d\n", a, b);
}
void value(int x, int y)
{
	x++;
	y++;
	printf("Inside function x = %d , y = %d\n",x,y);
}
