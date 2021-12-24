/* Sorting two dimensional arrays row wise */
/* TWO_SORT.C */

# include<stdio.h>

int i, j;
float mat[10][10];

void display( int, int);
void input( int, int);
void Two_Sort_Matrix(int, int);

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
	for(i = 0 ; i< row; i++)
	{
		for(j = 0 ;  j<col; j++)
		{
			printf("\nInput Value for : %d: %d: ", i+1, j+1);
			scanf("%f", &mat[i][j]);
		}
	}
}

/* Sorting of a matrix */

void Two_Sort_Matrix(int row, int col)
{
	int flag ;
	do
	{
		flag = 1;
		for(i = 0; i < row; i++)
		{
			for(j = 0; j< col ; j++)
			{
				if(mat[i][j] < mat[i][j+1])
				{
					float temp = mat[i][j];
					mat[i][j] = mat[i][j+1];
					mat[i][j+1] = temp;
					flag = 0;
				}
			}
		}
		col -= 1;
	} while(flag == 0);
}

/* main function */

void main()
{
	float trace;
	int r,c;
	printf("\n Input number of rows:");
	scanf("%d", &r);
	printf("\n Input number of cols:");
	scanf("%d", &c);

	input(r, c);

	printf("\n Entered Matrix is as follows:\n");
	display(r, c);

	printf("\n Sorted Matrix is as follows:\n");
	Two_Sort_Matrix(r, c);

	display(r, c);
}
