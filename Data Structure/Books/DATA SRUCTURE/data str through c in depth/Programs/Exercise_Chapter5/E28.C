/*E28 Find remainder*/
#include<stdio.h>
int rem(int a, int b);
main()
{
	int a,b;
	printf("Enter two numbers :");
	scanf("%d%d",&a,&b);
	printf("%d\n",rem(a,b));
}
int rem(int a, int b)
{
	if(a<b) 
		return a;
	else 
		return rem(a-b, b);
}


