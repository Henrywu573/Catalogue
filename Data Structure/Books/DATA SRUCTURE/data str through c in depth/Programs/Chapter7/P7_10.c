
/* P7.10 Program to find shortest paths using Bellman-Ford algorithm */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define infinity 9999
#define NIL -1
#define TRUE 1
#define FALSE 0

int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/

int predecessor[MAX];
int pathLength[MAX];
int isPresent_in_queue[MAX];

int front,rear;
int queue[MAX];
void initialize_queue( );
void insert_queue(int u);
int delete_queue();
int isEmpty_queue();
void create_graph( );
void findPath(int s, int v);
int BellmanFord(int s);

main()
{
	int flag,s,v;
	
	create_graph();
	
	printf("Enter source vertex : ");
	scanf("%d",&s);
	
	flag = BellmanFord(s);

	if(flag == -1)
	{
		printf("Error : negative cycle in Graph\n");
		exit(1);
	}	

	while(1)
	{
		printf("Enter destination vertex(-1 to quit): ");
		scanf("%d",&v);
		if(v == -1)
			break;
		if(v < 0 || v >= n )
			printf("This vertex does not exist\n");
		else if(v == s)
			printf("Source and destination vertices are same\n");
		else if( pathLength[v] == infinity )
            printf("There is no path from source to destination vertex\n");
		else
			findPath(s,v);
	}
}/*End of main()*/
void findPath(int s, int v )
{
	int i,u;
	int path[MAX];		/*stores the shortest path*/
	int shortdist = 0;	/*length of shortest path*/ 
	int count = 0;		/*number of vertices in the shortest path*/
	
	/*Store the full path in the array path*/
	while( v != s )
	{
		count++;
		path[count] = v;
		u = predecessor[v];
		shortdist += adj[u][v];
		v = u;	
	}
	count++;
	path[count]=s;

	printf("Shortest Path is : ");
	for(i=count; i>=1; i--)	
		printf("%d  ",path[i]);
	printf("\n Shortest distance is : %d\n", shortdist);
}/*End of findPath()*/ 

int BellmanFord(int s)
{
	int k = 0,i,current;
	
	for(i=0;i<n;i++)
	{
		predecessor[i] = NIL;
		pathLength[i] = infinity;
		isPresent_in_queue[i] = FALSE;
	}
	
	initialize_queue( );
	pathLength[s] = 0; /*Make pathLength of source vertex 0*/
	insert_queue(s); /*Insert the source vertex in the queue*/
    isPresent_in_queue[s] = TRUE;
	while( !isEmpty_queue( ) )
	{
		current = delete_queue( );
		isPresent_in_queue[current] = FALSE;
		if(s == current)
			k++;
		if(k > n )
			return -1;/*Negative cycle reachable from source vertex*/
		for(i=0;i<n;i++)
		{
			if ( adj[current][i] != 0 )
				if( pathLength[i] > pathLength[current] + adj[current][i] )
				{
					pathLength[i] = pathLength[current] + adj[current][i];
					predecessor[i] = current;
					if( !isPresent_in_queue[i] )
					{
						insert_queue(i);
						isPresent_in_queue[i]=TRUE;
					}
				}
		}
	}
	return 1;
}/*End of BellmanFord()*/

void initialize_queue( )
{
	int i;
	for(i=0;i<MAX;i++)
		queue[i] = 0;
	rear = -1;front = -1;
}/*End of initailize_queue()*/

int isEmpty_queue()
{
	if(front == -1 || front>rear )
		return 1;
	else 
		return 0;
 }/*End of isEmpty_queue()*/

void insert_queue(int added_item)
{
	if (rear == MAX-1)
	{
		printf("Queue Overflow\n");
		exit(1);
	}
	else
	{
		if (front == -1)  /*If queue is initially empty */
			front = 0;
		rear = rear+1;
		queue[rear] = added_item ;
	}
}/*End of insert_queue()*/

int delete_queue()
{
	int d;
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	else
	{
		d = queue[front];
		front=front+1;
	}
	return d;
}/*End of delete_queue() */

void create_graph()
{
	int i,max_edges,origin,destin, wt;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges=n*(n-1);

	for(i=1;i<=max_edges;i++)
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

/*Graph given in book figure 7.55*/
/*
void create_graph()
{
	n = 8;

	adj[0][1] = 8;
	adj[0][2] = 9;
	adj[0][4] = 7;
	adj[1][5] = 9;
	adj[2][0] = 5;
	adj[2][1] = -4;
	adj[2][3] = 3;
	adj[3][1] = 3;
	adj[3][2] = 6;
	adj[3][5] = 4;
	adj[4][7] = 16;
	adj[5][0] = 4;
	adj[5][6] = -8;
	adj[5][7] = 5;
	adj[6][3] = 5;
	adj[6][7] = 2;
}
*/
