/* CREATING CIRCULAR LINKED LIST WITH HEADER NODE */
/* CIRCLIST.C */

# include <stdio.h>
# include <malloc.h>

struct link_list
{
	int info;
	struct link_list *next;
};
typedef struct link_list node;

/* Global declaration */
int i;
int number;
node *start, *new1;

/* Prototypes of various functions */
void create(node *);
void display (node *);

/* Function main */
void main()
  {
    start = (node *) malloc(sizeof(node));
    create (start);
    printf("\n created list is as follows:\n");
    display (start);
    getch();
}

/* function create */
void create(node *ptr)
{
	char ch;
	clrscr();
	start->info = 0; /* Set header node */
	printf("\n Enter E for Exit any other key for continue: ");
	ch = getchar();
	if(ch=='e')
	 {
	  free(ptr);
	  exit(0);
	 }
	ptr->next = (node *) malloc(sizeof(node)); /* Create a new node */
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
	while (ptr!=NULL)  /* Traverse up to end of the list */
	{
		printf(" %d",  ptr->info);
		ptr = ptr->next;
	}
}

