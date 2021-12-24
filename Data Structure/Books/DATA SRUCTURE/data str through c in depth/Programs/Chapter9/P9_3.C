/*P9.3 Sequential search in a sorted array*/

#include <stdio.h>
#define MAX 50

int LinearSearch(int arr[], int n, int item);
main()
{
	int i,n,item,arr[MAX],index;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("Enter the elements(in sorted order) : \n");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	printf("Enter the item to be searched : ");
	scanf("%d", &item);
	
	index = LinearSearch(arr, n, item);
	
	if(index == -1)
		printf("%d not found in array\n", item);	
	else
		printf("%d found at position %d\n", item, index);
}

int LinearSearch(int arr[], int n, int item)
{
	int i=0;
	while(i<n && arr[i]<item)
			i++;
	if(arr[i]==item)
		return i;
	else
		return -1;
}




