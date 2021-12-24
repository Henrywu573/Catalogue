/* RADIX SORT */
/* RADIX.C*/

# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>

struct node
{
	int data ;
	struct node *next;
};

typedef struct node node1;

node1 *first;
node1 *pocket[100], *pocket1[100];
void create_node(node1 *, int);
void display(node1 *);
node1 *radix_sort(node1 *);
int large(node1 * );
int numdig(int );
int digit(int , int);
void update(int, node1 *);
node1 *Make_link(int, node1 *);

/* This function create nodes and take input data */

void  create_node(node1 *rec, int n)
{
	int i, j, k;
	for(i = 0 ; i< n; i++)
	{
		rec->next = (node1 *) malloc(sizeof(node1));
		printf("\n First node value: %d: ", i);
		scanf("%d", &rec->data);
		rec = rec->next;
	}
	rec->next = NULL;
}

/* Output Function */

void  display(node1 *rec)
{
	while(rec !=NULL)
	{
		printf(" %d", rec->data);
		rec= rec->next;
	}
}

/* This radix sort function */

node1 *radix_sort(node1 *rec)
{
	node1 *r, *nex;
	int poc = 0 ;
	int i, j, k;
	int larg = large(rec);
	int m = numdig(larg);

	/* These statements create pockets */

	for(k = 0 ; k < 10; k++)
	{
		pocket[k] = (node1 *)malloc(sizeof(node1));
		pocket1[k] = (node1 *)malloc(9*sizeof(node1));
	}

	/* These statements initialize pockets */

	for(j = 1; j <= m ; j++)
	{
		for(i = 0 ; i < 10 ; i++)
		{
			pocket[i] = NULL;
			pocket1[i] = NULL ;
		}

		r = rec ;
		while(r != NULL)
		{
			int dig = digit(r->data, j);
			nex = r->next ;
			update(dig,r);
			r = nex;
		}

		if(r!= NULL)
		{
			int dig = digit(r->data,j);
			update(dig,r);
		}

		while(pocket1[poc] == NULL)
			poc ++;
		rec = Make_link(poc, rec);
	}
	return(rec);
}

/* This function finds largest number in the list */

int large(node1 *rec)
{
	node1 *save ;
	int p = 0;
	save = rec ;
	while(save != NULL)
	{
		if(save ->data > p)
		{
			p = save->data;
		}
		save = save->next ;
	}

	printf("\n Largest element: %d", p);
	return(p);
}

/* This Function finds number digits in a number */

int numdig(int large)
{
	int temp = large ;
	int num = 0 ;

	while(temp != 0)
	{
		++num ;
		temp = temp/10 ;
	}

	printf("\n  Number of digits of the number %d is %d", large, num);
	return(num);
}

/* This function scarve a number into digits */

int digit(int num, int j)
{
	int dig, i, k;
	int temp = num ;

	for(i = 0 ; i < j ; i++)
	{
		dig = temp % 10 ;
		temp = temp / 10 ;
	}
	printf("  %d digit of number  %d is %d", j, num, dig);
	return(dig);
}

/* This function updates the pockets value */

void  update(int dig, node1 *r)
{
	if(pocket[dig] == NULL)
	{
		pocket[dig] = r ;
		pocket1[dig] = r ;
	}
	else
	{
		pocket[dig]->next = r ;
		pocket[dig] = r ;
	}
	r->next = NULL;
}

/* This function create links between the nodes */

node1* Make_link(int poc , node1 *rec)
{
	int i, j, k;
	node1 *pointer;
	rec = pocket1[poc];
	for(i = poc +1 ; i< 10 ; i++)
	{
		pointer = pocket[i-1];
		if(pocket[i] != NULL)
			pointer->next= pocket1[i];
		else
			pocket[i] = pointer ;
	}
	return(rec);
}

/* Main function */

void  main()
{
	node1 *start, *pointer;
	int number;

	printf("\n Input the number of elements in the list:");
	scanf("%d", &number);

	start = (node1 *)malloc(sizeof(node1));

	create_node(start, number);

	printf("\n Given list is as follows \n");
	display(start);

	start = radix_sort(start);

	printf("\n Sorted list is as follows:\n");
	display (start);
}
