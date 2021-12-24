/* DELETE A NODE FROM A SIMPLE DOUBLY LINKED LIST */
/* DBL_D.C */

# include <stdio.h>
# include <malloc.h>

struct Dlink_list
{
	struct Dlink_list *previous;
	int info;
	struct Dlink_list *next;
};
typedef struct Dlink_list Dnode;

/* Global declaration */
int num ;
Dnode *lp=NULL,*rp=NULL;

/* Prototypes of various functions */
void Create(Dnode *);
void display (Dnode *);
void Delete (int ,Dnode *);

/* Function main */
void main()
{
	int n;
	lp = (Dnode *) malloc(sizeof(Dnode));
	Create(lp);
	printf("\n Created doubly linked list is as follows\n");
	display(lp);
	printf("\n Enter the node no. to be deleted:->");
	scanf("%d",&n);
	Delete(n,lp);
	printf("\n After deletion of a node linked list is as follows\n");
	display(lp);
	getch();
}

/* Function create */
void Create(Dnode *ptr)
{
	char ch;
	clrscr();
	num = 0;
	lp->previous = NULL;
	printf("\n Enter E for Exit any other key for continue: ");
	ch = getchar();
	if(ch=='e')
	{
	free(lp);
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
		ptr->next = (Dnode *) malloc(sizeof(Dnode));
		ptr->next->previous = ptr;
		ptr = ptr->next;
		}
		num ++;
	}while(ch=='y');
	ptr->next=NULL;
	rp=ptr;
	printf("\n Total nodes = %d", num);
}

/* Function delete */
void Delete (int node_no,Dnode *ptr)
{
	int search_counter = 1;
	Dnode *prev=NULL;

	if ( lp == NULL)  /* Check for empty list */
	  {
	   printf("\n List is empty\n");
	   exit(0);
	  }
	while(ptr!=NULL && search_counter!=node_no)  /* Locate the element */
	    {
	     prev=ptr;
	     ptr=ptr->next;
	     search_counter++;
	    }
	if(ptr==NULL)
	  {
	    printf("\n node does not exist");
	    exit(0);
	  }
	if(ptr->previous==NULL)   /*if it is first node */
	   {
	     lp=ptr->next;
	     lp->previous=NULL;
	     free(ptr);
	   }
	    else if(ptr->next==NULL)   /*if it is last node */
	      {
		rp=ptr->previous;
		rp->next=NULL;
		free(ptr);
	      }
	    else
	      {
		prev->next=ptr->next;
		ptr->next->previous=prev;
	      }
}


/* Function display */
void display (Dnode *ptr)
{
	while(ptr!=NULL)  /* Traverse up to end of the list */
	  {
		printf("\n 0x%x", ptr);
		printf(" %d", ptr->info);
		ptr = ptr->next;
	  }
}
