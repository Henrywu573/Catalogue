/*E33 Binomial coefficient*/
#include<stdio.h>
int BC(int n, int k);

int main() 
{ 
	int n,k;
	printf("Enter n and k : ");
	scanf("%d%d",&n,&k);
	printf("%d\n",BC(n,k));
}

int BC(int n, int k)
{
	if(k==0 || k==n)
		return 1;
	return BC(n-1,k-1) + BC(n-1,k);
}
