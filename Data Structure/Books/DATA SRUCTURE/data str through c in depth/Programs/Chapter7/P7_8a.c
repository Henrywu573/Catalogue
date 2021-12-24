
/* P7.8a Program for traversing a directed graph through DFS recursively, 
   with comments displayed in the output */

#include<stdio.h>
#define MAX 100

#define initial 1
#define visited 2
#define finished 3 

int n;    /*Number of vertices in the graph */
int adj[MAX][MAX];
void create_graph( );

int state[MAX];

void DF_Traversal();
void DFS(int v);

main()
{
	create_graph();
	DF_Traversal();
	
}/*End of main()*/

void DF_Traversal()
{
	int v;
	
	for(v=0; v<n; v++)
		state[v] = initial;
		
	printf("Enter starting vertex for Depth First Search : ");
	scanf("%d",&v);
	DFS(v);
	for(v=0; v<n; v++)
	{
		if(state[v] == initial)
			DFS(v);
	}
	printf("\n");
}/*End of DF_Traversal( )*/

void DFS(int v)
{
	int i;
	state[v] = visited;
	printf("DFS(%d) called  \n", v);

	for(i=0; i<n; i++)
	{
		if( adj[v][i] == 1 )
		{
			if(state[i] == initial )
			{
				printf("-- %d is adjacent to %d and initial\n", i, v);
				DFS(i);
			}
		}
	}
	state[v] = finished;
	printf("Vertex %d finished\n", v);
	
}/*End of DFS()*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if( (origin == -1) && (destin == -1) )
			break;

		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
		}
	}
}

/*Example graph given in book fig 7.42*/
/*
void create_graph()
{
	n = 9;
	adj[0][1] = 1;
	adj[0][3] = 1;
	adj[1][2] = 1;
	adj[1][4] = 1;
	adj[3][4] = 1;
	adj[3][6] = 1;
	adj[4][2] = 1;
	adj[4][5] = 1;
	adj[4][7] = 1;
	adj[6][7] = 1;
	adj[7][5] = 1;
	adj[7][8] = 1;
}
*/
/*Example graph given in book fig 7.40*/
/*
void create_graph()
{
	n=10;
	adj[0][1]=1;
	adj[0][3]=1;
	adj[1][2]=1;
	adj[1][4]=1;
	adj[1][5]=1;
	adj[2][3]=1;
	adj[2][5]=1;
	adj[3][6]=1;
	adj[4][7]=1;
	adj[5][6]=1;
	adj[5][7]=1;
	adj[5][8]=1;
	adj[6][9]=1;
	adj[7][8]=1;
	adj[8][9]=1;
}
*/
