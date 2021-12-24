/*E47, E48, E49, E50, E51*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};
struct node *create_list(struct node *start);
void display(struct node *ptr);
int Identical(struct node *start1, struct node *start2);
struct node *Copy(struct node *start1);
struct node *del(struct node *start, int item);
struct node *InsertSorted(struct node *p, int item);
void displayAlternate(struct node *ptr);

main()
{
	struct node *start1=NULL,*start2=NULL, *start3=NULL;	
	struct node *start4=NULL, *start5=NULL;
	int item;

	printf("Enter a List : \n");
	start1=create_list(start1);
	printf("\nList 1 is :\n");
	display(start1);
	printf("\nAlternate nodes of List 1 :\n");
	displayAlternate(start1);

	start2 = Copy(start1);
	printf("\nCopy of List 1 is :\n");
	display(start2);

	printf("\nEnter a number to be deleted from List 1 : "); 
	scanf("%d",&item);
	start1  = del(start1, item);
	display(start1);

	printf("\nEnter two lists for comparison\n");
	printf("Enter List A : \n");
	start3=create_list(start3);
	printf("Enter List B : \n");
	start4=create_list(start4);
	
	if(Identical(start3,start4))
		printf("\nLists are same\n");
	else
		printf("\nLists are different\n");

	printf("\nEnter a list in sorted order : \n");
	start5 = create_list(start5);
	printf("\nEnter a number to be inserted in this sorted list : \n");
	scanf("%d",&item);
	start5 = InsertSorted(start5, item);
	display(start5);

}/*End of main()*/

void displayAlternate(struct node *ptr)
{
	if(ptr==NULL)
		return;
	printf("%d  ",ptr->info);
	if(ptr->link!=NULL)
        displayAlternate(ptr->link->link);
}

struct node *Copy(struct node *start)
{
	struct node *tmp;
	if(start == NULL )
		return NULL;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = start->info;
	tmp->link = Copy(start->link);
	return tmp;
}/*End of Copy()*/

int Identical(struct node *p1, struct node *p2)
{
	if( (p1==NULL) && (p2==NULL) )  
		return 1;
	if( (p1==NULL) || (p2==NULL) )
		return 0;
	if( p1->info != p2->info )
		return 0;
	return Identical( p1->link, p2->link );
}/*End of Identical()*/

struct node *del(struct node *p, int item)
{
	struct node *tmp;
	if(p==NULL)
		return NULL;
	if(p->info == item)
	{
		tmp = p->link;
		free(p);
		return tmp;
	}
	p->link = del(p->link, item);
	return p;
}

struct node *InsertSorted(struct node *p, int item)
{
	struct node *tmp;
	if( p==NULL || item < p->info )
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->info = item;
		tmp->link = p;
		return tmp;
	}
	p->link = InsertSorted(p->link, item);
	return p;
}

struct node *create_list(struct node *start)
{
	int i,n,value;
	struct node *q,*tmp;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	for(i=1;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&value);

		tmp= malloc(sizeof(struct node));
		tmp->info=value;
		tmp->link=NULL;

		if(start==NULL) /*If list is empty */
			start=tmp;
		else
		{       /*Element inserted at the end */
			q=start;
			while(q->link!=NULL)
				q=q->link;
			q->link=tmp;
		}
	}
	return start;
}/*End of create_list()*/

void display(struct node *ptr)
{
	if(ptr==NULL)
		return;
	printf("%d ",ptr->info);
	display(ptr->link);
}/*End of display()*/
