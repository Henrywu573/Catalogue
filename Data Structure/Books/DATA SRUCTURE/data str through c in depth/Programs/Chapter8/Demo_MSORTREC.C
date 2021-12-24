/*Demo Program of sorting using merge sort through recursion*/

#include<stdio.h>
#define MAX 100
#define STOP getchar()
main()
{
	int i,n,arr[MAX];
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	printf("Unsorted list is :\n");
	for( i = 0 ; i<n ; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	merge_sort( arr, 0, n-1);

	printf("\nSorted list is :\n");
	for( i = 0 ; i<n ; i++)
		printf("%d ", arr[i]);
	printf("\n");
}/*End of main()*/

merge_sort( int arr[], int low, int up )
{
	int i, mid;
	int temp[MAX];
	
	printf("arr[%d:%d]\t[ ",low, up);
	for( i = low ; i<=up ; i++)
		printf("%d ", arr[i]);
	printf("]\n\n");

	if( low < up )/* if more than one element*/
	{
		mid = (low+up)/2;
		merge_sort( arr, low , mid );  /* Sort arr[low:mid] */
		merge_sort( arr, mid+1, up );  /* Sort arr[mid+1:up] */
		/*Merge arr[low:mid] and arr[mid+1:up] to temp[low:up]*/
		printf("Merge arr[%d:%d] and arr[%d:%d] to temp[%d:%d]", low, mid, mid+1, up, low, up); 
		merge( arr, temp, low, mid, mid+1, up ); 
		/* Copy temp[low:up] to arr[low:up] */ 
		printf("  &  Copy temp[%d:%d] to arr[%d:%d]\n", low,up,low,up); 
		copy(arr,temp,low, up);	
	}
	
	if(low!=up)
	{	
	printf("Now arr[%d:%d] is [ ",low, up);
	for( i = low ; i<=up ; i++)
		printf("%d ", arr[i]);
	printf("]\n\n");
	}
}/*End of merge_sort*/

/*Merges arr[low1:up1] and arr[low2:up2] to temp[low1:up2]*/
merge( int arr[], int temp[], int low1, int up1, int low2, int up2 )
{
	int i = low1;
	int j = low2 ;
	int k = low1 ;

	while( (i <= up1) && (j <=up2) )
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++] ;
		else
			temp[k++] = arr[j++] ;
	}
	while( i <= up1 )
		temp[k++]=arr[i++];
	while( j <= up2 )
		temp[k++]=arr[j++];
}/*End of merge()*/

copy(int arr[], int temp[], int low, int up )
{
	int i;
	for(i=low;i<=up;i++)
		arr[i]=temp[i];
}








