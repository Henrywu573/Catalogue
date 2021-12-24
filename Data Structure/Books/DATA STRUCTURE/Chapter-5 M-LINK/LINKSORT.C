/* SORTING A LINKED LIST IN ASCENDING ORDER */
/* LINKSORT.C */
#include <stdio.h>
#include <malloc.h>

struct  link_list
{
	int data;
	struct link_list *next;
};
typedef struct  link_list node;
node *start;
int num;

void  create(node *);
void  sort(node *);
void  display(node *);
/* Function main */
void main()
{
	/* Assign memory to single(struct) type variables */
	start = (node *) malloc(sizeof(node));
	create(start);
	printf("\n created list is as follows:\n");
	display(start);
	sort(start);
	printf("\n sorted is as follows:\n");
	display(start);
	getch();
}

/* function create */
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
		scanf("%d", &ptr->data);
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
		printf(" %d",  ptr->data);
		ptr = ptr->next;
	}
}

  /* SORTING THE LINK LIST START FROM HERE */
void sort(node *ptr)
     {
      node *counter;
      for(; ptr->next != NULL; ptr = ptr->next)
	   {
	     for(counter = ptr->next; counter != NULL; counter = counter->next)
	       {
		 if(ptr->data > counter->data)
		   {
		     int temp = ptr->data;
		     ptr->data = counter->data;
		     counter->data = temp;
		    }
		 }
	      }
     }



