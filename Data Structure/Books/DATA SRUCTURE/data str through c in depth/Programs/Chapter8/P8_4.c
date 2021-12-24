/* P8.4 Program of sorting using shell sort */
#include<stdio.h>
#define MAX 100

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
	
	printf("\nEnter maximum increment (odd value) : ");
	scanf("%d",&incr);
	
	/*Shell sort*/
	while(incr>=1)
	{
		for(i=incr; i<n; i++)
		{
			k=arr[i];
			for(j=i-incr; j>=0 && k<arr[j]; j=j-incr)
				arr[j+incr]=arr[j];
			arr[j+incr]=k;
		}
		incr=incr-2; /*Decrease the increment*/
	}/*End of while*/
	
	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}/*End of main()*/



/* Program of sorting using shell sort using knuth increments*/
/*
#include<stdio.h>
#define MAX 100
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
	
	incr=1;
	while(incr<=(n-1)/9)
		incr=3*incr+1;
		
	while(incr>=1)
	{
		for(i=incr; i<n; i++)
		{
			k=arr[i];
			for(j=i-incr; j>=0 && k<arr[j]; j=j-incr)
				arr[j+incr]=arr[j];
			arr[j+incr]=k;
		}
		incr=incr/3; 
	}
	
	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
*/