/* DELETE FIRST NODE FROM A SIMPLE DOUBLY LINKED LIST */
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
void Delete (Dnode *);

/* Function main */
void main()
{
	lp = (Dnode *) malloc(sizeof(Dnode));
	Create(lp);
	printf("\n Created doubly linked list is as follows\n");
	display(lp);
	Delete(lp);
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
	rp=ptr;    /* Assign the address of rightmost node to rp pointer */
	printf("\n Total nodes = %d", num);
}


/* Function delete */
void Delete (Dnode *ptr)
{
	if ( ptr == NULL)
	  {
	   printf("\n List is empty\n");
	   exit(0);
	  }
	if(lp==rp)
	  {
		lp=rp=NULL;
		free(ptr);
	  }
	else
	  {
		lp=ptr->next;
		lp->previous=NULL;
		free(ptr);
	  }
}

/* Display the list */
void display (Dnode *ptr)
{
	while(ptr!=NULL)  /* Traverse up to end of the list */
	  {
		printf("\n 0x%x", ptr);
		printf(" %d", ptr->info);
		ptr = ptr->next;
	  }
}
