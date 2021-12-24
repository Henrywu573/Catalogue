/*E26 Display a number in words*/

#include<stdio.h>
void f(int n); 

int main() 
{ 
	int num = 12340;
	f(num);
} 

void f(int n) 
{ 
	if(n==0)
		return;

	f(n/10);

	switch(n%10)
	{
		case 0: printf("zero ");break;
		case 1: printf("one ");break;
		case 2: printf("two ");break;
		case 3: printf("three ");break;
		case 4: printf("four ");break;
		case 5: printf("five ");break;
		case 6: printf("six ");break;
		case 7: printf("seven ");break;
		case 8: printf("eight ");break;
		case 9: printf("nine ");break;
	}
} 
