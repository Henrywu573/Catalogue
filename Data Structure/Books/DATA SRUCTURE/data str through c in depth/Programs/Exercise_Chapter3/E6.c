/* 
E6 - Swapping adjacent elements 
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
void SwapAdjacentInfo(struct node *start);
struct node *SwapAdjacent(struct node *start);

main()
{
	struct node *start=NULL;	
	start=create_list(start);
	display(start);
	start = SwapAdjacent(start);
	display(start);
	SwapAdjacentInfo(start);
	display(start);
}/*End of main()*/

void SwapAdjacentInfo(struct node *start)
{
	struct node *p,*q;
	int tmp;
	if(start==NULL || start->link==NULL) /*List empty or only one element in the list*/
		return;
	p=start;
	while(p!=NULL && p->link != NULL)
	{
		q=p->link;
		tmp = p->info;
		p->info = q->info;
		q->info = tmp;
		p=q->link;
	}
}/*End of SwapAdjacentInfo()*/

struct node *SwapAdjacent(struct node *start)
{
	struct node *r,*p,*q;
	if(start==NULL || start->link==NULL)/*List empty or only one element in the list*/
		return start;
	r=p=start;
	while(p->link!=NULL)
	{
		q=p->link;
		p->link=q->link;
		q->link=p;
		if(p!=start)
			r->link=q;
		else
			start=q;
		r=p;
		if(p->link!=NULL)
			p=p->link;
	}
	return start;
}/*End of SwapAdjacent()*/

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
	start=addatbeg(start,data);

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
		p=p->link;
	}
	printf("\n\n");
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

