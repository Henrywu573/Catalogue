/*  MERGING TWO DOUBLY LINKED LISTS (ASCENDING ORDER) */
/*  DBL_MRG.C */

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
Dnode *start1=NULL,*start2=NULL,*start=NULL;
Dnode *list1=NULL,*list2=NULL,*list=NULL,*new1;

/* Prototypes of various functions */
void Create(Dnode *);
void display (Dnode *);
void Merge (Dnode *,Dnode *);

/* Function main */
void main()
{
	start1 = (Dnode *) malloc(sizeof(Dnode));
	start2 = (Dnode *) malloc(sizeof(Dnode));
	Create(start1);
	printf("\n first list is as follows\n");
	display(start);
	Create(start2);
	printf("\n second list is as follows\n");
	display(start2);

	Merge(start1,start2);
	printf("\n After inesertion of a node linked list is as follows\n");
	display(start);
	getch();
}

/* Function create */
void Create(Dnode *ptr)
{
	char ch;
	clrscr();
	num = 0;
	start->previous = NULL;
	printf("\n Enter E for Exit any other key for continue: ");
	ch = getchar();
	if(ch=='e')
	{
	free(ptr);
	exit(0);
	}
	printf("\n Enter first list: ");
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
	printf("\n Enter second list:");
}

/* Function insert */
void Merge (Dnode *list1 ,Dnode *list2)
{

	if ( start1 == NULL)  /* if list1 is empty */
	  start=start2;       /* resultant list will be list2 */
	else if(start2==NULL) /* if list2 is empty */
	  start=start1;       /* resultant list will be list1 */
	else
	  {

	    start=list = (Dnode *) malloc(sizeof(Dnode));
	    start->previous=start->next=NULL;
	    while(list1!=NULL&&list2!=NULL)
	    {
	      if(list1->info<=list2->info)
		{
		    list->info=list1->info;
		    list1=list1->next;
		 }
	       else
		 {
		     list->info=list2->info;
		     list2=list2->next;
		  }
		list->next = (Dnode *) malloc(sizeof(Dnode));
		list->next->previous=list;
		list=list->next;
	     }
	     if(list1==NULL)
	       while(list2!=NULL) /* copy the remaining element of list2 */
		 {
		   list->info=list2->info;
		   list2=list2->next;
		   list->next = (Dnode *) malloc(sizeof(Dnode));
		   list->next->previous=list;
		   list=list->next;
		 }
	     else
		while(list1!=NULL) /* copy the remaining element of list2 */
		 {
		   list->info=list1->info;
		   list1=list1->next;
		   list->next = (Dnode *) malloc(sizeof(Dnode));
		   list->next->previous=list;
		   list=list->next;
		 }
		list->previous->next=NULL;
		free(list);

	  }
}


/* Display the list */
void display (Dnode *ptr)
{
	while(ptr!=NULL)   /* Traverse up to end of the list */
	  {
		printf("\n 0x%x", ptr);
		printf(" %d", ptr->info);
		ptr = ptr->next;
	  }
}
