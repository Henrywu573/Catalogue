/* 
E31 - split a single linked list into two lists such that alternate nodes go to different lists. 
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
struct node *AlternateSplit(struct node *start1); 

main()
{
	struct node *start1=NULL,*start2=NULL, *start3=NULL;	
	
	start1=create_list(start1);
	display(start1);

	start2 = AlternateSplit(start1);

	printf("List 1 is :\n");
	display(start1);
	printf("List 2 is :\n");
	display(start2);

}/*End of main()*/

struct node *AlternateSplit(struct node *start1 )
{
	struct node *prev,*ptr,*start2;
	
	if(start1==NULL)
		return;
	
	start2 = start1->link;
	
	prev=start1;
	ptr=start1->link;
	
	while( ptr!=NULL )
	{
		prev->link = ptr->link;
		prev=prev->link;
		if(prev==NULL)
            ptr->link=NULL;
		else
			ptr->link = prev->link;
		ptr = ptr->link;
	}
	return start2;
}/*End of AlternateSplit()*/

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

