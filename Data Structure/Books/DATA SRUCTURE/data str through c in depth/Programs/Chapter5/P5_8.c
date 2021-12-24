/*P5.8 Program to find GCD of two numbers*/

#include<stdio.h>
int GCD(int a, int b);
int gcd(int a, int b);

main()
{

	int a, b;
	printf("Enter a and b : \n");
	scanf("%d%d",&a, &b);
	printf("%d\n",GCD(a,b));
	printf("%d\n",gcd(a,b));
}/*End of main()*/

/*Recursive*/
int GCD(int a, int b)   
{
	if(b==0)
		return a;
	return GCD(b, a%b);
}/*End of GCD()*/

/*Iterative*/
int gcd(int a, int b)
{
	int rem;
	while(b != 0) 
	{
		rem = a%b;
		a = b;
		b = rem;
	}
	return a;
}/*End of gcd()*/



