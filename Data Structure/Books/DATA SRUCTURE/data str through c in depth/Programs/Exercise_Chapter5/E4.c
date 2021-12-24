/*E4*/
#include<stdio.h>
int func(int a, int b);
main()
{
	printf("%d\n",func(4,8));
	printf("%d\n",func(3,8));
}
int func(int a, int b)
{
	if(a == b)
		return a;
	return a + b + func(a+1, b-1);
}

