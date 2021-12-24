/* Transpose of a matrix */

/* TRANS_M.C */

# include<stdio.h>

int i, j;
int value;
int mat[10][10];
void display(int, int);
void display_o( int transp[10][10],int, int);
void input( int transp[10][10],int, int);
void transpose( int transp[10][10],int, int);

/* Transpose function */

void transpose(int transp[10][10], int row, int col)
{
	for(i = 0; i< row; i++)
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
			printf("  %d", mat[i][j]);
		}
		printf("\n");
	}
}

/* Output function */

void display_o(int transp[10][10], int row, int col)
{
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("  %d", transp[i][j]);
		}
		printf("\n");
	}
}

/* Input function */

void input(int transp[10][10], int row, int col)
{
	for(i = 0 ; i< row; i++)
	{
		for(j = 0 ;  j<col; j++)
		{
			printf("Input Value for : %d: %d: ", i+1,j+1);
			scanf("%d", &value);
			transp[i][j] = value;
		}
	}
}

/* main function */

void main()
{
	int row,col;
	int transp[10][10];
	printf("\n Input the number of rows:");
	scanf("%d", &row);
	printf(" Input number of cols:");
	scanf("%d", &col);
	input(transp, row, col);
	printf("\n Entered Matrix is as follows:\n");
	display_o(transp, row, col);
	transpose(transp,col,row);
	printf("\n Transpose of above matrix is as follows:\n");
	display(col, row);
}
