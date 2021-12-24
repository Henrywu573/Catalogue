/* quick.c */

#include <stdio.h>
#include <stdlib.h>
void display(int *, int, int, int );
void quick_sort(int list[], int first, int last)
{
	int temp, low, high, pivot;

	low = first;
	high = last;
	pivot = list[(first + last) / 2];

	display(list, first, high, pivot);
	display(list, low, last, pivot);

	do {
		while (list[low] < pivot)
			low++;

		while (list[high] > pivot)
			high--;
		if (low <= high)
		{
			temp = list[low];
			list[low++] = list[high];
			list[high--] = temp;
		}

	} while (low <= high);
	if (first < high)
		quick_sort(list, first, high);

	if (low < last)
		quick_sort(list, low, last);
}

/* Output function */
void display(int list[], int low, int upper, int pivot)
{
	int k=0;
	//printf("\n Divided list is as follows \n");
	printf("\n Pivot is: %d \n ", pivot);
	for(k=low; k <upper; k++)
		printf(" %d", list[k]);
}
void main(void)
{
	int list[100], i, n;
	int first=0, last;
	printf("Input number of element: ");
	scanf("%d", &n);
	printf("\n Randomly Generated Unsorted list is as follows \n");
	last = n-1;
	for (i = 0; i < n; i++)
	{
		list[i] = rand() % 100;
		printf(" %d", list[i]);
	}
	quick_sort(list, first, last);

	printf("\n Sorted list as follows\n");

	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
}

