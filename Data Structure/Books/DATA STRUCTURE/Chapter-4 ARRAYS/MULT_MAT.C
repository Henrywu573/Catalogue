/* Multiply Two Matrices */

/* MULT_MAT.C */

# include<stdio.h>
# include<stdlib.h>

# define row 10
# define col 10

int i, j;
int row1, col1;
int row2, col2;
float mat1[row][col];
float mat2[row][col];
float mat_res[row][col];

void mat_mult(  float mat1[row][col], int, int,
float mat2[row][col], int, int,
float mat_res[row][col]);

void display(float mat[row][col], int, int);
void input(float mat[row][col], int , int);

/* function to multiply two matrices */

void mat_mult( float mat1[row][col], int row1, int col1,
float mat2[row][col], int row2, int col2,
float mat_res[row][col])
{
	int i, j, k;
	if(col1 == row2)
	{
		printf("\n Multiplication is possible and Result is as follows\n");

		for(i =0; i<row1; i++)
			for(j=0; j<col2; j++)
			{
				mat_res[i][j] = 0;
				for(k = 0; k < col1; k ++)
				{
					mat_res[i][j] += mat1[i][k] * mat2[k][j];

				}
			}
		display(mat_res, row1, col2);
	}

	else
		printf("\n Multiplication is not possible");
	exit(0);
}

/* Output function */

void display(float mat[row][col], int r, int c )
{
	for( i = 0; i < r; i++)
	{
		for( j = 0; j < c; j++)
		{
			printf("  %f", mat[i][j]);
		}
		printf("\n");
	}
}

/* Input function */

void input(float mat[row][col], int r, int c)
{

	for( i = 0 ; i< r; i++)
	{
		for( j = 0 ;  j<c; j++)
		{
			printf("Input Value for : %d: %d: ", i+1, j+1);
			scanf("%f", &mat[i][j]);
		}
	}
}


/* main function */

void main()
{

	int row1, col1;
	int row2, col2;
	float mat1[row][col];
	float mat2[row][col];
	float mat_res[row][col];

	printf("\n Input the row  of the matrix->1:");
	scanf("%d", &row1);

	printf("\n Input the col  of the matrix->1:");
	scanf("%d", &col1);

	printf("\n Input data for matrix-> 1\n");
	input(mat1, row1, col1);

	printf("\n Input the row  of the matrix ->2:");
	scanf("%d", &row2);

	printf("\n Input the col  of the matrix->2:");
	scanf("%d", &col2);

	printf("\n Input data for matrix-> 2\n");
	input(mat2, row2, col2);

	printf("\n Entered Matrix First is as follows:\n");
	display(mat1,row1,col1);

	printf("\n Entered Matrix Two is as follows:\n");
	display(mat2,row2,col2);

	mat_mult(mat1 ,row1 ,col1, mat2, row2, col2, mat_res);
}
