/* 
E19 - Program to delete duplicates from a sorted linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};
struct node *insert_s(struct node *start,int data);
void display(struct node *start);
void deleteDuplicates(struct node *start);

main()
{
	int i,n,data;
	struct node *start=NULL;

	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=insert_s(start,data);
	}
	display(start);
	deleteDuplicates(start);
	display(start);
}/*End of main()*/

void deleteDuplicates(struct node *start)
{
	struct node *p,*duplicate;

	if(start==NULL)
		return;
	p=start;
	while(p->link!=NULL)
	{
		if(p->info == p->link->info)
		{
			duplicate = p->link;
			p->link = p->link->link;
			free(duplicate);
		}
		else
			p=p->link;
	}
}/*End of deleteDuplicates()*/

struct node *insert_s(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	/*list empty or new node to be added before first node*/
	if(start==NULL || data < start->info)
	{
		tmp->link=start;
		start=tmp;
		return start;
	}
	else
	{
		p=start;
		while(p->link!=NULL && p->link->info < data)
			p=p->link;
		tmp->link=p->link;
		p->link=tmp;
	}
	return start;
}/*End of insert()*/

void display(struct node *start)
{
	struct node *q;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	q=start;
	printf("List is :\n");
	while(q!=NULL)
	{
		printf("%d ",q->info);
		q=q->link;
	}
	printf("\n");
}/*End of display() */

