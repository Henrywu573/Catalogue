/* SEARCH A NODE INTO A LINKED LIST WITH HEADER NODE WHEN INFORMATION IS KNOWN */
/* LINK_RD.C */

# include <stdio.h>
# include <malloc.h>

struct link_list
{
	int info;
	struct link_list *next;
};
typedef struct link_list node;
int i;
int number;
node *start, *new1;

void create(node *);
void display (node *);
void search(node *);
/* Function main */

void main()
{
	start = (node *) malloc(sizeof(node));

	create (start);
	printf("\n created list is as follows:\n");
	display (start);
	search (start);
	getch();
}
/* function create */
void create(node *ptr)
{
	char ch;
	clrscr();
	start->info = 0;
	printf("\n Enter E for Exit any other key for continue: ");
	ch = getchar();
	if(ch=='e')
	{
	free(ptr);
	exit(0);
	}
	ptr->next = (node *) malloc(sizeof(node));
	ptr=ptr->next;
	do
	{

		printf("\n Input the values of the node : %d: ", (start->info+1));
		scanf("%d", &ptr->info);
		fflush(stdin);
		printf("\n want to continue(y/n)->: ");
		ch = getchar();
		if(ch=='y')
		{
		ptr->next = (node *) malloc(sizeof(node));
		ptr = ptr->next;
		}
		start->info ++;
	}while(ch=='y');
	ptr->next=NULL;
	printf("\n Total nodes = %d", start->info);
}

/* function display */
void display(node *ptr)
{
	ptr=ptr->next;
	while (ptr!=NULL)
	{
		printf(" %d",  ptr->info);
		ptr = ptr->next;
	}
}

/* Searching a value */
void search(node *ptr)
{
	int node_number = 1;
	int search_node;
	printf("\n Enter information of a node you want to search:");
	scanf("%d", &search_node);
	if (start == NULL)
		printf("\n List is empty");

	/*  By pass header node*/
	ptr = ptr->next;
	while(ptr!=NULL && search_node != ptr->info)
	{
	ptr=ptr->next;
	node_number++;
	}
	if(ptr==NULL)
	{
	printf("\n Search is unsuccessful");
	printf("\n Information does not found in the list:");
	}
	else
	{
	 printf("\n Search is successful");
	 printf("\n Information to which we want search is: %d", search_node);
	 printf("\n Position from beginning of the list: %d", node_number);
	}
}

