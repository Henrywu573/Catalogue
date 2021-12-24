/*E36 Replace  each occurence of a character by another character*/
#include<stdio.h>
void f(char *s, char a, char b);
int main() 
{ 
	char str[100],a,b;
	printf("Enter a string :");
	gets(str);
	printf("Enter two characters :");
	scanf("%c %c",&a,&b);
	f(str,a,b);
	puts(str);
}
void f(char *str, char a, char b)
{ 
    if(*str=='\0')
		return;
    if(*str==a)
		*str=b;
	f(str+1,a,b);
} 

