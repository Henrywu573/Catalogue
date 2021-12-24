/* FACT.C */

/* FIND FACTORIAL OF AN INTEGER NUMBER */

# include<stdio.h>

int factorial (int );

void main()
{
	int  n ;
	long int result ;
	printf("\n Input a number = ");
	scanf("%d", &n);
	result = factorial(n) ;  /* invocation of function */
	printf("\n Factorial = %d", result);
}

/* Definition of the function factorial() */

int factorial(int m)
{
	int fact  ;
	if ( m == 0 )
		return ( 1 );
	else
		fact = m * factorial(m-1) ;
	return (fact);
}

