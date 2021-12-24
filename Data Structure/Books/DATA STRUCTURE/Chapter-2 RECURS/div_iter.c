
/* FIND MAXIMUM AND MINIMUM USING ITERATIVE METHOD */
/* DIV_ITER.C */

# include<stdio.h>

void max_min(int *, int, int , int );

/* Definition of the function  max_min() */

void max_min(int l[], int n, int max, int min)
{
	int i;
	max = min = l[0];
	for(i = 1; i < n; i++)
	{
		if(l[i] > max)
			max = l[i];
		if(l[i] < min)
			min = l[i];
	}
	printf("\n Maxmum = %d", max);
	printf("\n Minimum = %d", min);
}

/* main function */

void main()
{
	int i, list[100];
	int n, max, min;

	printf("\n Number of elements in the list :");
	scanf("%d", &n);

	printf("\n Input elements of the list:");

	for(i =0; i < n; i++)
		scanf("%d", &list[i]);

	max_min(list, n, max, min);
}
