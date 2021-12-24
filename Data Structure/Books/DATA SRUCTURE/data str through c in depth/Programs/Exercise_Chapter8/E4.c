/*E4*/

#include <stdio.h>
#define MAX 100

main()
{
	int arr[MAX],i,j,n,temp,max,k;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for( i=0; i<n; i++ )
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}
	
	/*Selection sort*/
	for(i=n-1; i>0; i--)
	{
		/*Find the index of largest element*/
		max=i;
		for(j=i-1; j>=0; j--)
		{
			if(arr[max] < arr[j])
				max=j ;
		}
		if(i!=max)
		{
			temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp ;
		}
		for(k=0; k<n; k++)
			printf("%d ", arr[k]);
		printf("\n");
	}
	printf("Sorted list is : \n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}/*End of main()*/





