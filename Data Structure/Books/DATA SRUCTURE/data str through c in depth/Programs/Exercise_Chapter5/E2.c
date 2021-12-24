/*E2*/
#include<stdio.h>
int func(int a, int b);
main()
{
	printf("%d \n",func(3,8));
}
int func(int a, int b)
{
	if(a>b)
		return 1000;
	return a + func(a+1,b);
}


