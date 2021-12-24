/*E20 Find sum of those proper divisors of number a*/

#include<stdio.h>
int sumdiv(int num, int x);

main()
{
	int num;
	printf("Enter a number : ");
	scanf("%d",&num);
	printf("\nSum of divisors = %d\n",sumdiv(num,num/2));
}

sumdiv(int num, int x)
{
	if(x==1)
	{
		printf("%d  ",x);
		return 1;
	}
	if(num%x==0)/*if x is a proper divisor*/
	{
		printf("%d  ",x);
		return x + sumdiv(num,x-1);
	}
	else
		return sumdiv(num,x-1);
}

