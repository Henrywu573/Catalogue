/* SEARCH A NODE INTO A SIMPLE LINKED LIST WHEN INFORMATION IS KNOWN */
/* LINK_HEA.C */

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
void search(node *);
void display(node *);


/* Function main */

void main()
{
	start = (node *) malloc(sizeof(node));
	create(start);
	printf("\n created list is as follow:");
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
void search(node *ptr)
{
	node *prev;
	int x,counter=0;
	if ( ptr == NULL)
	  {
	   printf("\n List is empty\n");
	   exit(0);
	  }
	printf("\n Enter element you want to search:->");
	scanf("%d",&x);
	while(ptr->info!=x && ptr!=NULL)
	{
	 ptr=ptr->next;
	 counter++;
	}
	if(ptr==NULL)
	  printf("element you want to search does not exist:");
	else
	{
	  if(start->info==x)
	  printf("element is present in first node");
	  else if(ptr->next==NULL)
	  printf("element is present in last node");
	  else
	  printf("element is present in node no.:->%d",counter+1);
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
