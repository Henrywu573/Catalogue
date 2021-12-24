/*  INSERT A NODE INTO A SIMPLE LINKED LIST AT THE END OF THE LIST */
/* LINK_IL.C */


# include <stdio.h>
# include <malloc.h>

struct link_list
{
	int info;
	struct link_list *next;
};
typedef struct link_list node;

void insert(node *);
void create(node *);
void display(node *);

int num;
node *start=NULL;


/* Function main */

void main()
{
	start = (node *) malloc(sizeof(node));
	create(start);
	display(start);
	insert(start);
	display(start);
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

/* Inserting a node */
void insert (node *ptr)
{
	int x;
	node *new1;
	new1 = (node *) malloc(sizeof(node));
	printf("\n Enter element you want to insert :");
	scanf("%d", &new1->info);
	if ( start == NULL)  /* check for empty list */
	  {
	   new1->next=NULL;
	   start=new1;
	  }
	else
	  {
	    while(ptr->next!=NULL)
	    ptr=ptr->next;

	    new1->next=NULL;
	    ptr->next=new1;
	  }
}
