/* Fibonacci Numbers */
/* FIBO.C */

# include<stdio.h>

long fibo_number(int );

/* Definition of the function Fibonacci number generator */

long fibo_number( int n)
{
	int r;
	if(( n == 1) || ( n == 0))
		return 0;
	else
		if(n == 2)
			return 1;
		else
			return (fibo_number(n-1) + fibo_number(n-2));

}

/* main function */

void main()
{
	int n;
	int i =0;
	printf("\n Input the number for Fibonacci series, you want to generate: ");
	scanf("%d", &n);
	printf("\n Fibonacci Series is as follows: \n");

	while(i < n)
	{
		++i;
		printf(" %d", fibo_number(i));
	}
}

