/* binary.c */
#include <stdio.h>
/* thisfunction implements the binary search algorithm */
int binary_search(int list[], int key, int n)
{
	int flag = 0;
	int high = n-1, low = 0, mid;

	mid = (high + low) / 2;

	printf("\n\n Looking for %d \n", key);

	while ((! flag) && (high >= low))
	{
		printf(" Low %d Mid %d High %d \n", low, mid, high);

		if (key == list[mid])
			flag = 1;
		else if (key < list[mid])
			high = mid - 1;
		else
			low = mid + 1;

		mid = (high + low) / 2;
	}
	return((flag) ? mid: -1);
}

void main(void)
{
	int list[100], i;

	for (i = 0; i < 100; i++)
		list[i] = i+20;

	printf("Result of search %d\n", binary_search(list, 33, 100));
	printf("Result of search %d\n", binary_search(list, 75, 100));
	printf("Result of search %d\n", binary_search(list, 1001, 100));
}



   
