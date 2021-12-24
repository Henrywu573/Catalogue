/* P3.5 Program of sorted linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};
struct node *insert_s(struct node *start,int data);
void search(struct node *start,int data);
void display(struct node *start);
main()
{
	int choice,data;
	struct node *start=NULL;
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Display\n");
		printf("3.Search\n");
		printf("4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=insert_s(start,data);
			break;
		 case 2:
			display(start);
			break;
		 case 3:
			printf("Enter the element to be searched : ");
			scanf("%d",&data);
			search(start,data);
			break;
		 case 4:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
} /*end of main */

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
void search(struct node *start,int data)
{
	struct node *p;
	int pos;
	
	if(start==NULL || data < start->info)
	{
		printf("%d not found in list\n",data);
		return;
	}
	p=start;
	pos=1;
	while(p!=NULL && p->info<=data)
	{
		if(p->info==data)
		{
			printf("%d found at position %d\n",data,pos);
			return;
		}
		p=p->link;
		pos++;
	}
	printf("%d not found in list\n",data);
}/*End of search()*/

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

