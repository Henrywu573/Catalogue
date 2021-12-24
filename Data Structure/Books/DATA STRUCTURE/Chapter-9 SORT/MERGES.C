/* SIMPLE MERGE SORT */
/* MERGES.C */

# include<stdio.h>

int merge_sort( int , int *, int  , int *, int * );
int bubble_sort(int , int *);

/* Definition of function */

bubble_sort(int n, int list[])
{
	int flag = 1 ;
	int i, j, k, temp;
	for(j = 0 ; j< n - 1; j++)
	{
		for(k = 0 ; k<  n - j - 1 ; k++)
		{
			if(list[k] > list[k+1])
			{
				temp = list[k];
				list[k] = list[k+1];
				list[k+1] = temp ;
				flag = 0;
			}
		}
		if(flag)
			break ;
		else
			flag = 1;
	}
	printf("\n Entered  list as  follows in");
	printf("\n Ascending order: ");
	for(i = 0 ; i < n ; i++)
		printf(" %d", list[i]);
	return 0 ;
}

/* Definition of function */

merge_sort( int n, int list_a[], int m ,
int list_b[], int result_list[] )
{
	int i = 0;
	int j = 0;
	int k = 0;
	int ch, l;

	/* Repeat the process until the elements of list_a and list_b are exhausted */

	while((i < n) &&(j<m))
	{
		if(list_a[i] < list_b[j])
		{
			result_list[k] = list_a[i];
			i++;
			k++;
		} /*  end of if statement */
		else
			if(list_a[i] > list_b[j])
			{
				result_list[k] = list_b[j];
				j++;
				k++;
			} /* end of if statement */
			else
			{
				result_list[k] = list_a[i];
				i++;
				j++;
				k++;
			}  /* end of else statement */
		printf("\n");
		for(ch = 0; ch < k; ch++)
			printf(" %d", result_list[ch]);

	}  /* end of while statement */

	/*  checks if size of list_a larger than list_b
	 copy rest of the elements of list_a into result_list */

	if(i <n )
	{
		for(l = i ; l <n ; l++)
		{
			result_list[k] = list_a[i];
			i++;
			k++;
			printf("\n");
			for(ch = 0; ch < k; ch++)
				printf(" %d", result_list[ch]);
		}
	}
	else

		/* checks if size of list_b larger than list_a
		 copy rest of the elements of list_b into result_list */

		if(j < m)
		{
			for(l = j; l<m; l++)
			{
				result_list[k] = list_b[j];
				j++;
				k++;
				printf("\n");
				for(ch = 0; ch < k; ch++)
					printf(" %d", result_list[ch]);
			}
		}
	return (k);
}

/* function main */

void main()
{
	int list_a[100],list_b[100];
	int result[200];
	int n, m, k, i;

	printf("\n Input the number of elements of list_a: ");
	scanf("%d", &n);

	for(i = 0; i<n ; i++)
	{
		printf("\n Input the element: %d: ",  i+1);
		scanf("%d", &list_a[i]);
	}

	/* Sort the elements of list_a */

	bubble_sort(n, list_a);

	/* End of sorting */

	printf("\n Input the number of elements of list_b:");
	scanf("%d", &m);
	for(i = 0 ; i< m ; i++)
	{
		printf("\n Input the element: %d: ", i+1);
		scanf("%d", &list_b[i]);
	}

	/* Sort the elements of list_b */

	bubble_sort(m, list_b);

	/* End of sorting */

	k = merge_sort( n, list_a, m , list_b, result);
	printf("\n Duplicates are : %d", m+n-k);
	printf("\n");

	printf("\n Sorted list is as follows:\n");
	for(i = 0 ; i< k ; i++)
	{
		printf(" %d", result[i]);
	}
}
