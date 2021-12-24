/* Find upper and lower half triangle of a matrix */
/* TRIANGLE.C */

# include<stdio.h>

int i, j;
float mat[10][10];

void display( int, int);
void input( int, int);
void Triangle_Matrix(int, int);

/* Display function */

void display(int row, int col)
{
	for( i = 0; i < row; i++)
	{
		for( j = 0; j < col; j++)
		{
			printf("  %f", mat[i][j]);
		}
		printf("\n");
	}
}

/* Input function */

void input(int row, int col)
{
	for(i = 0 ; i< row; i++)
	{
		for(j = 0 ;  j<col; j++)
		{
			printf("Input Value for : %d: %d: ",i+1, j+1);
			scanf("%f", &mat[i][j]);
		}
	}
}

/* Finding Triangle of a matrix */

void Triangle_Matrix(int row, int col)
{
	printf("\n Lower Half is as follows:\n");

	for(i = 0; i < row; i++)
	{
		for(j = 0; j< col ; j++)
		{
			if( i >= j )
			{
				printf(" %f", mat[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n Upper Half is as follows:\n");
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col ; j++)
		{
			if( i <= j )
				printf("  %f", mat[i][j]);
			if(i>j)
				printf("        ");
		}
		printf("\n");
	}
}

/* main function */

void main()
{
	int r,c;
	printf("\n Input number of rows:");
	scanf("%d", &r);
	printf(" Input number of cols:");
	scanf("%d", &c);
	input(r, c);
	printf("\n Entered Matrix is as follows:\n");
	display(r, c);
	printf("\n Triangle Matrix is as follows:\n");
	Triangle_Matrix(r,c);
}
