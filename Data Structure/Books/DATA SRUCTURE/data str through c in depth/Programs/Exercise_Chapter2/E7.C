/*E7*/
#include<stdio.h>
main( )
{
	int i, arr[5] = {25, 30, 35, 40, 55};
	for( i=0; i<5; i++)
	{
		printf("%d   ", *arr);
		arr++;
	}
}
