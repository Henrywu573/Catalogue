/* shell.c */
/* shell sort */

#include <stdio.h>
#include <stdlib.h>
void display(int *, int );
void shell_sort(int *, int );

/* function for shell sort */
void shell_sort(int list[], int n)
{
	int temp, gap, i, swap=0;

	gap = n / 2;

	do {
		do {
			swap = 0;

			for (i = 0; i < n - gap; i++)
				if (list[i] > list[i + gap])
				{
					temp = list[i];
					list[i] = list[i + gap];
					list[i + gap] = temp;
					swap = 1;
				}
		printf("\n List after pass \n");
		display(list, n);
		} while (swap);
	} while (gap = gap / 2);
}
/* Output Function */
void display(int list[], int n)
{
	int k;
	for(k = 0; k < n; k++)
		printf(" %d ", list[k]);
}

void main(void)
{
	int list[50], i, n;
	printf("\n Input Number of Data Elements: ");
	scanf("%d", &n);
	printf("\n Randomly Generated Unsorted list is as follows \n");

	for (i = 0; i < n; i++)
	{
		list[i] = rand() % 100;
		printf(" %d", list[i]);
	}
	shell_sort(list, n);

	printf("\n Sorted list is as follows \n");

	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
}

