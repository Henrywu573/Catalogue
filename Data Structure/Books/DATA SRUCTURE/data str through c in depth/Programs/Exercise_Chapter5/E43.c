
/*E43 Convert a string of numbers to an integer */
#include<stdio.h>
#include<ctype.h>
void f(char *s, int *num);
int main() 
{ 
	char str[10];
	int num;
	printf("Enter a string of numbers :");
	gets(str);
	num=0;
	f(str, &num);
	printf("%d  %s\n",num,str);
	
	printf("Enter a string of numbers :");
	gets(str);
	num=0;
	f(str, &num);
	printf("%d  %s\n",num,str);
}

void f(char *s, int *pnum) 
{ 
    if(*s=='\0' || !isdigit(*s)) 
        return; 
	*pnum = (*pnum)*10 + *s-'0'; 
    return f(s+1, pnum); 
} 

