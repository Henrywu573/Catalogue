/*E12*/
#include<stdio.h>
int func(int arr[], int n);
main( )
{
	int arr[10]={1,2,3,4,8,10};
	printf("%d\n",func(arr,6) );
}/*End of main()*/
int func(int arr[], int size)
{
	if(size==0)
		return 0;
	return arr[size-1] + func(arr,size-1);
}


