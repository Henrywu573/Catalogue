/* SHORTEST PATH */
/* WARSHALL.C */

# include<stdio.h>
# define size 10

int a [size][size];
int p [size][size];
int i,k,j;
int n;

void Input ();
void Warshall ();
void Output ();

/* Input function */

void Input()
{
	printf("\n Input the number of vertices: ");
	scanf("%d", &n);
	printf("\n Input adjency matrix\n");
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
		printf("\n");
	}
	printf("\n Adjency matrix \n");
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			printf(" %d", a[i][j]);
		}
		printf("\n");
	}
}

/* Output function */

void   Output()
{
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			printf("  %d", p [i][j]);
		}
		printf("\n");
	}
}

/* Shortest path function */

void  Warshall ()
{
	/* Initialization of matrix m */

	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
				p [i][j] = 0;
			else
				p[i][j] = 1;
		}
	}

	/* Shortest Path evaluation start from here */

	for ( k = 0; k < n; k++)
	{
		for ( i = 0; i < n; i++)
		{
			for ( j = 0; j < n; j++)
			{
				p[i][j] = p[i][j] | ( p[i][k] & p[k][j]);
			}
		}
	}
}

/* Function main */

void main()
{
	Input ();
	Warshall ();
	printf("\n Path matrix:\n");
	Output ();
}
