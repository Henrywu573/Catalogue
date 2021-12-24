/* CREATING A SIMPLE DOUBLY LINKED LIST */
/* DBLINK.C */


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

/* Function main */
void main()
{
	lp = (Dnode *) malloc(sizeof(Dnode));
	Create(lp);
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
	rp=ptr; /* Assign the adress of rightmost node to rp */
	printf("\n Total nodes = %d", num);
}

/* Functio Display  */
void display (Dnode *ptr)
{
	while(ptr!=NULL)  /* Traverse up to end of the list */
	  {
		printf("\n 0x%x", ptr);
		printf(" %d", ptr->info);
		ptr = ptr->next;
	  }
}
