/*E30*/
#include<stdio.h>
main()
{
	int a,b;
	printf("Enter two numbers :");
	scanf("%d%d",&a,&b);
	printf("%d\n",pow(a,b));
}
int pow(int a, int n)
{
	if (n==0) 
		return 1;
	else if (n%2==0) 
		return pow(a*a, n/2);
	else 
		return a * pow(a*a, (n-1)/2);
}

