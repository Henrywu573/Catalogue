/*P7.4 Program to find out the path matrix by powers of adjacency matrix*/

#include<stdio.h>
#define MAX 100

void display(int matrix[MAX][MAX]);
void pow_matrix(int p,int adjp[MAX][MAX] );
void multiply(int mat1[MAX][MAX],int mat2[MAX][MAX],int mat3[MAX][MAX]);

void create_graph( );
int adj[MAX][MAX];
int n;

main()
{

	int adjp[MAX][MAX];
	int x[MAX][MAX],path[MAX][MAX],i,j,p;

	create_graph();

	printf("The adjacency matrix is :\n");
	display(adj);

	/*Initialize all elements of matrix x to zero*/
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		   x[i][j] = 0;
	
	/*All the powers of adj will be added to matrix x */
	for(p=1; p<=n; p++)
	{
		pow_matrix(p,adjp);
		printf("Adjacency matrix raised to power %d is - \n", p);
		display(adjp);	
		for(i=0; i<n; i++)
		  for(j=0; j<n; j++)
			 x[i][j] = x[i][j]+adjp[i][j];
	}

	printf("The matrix x is :\n");
	display(x);
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if (x[i][j] == 0 )
	   			path[i][j] = 0;
			else
				path[i][j] = 1;
	
	printf("The path matrix is :\n");
	display(path);
}/*End of main() */


void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);

	max_edges = n*(n-1); 

	for( i=1; i<=max_edges; i++ )
	{
		printf("Enter edge %d( -1 -1 ) to quit : ",i);
		scanf("%d %d",&origin,&destin);
		if( (origin == -1) && (destin == -1) )
			break;
		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[origin][destin] = 1;
	}/*End of for*/
}/*End of create_graph()*/


/*This function computes the pth power of matrix adj and stores result in adjp */
void pow_matrix(int p,int adjp[MAX][MAX])
{

	int i,j,k,tmp[MAX][MAX];

	/*Initially adjp is equal to adj*/
	for(i=0; i<n; i++)
	  for(j=0; j<n; j++)
	   adjp[i][j] = adj[i][j];

	for(k=1; k<p; k++)
	{
		/*Multiply adjp with adj and store result in tmp */
		multiply(adjp,adj,tmp);
		for(i=0; i<n; i++)
		  for(j=0; j<n; j++)
		     adjp[i][j] = tmp[i][j]; /* New adjp is equal to tmp */
	}
}/*End of pow_matrix()*/

/*This function multiplies mat1 and mat2 and stores the result in mat3 */
void multiply(int mat1[MAX][MAX],int mat2[MAX][MAX],int mat3[MAX][MAX])
{
	int i,j,k;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			mat3[i][j] = 0;
			for(k=0; k<n; k++)
				mat3[i][j] = mat3[i][j]+ mat1[i][k] * mat2[k][j];
	   }
}/*End of multiply()*/

void display(int matrix[MAX][MAX])
{
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%4d",matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}/*End of display()*/
