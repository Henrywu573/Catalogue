/* INSERT A NODE INTO A SIMPLE LINKED LIST INFORMATION IS KNOWN
   AND PUT AFTER SOME SPECIFIED NODE */
/* LINK_INI.C */

# include <stdio.h>
# include <malloc.h>

struct link
{
	int info;
	struct link *next;
};

int i;
int number;
struct link start, *previous, *new1;

void insertion(struct link *);
void create_list(struct link *);
void display(struct link *);

/* Function create a linked list */

void create_list(struct link *node)
{
	char ch;
	start.next = NULL;  /* Empty list */

	node = &start;      /* Point to the start of the list */
	i = 0;
	printf("\n Input choice n for break: ");
	ch = getchar();
	while(ch != 'n')
	{
		node->next = (struct link* ) malloc(sizeof(struct link));
		node = node->next;
		printf("\n Input the node: %d: ", i+1);
		scanf("%d", &node->info);
		node->next = NULL;
		fflush(stdin);
		printf("\n Input choice n for break: ");
		ch = getchar();
		i++;
	}
	printf("\n Total nodes = %d", i);
}

/* Inserting a node */
void insertion(struct link *node)
{
	int node_number = 0;
	int insert_node;

	node = start.next;
	previous = &start;

	printf("\n Input value node the node you want to insert:");
	scanf("%d", &insert_node);

	while(node)
	{
		if(node->info < insert_node)
		{
			new1 = (struct link* ) malloc(sizeof(struct link));
			new1->next = node;
			previous->next = new1;
			new1->info = insert_node;
			break ;
		}
		else
		{
			node = node->next;
			previous= previous->next;
		}
		node_number ++;
	}
}

/* Display the list */

void display(struct link *node)
{
	node = start.next;

	while (node)
	{ 
		printf("\n 0x%x", node);
		printf(" %d", node->info);
		node = node->next;
	}
}

void main()
{
	struct link *node = (struct link *) malloc(sizeof(struct link));
	create_list(node);

	printf("\n Created list is as follows:\n");
	display(node);

	insertion(node);

	printf("\n After Inserting a node list is as follows:\n");
	display(node);
}
