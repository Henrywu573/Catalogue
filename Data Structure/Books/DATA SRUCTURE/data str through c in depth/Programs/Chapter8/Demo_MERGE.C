/* Demo Program of merging two sorted arrays into a third sorted array*/

#include<stdio.h>
#define MAX 100
#define STOP getchar()
void merge(int arr1[], int arr2[], int arr3[], int n1, int n2);
main()
{
	int arr1[MAX],arr2[MAX],arr3[2*MAX],n1,n2,i;

	printf("Enter the number of elements in array 1 : ");
	scanf("%d",&n1);
	printf("Enter all the elements in sorted order :\n");
	for(i=0;i<n1;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr1[i]);
	}
	
	printf("Enter the number of elements in array 2 : ");
	scanf("%d",&n2);
	printf("Enter all the elements in sorted order :\n");
	for(i=0;i<n2;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr2[i]);
	}
	
	merge( arr1, arr2, arr3, n1, n2);
	
	printf("\n\nMerged list : ");
	for(i=0;i<n1+n2;i++)
		printf("%d ",arr3[i]);
	printf("\n");
}

void merge(int arr1[], int arr2[], int arr3[], int n1, int n2)
{
	int m;
	int i,j,k;
	i=0;  	/*Index for first array*/
	j=0;  	/*Index for second array*/
	k=0;  	/*Index for merged array*/

	while( (i <= n1-1 ) && (j <= n2-1) )
	{
		STOP;
		printf("\nArray 1 :  ");
		for(m=i; m<=n1-1; m++)
			printf("%d ", arr1[m]);
		printf("\nArray 2 :  ");
		for(m=j; m<=n2-1; m++)
			printf("%d ", arr2[m]);
		STOP;
		printf("\nCompare %d and %d : ", arr1[i] , arr2[j]);
		if( arr1[i] < arr2[j] )
		{
			printf("%d is smaller so insert it in arr3\n", arr1[i]);
			arr3[k++]=arr1[i++];
		}
		else
		{
			printf("%d is smaller so insert it in arr3\n", arr2[j]);
			arr3[k++]=arr2[j++];
		}
		STOP;
		printf("Array 3 is : ");
		for(m=0;m<k;m++)
			printf("%d ",arr3[m]);
		printf("\n");	
	}


	/*Put remaining elements of arr1 into arr3*/
	if(i <= n1-1)
	{
		printf("Elements left in array 1 : ");
		while( i <= n1-1 )
		{
			printf("%d ", arr1[i] );
			arr3[k++]=arr1[i++];
		}
	}

	/*Put remaining elements of arr2 into arr3*/
	if(j<=n2-1)
	{
		printf("\nElements left in array 2 : ");
		while( j <= n2-1 )
		{
			printf("%d ", arr2[j]);
			arr3[k++]=arr2[j++];
		}
	}

}/*End of merge()*/






