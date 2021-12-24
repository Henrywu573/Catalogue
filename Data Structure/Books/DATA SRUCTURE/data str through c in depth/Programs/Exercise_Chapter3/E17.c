/*
E17 - Functions to insert a node just before and just after a node pointed to by a pointer p, 
	  without using the pointer start
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
void InsertAfter(struct node *ptr, int data);
void InsertBefore(struct node *ptr, int data);

main()
{
	struct node *start=NULL,*ptr;	
	
	int item;
	start=create_list(start);
	display(start);
	
	printf("Enter a value : ");
	scanf("%d",&item);
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->info==item)
			break;
		ptr=ptr->link;
	}
	if(ptr==NULL)
	{
		printf("Value does not exist\n");
		exit(1);
	}
	InsertAfter(ptr,64);
	InsertBefore(ptr,32); 
	display(start);
}/*End of main()*/

void InsertAfter(struct node *ptr, int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->link = ptr->link;
	ptr->link = tmp;
	tmp->info=data;
}/*End of InsertAfter()*/

void InsertBefore(struct node *ptr, int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->link = ptr->link;
	ptr->link = tmp;
	tmp->info=ptr->info;
	ptr->info=data;
}/*End of InsertBefore()*/

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

