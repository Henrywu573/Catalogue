/* Divide and  Conquer */
/* Find minimum and maximum from a given series of numbers */
/* by using above said policy */

/* DIV_CON.C */

# include<stdio.h>
# define size 100

int min1, max1;
void div_con(int *, int, int *, int *);

/* definition of the function  div_con() */
void div_con( int list[], int n, int *min, int *max)
{
	if( n == 1)
		*min = *max = list[0];
	else
		if( n == 2)
		{
			if(list[0] < list[1])
			{
				*min = list[0];
				*max = list[1];
			}
			else
			{
				*min = list[1];
				*max = list[0];
			}
		}
		else
		{
			div_con(list, n/2, min,  max);
			div_con(list+ n/2, n - n/2, &min1, &max1);
			if( min1 < *min)
				*min = min1;
			if( max1 > *max)
				*max =  max1;
		}
}

/*  Function main */

void main()
{
	int i;
	int *min, *max;
	int list[size];
	int number;
	printf("\n Input the number of elements in the list :");
	scanf(" %d", &number);

	printf("\n Input the list elements:\n");
	for(i = 0; i < number; i++)
	{
		scanf("%d", &list[i]);
	};

	printf("\n Min and Max are :");
	div_con( list, number, min, max);
	printf("\n Mimimum = %d", *min);
	printf("\n Maximum = %d", *max);
}
