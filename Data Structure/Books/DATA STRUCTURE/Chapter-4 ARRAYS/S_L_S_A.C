/* SEARCHING FOR LARGEST AND SMALLEST ELEMENTS IN A LINEAR ARRAY */
/* S_L_S_A.C */

# include<stdio.h>

int s;
int small, big, temp;

int search_array(int *, int);
void input(int *, int );
void display(int *, int );

/* Definition of the function */

int search_array(int array[], int number)
{
	big = small = array[0];
	temp = 0;

	while(temp < number)
	{
		if(array[temp] > big)
		{
			big = array[temp] ;
		}
		else if(array[temp] < small)
		{
			small = array[temp];
		}

		temp ++;
	}
	s = small;
	return(big);
}

/* Input function */

void input(int array[], int number)
{
	int i;
	for(i = 0; i< number ; i++)
	{
		printf("Input value for : %d: ",i+1);
		scanf("%d", &array[i]);
	}
}

/* Output function */

void display(int array[], int number)
{ 
	int i;
	for(i = 0; i < number; i++)
	{
		printf("\n Value at the position: %d: %d", i+1, array[i]);
	}
}

/* main function */

void main()
{
	int number,big;
	int array[100];

	printf("\n Input the number of elements in the list:");
	scanf("%d", &number);
	input(array, number);
	printf("\n Entered list is as follows:\n");

	display(array,number);

	big = search_array(array,number);
	printf("\nLargest number in the array is : %d", big);
	printf("\nSmallest number in the array is : %d", s);
}
