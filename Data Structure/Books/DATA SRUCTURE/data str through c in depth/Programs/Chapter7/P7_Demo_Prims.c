
/* P7.12 Program for creating minimum spanning tree using Prim's algorithm */

#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1

#define STOP getchar()

struct edge
{
	int u;
	int v;
};

int n;	
int adj[MAX][MAX];

int predecessor[MAX];
int status[MAX];
int length[MAX];

void create_graph();
void maketree(int r, struct edge tree[MAX]);
int min_temp();
void displayTable();

main()
{
	int wt_tree = 0; 
	int i, root;
	struct edge tree[MAX];

	create_graph();
	
	printf("Enter root vertex : ");
	scanf("%d",&root);

	maketree(root, tree);
	
	printf("Edges to be included in spanning tree are : \n");
	
	for(i=1; i<=n-1; i++)
	{
		printf("%d->",tree[i].u);
		printf("%d\n",tree[i].v);
		wt_tree += adj[tree[i].u][tree[i].v];
	}
	printf("Weight of spanning tree is : %d\n", wt_tree);
}/*End of main()*/

void maketree(int r, struct edge tree[MAX])
{	
	int current,i;
	int count = 0;/*number of vertices in the tree*/
	
	/*Initialize all vertices*/
	for(i=0; i<n; i++)
	{
		predecessor[i] = NIL;
		length[i] = infinity;
		status[i] = TEMP;
	}

	/*Make length of root vertex 0*/
	length[r] = 0;

	while(1)
	{
		/*Search for temporary vertex with minimum length
		and  make it current vertex*/

		current = min_temp();
		printf("current = %d\n",current);	

		if(current == NIL) 
		{
			if( count == n-1 ) /*No temporary vertex left*/
				return;
			else /*Temporary vertices left with length infinity*/	 		
			{
				printf("Graph is not connected, No spanning tree possible\n");
				exit(1);
			}
		}
		
		/*Make the current vertex permanent*/
        status[current] = PERM;

		/*Insert the edge ( predecessor[current], current) into the tree,
		except when the current vertex is root*/ 
		if( current != r)
		{
           count++;
		   tree[count].u = predecessor[current];
		   tree[count].v = current;
		}

		for(i=0;i<n;i++)
			if ( adj[current][i] > 0 && status[i] == TEMP )
			{
				printf("Vertex %d is temporary, and is adjacent to current vertex %d\n", i, current);
				if(  adj[current][i] < length[i] )
				{
					printf("weight(%d,%d) < length(%d)            ",current,i,i);
					printf("%d < %d\n", adj[current][i] , length[i]);
					printf("Relabel Vertex %d\n",i);
					predecessor[i] = current;
					length[i] = adj[current][i];
					printf("predecessor[%d] = %d, ",i,current);
					printf("length[%d] = %d\n\n",i,adj[current][i]);    
				}
				else
				{
					if( adj[current][i] == length[i])
					{
						printf("weight(%d,%d) = length(%d)\n",current,i,i);
						printf("%d = %d\t", adj[current][i] , length[i]);
					}
					else
					{
						printf("weight(%d,%d) > length(%d)\n",current,i,i);
						printf("%d > %d\t", adj[current][i] , length[i]);
					}
					printf("Don't Relabel vertex %d\n\n",i);
				}
				STOP;
			}	
		displayTable();
		STOP;
	}
}/*End of make_tree( )*/

/*Returns the temporary vertex with minimum value of length
  Returns NIL if no temporary vertex left or 
  all temporary vertices left have pathLength infinity*/
int min_temp()
{
	int i;
	int min = infinity;
	int k = -1;
	
	for(i=0; i<n; i++)
	{
		if(status[i] == TEMP && length[i] < min)
		{
			min = length[i];
			k = i;
		}
	}

	return k;
}/*End of min_temp()*/


void displayTable()
{
	int i;
	printf("\nVertex  length      Predecessor       status\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t%d\t\t", i, length[i]);
		if( predecessor[i] == NIL )
			printf("NIL\t\t");
		else
			printf("%d\t\t", predecessor[i]);
		if(status[i] == 0)
			printf("Temp\n");
		else
			printf("Perm\n");
	}
	printf("\n\n");
}/*End of displayTable()*/


/*Example graph given in book figure 7.62*/
void create_graph()
{
	n = 6;
	adj[0][1] = 6;	adj[1][0] = 6;
	adj[0][2] = 2;	adj[2][0] = 2;
	adj[0][3] = 3;	adj[3][0] = 3;
	adj[0][4] = 10;	adj[4][0] = 10;
	adj[1][3] = 11;	adj[3][1] = 11;
	adj[1][5] = 9;	adj[5][1] = 9;
	adj[2][3] = 14;	adj[3][2] = 14;
	adj[2][4] = 8;	adj[4][2] = 8;
	adj[3][4] = 7;	adj[4][3] = 7;
	adj[3][5] = 5;	adj[5][3] = 5;
	adj[4][5] = 4;	adj[5][4] = 4;
}


/*Example graph given in book figure 7.63*/
/*
void create_graph()
{
	n = 8;
	adj[0][1] = 6;	adj[1][0] = 6;
	adj[0][2] = 3;	adj[2][0] = 3;
	adj[0][3] = 8;	adj[3][0] = 8;
	adj[1][4] = 9;	adj[4][1] = 9;
	adj[2][3] = 7;	adj[3][2] = 7;
	adj[2][4] = 5;	adj[4][2] = 5;
	adj[3][4] = 4;	adj[4][3] = 4;
	adj[5][6] = 2; 	adj[6][5] = 2;
	adj[5][7] = 8;	adj[7][5] = 8;
	adj[6][7] = 5;	adj[7][6] = 5;
}
*/

/*Example graph given in book figure 7.65*/
/*
void create_graph()
{
	n = 9 ;	
	adj[0][1]=9;	adj[1][0]=9;
	adj[0][3]=4;	adj[3][0]=4;
	adj[0][4]=2;	adj[4][0]=2;
	adj[1][2]=10;	adj[2][1]=10;	
	adj[1][4]=8;	adj[4][1]=8;
	adj[2][4]=7;	adj[4][2]=7;
	adj[2][5]=5;	adj[5][2]=5;
	adj[3][4]=3;	adj[4][3]=3;
	adj[3][6]=18;	adj[6][3]=18;
	adj[4][5]=6;	adj[5][4]=6;
	adj[4][6]=11;	adj[6][4]=11;
	adj[4][7]=12;	adj[7][4]=12;
	adj[4][8]=15;	adj[8][4]=15;
	adj[5][8]=16;	adj[8][5]=16;
	adj[6][7]=14;	adj[7][6]=14;
	adj[7][8]=20;	adj[8][7]=20;
}
*/


/*
void create_graph()
{
	int i,max_edges,origin,destin,wt;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges = n*(n-1)/2; 
	
	for(i=1; i<=max_edges; i++)
	{
		printf("Enter edge %d(-1 -1 to quit) : ",i);
		scanf("%d %d",&origin,&destin);
		if((origin == -1) && (destin == -1))
			break;
		printf("Enter weight for this edge : ");
		scanf("%d",&wt);
		if( origin >= n || destin >= n || origin < 0 || destin < 0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = wt;
			adj[destin][origin] = wt;
		}
	}
}
*/