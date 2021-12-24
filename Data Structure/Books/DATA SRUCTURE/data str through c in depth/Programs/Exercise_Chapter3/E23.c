/* 
E23 
Delete all the nodes having negative numbers in info part from the list L1 and insert them into list L2 
Delete all the nodes having positive numbers in info part from the list L1 and insert them into list L3. 
No new nodes to be allocated.
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
void PositiveNegative(struct node **start1,struct node **start2,struct node **start3 );

main()
{
	struct node *start1=NULL, *start2=NULL, *start3=NULL;	
	start1=create_list(start1);
	display(start1);
	PositiveNegative(&start1, &start2, &start3);
	printf("List L1 is ");
	display(start1);
	printf("List L2 is : ");
	display(start2);
	printf("List L3 is : ");
	display(start3);
}/*End of main()*/

void PositiveNegative(struct node **start1,struct node **start2,struct node **start3)
{
	struct node *p1=*start1, *p2=*start2, *p3=*start3;
	while(p1!=NULL)
	{
		if((p1->info)<0)  /*Insert in first list*/
		{
			if(*start2==NULL)
				p2=*start2=p1;
			else
			{
				p2->link=p1;
				p2=p2->link;
			}
		}
		else     /*Insert in second list*/
		{
			if(*start3==NULL)
				p3=*start3=p1;
			else
			{
				p3->link=p1;
				p3=p3->link;
			}
		}
		p1=p1->link;
	}
	if(p2!=NULL)
		p2->link=NULL;
	if(p3!=NULL)
		p3->link=NULL;
	*start1=NULL;
}/*End of PositiveNegative()*/

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
