
/*  DELETING  DUPLICATES FROM A LINEAR ARRAY*/
/* DUPL_A.C */

# include<stdio.h>

int status ;
int dup;
int duplicate_array(int *, int);
void input(int *, int );
void display(int *, int );

/* Definition of the function */

int duplicate_array(int array[], int number)
{
	int i, j, k;
	status = 0;
	dup  = number;

	for(i = 0; i< number-1; i++)
		for(j = i+1; j< number; j++)
		{
			if(array[i] == array[j])
			{
				number = number - 1 ;
				for(k = j; k<number; k++)
					array[k] = array[k+1];
				status = 1;
				j = j - 1;
			}
		}
	if( status ==0)
		printf("\n No duplicate is found");
	return(dup-number);
}

/* Input function to read data */

void input(int array[], int number)
{
	int i;
	for(i = 0; i< number ; i++)
	{
		printf("Input value for: %d: ", i+1);
		scanf("%d", &array[i]);
	}
}

/* Output function */

void display(int array[], int number)
{
	int i;
	for(i = 0; i< number; i++)
	{
		printf("\n Value at the position: %d: %d", i+1, array[i]);
	}
}

/* main function */

void main()
{
	int number;
	int array[100];
	int n;
	printf("\n Input the number of elements in the list: ");
	scanf("%d", &number);
	input(array, number);
	printf("\n Entered list is as follows:\n");

	display(array,number);

	n = duplicate_array(array,number);
	printf("\nNumber of duplicate elements in the list are: %d", n);
	printf("\nAfter removing duplicates from the list, the list is as follows:");
	display(array,number-n);
}
