/*E11*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};

struct node *create_list(struct node *start );
void display(struct node *start);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *insertion_l(struct node *start);

main()
{
	struct node *start=NULL;	
	start=create_list(start);
	start=insertion_l(start);
	display(start);
}/*End of main()*/

struct node *create_list(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	for(i=1;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		if(start==NULL)
			start=addatbeg(start,data);
		else
			start=addatend(start,data);	
	}
	return start;
}/*End of create_list()*/

struct node *insertion_l(struct node *start)
{
	struct node *p1,*p2,*q;
	struct node *last; /*last points to last node of sorted part*/ 
	if(start==NULL)
		return NULL;
	last = start;  /*Initially only first node is in the sorted part*/
    while(last->link!=NULL) 
	{
			q=last->link; /*q points to the node that is to be inserted*/
			if( q->info < start->info ) /*If item to be inserted is less than first element of list then insert it at the begining and change start*/
			{
				last->link = q->link;
				q->link = start;
				start = q;
			}
			else   /*start searching from the beginning of the list*/
			{ 
				p1=start;
				p2=start->link;
				while( q->info > p2->info )
				{
					p1=p2;
					p2=p2->link;
				}
				if(q==p2) /*If item to be inserted is at its proper place, then make last point to it*/
					last=q;
				else /*insert the node at proper place*/
				{
					last->link = q->link;
					q->link = p2;
					p1->link = q;
				}
			}
	}
	return start;
}/*End of insertion_l( )*/

void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is : ");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n");
}/*End of display() */

struct node *addatbeg(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}/*End of addatbeg()*/

struct node *addatend(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}/*End of addatend()*/



