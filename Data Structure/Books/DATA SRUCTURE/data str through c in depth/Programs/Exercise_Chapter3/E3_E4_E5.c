/*
E3-To check whether two single linked lists are identical
E4-To create a copy of a single linked list
E5-To create a reverse list 
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

int Identical(struct node *start1, struct node *start2);
struct node *Copy(struct node *start1);
struct node *CreateReverse(struct node *start);

main()
{
	struct node *start1=NULL,*start2, *start3;	
	struct node *start4=NULL, *start5=NULL;
	
	printf("Enter list 1 -\n");
	start1=create_list(start1);
	
	printf("List 1 is :\n");
	display(start1);
	
	start2 = Copy(start1);
	printf("Copy of list 1 is :\n");
	display(start2);

	start3 = CreateReverse(start1);	
	printf("Reverse list of list 1 is :\n");
	display(start3);
	
	printf("Compare two lists :\n\n");
	printf("Enter first list -\n");
	start4=create_list(start4);
	printf("Enter second list -\n");
	start5=create_list(start5);
	
	if(Identical(start4,start5))
		printf("Lists are same\n");
	else
		printf("Lists are different\n");
}/*End of main()*/

struct node *Copy(struct node *start)
{
	struct node *startCopy=NULL;
	struct node *p1,*p2,*tmp;
	
	if(start == NULL)
		return NULL;
   	
	p1=start;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = p1->info;
	p2 = startCopy = tmp;
	p1=p1->link;

	while(p1!=NULL)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->info = p1->info;
		p2->link=tmp;
		p2=tmp;
		p1=p1->link;
	}
	p2->link=NULL;
	return startCopy;
}/*End of Copy()*/

struct node *CreateReverse(struct node *start)
{
	struct node *startRev=NULL;
	struct node *p=start;
	while(p!=NULL)
	{
		startRev = addatbeg(startRev,p->info);	
		p=p->link;
	}
	return startRev;
}/*End of CreateReverse()*/

int Identical(struct node *p1, struct node *p2)
{
	while(1)
	{
		if((p1==NULL) && (p2==NULL))  
			return 1;
		if((p1==NULL) || (p2==NULL))
			return 0;
		if(p1->info != p2->info)
			return 0;
		p1 = p1->link;
		p2 = p2->link ;
	}
}/*End of Identical()*/

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
		printf("Empty\n");
		return;
	}
	p=start;

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

