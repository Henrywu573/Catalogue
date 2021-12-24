/*
E7 - Swap Adjacent elements in a double linked list
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addtoempty(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *SwapAdjacent(struct node *start);

main()
{
	struct node *start=NULL;
	start=create_list(start);
	display(start);
	start = SwapAdjacent(start);
	display(start);
}/*End of main()*/

struct node *SwapAdjacent(struct node *start)
{
	struct node *p,*q;
	if(start==NULL || start->next==NULL)/*List empty or only one element in the list*/
		return start;
	
	p=start;
	while(p->next!=NULL)
	{
		q=p->next;
		p->next=q->next;
		q->prev=p->prev;
		if(q->next!=NULL)
			q->next->prev=p;
		q->next=p;
		if(p!=start)
			p->prev->next=q;
		else
			start=q;
		p->prev=q;
		if(p->next!=NULL)
			 p=p->next;
	}
	return start;
}

struct node *create_list(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=addtoempty(start,data);
		
	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=addatend(start,data);	
	}
	return start;
}/*End of create_list()*/

void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}/*End of display() */

struct node *addtoempty(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}/*End of addtoempty( )*/

struct node *addatbeg(struct node *start,int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
	return start;
}/*End of addatbeg( )*/

struct node *addatend(struct node *start,int data)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}/*End of addatend( )*/

