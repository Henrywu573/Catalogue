/*
E21 - Intersection of two single linked lists
E22 - Union of two single linked lists
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
struct node *insert(struct node *start,int data);
struct node *Intersection(struct node *start1,struct node *start2);
struct node *Union(struct node *start1,struct node *start2);
int isPresent(struct node *start, int data);

main()
{
	struct node *start1=NULL, *start2=NULL, *start3, *start4;	
	start1=create_list(start1);
	start2=create_list(start2);
	display(start1);
	display(start2);
	start3 = Intersection(start1,start2);
	start4 = Union(start1,start2);

	printf("Intersection "); 
	display(start3);
	printf("Union "); 
	display(start4);
}/*End of main()*/

struct node *Intersection(struct node *start1,struct node *start2)
{
	struct node *start3=NULL, *ptr=start1;
	while(ptr!=NULL)
	{
		if( isPresent(start2,ptr->info) )
			start3 = insert(start3,ptr->info);			
		ptr=ptr->link;		
	}
	return start3;
}/*End of Intersection()*/

struct node *Union(struct node *start1,struct node *start2)
{
	struct node *start4=NULL, *ptr=start1;
	while(ptr!=NULL)
	{
		start4 = insert(start4,ptr->info);			
		ptr=ptr->link;
	}
	ptr=start2;
	while(ptr!=NULL)
	{
		if( !isPresent(start1,ptr->info) )	
			insert(start4,ptr->info);			
		ptr=ptr->link;	
	}
	return start4;
}/*End of Union()*/

int isPresent(struct node *start, int data)
{
	struct node *ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->info == data )
			return 1;
		ptr=ptr->link;
	}
	return 0;
}

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

struct node *insert(struct node *start,int data)
{
	if(start==NULL)
		start=addatbeg(start,data);
	else
		start=addatend(start,data);	
	return start;
}/*End of insert()*/

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

