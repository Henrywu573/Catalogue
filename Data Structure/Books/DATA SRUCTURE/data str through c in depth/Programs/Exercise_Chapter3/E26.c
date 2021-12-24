/* 
E26 - get the nth node from the end of a single linked list
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
struct node *nthLast_node(struct node *start,int n);

main()
{
	struct node *start=NULL, *p;	
	int n;
	start=create_list(start);
	display(start);
	printf("Enter n : ");
	scanf("%d",&n);
	p = nthLast_node(start,n);
	if(p!=NULL)
		printf("%d\n",p->info);
}/*End of main()*/

struct node *nthLast_node(struct node *start,int n)	
{
	struct node *p1,*p2;
	int i=0;

	if(start==NULL)
		return NULL;
	p1=p2=start;
  
	for(i=0; i<n; i++)  /*Move the pointer p1 n times */
	{
		if(p1==NULL)
		{
			printf("List has less than %d elements\n",n);
			return NULL;   
		}
		p1=p1->link;
	}
  
	while(p1!=NULL) /*Move both pointers till p1 becomes NULL */
	{
		p2=p2->link;
		p1=p1->link;
	}
	return p2;	
}/*End of nthLast_node()*/

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

