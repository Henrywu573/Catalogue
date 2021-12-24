
/*E31 Multiplication by Russian peasant method*/
#include<stdio.h>
int f(int a, int b);
main()
{
	int a,b;
	printf("Enter two numbers : ");
	scanf("%d%d",&a,&b);
	printf("%d\n",f(a,b));
}
int f(int a, int b) 
{
	if(a==0)            /*if we write if(a==1) return b; then 0 * b can not be computed, so this condition*/
		return 0;
	if(a%2!=0)  /*if a is odd*/
        return b + f(a/2, b*2);
    return f(a/2, b*2);
}
