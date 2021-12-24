/*Demo Program of sorting through heapsort*/

#include <stdio.h>
#include<math.h>
#define MAX 100
#define STOP getchar()

main()
{
	int i, n, arr[MAX];
	
	printf("Enter number of elements : ");
	scanf("%d",&n);
		
	for(i=1;i<=n;i++)
	{
		printf("Enter element %d : ",i);
		scanf("%d",&arr[i]);
	}
	
	printf("Entered list is :\n");
	display(arr,n);
	printf("\n");

	heap_sort(arr,n);
	
	printf("Sorted list is :\n");
	display(arr,n);
}/*End of main()*/


heap_sort(int arr[], int size)
{
	int max;
	int i, n = size;
	buildHeap(arr, size);
		
	printf("Heap size is %d\n", size);
	printf("Heap is : ");	
	display(arr,size);
	display_heap(arr,size);
	printf("\n");

	while(size>1)
	{
		max = del_root(arr,&size);
		arr[size+1]=max;
		
		printf("Root = %d is deleted and placed at arr[%d]\n", max, size+1);
		
		printf("Heap size is %d\n", size);
		printf("Heap is  : ");	
		
		for(i=1;i<=size;i++)
			printf("%d  ",arr[i]);
		printf("\n");
		
		display_heap(arr, size);
		printf("\n");
		
		printf("Array is : ");	
		for(i=1;i<=size;i++)
			printf("%d  ",arr[i]);
		printf("_____");
		
		for(i=size+1;i<=n;i++)
			printf("%d  ",arr[i]);
		
		printf("\n\n");
		
		STOP;
	}
}/*End of heap_sort*/

buildHeap(int arr[], int size)
{
	int i;
	for(i=size/2; i>=1; i--)
		restoreDown(arr,i,size);
}

int del_root(int arr[], int *size)
{
	int max = arr[1];
	arr[1] = arr[*size];
	(*size)--;
	restoreDown(arr,1,*size);
	return max;
}

restoreDown(int arr[], int i, int size )
{
	int left=2*i, right=left+1;
	
	int num=arr[i];
	
	while(right<=size)
	{
		if( num>=arr[left] && num>=arr[right] )
		{
			arr[i] = num;
			return;
		}
		else if(arr[left] > arr[right])
		{
			arr[i] = arr[left]; 
			i = left;
		}
		else
		{
			arr[i] = arr[right];
			i = right;
		}
		left = 2 * i;
		right = left + 1;
	}	

	if(left == size && num < arr[left] )/* when right == size+1 */
	{
		arr[i]=arr[left];
		i = left;
	}
	arr[i]=num;
}

display(int arr[], int n)
{       
	int i;
	for(i=1;i<=n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
}/*End of display()*/

display_heap(int arr[], int size)
{
	int i,j, l;
	double log2_sizeplus1;
	int p=1;

	log2_sizeplus1 = log(size+1) / log(2) ;

	l = ceil( log2_sizeplus1 ) - 1 ;
	printf("\nLevel =%d\n\n",l);

	for( i=0; i<=l; i++ )
	{
		for(j=1; j<=l-i; j++)
			space(5);
		for( j=1; j<=pow(2,i) && p<=size; j++ )
		{
			printf("%5d",arr[p++]);
			space(l+3-i*2);
		}
		printf("\n");
	}
}

space(int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf(" ");
}

