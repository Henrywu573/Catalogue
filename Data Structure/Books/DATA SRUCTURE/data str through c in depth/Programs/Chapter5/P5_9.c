/*P5.9 Program to generate fibonacci series*/
#include<stdio.h>

int fib(int n);		
int TailRecursiveFib(int n);		
int TRfib(int n, int next, int result);
int Ifib(int n);		

main( )
{
	int nterms, i;
	printf("Enter number of terms : ");
	scanf("%d", &nterms);
	
	for(i=0; i<nterms; i++)
		printf("%d  ", fib(i));
	printf("\n");
	
	for(i=0; i<nterms; i++)
		printf("%d  ", TailRecursiveFib(i));
	printf("\n");

	Ifib(nterms);
	printf("\n");
}

/*Recursive*/
int fib(int n)		
{
	if(n==0 || n==1)
		return(1);
	return(fib(n-1) + fib(n-2));
}

int TailRecursiveFib(int n)		
{
	return TRfib(n,1,1);
}

int TRfib(int n, int next, int result)	
{
	if(n == 0)
		return(result);
	return TRfib(n-1, next+result, next);
}

/*Iterative*/
int Ifib(int n)		
{
	int i, x=0, y=1, z;
	printf("%d  ", y);
	for(i=1; i<n; i++)
	{
		z=x+y;
		printf("%d  ", z);
		x = y;
		y = z;
	}
}
