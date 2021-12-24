/* P7.8f Program for traversing an undirected graph through DFS
 and classifying edges as tree edges and back edges*/

#include<stdio.h>
#define MAX 100
#define NIL -1

#define initial 1
#define visited 2
#define finished 3 

int adj[MAX][MAX];
int n;    /* Denotes number of vertices in the graph */
int state[MAX];

int predecessor[MAX];
void create_graph();
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
	{
		state[v] = initial;
		predecessor[v] = NIL;
	}
	printf("Enter starting vertex for Depth First Search : ");
	scanf("%d",&v);
	DFS(v);
	for(v=0; v<n; v++)
	{
		if(state[v] == initial)
			DFS(v);
	}
}/*End of DF_Traversal()*/

void DFS(int v)
{
	int i;
	state[v] = visited;
	for(i=0; i<n; i++)
	{
		if(adj[v][i] == 1 && predecessor[v]!=i )
		{
			if(state[i] == initial) 
			{
				predecessor[i] = v;
				printf("(%d,%d) Tree edge\n", v, i);
				DFS(i);
			}
			else if(state[i] == visited)
			{
				printf("(%d,%d) Back edge\n", v, i);
			}
		}
	}
	state[v] = finished;
}/*End of DFS()*/


void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges=n*(n-1)/2;

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);
		if( (origin == -1) && (destin == -1) )
			break;
		if(origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
			adj[destin][origin] = 1;
		}
	}
}

/*Example graph given in book figure 7.45*/
/*
void create_graph()
{
	n = 15;
	adj[0][1] = 1;	adj[1][0] = 1;
	adj[0][2] = 1;	adj[2][0] = 1;
	adj[0][3] = 1;	adj[3][0] = 1;
	adj[2][3] = 1;	adj[3][2] = 1;
	adj[4][5] = 1;	adj[5][4] = 1;
	adj[4][6] = 1;	adj[6][4] = 1;
	adj[4][7] = 1;	adj[7][4] = 1;
	adj[4][8] = 1;	adj[8][4] = 1;
	adj[5][7] = 1;	adj[7][5] = 1;
	adj[6][8] = 1;	adj[8][6] = 1;
	adj[6][9] = 1;	adj[9][6] = 1;
	adj[10][11] = 1;	adj[11][10] = 1;
	adj[10][12] = 1;	adj[12][10] = 1;
	adj[10][13] = 1;	adj[13][10] = 1;
	adj[11][12] = 1;	adj[12][11] = 1;
	adj[11][13] = 1;	adj[13][11] = 1;
	adj[11][14] = 1;	adj[14][11] = 1;
	adj[13][14] = 1;	adj[14][13] = 1;
}
*/
