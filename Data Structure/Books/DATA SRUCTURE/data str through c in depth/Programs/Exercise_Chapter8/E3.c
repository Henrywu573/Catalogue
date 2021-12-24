/*E3*/

#include <stdio.h>
#define MAX 100
main()
{
	int arr[MAX],i,j,n,temp,max;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}
	
	/*Selection sort*/
	for(i=0; i<n-1; i++)
	{
		/*Find the index of smallest element*/
		max=i;
		for(j=i+1; j<n ; j++)
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
	}
	printf("Sorted list is : \n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}/*End of main()*/





