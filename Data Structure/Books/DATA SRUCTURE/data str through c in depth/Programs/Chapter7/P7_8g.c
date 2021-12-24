/*P7.8g Program to find whether an undirected graph is cyclic or not*/

#include<stdio.h>
#include<stdlib.h>

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
	DFS(0); /*start from vertex 0*/
	for(v=0; v<n; v++)
	{
		if(state[v] == initial)
			DFS(v);
	}
	printf("Graph is acyclic\n");
}/*End of DF_Traversal()*/

void DFS(int v)
{
	int i;
	state[v] = visited;
	for(i=0; i<n; i++)
	{
		if( adj[v][i] == 1 && predecessor[v]!=i )
		{
			if( state[i] == initial) 
			{
				predecessor[i]=v;
				DFS(i);
			}
			else if(state[i] == visited )
			{
				printf("Back edge (%d,%d) detected \n", v, i);
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
	max_edges = n*(n-1)/2;

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
			adj[destin][origin] = 1;
		}
	}/*End of for*/
}/*End of create_graph()*/

/*Example of a cyclic graph*/
/*
void create_graph()
{
	n=4;
	adj[0][1] = 1;	adj[1][0] = 1;
	adj[0][2] = 1;	adj[2][0] = 1;
	adj[1][2] = 1;	adj[2][1] = 1;
	adj[2][3] = 1;	adj[3][2] = 1;
}
*/

/*Example of an acyclic graph*/
/*
void create_graph()
{
	n=4;
	adj[0][1] = 1;	adj[1][0] = 1;
	adj[1][2] = 1;	adj[2][1] = 1;
	adj[2][3] = 1;	adj[3][2] = 1;
}
*/
