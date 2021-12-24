/* SEARCH A NODE INTO A SIMPLE LINKED LIST WITH INFORMATION IS KNOWN */
/* LINK_S.C */
# include <stdio.h>
# include <malloc.h>

struct link_list
{
	int info;
	struct link_list *next;
};
typedef struct link_list node;
int i,num;
node *start;

void search(node *);
void create(node *);
void display(node *);


/* Function main */

void main()
{
	start = (node *) malloc(sizeof(node));
	create(start);
	display(start);
	search(start);
	getch();
}
/* Function create a linked list */
void create(node *ptr)
{
	char ch;
	clrscr();
	num = 0;
	printf("\n Enter E for Exit any other key for continue: ");
	ch = getchar();
	if(ch=='e')
	{
	free(ptr);
	exit(0);
	}
	do
	{
		printf("\n Input the values of the node : %d: ", (num+1));
		scanf("%d", &ptr->info);
		fflush(stdin);
		printf("\n want to continue(y/n)->: ");
		ch = getchar();
		if(ch=='y')
		{
		ptr->next = (node *) malloc(sizeof(node));
		ptr = ptr->next;
		}
		num ++;
	}while(ch=='y');
	ptr->next=NULL;
	printf("\n Total nodes = %d", num);
}

/* function display */
void display(node *ptr)
{
	while (ptr!=NULL)
	{
		printf("\n %d",  ptr->info);
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

