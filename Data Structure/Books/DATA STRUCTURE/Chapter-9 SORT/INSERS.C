/* INSERTION SORT */
/* INSERS.C */

# include<stdio.h>
# include<stdlib.h>

int key;

int  insertion_sort(int *);  
// prototype
void display(int *, int);

/* Definition of the insertion sort function */

int insertion_sort(int list[])
{
	int i = 0;
	int j, k ;
	printf("\nElement to be inserted Break condition is -0 : ");
	scanf("%d", &key);
	printf("\n Selected Element is: %d", key);

	while(key != -0 ) /* -0 is break condition */
	{
		k = i - 1;
		while((key < list[k]) && (k >= 0))
		{
			list[k+1] = list[k];
			--k;
		}

		list[k+1] = key ;
		printf("\n List after inserting an element ");
		for(j = 0 ; j<=i; j++)
			printf(" %d", list[j]);

		printf("\n Element to be inserted Break condition is -0: ");
		scanf("%d", &key);
		printf("\n Selected Element is: %d", key);
		i ++;

	}
	return i;
}

/* End of the insertion sort function */

/* Definition of the function */

void display(int list[], int n)
{
	int j;
	printf("\n Final sorted list is as follows:\n");
	for(j = 0 ; j < n ; j++)
		printf(" %d", list[j]);
}

/* End of the display function */

void main()
{
	int list[200];
	int n ;

	n = insertion_sort(list);
	display(list,n);
}

