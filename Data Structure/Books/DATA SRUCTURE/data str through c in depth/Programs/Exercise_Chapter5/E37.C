/*E37 Reverse a string*/
#include<stdio.h>
#include<string.h>
void rev(char *s, int size);
int main() 
{ 
	char str[100]; 
	printf("Enter a string :");
    gets(str);
	rev(str,strlen(str));
	puts(str);
} 

void rev(char *str, int size)
{
	char tmp;
	if(size<=1)
		return;
	else
	{
		tmp = str[0];
		str[0] = str[size-1];
		str[size-1] = tmp;
		rev(str+1,size-2);
	}
}
