/*Demo Program of sorting using quick sort */
#include<stdio.h>
#define MAX 100
#define STOP getchar()
main()
{
	int arr[MAX],n,i;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	quick(arr,0,n-1);

	printf("Sorted list is :\n");
	display(arr,0,n-1);
	printf("\n");

}/*End of main() */

quick(int arr[],int low,int up)
{
	int pivloc;
	printf("\n*************************************************************");
	printf("\n\nquick( ) called with low=%d and up=%d\n",low, up);
	
	if(low>=up)
	{
		if(low==up)
			printf("Only one element in the list, Return\n");
		else 
			printf("No element in the list, Return\n");
		return;
	}
	
	pivloc = partition(arr,low,up);
    display(arr, low, pivloc);
	display(arr, pivloc+1, up);
	
	quick(arr,low,pivloc-1);/*process left sublist*/
	quick(arr,pivloc+1,up); /*process right sublist*/
}/*End of quick()*/

partition(int arr[], int low, int up)
{
	int temp,i,j,pivot;
	
	i=low+1;
	j=up;
	
	pivot=arr[low];
	printf("Subarray : "); 
	display(arr, low, up);
	printf("\n\n");
	printf("i=%d, j=%d\n",i,j); 
	printf("Pivot is %d\n\n", pivot);
	
	while( i <= j )
	{
		printf("i=%d, j=%d\n", i, j); 
		while( arr[i] < pivot && i<up )    
		{
			printf(" %d < %d : ", arr[i], pivot);  
			printf("Increment i : ");		
			i++;
			printf("i=%d\n", i); 
		}
		if(arr[i] == pivot )
            printf(" %d == %d : Stop i\n\n", arr[i], pivot);  
		else if(arr[i] > pivot )
			printf(" %d > %d : Stop i\n\n", arr[i], pivot);  
		else
			printf("Value of i is equal to up, so to prevent i from crossing upper bound, stop i\n\n");
		STOP;
	
		while( arr[j] > pivot )	
		{
			printf(" %d > %d : ", arr[j], pivot);  
			printf("Decrement j : ");
			j--;
			printf("j=%d\n",j); 
		}
		if(arr[j] == pivot )
            printf(" %d == %d : Stop j\n\n", arr[j], pivot);  
		else if(arr[j] < pivot )
			printf(" %d < %d : Stop j\n\n", arr[j], pivot);  
		STOP;
	
		if(i < j)
		{
			printf("i=%d, j=%d, i is less than j , ", i, j);
			printf("Exchange arr[i]=%d and arr[j]=%d\n\n", arr[i], arr[j]); 
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			printf("Subarray : "); display(arr, low, up);
			printf("\n\n");
			
			printf("Increment i and decrement j  :  ");
			i++;
			j--;
			printf("i=%d, j=%d\n\n", i, j); 
			STOP;
		}
		else 
		{
			if( i == j )
				printf("i=%d, j=%d, i is equal to j, no exchange\n\n", i, j);
			else
				printf("i=%d, j=%d, i is greater than j, no exchange\n\n", i, j);

			printf("Increment i :  ");
			i++;
			printf("i=%d, j=%d\n\n", i, j); 
			STOP;			
		}
		printf(".......................................\n\n");
	}

	printf("Now value of i is greater than j\n");
	printf("So proper place for pivot found and it is j=%d\n", j );
	printf("Exchange arr[low]=%d and arr[j]=%d \n",arr[low], arr[j] );
	
	arr[low]=arr[j];
	arr[j]=pivot;
	
	STOP;

	display(arr, low, j-1);
	printf("|%d|  ", pivot);
	display(arr, j+1, up);
	
	printf("\nPivot %d placed at proper position\n", pivot );
	
	getch( );
	return j;
}

display(int arr[],int low,int up)
{
	int i;
	for(i=low;i<=up;i++)
		printf("%d  ",arr[i]);
	
}






