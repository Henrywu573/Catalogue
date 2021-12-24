/*E39 Find index of last occurence of a character*/  
 
#include<stdio.h>
#include<string.h>
int find(char *str, char c, int n);
int main() 
{ 
	char str[100]; 
	char c='a';
	printf("Enter a string :");
    gets(str);
	printf("%d\n",find(str,c,strlen(str)));
} 
int find(char *str, char c, int n)
{
	if(n==0)
		return -1;
	if(str[n-1]==c)
		return n-1;
	return find(str,c,n-1);
}

