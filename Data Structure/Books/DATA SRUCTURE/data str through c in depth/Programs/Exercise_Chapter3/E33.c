/* 
E33 - To find merge point of two single linked lists 
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
create_mergedLists(struct node **start1, struct node **start2);
struct node *Find_mergePoint(struct node *start1, struct node *start2);

main()
{
	struct node *start1=NULL, *start2=NULL,*start3=NULL, *start4=NULL,*p;
	start1 = create_list(start1);
	start2 = create_list(start2);
	display(start1);
	display(start2);
	p = Find_mergePoint(start1, start2);
	
	if(p==NULL)
		printf("Lists don't merge\n");
	else
		printf("List merge at node %d\n", p->info);

	create_mergedLists(&start3, &start4);
	display(start3);
	display(start4);
	p = Find_mergePoint(start3, start4);
	if(p==NULL)
		printf("Lists don't merge\n");
	else
		printf("Lists merge at node %d\n", p->info);
}/*End of main()*/

struct node *Find_mergePoint(struct node *start1, struct node *start2)
{
	struct node *p,*q;
	int len1=0, len2=0, i, d;
	
	p=start1;
	while(p!=NULL)/*Find length of first list*/
	{
		len1++;
		p=p->link;
	}
	p=start2;
	while(p!=NULL)/*Find length of second list*/
	{
		len2++;
		p=p->link;
	}
	
	p=start1;
	q=start2;
		
	if(len1>len2)/*If first list is longer*/
	{
		d=len1-len2;	
		for(i=1;i<=d;i++)
			p=p->link;
	}
	else if(len1<len2)/*If second list is longer*/
	{
		d=len2-len1;	
		for(i=1;i<=d;i++)
			q=q->link;
	}

	while(p!=NULL && q!=NULL)
	{
		if(p==q)
			return p;	/*Merge point found*/
		p=p->link;
		q=q->link;
	}
	return NULL;	/*Lists don't merge*/
}/*End of Find_mergePoint()*/

create_mergedLists(struct node **start1, struct node **start2)
{
	struct node *tmp, *p, *q;

	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=31;
	*start1 = p = tmp;
	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=14;
	p->link=tmp; p=p->link;
	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=52;
	p->link=tmp;  p=p->link;

	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=23;
	*start2 = q = tmp;
	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=45;
	q->link=tmp; q=q->link;
	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=54;
	q->link=tmp;  q=q->link;
	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=61;
	q->link=tmp;  q=q->link;
	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=12;
	q->link=tmp;  q=q->link;


	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=18;
	p->link = q->link = tmp;  p=p->link;  
	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=20;
	p->link = tmp;  p=p->link;
	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=89;
	p->link = tmp;  p=p->link;
	tmp=(struct node *)malloc(sizeof(struct node));	tmp->info=98; tmp->link=NULL;
	p->link = tmp;  
}/*End of create_mergedLists()*/

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

