/*
E9 - Move the largest element to the end of a single linked list.
E10 - Move the smallest element to the beginning of a single linked list.
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
void MoveLarge(struct node *start);
void MoveSmall(struct node *start);

main()
{
	struct node *start=NULL;
	start=create_list(start);
	display(start);
	MoveLarge(start);
	display(start);
	MoveSmall(start);
	display(start);
}/*End of main()*/

void MoveLarge(struct node *start)
{
	struct node *p;
	int tmp;
	if(start==NULL)
		return;
	
	p=start;
	while(p->link!=NULL)
	{
		if(p->info > p->link->info)
		{
			tmp = p->info;
			p->info = p->link->info;
			p->link->info = tmp;
		}
		p=p->link;
	}
}/*End of MoveLarge()*/

void MoveSmall(struct node *start)
{
	struct node *p,*q;
	int tmp;
	if(start==NULL)
		return;
	p=start;
	q=start->link;
	while(q!=NULL)
	{
		if(p->info > q->info )
		{
			tmp = p->info;
			p->info = q->info;
			q->info = tmp;
		}
		q=q->link;
	}
}/*End of MoveSmall()*/

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

