/*P7.11 Demo Program to find shortest path matrix by Modified Warshall's algorithm  */

#include<stdio.h>
#include<stdlib.h>

#define infinity 9999
#define MAX 100

#define STOP getchar()

int n; /*Number of vertices in the graph*/
int adj[MAX][MAX];  /*Weighted Adjacency matrix*/
int D[MAX][MAX];  /*Shortest Path Matrix*/
int Pred[MAX][MAX]; /*Predecessor Matrix*/

void create_graph();
void FloydWarshalls( );
void findPath(int s, int d);
void display(int matrix[MAX][MAX], int n);

main( )
{
	int s, d;
	create_graph();

	FloydWarshalls( );
	while(1)
	{
		printf("Enter source vertex(-1 to exit)  : ");
		scanf("%d",&s);
		if(s == -1)
			break;
		printf("Enter destination vertex : ");
		scanf("%d",&d);
		if( s < 0 || s>n-1 || d<0 || d>n-1)
		{
			printf("Enter valid vertices \n\n");
			continue;
		}
		printf("Shortest path is : ");
		findPath(s,d);
		printf("Length of this path is %d\n",D[s][d]);
	}

}/*End of main( )*/

void FloydWarshalls( )
{
	int i,j,k;
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			if(adj[i][j] == 0)
			{
				D[i][j] = infinity;
				Pred[i][j] = -1;
			}
			else
			{
				D[i][j] = adj[i][j];
				Pred[i][j] = i;
			}	
		}
	
	printf("Weighted Adjacency Matrix is :\n");
	display(adj,n);
	printf("\n");
	printf("Matrix D-1 is :\n");
	display(D,n);
	printf("\n");
	printf("Matrix P-1 is :\n");
	display(Pred,n);
	printf("\n");

	for(k=0; k<n; k++)
	{
		for(i=0; i<n; i++)
		  for(j=0; j<n; j++)
		  {
			  printf("Find D%d[%d][%d]\n",k,i,j);
			  if( D[i][k] + D[k][j] < D[i][j] )
			  {
				  printf("D%d[%d][%d] + D%d[%d][%d] < D%d[%d][%d]\n",k-1,i,k,k-1,k,j,k-1,i,j);
				  printf("(%d + %d < %d )\n",D[i][k], D[k][j], D[i][j] );
				  D[i][j] = D[i][k] + D[k][j];
				  Pred[i][j] = Pred[k][j];
				  printf("D%d[%d][%d] = D%d[%d][%d] + D%d[%d][%d] = %d\n",k,i,j,k-1,i,k,k-1,k,j,D[i][k] + D[k][j] );
				  printf("Pred%d[%d][%d] = Pred%d[%d][%d] = %d\n\n",k,i,j,k-1,k,j,Pred[k][j] );
				  STOP;
			  }
			  else if ( D[i][k] + D[k][j] > D[i][j] )
			  {
				  printf("D%d[%d][%d] + D%d[%d][%d] > D%d[%d][%d]\t",k-1,i,k,k-1,k,j,k-1,i,j);
				  printf("=>  No change\n");
				  printf("(%d + %d > %d) \n\n",D[i][k], D[k][j], D[i][j] );
				  STOP;
			  }
			  else
			  {
				  printf("D%d[%d][%d] + D%d[%d][%d] = D%d[%d][%d]\t",k-1,i,k,k-1,k,j,k-1,i,j);
				  printf("=>  No change\n");
				  printf("(%d + %d = %d) \n\n",D[i][k], D[k][j], D[i][j] );
				  STOP;
			  }
		  }
		  printf("D%d is :\n",k);
			display(D,n);
			printf("P%d is :\n",k);
			display(Pred,n);
			STOP;
	}
	
	for(i=0;i<n;i++)
		if(D[i][i]<0)
		{		
			printf("Error :	negative cycle\n");
			exit(1);
		}
}/*End of FloydWarshalls()*/

void findPath(int s, int d)
{
	int i, path[MAX], count;
		
	if( D[s][d] == infinity )
	{
		printf("No path \n");
		return;
	}

	count = -1;
	do
	{
		path[++count] = d;
		d = Pred[s][d];
	}while(d!=s);
	
	path[++count] = s;
	
	for(i=count; i>=0; i--)
		printf("%d ",path[i]);		
	printf("\n");
}/*End of findPath()*/


void display(int matrix[MAX][MAX],int n )
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%7d",matrix[i][j]);
		printf("\n");
	}
}/*End of display( )*/

/*Graph given in book figure 7.60*/
void create_graph()
{
	n = 4;
	adj[0][1] = 2;
	adj[0][3] = 9;
	adj[1][0] = 3;
	adj[1][2] = 4;
	adj[1][3] = 7;
	adj[2][1] = 6;
	adj[2][3] = 2;
	adj[3][0] = 14;
	adj[3][2] = 4;
}				  					
 
/*
void create_graph()
{
	int i,max_edges,origin,destin, wt;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1);

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if( (origin == -1) && (destin == -1) )
			break;
		
		printf("Enter weight for this edge : ");
		scanf("%d",&wt);
		
		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[origin][destin] = wt;
	}
}
*/
