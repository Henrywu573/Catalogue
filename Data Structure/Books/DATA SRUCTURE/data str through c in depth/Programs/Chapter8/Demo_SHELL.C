/*Demo Program of sorting using shell sort */

#include<stdio.h>
#define MAX 100
#define STOP getchar()

main()
{
	int arr[MAX],i,j,k,n,incr;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("Unsorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ",arr[i]);
	printf("\nEnter maximum increment (odd value) : ");
	scanf("%d",&incr);
	
	printf("\n");

	/*Shell sort*/
	while(incr>=1)
	{
		printf("Increment=%d\n\n",incr);
		for(k=0; k<incr; k++)
		{
			printf("Sublist %d : ",k+1);
			for(i=k;i<n;i=i+incr)
			 printf("%d  ",arr[i]);
			printf("\n");
		}
		printf("\n");
		
		for(i=incr; i<n; i++)
		{
			k=arr[i];
			for(j = i-incr; j >= 0 && k < arr[j]; j = j-incr)
				arr[j+incr]=arr[j];
			arr[j+incr]=k;
		}
	
		if(incr==1)
			printf("After Sorting this single sublist\n\n");
		else
			printf("After sorting these sublists \n\n");

		for(k=0; k<incr; k++)
		{
			printf("Sublist %d : ",k+1);
			for(i=k; i<n; i=i+incr)
				printf("%d  ",arr[i]);
			printf("\n");
		}
		printf("\n");
		
		printf("Now array elements are : \n\n");
		for (j = 0; j < n; j++)
			printf("%d ", arr[j]);

		printf("\n");
		incr=incr-2; /*Decrease the increment*/
		printf("............................................................\n\n");
		STOP;
	}/*End of while*/

	printf("Sorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n\n");


}/*End of main()*/

