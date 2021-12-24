/*E25*/

#include<stdio.h>
int isAscending(int arr[], int size);

main( )
{
	int i,n,arr[50];
	
	printf("Enter number of elements :");
	scanf("%d",&n);

	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);

	if(isAscending(arr,n))
        printf("Array elements are in strict ascending order\n");
	else
		printf("Array elements are not in strict ascending order\n");
}

int isAscending(int arr[], int size)
{
	if(size == 1)
		return 1;
	if(arr[0]>=arr[1])
		return 0;
	return isAscending(arr+1, size-1);
}
