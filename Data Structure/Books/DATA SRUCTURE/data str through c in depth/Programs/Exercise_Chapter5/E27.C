/*E27 Reverse an integer*/

#include<stdio.h>
void reverse(int n, int *p_rev); 

int main() 
{ 
	int rev=0;

	reverse(1234,&rev);
	printf("%d\n",rev);

	rev=0;
	reverse(4567,&rev);
	printf("%d\n",rev);

} 

void reverse(int n, int *p_rev) 
{ 
	if(n==0)
		return;
	*p_rev = *p_rev * 10 + n%10 ;
	reverse(n/10, p_rev);
} 

