/* Traversing a linear array */
/* ARRAY_L.C */

# include<stdio.h>


void memory(int *, int, int);
void memory1(char *, int, int);

/* Definition of the function memory */

void memory(int a[], int l_b, int u_b)
{
	int counter;

	for(counter = l_b; counter<=u_b; counter++)
	{
		printf("\n Element at location: 0x%x is %d", &a[counter], a[counter]);
	}
	printf("\n Array size = %d ", &a[counter-1] - &a[0] + 1);
}

void memory1(char b[], int l_b, int u_b)
{
	char *pointer;
	int counter;
	pointer =&b[0];

	for(counter = l_b; counter<=u_b; counter++)
	{
		printf("\n Element at location: 0x%x is %d", &b[counter], b[counter]);
	}
	printf("\n Array size = %d", &b[counter-1] - &b[0] + 1);
}

/*Function main */

void main()
{
	int a[12] = {
		99,88,77,66,55,44,33,22,11,100,200,300	};
	char b[] = {
		'A','B','C','D','E','F','G','H','I','J','K',
					  'L','M','N','O','P','Q','R','S','T','U','V',
					  'W','X','Y','Z'	};
	int lb=0, ub=11;
	memory(a,lb,ub);
	lb = 0;
	ub = 25;
	memory1(b,lb,ub);
}


