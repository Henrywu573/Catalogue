/*P9.5 Recursive binary search in an array*/

#include <stdio.h>
#define MAX 50

int RBinarySearch(int arr[], int low, int up, int item);
main()
{
	int i, size, item, arr[MAX], index;
	
	printf("Enter the number of elements : ");
	scanf("%d",&size);
	printf("Enter the elements (in sorted order) : \n");
	for( i=0; i<size; i++)
		scanf("%d", &arr[i] );

	printf("Enter the item to be searched : ");
	scanf("%d", &item);
	
	index = RBinarySearch(arr, 0, size-1, item);
	if( index == -1 )
		printf("%d not found in array\n", item);
	else
		printf("%d found at position %d\n", item, index);
}

int RBinarySearch(int arr[], int low, int up, int item)
{
	int mid;
	if( low > up)
		return -1;
	mid = (low+up)/2;
	if(item > arr[mid]) /*Search in right half*/
		RBinarySearch(arr, mid+1, up, item);
	else if( item < arr[mid] )/*Search in left half*/
		RBinarySearch(arr, low, mid-1, item);
	else
		return mid;
}

