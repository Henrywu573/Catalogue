/*E40*/

#include<stdio.h>
#include<string.h>

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
} 
int is_palindrome(char *str, int size)
{
	if(size<=1) 
		return 1;
	if(str[0] != str[size-1])
		return 0;
    return is_palindrome(str+1,size-2);
}

