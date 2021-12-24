/*Demo Program of sorting using bubble sort*/

#include <stdio.h>
#define MAX 100
#define STOP getchar()

main()
{
	int arr[MAX],i,j,k,temp,n,xchanges;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	printf("Unsorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	 printf("\n");

	/*Bubble sort*/
	for(i=0; i<n-1; i++)
	{
		printf("..........................................................\n\n");
		printf("PASS %d - : \n\n",i+1);
		printf("Comparisons will be done till index %d\n",n-i-1); 
		xchanges=0;
		for(j=0; j<n-1-i; j++)
		{
			printf("Elements are :  ",i+1);
			for(k=0; k<n; k++)
			{
				printf("%d ",arr[k]);
				if(k==n-i-1 && k!=n-1)
					printf("___");
			}
			printf("\n");
			printf("Compare %d and %d  :  ", arr[j], arr[j+1]);
						
			if( arr[j] > arr[j+1] )
			{
				printf("Since %d > %d, Exchange them\n",arr[j],arr[j+1]);
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				xchanges++;
			}
			else 
				printf("Since %d < %d, Don't exchange\n",arr[j], arr[j+1]);
			STOP;
		}

		if(xchanges==0) /*If list is sorted*/
		{
			printf("No exchanges in this pass, so the list is sorted\n\n");
			break;
		}
		
		printf("After Pass %d elements are :  \n",i+1);
		for(k=0; k<n; k++)
		{
			printf("%d ", arr[k]);
				if(k==n-i-2)
					printf("___");
		}
		printf("\n");
	}

	printf("Sorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
	
}/*End of main()*/






