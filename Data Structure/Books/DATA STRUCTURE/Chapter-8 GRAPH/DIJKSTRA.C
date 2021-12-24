/* DIJKSTRA METHOD */
/* DIJKSTRA.C*/

# include<stdio.h>

# define size 20
# define P 1
# define T 0
# define infinity 9999

struct Label
{
	int predecessor;
	int length;
	int flag;
};

int k, min, count;
struct Label state[size];
int visit_path[size];

int Short_Path(int a[size][size], int , int , int,
int path [size], int *);
void Input(int , int a[size][size]);
void Output(int , int a[size][size]);

/* Shortest path computing function */
int  Short_Path(int a[size][size], int n, int s, int t,
int path[size], int *dist)
{
	int i;
	int t1, t2;
	*dist = 0;

	for(i = 1; i <= n; i ++)
	{
		state[i].predecessor = 0;
		state[i].length = infinity ;
		state[i].flag = T;
	}
	/* Make source vertex permanent */
	state[s].predecessor = 0;
	state[s].length = 0;
	state[s].flag = P;

	/* Start from source vertex */

	k = s;
	do
	{
		/*  Check all the paths from kth vertex and find their distance from k vertex */
		for ( i = 1; i <= n; i++)
		{
			if ((a[k][i] > 0) && (state[i].flag == T))
			{
				if ((state[k].length + a[k][i]) < state[i].length)
				{
					state[i].predecessor = k;
					state[i].length = state[k].length + a[k][i];
				}
			}
		}
		min = infinity;
		k = 0;
		for ( i =1; i <= n; i++)
		{
			if ((state[i].flag == T) && (state[i].length < min))
			{
				min = state[i].length;
				k = i;
			}
		}
		if ( k==0)
			return (0);
		state[k].flag = P;
	} while(k != t);

	/* Store optimal path */
	k = t;
	count = 1;
	do
	{

		visit_path[count] = k;
		count ++;
		k = state[k].predecessor;
	} while(k!= 0);

	/* Reverse the vertices since algorithm stores path in reverse direction */

	count --;
	for ( i = 1; i <= count ; i++)
		path[i] = visit_path[count-i+1];

	for ( i = 1; i < count ; i ++)
	{
		t1 = path[i];
		t2 = path [i+1];
		*dist += a[t1][t2];
	}
	return (count);
}

/* Input function */
void Input(int n, int a[size][size])
{
	int i, j;
	printf("\n Input adjacency matrix \n");
	for(i =0; i < n; i++)
	{
		for(j =0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
		printf("\n");
	}
}

/* Output function */
void Output(int n, int a[size][size])
{
	int i, j;
	printf("\n Adjacency matrix \n");
	for(i =0; i < n; i++)
	{
		for(j =0; j < n; j++)
		{
			printf("  %d", a[i][j]);
		}
		printf("\n");
	}
}

/* Function main */

void main()
{
	int a[size][size];
	int path [size];
	int org, dest, dist;
	int count, i, n;

	printf("\n Input the number of vertices in the graph: ");
	scanf("%d", &n);

	Input(n,a);
	Output(n,a);

	printf("\n Input strating vertex: ");
	scanf("%d", &org);
	printf("\n Input destination: ");
	scanf("%d", &dest);
	count = Short_Path(a, n, org, dest, path, &dist);
	if (dist)
	{
		printf("\n Shortest path: %d", path[1]);
		for (i = 2; i<=count; i++);
		printf(" => %d", path[i]);
		printf("\n Minimum distance = %i", dist);
	}
	else
		printf("\n Path does not exist \n");
}
