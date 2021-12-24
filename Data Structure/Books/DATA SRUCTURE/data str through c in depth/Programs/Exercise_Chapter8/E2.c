/*E2*/

#include <stdio.h>
#define MAX 100

void selectionSort(int arr[], int start, int end);

main()
{
	int arr[MAX],i,n;
	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}

	selectionSort(arr, 0, n-1);

	printf("Sorted list is : \n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}/*End of main()*/

void selectionSort(int arr[], int start, int end)
{
  int min,j,temp; 

  if(start>=end)
     return;
  
  min = start;
  for(j=start+1; j<=end; j++)
  {
		if(arr[min] > arr[j])
			min=j ;
  }
  temp = arr[start];
  arr[start] = arr[min];
  arr[min] = temp;        

  selectionSort(arr, start + 1, end);

}/*End of selectionSort()*/

	