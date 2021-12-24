/* Inserting a nodes in double linked list at desired location */
/* Double_i.c */


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
void Create(Dnode *);
void display (Dnode *);
void Insert_before (int,Dnode *);
void Insert_after (int,Dnode *);

/* Function main */
void main()
{
	int x;
	lp = (Dnode *) malloc(sizeof(Dnode));
	Create(lp);
	printf("\n Created doubly linked list is as follows\n");
	display(lp);
	printf("\n Enter the element before which you want to insert :");
	scanf("%d", &x);
	Insert_before(x,lp);
	printf("\n After inesertion of a node linked list is as follows\n");
	display(lp);
	printf("\n Enter the element after which you want to insert :");
	scanf("%d", &x);
	Insert_after(x,lp);
	printf("\n After inesertion of a node linked list is as follows\n");
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
	rp=ptr;   /* Assign the address of rightmost node to rp pointer */
}

/* Function insert_before */
void Insert_before (int x,Dnode *ptr)
{
	Dnode *new1;
	new1 = (Dnode *) malloc(sizeof(Dnode));
	while(ptr->info!=x && ptr!=NULL)  /* Traverse list to locate the node */
	  ptr=ptr->next;
	if(ptr==NULL)
	  {
	   printf("\n The element before which you want to insert does not exist:");
	   exit(0);
	  }

	 if(ptr==lp)   /* insertion before first node */
	 {
	 new1->next=ptr;
	 new1->previous=NULL;
	 ptr->previous=new1;
	 lp=new1;
	 }
	 else
	 {
	 ptr->previous->next=new1;
	 new1->previous=ptr->previous;
	 new1->next=ptr;
	 ptr->previous=new1;
	 }
	 num++;
}
/* Function insert_after */
void Insert_after(int x,Dnode *ptr)
{
	Dnode *new1;
	new1 = (Dnode *) malloc(sizeof(Dnode));

	while(ptr->info!=x && ptr!=NULL)   /* Traverse list to locate the node */
	  ptr=ptr->next;
	if(ptr==NULL)
	  {
	   printf("\n The element after which you want to insert does not exist:");
	   exit(0);
	  }
	 printf("\n Enter the element you want to insert :");
	 scanf("%d", &new1->info);
	 ptr->next->previous=new1;
	 new1->next=ptr->next;
	 ptr->next=new1;
	 new1->previous=ptr;

}
/* Function Display */
void display (Dnode *ptr)
{
	while(ptr!=NULL)  /* Traverse up to end of the list */
	  {
		printf("\n 0x%x", ptr);
		printf(" %d", ptr->info);
		ptr = ptr->next;
	  }
}

