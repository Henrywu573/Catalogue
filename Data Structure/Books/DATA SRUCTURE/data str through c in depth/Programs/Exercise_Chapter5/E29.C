/*E29 Find Quotient */
#include<stdio.h>
int quo(int a, int b);

main()
{
	int a,b;
	printf("Enter two numbers :");
	scanf("%d%d",&a,&b);
	printf("%d\n",quo(a,b));
}

int quo(int a, int b)
{
	if(a<b) 
		return 0;
	else 
		return 1 + quo(a-b,b);
}
