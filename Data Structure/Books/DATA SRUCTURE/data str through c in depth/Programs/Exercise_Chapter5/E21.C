
/*E21 find whether a number is perfect or not */

#include<stdio.h>
int sumdiv(int num, int x);

main()
{
	int num;
	printf("Enter a number :");
	scanf("%d",&num);
	if(sumdiv(num, num/2) == num)
		printf("Perfect\n");
	else
		printf("Not Perfect\n");  
}

sumdiv(int num, int x)
{
	if(x==1)
		return 1;
	if(num%x==0)/*if x is a proper divisor*/
		return x + sumdiv(num,x-1);
	else
		return sumdiv(num,x-1);
}

