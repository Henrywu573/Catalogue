/* Doubly linked list */
/* This program segment creates a doubly linked list then prints in forward and backword */
/* Double_l.c */

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

/* Prototype declaration */
void Doubly_Link_Create(Dnode *);
void display (Dnode *);

/* Function main */
void main()
{
	lp = (Dnode *) malloc(sizeof(Dnode));
	Doubly_Link_Create(lp);
	printf("\n Created doubly linked list is as follows\n");
	display(lp);
	getch();
}

/* Function creates a doubly linked list */
void Doubly_Link_Create(Dnode *ptr)
{
	char ch;
	clrscr();
	num = 0;
	lp->previous = NULL;
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
		ptr->next = (Dnode *) malloc(sizeof(Dnode));
		ptr->next->previous = ptr;
		ptr = ptr->next;
		}
		num ++;
	}while(ch=='y');
	ptr->next=NULL;
	printf("\n Total nodes = %d", num);
	rp=ptr;
}

/* Display the list */
void display (Dnode *ptr)
{
	while(ptr!=NULL)
	  {
		printf("\n 0x%x", ptr);
		printf(" %d", ptr->info);
		ptr = ptr->next;
	  }
	ptr=rp;
	while(ptr!=NULL)
	  {
		printf("\n 0x%x", ptr);
		printf(" %d", ptr->info);
		ptr = ptr->previous;
	  }
}

