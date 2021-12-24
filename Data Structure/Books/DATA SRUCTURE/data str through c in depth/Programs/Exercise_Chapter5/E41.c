/*E41*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int is_palindrome(char *s, int size);

int main() 
{ 
	char str[100]; 
	printf("Enter a string :");
    gets(str);
	if( is_palindrome(str,strlen(str)) )
		printf("%s is a palindrome\n", str);
	else
		printf("%s is not a palindrome\n", str);

	puts(str);
} 
int is_palindrome(char *str, int size)
{
	if(size<=1) 
		return 1;
	if(str[0] == ' ' || str[0]==',' || str[0]=='"'|| str[0]=='.'|| str[0]=='!'|| str[0]=='-')
		return is_palindrome(str+1, size-1);
	if(str[size-1]==' ' || str[size-1]==','||  str[size-1]=='"'|| str[size-1]=='.'|| str[size-1]=='!'|| str[size-1]=='-')
		return is_palindrome(str, size-1);
	if(toupper(str[0]) != toupper(str[size-1]) )
		return 0;
    return is_palindrome(str+1, size-2);
}
