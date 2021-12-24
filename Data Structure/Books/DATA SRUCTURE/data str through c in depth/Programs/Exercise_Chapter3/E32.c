/* 
E32 - Program to combine alternate nodes of two single linked lists 
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
void CombineAlternate(struct node **start1, struct node **start2);

main()
{
	struct node *start1=NULL, *start2=NULL;
			
	start1=create_list(start1);
	start2=create_list(start2);
	
	printf("First ");
	display(start1);
	printf("Second ");
	display(start2);	
	
	CombineAlternate(&start1, &start2);
	
	printf("Combined ");
	display(start1);
}/*End of main()*/

void CombineAlternate(struct node **start1, struct node **start2)
{
	struct node *p1, *p2, *pnext;
	p1=*start1;
	p2=*start2;

	if(p1==NULL) /*If first list is empty*/
	{
		*start1=*start2;
		*start2=NULL;
		return;
	}
	if(p2==NULL) /*If second list is empty*/
		return;
	while(p1->link!=NULL && p2!=NULL)
	{
		pnext = p1->link;
		p1->link = p2;
		p1 = pnext;
		pnext = p2->link;
		p2->link = p1;
		p2=pnext;
	}
	if(p1->link==NULL)
		p1->link = p2;	
	*start2=NULL;
}/*End of CombineAlternate()*/

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

