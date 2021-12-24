/*E18 Input and add n numbers*/
#include<stdio.h>
int	InputAndAdd(int n);
main()
{
	int n;
	printf("Enter n :");
	scanf("%d",&n);
	printf("%d\n",InputAndAdd(n));
}
int	InputAndAdd(int n)
{
	int a;
	printf("Enter a number : ");      
    scanf("%d",&a);
	if (n == 1)
	    return a;
	else
	    return a + InputAndAdd(n-1);
}

