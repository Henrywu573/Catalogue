/* DELETING A NODE FROM A SIMPLE LINKED LIST */
/* LINK_DN.C */
# include <stdio.h>
# include <malloc.h>

struct link_list
{
	int info;
	struct link_list *next;
};
typedef struct link_list node;
int num;
node *start=NULL;

void create(node *);
void Delete(int,node *);
void display(node *);


/* Function main */

void main()
{
	int node_no;
	start = (node *) malloc(sizeof(node));
	create(start);
	printf("\n created list is as follow:");
	display(start);
	printf("\n Enter node no. you want to delete:->");
	scanf("%d",&node_no);

	Delete(node_no,start);
	printf("\n new list is as follow:");
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
void Delete(int node_no, node *ptr)
{
	node *prev;
	int counter=1;
	if ( ptr == NULL)
	  {
	   printf("\n List is empty\n");
	   exit(0);
	  }
	while(counter<node_no && ptr!=NULL)
	{
	 prev=ptr;
	 ptr=ptr->next;
	 counter++;
	}
	if(ptr==NULL)
	  printf("element you want to delete does not exist:");
	else
	{
	  if(counter==1)
	  start=start->next;
	  else if(ptr->next==NULL)
	  prev->next=NULL;
	  else
	  prev->next=ptr->next;
	  free(ptr);
	}
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
