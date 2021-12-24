/* select.c */
/* selection sort */

#include <stdio.h>
#include <stdlib.h>

/* function implements selection sort */
void selection_sort(int list[], int n)
{
	int temp, current, j, k=0;

	for (current = 0; current < n; current++)
	{
		for (j = current + 1; j < n; j++)
			if (list[current] > list[j])
			{
				temp = list[current];
				list[current] = list[j];
				list[j] = temp;
			}
		printf("\n Step : %d :", (current+1));
		for(k=0; k<n; k++)
			printf(" %d", list[k]);
	}
}

void main(void)
{
	int list[30], i,n;
	printf("Input Number of elements in the list: ");
	scanf("%d",&n);
	printf("\n Randomly Generated Unsorted list is as follows \n");
	for (i = 0; i < n; i++)
	{
		list[i] = rand() % 100;
		printf(" %d", list[i]);
	}
	selection_sort(list, n);

	printf("\n Sorted list is as follows \n");

	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
}

