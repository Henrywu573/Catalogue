/* P7.8d Program to find whether a directed graph is cyclic or not */

#include<stdio.h>
#include<stdlib.h>

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
		
	DFS(0);/*start DFS from vertex 0*/
	
	for(v=0; v<n; v++)
	{
		if(state[v]==initial)
			DFS(v);
	}
	printf("Graph is Acyclic\n");
}/*End of DF_Traversal( )*/

void DFS(int v)
{
	int i;
	state[v] = visited;

	for(i=0; i<n; i++)
	{
		if(adj[v][i]==1)
		{
			if(state[i]==initial)
				DFS(i);
			else if(state[i]==visited)
			{
				printf("Back edge  (%d,%d) found\n", v, i);
				printf("Graph is cyclic\n");
				exit(1);
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

/*Example of an acyclic graph*/
/*
void create_graph()
{
	n=4;
	adj[0][1] = 1;
	adj[1][2] = 1;
	adj[2][3] = 1;
	adj[1][3] = 1;
}
*/

/*Example of a cyclic graph*/
/*
void create_graph()
{
	n=4;
	adj[0][1] = 1;
	adj[1][2] = 1;
	adj[2][3] = 1;
	adj[3][1] = 1;
}
*/
