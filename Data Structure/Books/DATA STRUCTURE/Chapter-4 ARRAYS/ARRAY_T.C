
/* Traversing a linear array */
/* ARRAY_T.C */

# include<stdio.h>

void traversing_array(int *, int, int);
void input(int *, int, int);

/*  Definition of the function*/

void traversing_array(int linear_array[], int l_b, int u_b)
{
	int counter;
	for(counter = l_b; counter<=u_b; counter++)
	{
		printf("\n Element at position: %d is %d ", counter, linear_array[counter]);
	}
}

/*  Defintion of the function*/

void input(int array[], int l_b, int u_b)
{
	int counter;
	for(counter = l_b; counter<= u_b; counter++)
	{
		printf("\n Input value for the: %d: ", counter);
		scanf("%d", &array[counter]);
	}
}


/* Definition of the function */

void main()
{
	int a[100];
	int lb, ub;

	printf("\n Lower limit of the array:");
	scanf("%d", &lb);
	printf("\n Upper limit of the array:");
	scanf("%d", &ub);
	input(a, lb, ub);
	traversing_array(a,lb,ub);
}


