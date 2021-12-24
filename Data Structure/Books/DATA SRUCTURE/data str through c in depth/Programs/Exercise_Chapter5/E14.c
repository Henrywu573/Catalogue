/*E14*/
#include<stdio.h>
void func1(int n);
void func2(int n);
main( )
{
	func1(4);
	printf("\n");
	func2(4);
}

void func1(int n)
{
	int i;
	if(n==0)
		return;
    for(i=1; i<=n; i++)
		printf("*");
    printf("\n");	
	func1(n - 1);
}

void func2(int n)
{
	int i;
	if(n==0)
		return;
    func2(n - 1);
	for(i=1; i<=n; i++)
		printf("*");
    printf("\n");	
}
