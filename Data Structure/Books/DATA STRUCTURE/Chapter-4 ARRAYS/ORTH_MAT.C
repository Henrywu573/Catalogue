/* Find Orthogonality of a matrix */

/* ORTH_MAT.C */

# include<stdio.h>
# include<stdlib.h>

# define row 10
# define col 10

int i, j, k;
int row1, col1;
float mat1[row][col];
float mat2[row][col];
float mat_res[row][col];

void mat_mult( float mat1[row][col], int, int,
float mat_res[row][col]);

void transpose( float transp[row][col], int, int);
void display(float mat[row][col], int, int);
void input(float mat[row][col], int , int);

/* function mat_mult */

void mat_mult( float mat1[row][col], int row1, int col1,
float mat_res[row][col])
{
	int flag ;
	if(col1 == row1)
	{
		printf("\n Multiplication is possible and Result is as follows\n");

		for(i = 0; i<row1; i++)
			for(j = 0; j<col1; j++)
			{
				mat_res[i][j] = 0;
				for(k = 0; k < col1; k ++)
				{
					mat_res[i][j] += mat1[i][k] * mat2[k][j];
				}
			}
		display(mat_res,row1,col1);
	}

	else
	{
		printf("\n Multiplication is not possible");
		exit(0);
	}

	for(i = 0 ; i< row1; i++)
	{
		for(j = 0; j < col1; j++)
		{
			if(((int)mat_res[i][i] == 1) && ((int ) mat_res[i][j] == 0))
				flag = 1;
		}
	}
	if( flag == 1)
	{
		printf("\n Matrix X * Transpose of X = Identity Matrix");
		printf("\n The given Matrix is Orthogonal");
	}
	else
	{
		printf("\n Matrix X * Transpose of X != Identity Matrix");
		printf("\n The given Matrix is not Orthogonal");
	}
}

/* Output function */

void display(float mat[row][col], int r, int c )
{
	printf("\n");
	for( i = 0; i < r; i++)
	{
		for( j = 0; j < c; j++)
		{
			printf("   %f", mat[i][j]);
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
			printf("Input Value for: %d: %d: ", i+1, j+1);
			scanf("%f", &mat[i][j]);
		}
	}
}

/* Transpose of a matrix */

void transpose( float transp[10][10],int row1, int col1)
{
	for( i = 0; i< row1; i++)
	{
		for( j = 0; j < col1; j++)
		{
			mat2[i][j] = transp[j][i] ;
		}
	}
	display(mat2,row1,col1);
}


/*  main function */

void main()
{
	int row1, col1;
	int row2, col2;
	float mat1[row][col];
	float mat2[row][col];
	float mat_res[row][col];

	printf("\n Input the row  of the matrix:");
	scanf("%d", &row1);

	printf(" Input the col  of the matrix:");
	scanf("%d", &col1);

	printf("\n Input data for matrix\n");
	input(mat1, row1, col1);

	printf("\n Entered Matrix First is as follows:\n");
	display(mat1,row1,col1);

	printf(" \n Transpose of above matrix is as follows:\n");
	transpose(mat1, col1, row1);

	mat_mult(mat1 ,row1 ,col1, mat_res);
}
