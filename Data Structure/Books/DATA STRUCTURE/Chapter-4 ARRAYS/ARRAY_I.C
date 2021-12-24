/* INSERTING AN ELEMENT INTO LINEAR ARRAY AT SPECIFIED POSITION */
/* ARRAY_I.C */

# include<stdio.h>

int insert_array(char *, int, int, char);
void input(char *, int );
void display(char *, int );

/* Definition of the function */

int insert_array(char array[], int number, int position, char element)
{
	int temp = number;
	while( temp >= position)
	{
		array[temp+1] = array[temp];
		temp --;
	}

	array[position] = element;
	number = number +1 ;
	return(number);
}

/* INPUT FUNCTION TO READ DATA */

void input(char array[], int number)
{
	int i;
	for(i = 1; i<= number ; i++)
	{
		fflush(stdin);
		printf("\n Input value for: %d: ", i);
		scanf("%c", &array[i]);
	}
}

/* OUTPUT FUNCTION TO PRINT ON THE CONSOLE */

void display(char array[], int number)
{
	int i;
	for(i = 1; i<= number; i++)
	{
		printf("\n Value at the position: %d: %c ", i, array[i]);
	}
}

/* main function */

void main()
{
	int number;
	char array[100];
	int position;
	char element;
	fflush(stdin);
	printf("\n Input the number of element into the LIST: ");
	scanf("%d", &number);
	fflush(stdin);
	input(array, number);
	printf("\n Entered list as follows:\n");
	fflush(stdin);
	display(array,number);
	fflush(stdin);
	printf("\n Input the position where you want add a new data:");
	scanf("%d", &position);
	fflush(stdin);
	printf("\n Input the value for the position:");
	scanf("%c", &element);
	number = insert_array(array,number,position,element);
	display(array,number);
}
