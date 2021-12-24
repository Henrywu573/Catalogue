/* Greatest Comman Divisor */
/* GCD.C */

# include<stdio.h>

int Greatest_Comm_Div(int , int);

/* Definition of the Greatest Comman Divisor Function */

int Greatest_Comm_Div( int n, int m)
{
	if(( n >= m) && (( n % m) == 0))
		return(m);
	else
		Greatest_Comm_Div(m,(n % m));
}

/* main function */

void main()
{
	int n, m;
	int result;
	printf("\n Input the first integer number: ");
	scanf("%d", &n);

	printf("\n Input the second integer number: ");
	scanf("%d", &m);

	result = Greatest_Comm_Div(n, m);
	printf("\n Greatest Comman Diviser of : %d and %d is = %d", n, m, result);
}
