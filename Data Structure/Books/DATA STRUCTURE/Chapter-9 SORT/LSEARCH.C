/* LINEAR SEARCH */
/* lsearch.c */
# include<stdio.h>
int flag = 0;
int list[200];

void linear_search(int * , int , int );
void display(int *, int);

/* This function implements the linear search algorithm */

void  linear_search(int list[], int n, int key)
{
	int k;
	flag = 1;
	for(k = 0; k< n; k++)
	{
		if(list[k] == key)
		{
			printf("\n Search is successful \n");
			printf("\n Element: %i Found at Location: %i", key,k+1);
			flag = 1 ;
		}
	}
	if (flag==0)
		printf("\n Search is unsuccessful");
}

/* Output function display the data list */
void display(int list[], int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		printf(" %d", list[i]);
	}
}

void main()
{
	int number, key, list[200];
	int i;
	printf("Input the number of elements in the list:");
	scanf("%d", &number);
	for(i = 0 ; i < number; i++)
	{
		list[i] = rand() %100; /* Generates data list */
	}
	printf("\n Input Element to be searched");
	scanf("%d", &key);

	printf("\n Entered list is as follows:\n");
	display(list, number);
	/* invoking function to search the key */
	linear_search(list, number, key);
	printf("\n In the following list\n");
	display(list, number);
}
