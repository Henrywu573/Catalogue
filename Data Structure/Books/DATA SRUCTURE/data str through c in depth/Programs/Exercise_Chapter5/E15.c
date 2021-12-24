/*E15*/
#include<stdio.h>
int func(int arr[], int n);
main( )
{
	int arr[10]={2,3,1,4,6,34};
	printf("%d\n",func(arr,6));
}
int func(int arr[], int size)
{
	int m;
	if(size==1)
		return arr[0];
    m = func(arr, size-1);
	if(arr[size-1] < m )
		return arr[size-1];
	else
		return m;
}
