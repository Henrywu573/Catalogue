/*P5.6 Program to raise a floating point number to a positive integer*/
#include<stdio.h>
float power(float a , int n);
float Ipower(float a , int n);
main( )
{
	float a, p;
	int n;
	printf("Enter a and n : ");
	scanf("%f %d", &a, &n);
	p = power(a, n);
	printf("%f raised to power %d is %f\n", a, n, p);
	p = Ipower(a, n);
	printf("%f raised to power %d is %f\n", a, n, p);
}/*End of main()*/

/*Recursive*/
float power(float a , int n)
{
	if(n == 0)
		return(1);
	else
		return(a * power(a,n-1));
}/*End of power()*/

/*Iterative*/
float Ipower(float a , int n)
{
	int i;
	float result=1;
	for(i=1; i<=n; i++)
		result = result * a;
	return result;
}/*End of Ipower()*/
