/*P7.7a Program for traversing a directed graph through DFS,visiting all the vertices*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define initial 1
#define visited 2 

int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*Can be initial or visited*/ 

void DF_Traversal();
void DFS(int v);
void create_graph();

int stack[MAX];
int top = -1;
void push(int v);
int pop();
int isEmpty_stack();

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
	
	push(v);
	while(!isEmpty_stack())
	{
		v = pop();
		if(state[v]==initial)
		{
            printf("%d ",v);
            state[v] = visited;
		}
		for(i=n-1; i>=0; i--)
			if(adj[v][i]==1 && state[i]==initial)
				push(i);
	}
}/*End of DFS( )*/

void push(int v)
{
	if(top == (MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top+1;
	stack[top] = v;
}/*End of push()*/

int pop()
{
	int v;
	if(top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	else
	{
		v = stack[top];
		top = top-1;
		return v;
	}
}/*End of pop()*/

int isEmpty_stack( )
{
  if( top == -1)
	  return 1;
  else 
	  return 0;
}/*End if isEmpty_stack()*/

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

		if((origin == -1) && (destin == -1))
			break;

		if(origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
		}
	}
}/*End of create_graph*/

/*Example graph given in book fig 7.40*/
/*
void create_graph()
{
	n = 10;
	adj[0][1] = 1;	
	adj[0][3] = 1;	
	adj[1][2] = 1;	
	adj[1][4] = 1;	
	adj[1][5] = 1;	
	adj[2][3] = 1;
	adj[2][5] = 1;
	adj[3][6] = 1;
	adj[4][7] = 1;
	adj[5][6] = 1;
	adj[5][7] = 1;
	adj[5][8] = 1;
	adj[6][9] = 1;
	adj[7][8] = 1;	
	adj[8][9] = 1;	
}
*/

/*Example graph given in book fig 7.39*/
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

