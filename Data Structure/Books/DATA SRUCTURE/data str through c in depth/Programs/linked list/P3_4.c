/*P3.4 Program of single linked list with header node*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *create_list(struct node *head);
void display(struct node *head);
struct node *addatend(struct node *head,int data);
struct node *addbefore(struct node *head,int data,int item );
struct node *addatpos(struct node *head,int data,int pos);
struct node *del(struct node *head,int data);
struct node *reverse(struct node *head);

main()
{
	int choice,data,item,pos;
	struct node *head;	
	head=(struct node *)malloc(sizeof(struct node));
	head->info=0;	
	head->link=NULL;
	
	head=create_list(head);
	
	while(1)
	{
		
		printf("1.Display\n");
		printf("2.Add at end\n");
		printf("3.Add before node\n");
		printf("4.Add at position\n");
		printf("5.Delete\n");
		printf("6.Reverse\n");
		printf("7.Quit\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			display(head);
			break;
		 case 2:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			head=addatend(head,data);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert : ");
			scanf("%d",&item);
			head=addbefore(head,data,item);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the position at which to insert : ");
			scanf("%d",&pos);
			head=addatpos(head,data,pos);
			break;
		 case 5:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			head=del(head,data);	
			break;
		 case 6:
			head=reverse(head);
			break;
		 case 7:
			 exit(1);
		 default:
			printf("Wrong choice\n\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/

struct node *create_list(struct node *head)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		head=addatend(head,data);	
	}
	return head;
}/*End of create_list()*/

void display(struct node *head)
{
	struct node *p;
	if(head->link==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=head->link;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n");
}/*End of display() */

struct node *addatend(struct node *head,int data)
{
	struct node *p,*tmp;
	tmp= (struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=head;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return head;
}/*End of addatend()*/

struct node *addbefore(struct node *head,int data,int item)
{
	struct node *tmp,*p;
	p=head;
	while(p->link!=NULL)
	{
		if(p->link->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return head;
		}
		p=p->link;
	}
	printf("%d not present in the list\n",item);
	return head;
}/*End of addbefore()*/		

struct node *addatpos(struct node *head,int data,int pos)
{
	struct node *tmp,*p;
	int i;
	tmp=(struct node *)malloc(sizeof(struct node) );
	tmp->info=data;
	p=head;
	for(i=1;i<=pos-1;i++)
	{
		p=p->link;
		if(p==NULL)
		{
			printf("There are less than %d elements\n",pos);
			return head;
		}
	}
	tmp->link=p->link;
	p->link=tmp;
	return head;
}/*End of addatpos()*/

struct node *del(struct node *head, int data)
{
	struct node *tmp,*p;
	p=head;
	while(p->link!=NULL)
	{
		if(p->link->info==data)   
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return head;
		}
		p=p->link;
	}
	printf("Element %d not found\n",data);
	return head;
}/*End of del()*/

struct node *reverse(struct node *head)
{
	struct node *prev, *ptr, *next;
	prev=NULL;
	ptr=head->link;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	head->link=prev;
	return head;
}/*End of reverse()*/

