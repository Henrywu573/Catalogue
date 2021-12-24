/*E13*/

#include<stdio.h>
#define MAX 100

main()
{
	int arr[MAX],i,j,k,n,x;
    int low, up, mid;

	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}

	/*Insertion sort*/
	for(i=1; i<n; i++)
	{
		k=arr[i]; /*k is to be inserted at proper place*/
	    low=0, up=i-1;
        while(low <= up)
	    {   
			mid = (low+up)/2;
			if(k >= arr[mid])
				low = mid+1;	
			else if(k < arr[mid])
				up = mid-1;		
		}
		for(j=i-1; j>=low; j--)
			arr[j+1]=arr[j];
		arr[j+1]=k;
	}
     
	printf("Sorted list is :\n");
	for (i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}/*End of main()*/

