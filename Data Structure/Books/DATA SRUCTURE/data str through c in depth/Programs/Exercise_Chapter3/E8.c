/* 
E8 - Swap First and last elements of a single linked list
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
void SwapFirstLastInfo(struct node *start);
struct node *SwapFirstLast(struct node *start);

main()
{
	struct node *start=NULL;
	start=create_list(start);
	display(start);
	SwapFirstLastInfo(start);
	display(start);
	start = SwapFirstLast(start);
	display(start);
}/*End of main()*/

void SwapFirstLastInfo(struct node *start)
{
	struct node *p=start;
	int tmp;

	if(p==NULL || p->link==NULL)/*List empty or ony one element in the list*/
		return;

	while(p->link!=NULL)
		p=p->link;

	/*Now p points to last node*/
	tmp=start->info;
	start->info=p->info;
	p->info=tmp;
}/*End of SwapFirstLastInfo()*/

struct node *SwapFirstLast(struct node *start)
{
	struct node *p=start, *psave;
	if(p==NULL || p->link==NULL)/*List empty or only one element in the list*/
		return start;

	if(p->link->link==NULL) /* only two elements */
	{
		p->link->link=start;
		start = p->link;
		p->link=NULL;
		return start;
	}
	
	while(p->link->link != NULL)
		p=p->link;
	/*Now p points to second last node*/
	p->link->link = start->link;
	psave = p->link;
	p->link = start;
	p->link->link=NULL;  
	start = psave;
	return start;
}/*End of SwapFirstLast()*/

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

