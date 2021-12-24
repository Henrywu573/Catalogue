/*E22 Sum of all even numbers in an array */
#include<stdio.h>
int sumEven(int arr[], int size);
main( )
{
	int arr[6]={1,2,3,4,8,10};
	printf("%d\n",sumEven(arr,6));
}
int sumEven(int arr[], int size)
{
	if(size==0)
		return 0;
	else if(arr[size-1]%2==0)
		return arr[size-1] + sumEven(arr,size-1);
	else
		return sumEven(arr, size-1);
}

