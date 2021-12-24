/*P5.1 Program to find the factorial of a number by recursive method*/

#include<stdio.h>
long int fact(int n);
long int Ifact(int n);

main( )
{
	int num;
	printf("Enter a number : ");
	scanf("%d", &num);
	if(num<0)
		printf("No factorial for negative number\n");
	else
		printf("Factorial of %d is %ld\n", num, fact(num) );

	if(num<0)
		printf("No factorial for negative number\n");
	else
		printf("Factorial of %d is %ld\n", num, Ifact(num) );
}/*End of main()*/

/*Recursive*/
long int fact(int n)
{
	if(n == 0)
		return(1);
	return(n * fact(n-1));
}/*End of fact()*/

/*Iterative*/
long int Ifact(int n)
{
	long fact=1;
	while(n>0)
	{
		fact = fact*n;
		n--;
	}
	return fact;
}/*End of ifact()*/

