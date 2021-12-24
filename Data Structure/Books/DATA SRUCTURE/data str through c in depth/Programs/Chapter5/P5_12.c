/*P5.12 Strings and recursion*/

#include<stdio.h>
#include<string.h>
void display(char *str);
void Rdisplay(char *str);
int length(char *str);

main( )
{
	char str[100];
	printf("Enter a string : ");
	gets(str);
	display( str );
	printf("\n");
	Rdisplay(str);
	printf("\n");
	printf("%d\n",length(str));
}/*End of main()*/

void display(char *str )
{
	if(*str == '\0')
	      return;
	putchar(*str );
	display(str+1);
}/*End of display()*/

void Rdisplay(char *str )	
{
	if(*str == '\0')
	      return;
	Rdisplay(str+1);
	putchar(*str );
}/*End of Rdisplay()*/
	
int length(char *str )
{
	if(*str == '\0')
	      return 0;
	return (1 + length(str+1));
}/*End of length()*/
	

