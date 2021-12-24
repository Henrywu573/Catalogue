/* Find trace of a matrix */
/* TRAC_M.C */

# include<stdio.h>

int i, j;
float mat[10][10];

void display( int, int);
void input( int, int);
float trace_mat(int, int);

/* Display function */

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

/* Input function */

void input(int row, int col)
{
	for(i = 0 ; i < row; i++)
	{
		for(j = 0 ;  j < col; j++)
		{
			printf("\nInput Value for : %d: %d: ", i+1, j+1);
			scanf("%f", &mat[i][j]);
		}
	}
}

/* Finding trace of a matrix */

float trace_mat(int row, int col)
{
	float trace = 0;
	for(i = 0; i < row; i++)
		for(j = 0; j< col; j++)
			if(i == j)
				trace += mat[i][j];
	return(trace);
}

/* main function */

void main()
{
	float trace;
	int r,c;
	printf("\n Input the number of rows:");
	scanf("%d", &r);
	printf(" Input number of cols:");
	scanf("%d", &c);
	input(r,c);
	printf("\n Entered Matrix is as follows:\n");
	display(r,c);
	printf("\n Trace of above matrix is :");
	trace = trace_mat(r,c);
	printf("%f", trace);
}
