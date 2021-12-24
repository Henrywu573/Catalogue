/* CREATING HEADER LINKED LIST */
/* LINK_CH.C */

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
void traverse (node *);

/* Function main */

void main()
{
	start = (node *) malloc(sizeof(node));

	create (start);
	printf("\n created list is as follows:\n");
	traverse (start);
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
void traverse(node *ptr)
{
	ptr=ptr->next;
	while (ptr!=NULL)
	{
		printf(" %d",  ptr->info);
		ptr = ptr->next;
	}
}
