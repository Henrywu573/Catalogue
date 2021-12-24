/* bubble.c */
#include <stdio.h>
#include <stdlib.h>
//int list[30];
void bubble_sort(int list[], int n)
{
	int temp, i=0, j=0, k=0;

	while(i < n-1)
	{
	   j = 0;
	   while (j < n-i-1)
	   {
		if (list[j+1] < list[j])
		{
			temp = list[j];
			list[j] = list[j+1];
			list[j+1] = temp;
		}
	   j++;
	   }
	   printf(" \n Result after %d pass \n", i+1);
	   for (k = 0; k < n; k++)
	   printf("  %d ", list[k]);

	i++;
	}
}

void main(void)
{
	int list[30], i, n;
	printf(" Input the number of elements in the list");
	scanf(" %d", &n);
	printf("\n Unsorted list is as follows\n");

	for (i = 0; i < n; i++)
	{
		list[i] = rand()%100;
	}

	for (i = 0; i < n; i++)
		printf("  %d ", list[i]);
	bubble_sort(list, n);
	printf("\n Sorted list is as follows\n");

	for (i = 0; i < n; i++)
		printf("  %d ", list[i]);

}