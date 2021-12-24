/* Find norm of matrix: Norm a matrix is defined as squareroot of the sum
   of the squares of the elements of a matrix */

/* TWO_NOR.C */

# include<stdio.h>
# include<math.h>

# define row 10
# define col 10

int i, j;
float summation;

void display( float mat[row][col], int, int);
void input(float mat[row][col] ,int, int);
float norm_mat(float mat[row][col], int, int);

/* Output function */

void display(float mat[row][col] ,int row1, int col1)
{
	for(i = 0; i < row1; i++)
	{
		for(j = 0; j < col1; j++)
		{
			printf("  %f", mat[i][j]);
		}
		printf("\n");
	}
}

/* Input function */

void input(float mat[row][col] ,int row1, int col1)
{
	for(i = 0 ; i< row1; i++)
	{
		for(j = 0 ;  j<col1; j++)
		{
			printf("\nInput Value for : %d: %d: ", i+1, j+1);
			scanf("%f", &mat[i][j]);
		}
	}
}

/* Calculating norm of a matrix */

float norm_mat( float mat[row][col], int row1, int col1)
{
	summation = 0;
	for(i = 0; i < row1; i++)
	{
		for(j = 0; j < col1; j++)
		{
			summation += mat[i][j] * mat[i][j];
		}
	}
	return(summation);
}

/* main function */

void main()
{
	float mat[row][col];
	int r,c;
	printf("\n Input number of rows:");
	scanf("%d", &r);
	printf("\n Input number of cols:");
	scanf("%d", &c);
	input(mat, r, c);
	printf("\n Entered Two Dimensional array is as follows:\n");
	display(mat, r, c);
	printf("\n Norm of above matix is : %f", sqrt(norm_mat(mat, r, c)));
}
