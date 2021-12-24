
/*E42 number to string */
#include<stdio.h>
void f(long int n, char str[]); 
int main() 
{ 
	long int num = 1234;
	char str[30];
	f(num, str);
	puts(str);

	num = 6789;
	f(num, str);
	puts(str);
} 
 
void f(long int n, char s[]) 
{ 
	static int i=0;
	if(n==0)
	{
		i=0;	/*If value of i is not made zero here, then fn will not work correctly if called more than once in the main() */
		return;
	}
	f(n/10, s);
	s[i++] = n%10  + '0';
	s[i]='\0';
} 
