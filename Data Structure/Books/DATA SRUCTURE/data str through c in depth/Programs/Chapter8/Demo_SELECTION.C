/*Demo Program of sorting using selection sort*/

#include <stdio.h>
#define MAX 100
#define STOP getchar()
main()
{
	int arr[MAX],i,j,k,n,temp,min;

	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for( i=0; i<n; i++ )
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("Unsorted list is : \n");
	for( i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	

	/*Selection sort*/
	for(i=0; i<n-1; i++)
	{
		printf("\nPASS %d - \n",i+1);	
	
		printf("Elements are :  ",i+1);
		for(k=0; k<n; k++)
		{
			printf("%d ", arr[k]);
			if( k == i-1 )
				printf("___ ");
		}

		printf("\nFind the smallest element from    { ");
		for( k=i; k<n; k++ )
			printf("%d ",arr[k]);
		printf("}\n");

		/*Find the index of smallest element*/
		min = i;
		for(j=i+1; j<n; j++)
		{
			if( arr[min] > arr[j] )
				min=j ;
		}
		
		printf("Smallest element is %d and its index is %d\n",arr[min], min);
		
		if( i != min )
		{
			printf("Exchange arr[%d]=%d and arr[%d]=%d\n",i,arr[i],min, arr[min]);	
			temp=arr [i];
			arr[i]=arr[min];
			arr[min]=temp ;
		}
		else
			printf("%d is at its proper place, no exchange needed\n", arr[i]);
		
		printf("After Pass %d elements are :  ",i+1);
		for(k=0; k<n; k++)
		{
			printf("%d ", arr[k]);
			if( k == i )
				printf("___ ");
		}
		printf("\n");
		STOP;
	}

	printf("\nSorted list is  :  ");
	for( i=0; i<n; i++ )
		printf("%d ", arr[i]);
	printf("\n");

}/*End of main()*/

