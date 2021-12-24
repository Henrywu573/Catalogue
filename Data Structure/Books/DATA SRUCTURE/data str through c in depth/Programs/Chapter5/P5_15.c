/*P5.15 Program to search an element through for binary search*/
#include <stdio.h>
#define SIZE 100
int binary_search(int arr[],int item, int low, int high);
main()
{
	int arr[SIZE],i, item, n;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("Enter elements of the array(in sorted order) : \n");
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	printf("Enter the item to be searched : ");
	scanf("%d", &item);
	
	i = binary_search(arr,item,0,n-1);
	if(i == -1)
		printf("Not Present\n");
	else
		printf("Present at index %d\n", i);
}/*End of main()*/

int binary_search(int arr[],int item, int low, int up)
{
	int mid;
	if(up < low)
		return -1;	/*not found*/
	mid = (low+up)/2;
	if(item > arr[mid])
		return binary_search(arr,item,mid+1,up);	/*Search in right portion, tail recursive call */
	else if(item  < arr[mid])
		return binary_search(arr,item,low,mid-1);	/*Search in left portion, tail recursive call */
	else
		return mid;	/*found*/
}/*End of binary_search()*/





