/* P7.13 Demo Program for creating a minimum spanning tree by Kruskal's algorithm */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define NIL -1

#define STOP getchar()

struct edge
{
	int u;
	int v;
	int weight;
	struct edge *link;
}*front = NULL;

void make_tree(struct edge tree[]);
void insert_pque(int i,int j,int wt);
struct edge *del_pque();
int isEmpty_pque( );
void create_graph();

int n;   /*Total number of vertices in the graph */

main()
{
	int i;
	struct edge tree[MAX]; /* Will contain the edges of spanning tree */
	int wt_tree = 0; /* Weight of the spanning tree */

	create_graph();
	
	make_tree(tree);

	printf("Edges to be included in minimum spanning tree are :\n");
	for(i=1; i<=n-1; i++)
	{
		printf("%d->",tree[i].u);
		printf("%d\n",tree[i].v);
		wt_tree += tree[i].weight;
	}
	printf("Weight of this minimum spanning tree is : %d\n", wt_tree);
}/*End of main()*/

void make_tree(struct edge tree[])
{
	struct edge *tmp;
	int v1,v2,root_v1,root_v2;
	int father[MAX]; /*Holds father of each vertex */
	int i,count = 0;    /* Denotes number of edges included in the tree */
	
	for(i=0; i<n; i++)
		father[i] = NIL;
		
	/*Loop till queue becomes empty or 
	till n-1 edges have been inserted in the tree*/
	while( !isEmpty_pque( ) && count < n-1 ) 
	{
		tmp = del_pque();
		printf("Edge (%d,%d),wt=%d\n",tmp->u,tmp->v,tmp->weight);
		v1 = tmp->u;
		v2 = tmp->v;
		
		printf("v1 = %d, v2 = %d\n",v1,v2);
		while(v1!=NIL)
		{
			root_v1 = v1;
			v1 = father[v1];
		}
		while(v2!=NIL)
		{
			root_v2 = v2;
			v2 = father[v2];
		}
		printf("root_v1 = %d, root_v2 = %d\n",root_v1,root_v2);
		if( root_v1 != root_v2 )/*Insert the edge (v1, v2)*/
		{
		    count++;
			tree[count].u = tmp->u;
			tree[count].v = tmp->v;
			tree[count].weight = tmp->weight;
			father[root_v2] = root_v1;
            printf("Edge inserted\n");
			printf("father[%d]=%d\n\n",root_v2,root_v1);
		}
		else
			printf("Edge not inserted\n\n");
		STOP;
	}

	if(count < n-1)
	{
		printf("Graph is not connected, no spanning tree possible\n");
		exit(1);
	}
	
}/*End of make_tree()*/

/*Inserting edges in the linked priority queue */
void insert_pque(int i,int j,int wt)
{
	struct edge *tmp,*q;

	tmp = (struct edge *)malloc(sizeof(struct edge));
	tmp->u = i;
	tmp->v = j;
	tmp->weight  =  wt;

	/*Queue is empty or edge to be added has weight less than first edge*/
	if( front == NULL || tmp->weight < front->weight )
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		q = front;
		while( q->link != NULL && q->link->weight <= tmp->weight )
			q = q->link;
		tmp->link  =  q->link;
		q->link = tmp;
		if(q->link == NULL)	/*Edge to be added at the end*/
			tmp->link = NULL;
	}
}/*End of insert_pque()*/

/*Deleting an edge from the linked priority queue*/
struct edge *del_pque()
{
	struct edge *tmp;
	tmp = front;
	front = front->link;
	return tmp;
}/*End of del_pque()*/

int isEmpty_pque()
{
	if(front == NULL)
		return 1;
	else
		return 0;
}/*End of isEmpty_pque()*/

/*Graph given in book figure 7.65*/

void create_graph()
{
	n = 9 ;	
	insert_pque(0,1,9);
	insert_pque(0,3,4);
	insert_pque(0,4,2);
	insert_pque(1,2,10);	
	insert_pque(1,4,8);
	insert_pque(2,4,7);
	insert_pque(2,5,5);
	insert_pque(3,4,3);
	insert_pque(3,6,18);
	insert_pque(4,5,6);
	insert_pque(4,6,11);
	insert_pque(4,7,12);
	insert_pque(4,8,15);
	insert_pque(5,8,16);
	insert_pque(6,7,14);
	insert_pque(7,8,20);
}

/*Example graph given in book figure 7.62*/
/*
void create_graph()
{
	n = 6;
	insert_pque(0,1,6);
	insert_pque(0,2,2);	
	insert_pque(0,3,3);	
	insert_pque(0,4,10);
	insert_pque(1,3,11);
	insert_pque(1,5,9);	
	insert_pque(2,3,14);
	insert_pque(2,4,8);
	insert_pque(3,4,7);
	insert_pque(3,5,5);
	insert_pque(4,5,4);
}
*/

/*Example graph given in book figure 7.63*/
/*
void create_graph()
{
	n = 8;
	insert_pque(0,1,6);	
	insert_pque(0,2,3);	
	insert_pque(0,3,8);	
	insert_pque(1,4,9);	
	insert_pque(2,3,7);	
	insert_pque(2,4,5);	
	insert_pque(3,4,4);	
	insert_pque(5,6,2); 	
	insert_pque(5,7,8);	
	insert_pque(6,7,5);	
}
*/

/*
void create_graph()
{
	int i,wt,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges=n*(n-1)/2;

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d(-1 -1 to quit): ",i);
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
			insert_pque(origin,destin,wt); 
	}
}/
*/

