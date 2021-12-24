/*
E15 - Program to move a node forward n positions
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
struct node *Move(struct node *start, int value , int n);

main()
{
	struct node *start=NULL;
	int value,n;
	start=create_list(start);
	display(start);
	printf("Enter info of the node that is to be moved: ");
	scanf("%d", &value);
	printf("Enter n : ");
	scanf("%d", &n);
	start = Move(start, value, n);
	display(start);
}/*End of main()*/

struct node *Move(struct node *start, int value, int n)
{
	struct node *r,*p,*q;
	int i;
	if(n<=0)
		return start;
	r=p=start;
	while(p!=NULL)
	{
		if(p->info==value)
			break;
		r=p;
		p=p->link;
	}
	if(p==NULL)
    {
		printf("Value does not exist\n");
		return start;
	}
	
	q=p;
	for(i=1;i<=n;i++)
	{
		if(q->link==NULL)
		{	
			printf("Can't move %d positions \n",n);
			return start;
		}
		q=q->link;
	}
	
	if(p!=start)
		r->link=p->link;
	else
		start=start->link;

	p->link=q->link;
	q->link=p;
		
	return start;
}/*End of Move()*/

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

