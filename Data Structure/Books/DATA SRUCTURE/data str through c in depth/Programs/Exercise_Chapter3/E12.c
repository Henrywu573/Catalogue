/*
E12 - Print a list according to other list
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
struct node *insert_s(struct node *start,int data);
void Print(struct node *start1, struct node *start2);

main()
{
	struct node *start1=NULL, *start2=NULL;	
	int i,n,data;

	printf("Enter the sorted list L1 : \n");
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start1=insert_s(start1,data);
	}

	printf("Enter the list L2 : \n");
	start2 = create_list(start2);	
	
	printf("List L1 is  : \n");
	display(start1);
	printf("List L2 is  : \n");
	display(start2);
	
	Print(start1,start2);
}/*End of main()*/

void Print(struct node *p1, struct node *p2)
{
	int i=1;
	
	if(p1==NULL || p2==NULL)
		return;
		
	while(p1!=NULL)
	{
		while(i < p1->info)
		{
			p2=p2->link;
			if(p2==NULL)
			{
				printf("\nError : Less than %d elements\n",p1->info);
				return;
			}
			i++;
		}
		printf("%d ",p2->info);
		p1=p1->link;	
	}
	printf("\n");
}/*End of Print()*/

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
		printf(" Empty\n");
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

struct node *insert_s(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	/*list empty or new node to be added before first node*/
	if(start==NULL || data<start->info)
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
