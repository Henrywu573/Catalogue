/*Demo Program of sorting using merge sort without recursion*/

#include<stdio.h>
#define MAX 100
#define STOP getchar()

void merge_sort(int arr[], int n);
void merge_pass(int arr[], int temp[], int size, int n);
void merge(int arr[], int temp[],int low1, int up1, int low2, int up2 );
void copy(int arr[], int temp[], int n);

main( )
{
	int arr[MAX],i,n;

	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("Unsorted list is : ");
	for( i = 0 ; i<n ; i++)
		printf("%d ", arr[i]);
	printf("\n");

	merge_sort(arr, n);

	printf("\nSorted list is :\n");
	for( i = 0 ; i<n ; i++)
		printf("%d ", arr[i]);
	printf("\n");
}/*End of main( )*/

void merge_sort(int arr[], int n)
{
	int i, temp[MAX];
	int pass=1;
	int size=1;
	
	while(size<n)
	{
		printf("\nPASS %d,  Size = %d\n\n", pass, size);
		STOP;
		merge_pass(arr,temp,size,n);
		printf("\nList after Pass %d  :  ",pass);
		for( i = 0 ; i<n ; i++)
			printf("%d ", arr[i]);
		printf("\n.......................................................................\n");
		pass++;
		size=size*2;
	}

}

void merge_pass(int arr[], int temp[], int size, int n)
{
	int i,low1,up1,low2,up2;
	low1=0;
	while( low1 + size < n )
	{
		up1 = low1 + size-1;
		low2 = low1 + size;
		up2 = low2 + size-1;
		if( up2 >= n )/*if length of last sublist is less than size*/ 						
			up2 = n-1;
		printf("Merge arr[%d:%d] and arr[%d:%d]\n", low1, up1, low2, up2);
		
		merge(arr,temp,low1,up1,low2,up2);

		printf("{ ");
		for(i=low1; i<=up1; i++)
			printf("%d ",arr[i]);
		printf("}  { ");
		for(i=low2; i<=up2; i++)
			printf("%d ",arr[i]);
		printf("}  ->  ");
		printf("{ ");
		for(i=low1; i<=up2; i++)
			printf("%d ",temp[i]);
		printf("}\n");
		STOP;
		low1=up2+1;	/*Take next two sublists for merging*/
	}
	
	if(low1<=n-1)
	{
		printf("Sublist left is arr[%d:%d]       { ", low1, n-1);
		for(i=low1;i<=n-1;i++)/*If any sublist is left*/
		{
			printf("%d ",arr[i]);
			temp[i]=arr[i];	
		}
		printf("}\n");
		STOP;
	}
	copy(arr, temp, n);
}

void merge(int arr[], int temp[],int low1, int up1, int low2, int up2 )
{
	int i=low1;
	int j=low2;
	int k=low1;

	while(i<=up1 && j<=up2 )
	{
		if( arr[i] <= arr[j] )
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=up1)
		temp[k++]=arr[i++];
	while(j<=up2)
		temp[k++]=arr[j++];
}
void copy(int arr[], int temp[], int n)
{
	int i;
	for(i=0;i<n;i++)
		arr[i]=temp[i];
}


