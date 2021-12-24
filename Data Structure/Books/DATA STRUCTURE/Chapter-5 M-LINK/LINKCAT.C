/* CONCATENATE TWO LINKED LIST */
/* LINKCAT.C */

#include <stdio.h>
#include <malloc.h>

struct  link_list
{
	int data;
	struct link_list *next;
};
typedef struct  link_list node;
node *list1, *list2, *list3;
int num;

void  create(node *);
void  concate(node *, node *, node *);
void  display(node *);
/* Function main */
void main()
{
	/* Assign memory to single(struct) type variables */
	list1 = (node *)malloc(sizeof(node));
	list2 = (node *)malloc(sizeof(node));
	list3 = (node *)malloc(sizeof(node));

	create(list1);
	printf("\n Original list ONE is as follows:\n");
	display(list1);

	create(list2);
	printf("\n Original list TWO is as follows:\n");
	display(list2);

	concate(list1, list2, list3);
	printf("\n concatenated list is as follows:\n");
	display(list3);
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

/* function concatenate */
void concate(node *list1, node *list2, node *list3)
{

	/* Copying first list */
	while(list1!= NULL)
	{
		list3->data = list1->data;
		list1 = list1->next;
		list3->next = (node* ) malloc(sizeof(node));
		list3 = list3->next;
	}

	/* Copying second list  */
	while(list2->next!=NULL)
	{
		list3->data = list2->data;
		list2 = list2->next;
		list3->next = (node*)malloc(sizeof(node));
		list3 = list3->next;
	}
	list3->data = list2->data;
	list3->next = NULL;
}

