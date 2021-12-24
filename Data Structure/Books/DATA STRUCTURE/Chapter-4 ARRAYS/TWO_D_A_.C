/* TRAVERSING A TWO DIMENSIONAL ARRAY */

/* TWO_D_A_.C */

# include<stdio.h>

int i, j;
float mat[10][10];

void Traverse ( int, int);
void input( int, int);

/* Display function */

void Traverse (int row, int col)
{
	printf("\n Traversing in row major order\n");

	for( i = 0; i < row; i++)
	{
		for( j = 0; j < col; j++)
		{
			printf("\n 0x%x", &mat[i][j]);
			printf("  %f", mat[i][j]);
		}
		printf("\n");
	}

	printf("\n Traversing in column major order\n");

	for(j = 0; j < col; j++)
	{
		for(i = 0; i < row; i++)
		{
			printf("\n  0x%x", &mat[i][j]);
			printf("  %f", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n Traversing in row major order\n");

	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("  mat[%d][%d] = ", i, j);
			printf("%f", mat[i][j]);
		}
		printf("\n");
	}

	printf("\n Traversing in column major order\n");

	for(j = 0; j < col; j++)
	{
		for(i = 0; i < row; i++)
		{
			printf("  mat[%d][%d] = ", i, j);
			printf("%f", mat[i][j]);
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
			printf("\nInput Value for : %d: %d: ",i+1, j+1);
			scanf("%f", &mat[i][j]);
		}
	}

}

/* main function */

void main()
{
	int r,c;
	printf("\n Input the number of rows:");
	scanf("%d", &r);
	printf(" Input the number of cols:");
	scanf("%d", &c);

	input(r, c);
	Traverse(r, c);
}
