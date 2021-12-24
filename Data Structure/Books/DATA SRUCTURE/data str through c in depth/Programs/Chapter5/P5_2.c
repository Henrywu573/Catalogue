/*P5.2 Program to display numbers from 1 to n and their sum*/

#include<stdio.h>
int summation(int n);
void display1(int n);
void display2(int n);

main( )
{
	int n;
	printf("Enter number of terms : ");
	scanf("%d", &n);
	
	display1(n);
	printf("\n");

	display2(n);
	printf("\n");
	
	printf("sum = %d\n", summation(n));	
}/*End of main()*/
int summation( int n)
{
	if(n==0)
		return 0;
	return ( n + summation(n-1) );
}/*End of summation()*/

/*displays in reverse order*/
void display1(int n)
{
	if( n==0 )
	   return;
	printf("%d ",n);	
	display1(n-1);
}/*End of display1()*/

void display2(int n)
{
	if( n==0 )
	   return;
	display2(n-1);
	printf("%d ",n);	
}/*End of display2()*/
