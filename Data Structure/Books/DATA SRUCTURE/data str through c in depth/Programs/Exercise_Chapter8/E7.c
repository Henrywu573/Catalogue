/*E7*/

#include <stdio.h>
#define MAX 100

main()
{
	int arr[MAX],i,j,temp,n,xchanges;
	int start, end;
	int k;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}

    for(i=0; i<n-1 ;i++)
	{
		xchanges=0;
		for(j=0; j<n-1-i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				xchanges++;
			}
		}
		if(xchanges==0) /*If list is sorted*/
			break;
		
		xchanges=0;
		for(j=n-1-i; j>i; j--)
		{
			if(arr[j] < arr[j-1])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				xchanges++;
			}
		}
		if(xchanges==0) /*If list is sorted*/
			break;
	
		for(k=0; k<n; k++)
			printf("%d ",arr[k]);
		printf("\n");
	}			

	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");

}/*End of main()*/

