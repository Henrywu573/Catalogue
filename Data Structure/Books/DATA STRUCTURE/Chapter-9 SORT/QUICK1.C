/*  QUICK SORT */
/* Sorting an array by using Hoare's quicksort */
/* QUICK1.C */

# include<stdio.h>

int quick_sort(int *, int, int, int (*p_cmp_f)(int *,int *));
int *select_pivot(int data[], int n, int size,  int (*p_cmp_f)(int *,int *));
void memswap(int *s, int *t, int count);

void main()
{
	int n, i;
	int list[100];
	int (*p_cmp_f)(int *, int *);
	int size ;
	printf("\n Number of elements in the list: ");
	scanf("%d", &n);

	printf("\n Input the elements: \n");
	for(i = 0 ; i < n ; i++)
		scanf("%d", &list[i]);
	
	printf("\n Sorted list\n");
	quick_sort(list, n, size, p_cmp_f);
	for(i = 0 ; i < n ; i++)
		printf(" %d", list[i]);
}

int quick_sort(int data[], int n, int size, int (*p_cmp_f)(int *,int *))
{
	int *p_left, *p_right, *p_pivot;
	int lsize;

	if(n <= 1)
		return 0;
	p_left = data;
	p_right = data + ( n - 1 ) * size;

	/* find pivot and move it to the right end */
	p_pivot = select_pivot(data, n, size, p_cmp_f);
	memswap(p_pivot, p_right, size);
	p_pivot = p_right;

	/* partition */

	while(p_left < p_right)
	{
		while((*p_cmp_f)(p_left, p_pivot) >= 0 && (p_left < p_right))
			p_left += size ;
		while((*p_cmp_f)(p_right, p_pivot) >= 0 && (p_left < p_right))
			p_right -= size ;

		if(p_left < p_right)
		{
			memswap(p_left, p_right, size);
			p_left += size ;
		}
	}

	if(p_right == data )
	{
		memswap(p_right, p_pivot, size);
		p_right += size ;
	}

	lsize = (p_right -data) / size ;
	quick_sort(data, lsize, size, p_cmp_f);
	quick_sort(p_right, n- lsize, size, p_cmp_f);
}

int *select_pivot(int data[], int n, int size,  int (*p_cmp_f)(int *, int *))
{
	return data;
}

void memswap(int *s, int *t, int count)
{
	int temp ;
	while(count --> 0)
	{
		temp = *s ;
		*s ++ = *t ;
		*t++ = temp ;
	}
}




