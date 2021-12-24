/* Test for symmetry of a matrix */

/* SYMMET.C */

# include<stdio.h>

# define r 10
# define c 10

int i, j;
float value;
float mat[r][c];
void display(int, int);
void display_o( float transp[r][c],int, int);
void input( float transp[r][c],int, int);
void transpose( float transp[r][c],int, int);
int Symmetry_Matrix(float transp[r][c], int , int );

/* Transpose function */

void transpose( float transp[r][c], int row, int col)
{
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			mat[i][j] = transp[j][i] ;
		}
	}
}

/* Output function */

void display(int row, int col)
{
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("  %f", mat[i][j]);
		}
		printf("\n");
	}
}

/* Output function */

void display_o(float transp[r][c], int row, int col)
{
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("  %f", transp[i][j]);
		}
		printf("\n");
	}
}

/* Input function */

void input( float transp[r][c], int row, int col)
{
	for(i = 0 ; i< row; i++)
	{
		for(j = 0 ;  j<col; j++)
		{
			printf("Input Value for : %d: %d: ", i+1,j+1);
			scanf(" %f", &value);
			transp[i][j] = value;
		}
	}
}

/* Test  for Symmetry */

int  Symmetry_Matrix(float transp[r][c], int row, int col)
{
	int status = 0;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j<col; j++)
			if(mat[i][j] != transp[i][j])
				status = 1;
	}
	return(status);
}

/* main function */

void main()
{
	int status;
	int row, col;
	float transp[10][10];
	printf("\n Input number of rows:");
	scanf("%d", &row);
	printf("\n Input number of cols:");
	scanf("%d", &col);
	input(transp, row, col);
	printf("\n Entered Matrix is as follows:\n");
	display_o(transp, row, col);
	transpose(transp, col, row);
	printf(" \n Transpose of above matrix is as follows:\n");
	display(col,row);
	status = Symmetry_Matrix(transp, row, col);
	if(status)
		printf("\n Matrix is not symmetric ");
	else
		printf("\n Matrix is Symmetric ");
}
