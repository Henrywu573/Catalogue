/*E24 Reverse an array*/
#include<stdio.h>
void reverse(int arr[], int low, int high);
main( )
{
	int i,arr[6]={1,2,3,4,8,10};
	reverse(arr,0,5);
	for(i=0; i<=5; i++)
		printf("%d ",arr[i]);
}
void reverse(int arr[], int low, int high)
{
	int tmp; 
	if(low >= high)
		 return;
	tmp = arr[low];
	arr[low]=arr[high];
	arr[high]=tmp;
	reverse(arr, low+1, high-1);
}
