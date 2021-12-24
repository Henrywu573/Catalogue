/*E3*/
#include<stdio.h>
main( )
{
	int i=0, sum=0, arr[6]={ 4, 2, 6, 0, 5, 10};
	while( arr[i] )
	{
		sum = sum+arr[i];
		i++;
	}
	printf("sum = %d\n", sum);
}
