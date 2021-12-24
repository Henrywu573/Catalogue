/* P5.5 Program to convert a positive decimal number to Binary, Octal or Hexadecimal */
#include<stdio.h>
void convert(int, int);
main()
{
	int num;
	printf("Enter a positive decimal number : ");
	scanf("%d", &num);
	convert(num, 2);
	printf("\n");
	convert(num, 8);
	printf("\n");
	convert(num, 16);
	printf("\n");
}/*End of main()*/

void convert (int num, int base)
{
	int rem = num%base;
	
	if(num==0)
		return;
	convert(num/base, base);
	
	if(rem < 10)
		printf("%d", rem);	
	else
		printf("%c", rem-10+'A' );
}/*End of convert()*/


