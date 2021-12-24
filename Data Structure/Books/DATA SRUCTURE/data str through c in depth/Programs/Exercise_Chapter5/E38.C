/*E38 Find index of first occurrence of a character*/  
#include<stdio.h>
#include<string.h>
int find(char *str, char c);
int main() 
{ 
	char str[100]; 
	char c='a';
	printf("Enter a string :");
    gets(str);
	printf("%d\n",find(str,c));
} 
int find(char *str, char c)
{
	static int i=0;
	if(*str=='\0')
		return -1;
	if(*str == c)
		return i; 
	i++;
	return find(str+1,c);
}
