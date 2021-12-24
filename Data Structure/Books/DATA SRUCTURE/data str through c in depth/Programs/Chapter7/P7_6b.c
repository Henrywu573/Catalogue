
/* P7.6b Program for traversing a directed graph through BFS, 
and finding shortest distance and shortest path of any vertex from
start vertex*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100  
#define infinity 9999
#define NIL -1

#define initial 1
#define waiting 2
#define visited 3

int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/
int distance[MAX];
int predecessor[MAX];

void create_graph();
void BF_Traversal();
void BFS(int v);

int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();


main()
{
	int u, v, i,count, path[MAX];

	create_graph();
	BF_Traversal();

	while(1)
	{
		printf("Enter destination vertex(-1 to quit) : ");
		scanf("%d",&v);
		if(v<-1 || v>n-1)
		{
			printf("Destination vertex does not exist\n");
			continue;
		}

		if(v == -1)
			break;
		count = 0;
		
		if(distance[v] == infinity)
		{
			printf("No path from start vertex to destination vertex\n");
			continue;
		}
		else
			printf("Shortest distance is : %d\n", distance[v]);
	
		/*Store the full path in array path*/
		while(v!=NIL)
		{
			count++;
			path[count]=v;
			u = predecessor[v];
			v = u;	
		}
			
		printf("Shortest Path is : ");
		for(i=count; i>1; i--)	
			printf("%d->",path[i]);
		printf("%d",path[i]);
		printf("\n");	
	}
}/*End of main()*/

void BF_Traversal()
{
	int v;
	
	for(v=0; v<n; v++) 
	{
		state[v] = initial;
		predecessor[v] = NIL;
		distance[v] = infinity;
	}
	printf("Enter starting vertex for Breadth First Search : ");
	scanf("%d", &v);
	BFS(v);
	printf("\n");
}/*End of BF_Traversal()*/

void BFS(int v)
{
	int i;
	
	insert_queue(v);
	
	state[v]=waiting;
	distance[v]=0;
	predecessor[v]=NIL;
	
	while( !isEmpty_queue() )
	{
		v = delete_queue( );
		printf("Vertex %d, distance %d, predecessor %d\n",v, distance[v], predecessor[v]);
		state[v] = visited;
		for(i=0; i<n; i++)
		{
			/* Check for adjacent unvisited vertices */
			if( adj[v][i] == 1 && state[i] == initial) 
			{
				insert_queue(i);
				state[i]=waiting;
				predecessor[i] = v;
				distance[i] = distance[v]+1;
			}
		}
	}
}/*End of BFS()*/

void insert_queue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)  /*If queue is initially empty */
			front=0;
		rear=rear+1;
		queue[rear] = vertex ;
	}
}/*End of insert_queue()*/

int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}/*End of isEmpty_queue()*/

int delete_queue()
{
	int del_item;
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	
	del_item = queue[front];
	front = front+1;
	return del_item;
	
}/*End of delete_queue() */

void create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1);

	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);

		if((origin == -1) && (destin == -1))
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
}/*End of create_graph()*/


/*Example graph given in book figure 7.32*/
/*
void create_graph()
{
	n = 9;
	adj[0][1] = 1;
	adj[0][3] = 1;
	adj[0][4] = 1;
	adj[1][2] = 1;
	adj[1][4] = 1;
	adj[2][5] = 1;
	adj[3][4] = 1;
	adj[3][6] = 1;
	adj[4][5] = 1;
	adj[4][7] = 1;
	adj[6][4] = 1;
	adj[6][7] = 1;
	adj[7][5] = 1;
	adj[7][8] = 1;
}
*/

