/* P7.8c Program for traversing a directed graph through DFS and classifying all edges*/

#include<stdio.h>
#define MAX 50

#define initial 1
#define visited 2
#define finished 3 

int n;    /*Number of vertices in the graph */
int adj[MAX][MAX];
void create_graph( );

int state[MAX];
int time;
int d[MAX];
int f[MAX];

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
	time++;
	d[v] = time; 
	state[v] = visited;
	
	for(i=0; i<n; i++)
	{
		if(adj[v][i] == 1)
		{
			if(state[i] == initial)
			{
				printf("(%d,%d) - Tree edge\n", v, i);
				DFS(i);
			}
			else if(state[i] == visited)
			{
				printf("(%d,%d) - Back edge\n", v, i);
			}
			else if(d[v] < d[i])
			{
				printf("(%d,%d) - Forward edge\n", v, i);
			}
			else
				printf("(%d,%d) - Cross edge\n", v, i);
		}
	}
	state[v] = finished;
	f[v] = ++time;
}/*End of DFS()*/

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges=n*(n-1);

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

/*Example graph given in book fig 7.43*/
/*
void create_graph()
{
	n = 16;
	adj[0][1] = 1;
	adj[0][2] = 1;
	adj[0][3] = 1;
	adj[1][2] = 1;
	adj[3][2] = 1;
	adj[4][1] = 1;
	adj[4][5] = 1;
	adj[4][6] = 1;
	adj[4][7] = 1;
	adj[5][6] = 1;
	adj[6][3] = 1;
	adj[6][9] = 1;
	adj[7][8] = 1;
	adj[8][4] = 1;
	adj[8][5] = 1;
	adj[8][9] = 1;
	adj[9][5] = 1;
	adj[10][11] = 1;
	adj[10][14] = 1;
	adj[11][8] = 1;
	adj[11][12] = 1;
	adj[11][14] = 1;
	adj[11][15] = 1;
	adj[12][15] = 1;
	adj[13][10] = 1;
	adj[14][13] = 1;
	adj[14][15] = 1;
}	
*/
