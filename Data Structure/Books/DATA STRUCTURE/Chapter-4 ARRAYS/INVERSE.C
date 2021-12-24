/* Find Inverse of a Matrix */
/* INVERSE.C */

# include<stdio.h>

int i, j;

void display( int, int,  float mat[10][10],float mat1[10][10]);
void input( int, int,  float mat[10][10],float mat1[10][10]);
Inverse_Mat(int , int,  float mat[10][10],float mat1[10][10]);
void swap(int, int, int,  float mat[10][10],float mat1[10][10]);

/* This function exchange two rows of a matrix */

void swap( int row1,int row2, int col, float mat[10][10],float mat1[10][10])
{
	for( i = 0; i < col; i++)
	{
		float   temp = mat[row1][i];
		mat[row1][i] = mat[row2][i];
		mat[row2][i] = temp;

		temp = mat1[row1][i];
		mat1[row1][i] = mat1[row2][i];
		mat1[row2][i] = temp;

	}
}

/* This function find inverse of matrix */

int Inverse_Mat(int row1, int col1, float mat[10][10],float mat1[10][10])
{
	int singular = 0;
	int r, c;
	for(r = 0;( r < row1)&& !singular;  r++)
	{

		if( mat[r][r] )  /* Diagonal element is not zero */
			for(c = 0; c < col1; c++)

				if( c == r)
				{

					/* Make all the elements above and below the current principal
					 diagonal element zero */

					float ratio =  mat[r][r];
					for( i = 0; i < col1; i++)
					{
						mat[r][i] /= ratio ;
						mat1[r][i] /= ratio;
					}
				}
				else
				{
					float ratio = mat[c][r] / mat[r][r];
					for( i = 0; i < col1;  i++)
					{
						mat[c][i] -= ratio * mat[r][i];
						mat1[c][i] -= ratio * mat1[r][i];
					}
				}

		else
		{
			/* If principal diagonal element is zero */
			singular = 1;

			for(c = (r+1); (c < col1) && singular; ++c)

				if(mat[c][r])
				{
					singular = 0;
					/* Find non zero elements in the same column */
					swap(r,c,col1, mat, mat1);
					--r;
				}

		}
	}
	return(!singular);
}

/* To print output this is used */

void display( int row, int col, float mat[10][10],float mat1[10][10])
{
	printf("\n");
	/* Output of inverse Matrix */
	for( i = 0; i < row; i++)
	{
		for( j = 0; j < col; j++)
		{
			printf("   %f", mat1[i][j]);
		}
		printf("\n");
	}

}

/* input function */

void input( int row, int col, float mat[10][10],float mat1[10][10])
{
	for( i = 0 ; i< row; i++)
	{
		for( j = 0 ;  j<col; j++)
		{
			printf("Input Value for: %d: %d: ", i+1, j+1);
			scanf("%f", &mat[i][j]);
			mat1[i][j] = 0;
		}
		mat1[i][i] = 1;
	}
	printf("\n Entered Matrix is as follows:\n");
	for( i = 0; i < row; i++)
	{
		for( j = 0; j < col; j++)
		{
			printf("   %f", mat[i][j]);
		}
		printf("\n");
	}
}


/* main function */


void main()
{

	int R, C;
	float mat[10][10];
	float mat1[10][10];
	printf("\n Input number of rows:");
	scanf("%d", &R);
	printf(" Input number of cols:");
	scanf("%d", &C);
	input(R,C, mat, mat1);

	Inverse_Mat(R,C, mat,  mat1);
	printf("\n Inverse of above matrix is as follows:\n ");
	display(R,C, mat, mat1);
}
