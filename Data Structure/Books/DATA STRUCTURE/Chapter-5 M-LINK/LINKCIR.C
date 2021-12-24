/* INSERT A NODE INTO A SIMPLE LINKED LIST */
/* LINK_CIR.C */
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
void insert(node *);

/* Function main */
void main()
{
	start = (node *) malloc(sizeof(node));

	create (start);
	printf("\n created list is as follows:\n");
	display (start);
	insert(start);
	printf("\n list after insertion is as follows:\n");
	display(start);
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


/* Inserting a node */
void insert (node *ptr)
{
	node *new1;
	int i,node_no;
	new1 = (node *) malloc(sizeof(node));
	printf("\n Enter node number you want to insert:");
	printf("\n Value should be less are equalto the");
	printf("\n Enter node no.:-> ");
	scanf("%d", &node_no);
	printf("\n Enter element you want to insert :");
	scanf("%d", &new1->info);
	ptr=ptr->next;
	if(node_no==1)
	{
	new1->next=start->next;
	start->next=new1;
	}
	else if(node_no==start->info)
	{
	while(ptr->next!=NULL)
	 ptr=ptr->next;

	 ptr->next=new1;
	 new1->next=start;
	}
	else
	{
	for(i=1;i<node_no-1;i++)
	ptr=ptr->next;

	new1->next=ptr->next;
	ptr->next=new1;
	}
}

