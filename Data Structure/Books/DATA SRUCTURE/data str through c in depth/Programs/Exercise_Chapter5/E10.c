/*E10*/
#include<stdio.h>
int count(long int n, int d);
main()
{
	printf("%d\n",count(123212,2));
}
int count(long int n, int d)
{
	if(n == 0) 
		return 0;
	else if(n%10 == d)
		return 1 + count(n/10,d);
	else
		return count(n/10,d);
}

