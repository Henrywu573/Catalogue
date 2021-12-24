/* P7.6e Program to find whether an undirected graph is connected or not */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100  

#define initial 1
#define waiting 2
#define visited 3

int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/
int state[MAX]; /*can be initial, waiting or visited*/

void create_graph();
void BF_Traversal();
void BFS(int v);

int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

main()
{
	create_graph();
	BF_Traversal();
}/*End of main()*/

void BF_Traversal()
{
	int v;
	int connected = 1;

	for(v=0; v<n; v++) 
		state[v] = initial;
	
	BFS(0); /*start BFS from vertex 0*/
	
	for(v=0; v<n; v++)
	{
		if(state[v] == initial)
		{
			connected = 0;
			break;
		}
	}
	
	if(connected)
        printf("Graph is connected\n");
	else
        printf("Graph is not connected\n");
}/*End of BF_Traversal()*/

void BFS(int v)
{
	int i;
	
	insert_queue(v);
	state[v] = waiting;
	
	while( !isEmpty_queue() )
	{
		v = delete_queue( );
		state[v] = visited;
		printf("%d ",v);
		
		for(i=0; i<=n-1; i++)
		{
			/* Check for adjacent unvisited vertices */
			if( adj[v][i] == 1 && state[i] == initial) 
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}/*End of BFS()*/

void insert_queue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)  /*If queue is initially empty */
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}/*End of insert_queue()*/

int isEmpty_queue()
{
	if(front == -1 || front > rear )
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
	max_edges = n*(n-1)/2;

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
			adj[destin][origin] = 1;
		}
	}/*End of for*/
}/*End of create_graph()*/

/*Example graph given in book fig 7.37*/
/*
void create_graph()
{
	n = 15;
	adj[0][1] = 1; adj[1][0] = 1; 
	adj[0][3] = 1; adj[3][0] = 1; 
	adj[1][2] = 1; adj[2][1] = 1; 
	adj[2][3] = 1; adj[3][2] = 1; 
	adj[4][5] = 1; adj[5][4] = 1; 
	adj[4][7] = 1; adj[7][4] = 1; 
	adj[4][8] = 1; adj[8][4] = 1; 
	adj[5][6] = 1; adj[6][5] = 1; 
	adj[5][8] = 1; adj[8][5] = 1; 
	adj[6][9] = 1; adj[9][6] = 1; 
	adj[7][8] = 1; adj[8][7] = 1; 
	adj[8][9] = 1; adj[9][8] = 1; 
	adj[10][11] = 1; adj[11][10] = 1; 
	adj[10][13] = 1; adj[13][10] = 1; 
	adj[10][14] = 1; adj[14][10] = 1; 
	adj[11][12] = 1; adj[12][11] = 1; 
	adj[12][13] = 1; adj[13][12] = 1; 
	adj[13][14] = 1; adj[14][13] = 1; 
}
*/

