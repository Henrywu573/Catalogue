/*E45 Print pyramid of numbers */
#include<stdio.h>
void func1(int n);
void func2(int n);
void func3(int n);

main( )
{
	func1(4);
	printf("\n");
	func2(4);
	printf("\n");
	func3(4);
}

void func1(int n)
{
	int i;
	if(n==0)
		return;
    else
	{
		func1(n-1);
		for(i=1; i<= n; i++)
			printf("%d ",i);
        printf("\n");	
	}
}

void func2(int n)
{
	int i;
	if(n==0)
		return;
    else
	{
		for(i=1; i<=n; i++)
			printf("%d ",i);
        printf("\n");	
		func2(n-1);
	}
}

void func3(int n)
{
	int i;
	if(n==0)
		return;
    else
	{
		for(i=n; i>=1; i--)
			printf("%d ",i);
        printf("\n");	
		func3(n-1);
	}
}
