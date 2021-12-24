/* HEAP SORT */
/* HEAP.C */

# include<stdio.h>

void  heap_sort(int *, int );
void create_heap(int *, int);
void display(int *, int);

/*	 Definition of the function */

void create_heap(int list[], int n )
{

	int k, j, i, temp;

	for(k = 2 ; k <= n;  ++k)
	{
		i = k ;
		temp = list[k];
		j = i / 2 ;

		while((i > 1) && (temp > list[j]))
		{
			list[i] = list[j];
			i = j ;
			j = i / 2 ;
			if ( j < 1 )
				j = 1 ;
		}

		list[i] = temp ;
	}
}

/* End of heap creation function */

/* Definition of the function */

void heap_sort(int list[], int n)
{
	int k, temp, value, j, i, p;
	int step = 1;
	for(k = n ; k >= 2; --k)
	{
		temp = list[1] ;
		list[1] = list[k];
		list[k] = temp ;

		i = 1 ;
		value = list[1];
		j = 2 ;

		if((j+1) < k)
			if(list[j+1] > list[j])
				j ++;
		while((j <= ( k-1)) && (list[j] > value))
		{
			list[i] = list[j];
			i = j ;
			j = 2*i ;
			if((j+1) < k)
				if(list[j+1] > list[j])
					j++;
				else
					if( j > n)
						j = n ;
			list[i] = value;
		} /* end of while statement */
		
		printf("\n Step = %d ", step);
		step++;	
		for(p = 1; p <= n; p++)
			printf(" %d", list[p]);
	} /* end for loop */
}

/* Display function */

void display(int list[], int n)
{
	int i;
	for(i = 1 ; i <= n; ++ i)
	{
		printf("  %d", list[i]);
	}
}

/* Function main */

void main()
{
	int list[100];
	int i, n ;

	printf("\n Size of the list:");
	scanf(" %d", &n);

	for(i = 1 ; i <= n ; ++i)
	{
		list[i] = rand() % 100;
	}
	printf("\n Entered list is as follows:\n");
	display(list, n);
	create_heap(list, n);
	printf("\n Heap\n");
	display(list, n);
	printf("\n\n");

	heap_sort(list,n);

	printf("\n\n Sorted list is as follows :\n\n");
	display(list,n);

}







