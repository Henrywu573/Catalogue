/* P3.6 Program of sorting a single linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *create_list(struct node *start );
void display(struct node *start);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
void selection(struct node *start);
void bubble(struct node *start);
struct node *selection_l(struct node *start);
struct node *bubble_l(struct node *start);

main()
{
	int choice;
	struct node *start=NULL;	
	while(1)
	{
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Bubble Sort\n");
		printf("4.Selection Sort\n");
		printf("5.Bubble Sort by changing links\n");
		printf("6.Selection Sort by changing links\n");
		printf("7.Quit\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			start=create_list(start);
			break;
		 case 2:
			display(start);
			break;
		 case 3:
			bubble(start);
			break;
		 case 4:
			selection(start);
			break;
		 case 5:
			start=bubble_l(start);
			break;
		 case 6:
			start=selection_l(start);
			break;
		 case 7:
			 exit(1);
		 default:
			printf("Wrong choice\n\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/

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
	printf("List is : ");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n");
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

void selection(struct node *start )
{
	struct node *p, *q;
	int tmp;
	p=start;
	for(p=start; p->link!=NULL; p=p->link )
	{
		for(q=p->link; q!=NULL; q=q->link)
		{
			if(p->info > q->info )
			{
				tmp=p->info;
				p->info=q->info;
				q->info=tmp;
			}
		}
	}
}/*End of selection( )*/

void bubble(struct node *start )
{
	struct node *end,*p,*q;
	int tmp;
	for(end=NULL; end!=start->link; end=q)
	{
  		for(p=start; p->link!=end; p=p->link)
		{
			q=p->link;
			if(p->info > q->info)
			{
				tmp=p->info;
				p->info=q->info;
				q->info=tmp;
			}
		}
	}
}/*End of bubble( )*/		
struct node *selection_l(struct node *start)
{
	struct node *p,*q,*r,*s,*tmp;
	
	for(r=p=start; p->link!=NULL; r=p,p=p->link)
	{
		for(s=q=p->link; q!=NULL; s=q,q=q->link)
		{
			if(p->info > q->info)
			{
				tmp=p->link;
				p->link=q->link;
				q->link=tmp;
				if(p!=start)
                    r->link=q;
				s->link=p;
				if(p==start)
					start=q;
				tmp=p;
				p=q;
				q=tmp;
			}
		}
	}
	return start;
}/*End of selection_l( )*/

struct node *bubble_l(struct node *start)
{
	struct node *end,*r,*p,*q,*tmp;
		
	for(end=NULL; end!=start->link; end=q)
	{
  		for(r=p=start; p->link!=end; r=p,p=p->link)
		{
			q=p->link;
			if(p->info > q->info )
			{
				p->link=q->link;
				q->link=p;
				if(p!=start)
                    r->link=q;
				else
					start=q;
				tmp=p;
				p=q;
				q=tmp;
			}
		}
		
	}
	return start;
}/*End of bubble_l( )*/		

