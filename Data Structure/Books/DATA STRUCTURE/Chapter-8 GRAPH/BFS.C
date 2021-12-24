/* BREADTH FIRST SEARCH TECHNIQUE */
/* BFS.C */

# include<stdio.h>
# define size 20
# define T 1
# define F 0

struct Edge
{
	int terminal;
	struct Edge *next;
};

struct Vertex
{
	int visit;
	int vertex_no;
	char info;
	int path_length;
	struct Edge *Edge_Ptr;
};
struct Q
{
	int info;
	struct Q *next;
};

void Table(int , int matrix [size][size], struct Vertex vert[size]);
struct Edge *Insert_Vertex (int , struct Edge *);
void BFS ( int , struct Vertex vert [size]);
void Input(int, int mat [size][size]);
void Output(int number, int mat [size][size]);
struct Q *Insert_Queue(int vertex_no, struct Q *first);
struct Q *Delete_Queue(int *vertex_no, struct Q *first);

/* Insert vertex into connectivity list */

struct Edge * Insert_Vertex (int vertex_no, struct Edge
*first)          {
	struct Edge *new1, *current;
	new1 = (struct Edge *) malloc(sizeof(struct Edge));
	new1->terminal = vertex_no;
	new1->next = NULL;
	if (!first)
		return (new1);
	for (current = first; current->next; current = current->next);
	current->next = new1;
	return (first);
}

/* Insert vertices into queue */

struct Q * Insert_Queue(int vertex_no, struct Q *first)
{
	struct Q *new1, *current;
	new1 =(struct Q *) malloc(sizeof(struct Q));
	new1->info = vertex_no;
	new1->next = NULL;
	if (!first)
		return (new1);
	for (current = first; current->next; current = current->next);
	current->next = new1;
	return (first);
}

struct  Q * Delete_Queue(int *vertex_no, struct Q *first)
{
	struct Q *previous;
	if (!first)
		return (NULL);
	*vertex_no = first->info;
	previous = first;
	first = first->next;
	free(previous);
	return (first);
}

/* Initializing entries */

void Table(int vertex_num, int matrix [size][size],
struct   Vertex vert[size])
{
	int i, j;
	for (i = 0; i < vertex_num; i++)
	{
		vert [i].visit = F;
		vert [i].vertex_no = i+1;
		vert [i].info = 'A'+ i;
		vert [i].path_length = 0;
		vert [i].Edge_Ptr = NULL;
	}

	for (i =0; i < vertex_num ; i++)
		for (j =0; j < vertex_num ; j++)
			if (matrix [i][j] > 0 )
				vert [i].Edge_Ptr = Insert_Vertex (j, vert [i].Edge_Ptr);
}

/* Computing path length */

void BFS ( int index, struct Vertex vert [size])
{
	struct Q  *queue = NULL;
	struct Edge *Link;
	vert [index].visit = T;
	queue = Insert_Queue(index, queue);
	while(queue)
	{
		queue = Delete_Queue(&index, queue);
		for ( Link = vert [index].Edge_Ptr; Link; Link = Link->next)
		{
			if (vert [Link->terminal].visit == F)
			{
				vert[Link->terminal].visit = T;
				vert[Link->terminal].path_length=vert[index].path_length+1;
				queue = Insert_Queue(Link->terminal, queue);
			}
		}
	}
}

/* Input function to read adjacency matrix */

void Input(int number, int mat [size][size])
{ 
	int i, j;
	printf("\n Input the adjacency matrix \n");
	for (i =0; i < number; i++)
	{
		for (j=0; j < number; j ++)
		{
			scanf("%d", &mat [i][j]);
		}
		printf("\n");
	}
}

/* Output function to display adjacency matrix */

void Output(int number, int mat [size][size])
{
	int i, j;
	printf("\n Adjacency matrix \n");
	for (i =0; i < number; i++)
	{
		for (j=0; j < number; j ++)
		{
			printf("   %d", mat [i][j]);
		}
		printf("\n");
	}
}

/* Function main */
void  main()
{
	int i, number, index;
	int mat [size][size];
	struct Vertex vert [size];
	struct Edge *List;
	printf("\n Input the number of vertices in the graph: ");
	scanf("%d", &number);
	Input(number, mat);
	Output(number, mat);
	Table(number, mat, vert);
	printf("\n Input the starting vertex 0- %d :",number-1);
	scanf("%d", &index);
	BFS (index, vert);
	printf("\n Path length of the vertex from %c", vert[index].info)
	    ;             
	printf("\n Vertex Length Vertex Connectivity \n ");
	for (i = 0; i < number; i++)
	{
		printf("\n   %c    %d   ",vert[i].info, vert[i].path_length);
		for (List= vert[i].Edge_Ptr; List; List = List->next)
		{
			printf(" ");
			putchar(List->terminal+'A');
		}
	}
}

