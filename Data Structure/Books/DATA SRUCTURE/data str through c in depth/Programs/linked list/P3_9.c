/* P3.9 Program to concatenate two circular linked lists*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *create_list(struct node *last);
void display(struct node *last);
struct node *addtoempty(struct node *last,int data );
struct node *addatend(struct node *last,int data);
struct node *concat(struct node *last1,struct node *last2);

main( )
{
	struct node *last1=NULL,*last2=NULL;
	last1=create_list(last1);
	last2=create_list(last2);
	printf("First list is :  ");
	display(last1);
	printf("Second list is :  ");
	display(last2);
    last1=concat(last1, last2);
	printf("Concatenated list is  : ");
	display(last1);
}/*End of main( )*/

struct node *concat( struct node *last1,struct node *last2)
{
	struct node *ptr;
	if(last1==NULL)
	{
		last1=last2;
		return last1;
	}
	if(last2==NULL )   
		return last1;
	ptr=last1->link;
	last1->link=last2->link;
	last2->link=ptr;
	last1=last2;
	return last1;
}
struct node *create_list(struct node *last)
{
	int i,n;
	int data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	last=NULL;
	if(n==0)
		return last;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	last=addtoempty(last,data);
		
	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		last=addatend(last,data);	
	}
	return last;
}

void display(struct node *last)
{
	struct node *p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=last->link;  /*p points to first node*/
	do 
	{
		printf("%d ", p->info);
		p=p->link;
	}while(p!=last->link);
	printf("\n");
}/*End of display( )*/

struct node *addtoempty(struct node *last,int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	last = tmp;
	last->link = last;
	return last;
}/*End of addtoempty( )*/

struct node *addatend(struct node *last,int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = last->link;
	last->link = tmp;
	last = tmp;
	return last;
}/*End of addatend( )*/

