/*E8*/
#include<stdio.h>
int count(int n);
main()
{
	printf("%d\n",count(17243));
}

int count(int n)
{
	if(n == 0) 
		return 0;
	else 
		return 1 + count(n/10);
}

