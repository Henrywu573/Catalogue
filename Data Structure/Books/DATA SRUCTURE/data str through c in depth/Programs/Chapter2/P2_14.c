/*P2.14 Call by reference*/
#include<stdio.h>
void ref(int *p, int *q);
main()
{
	int a = 5;
	int b = 8;
	printf("Before calling the function, a = %d and b = %d\n", a, b);
	ref(&a, &b);
	printf("After calling the function, a = %d and b = %d\n", a, b);
}
void ref(int *p, int *q)
{
	(*p)++;
	(*q)++;
	printf("Inside function *p = %d, *q = %d\n", *p, *q);
}
