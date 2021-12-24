/*P5.4 Program to display integer as sequence of digits and find sum of its digits*/

#include<stdio.h>
void display(long int n);
void Rdisplay(long int n);
int sumdigits( long int n);

main( )
{
	long int num;
	printf("Enter number : ");
	scanf("%ld", &num);
	printf("%d\n",sumdigits(num));
	printf("\n");
	display(num); 
	printf("\n");
	Rdisplay(num); 
	printf("\n"); 
}/*End of main()*/

/*Finds the sum of digits of an integer*/
int sumdigits(long int n)
{
	if( n/10 == 0 ) /* if n is a single digit number*/
		return n;
	return n%10 + sumdigits(n/10);		
}/*End of sumdigits()*/

/*Displays the digits of an integer*/
void display(long int n)
{
	if( n/10==0 )
	{
		printf("%d",n);
		return;
	}
	display(n/10);
	printf("%d",n%10);	
}/*End of display()*/

/*Displays the digits of an integer in reverse order*/
void Rdisplay(long int n)
{
	if(n/10==0)
	{
		printf("%d",n);
		return;
	}
	printf("%d",n%10);
	Rdisplay(n/10);
}/*End of Rdisplay()*/	

	
