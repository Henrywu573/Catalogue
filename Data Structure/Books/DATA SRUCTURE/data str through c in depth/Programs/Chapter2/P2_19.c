/*P2.19 Array of pointers */
#include<stdio.h>
main( )
{
	int *pa[3];
	int i, a=5, b=10, c=15;
	pa[0] = &a;
	pa[1] = &b;
	pa[2] = &c;

	for(i=0; i<3; i++)
	{
		printf("pa[%d] =  %p\t",i,pa[i]);
		printf("*pa[%d] =  %d\n",i,*pa[i]);
	}
}
