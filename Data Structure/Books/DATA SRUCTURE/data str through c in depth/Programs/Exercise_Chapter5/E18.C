/*E18 Enter a line of text and Reverse it*/
#include<stdio.h>
void func(void);
main( )
{
	printf("Enter text :\n");
	func();
	printf("\n");
}/*End of main()*/
void func(void)
{
	char c;
	if((c=getchar())!='\n')
		func();
	putchar(c);
}
