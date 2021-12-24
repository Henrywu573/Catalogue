/* SELECTION SORT */
/* selects.c */

# include<stdio.h>

void selection_sort(int , int *); /* Prototype */

void main()
{
	int number, list[200];
	int i;
	printf("Input the number of elements in the list:");
	scanf("%d", &number);
	printf("\n Number  of elements in the list is: %d", number);

	printf("\nInput the elements of the list\n");
	for(i = 0 ; i < number ; i++)
		scanf("%d", &list[i]);

	selection_sort( number, list);
}

/* Definition of function */

void selection_sort(int n, int list[])
{
	int min, temp;
	int k, l, index;

	for(index = 0; index< n - 1 ; index++)
	{
		min = index ;
		for(k = index + 1; k < n ; k ++)
		{
			if(list[min] > list[k])
				min = k ;
		}
		if(min != index)
		{
			temp = `list [index];
			list[index] = list[min];
			list[min] = temp ;
		}
		printf(" \n Step : %d :",(index+1));
		for( l = 0 ; l < n; l++)
		printf(" %d", list[l]);
	}

	printf("\n Sorted list is as  follows:\n");
	for( index = 0 ; index < n; index++)
		printf(" %d", list[index]);
	return 0;
}
