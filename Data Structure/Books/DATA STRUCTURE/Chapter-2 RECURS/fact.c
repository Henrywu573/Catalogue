/* Factorial of integer number */
/* FACT.C */

# include<stdio.h>

int n;
long int Factorial( int );
void Display( int);

/* The definition of the Factorial() function */

long int Factorial( int n)
{
	if( n == 0)
		return(1);
	else
		return(n * Factorial( n -1 ));
}

/* Output Function */

void Display(int n)
{
	printf("\n Factorial of : %d = %ld", n, Factorial(n));
}


/* main function */

void main()
{
	int n ;

	printf("\n Input the number of which you want to find factorial: ");
	scanf("%d", &n);

	Factorial( n );
	Display( n );
}
