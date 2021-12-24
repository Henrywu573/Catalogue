/* 
E1 - To count number of occurrences of an element in a single linked list
E2 - To find the smallest and largest element in a single linked list
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
int countOccurrences(struct node *start, int n);
int largest(struct node *start);
int smallest(struct node *start);

main()
{
	struct node *start=NULL;
	int n;

	start=create_list(start);
	display(start);
	printf("Largest element is %d\n",largest(start));
	printf("Smallest element is %d\n",smallest(start));
	
	printf("Enter a value : ");
	scanf("%d",&n);
	printf("The value %d occurs %d times\n",n,countOccurrences(start,n) );
}/*End of main()*/

int countOccurrences(struct node *ptr, int n)
{
	int k=0;
	while(ptr!=NULL)
	{
		if(ptr->info == n)
			k++;
		ptr=ptr->link;
	}
	return k;
}/*End of countOccurrences()*/

int largest(struct node *ptr)
{
	int large=ptr->info;
	while(ptr!=NULL)
	{
		if(ptr->info >large)
			large = ptr->info;
		ptr=ptr->link;
	}
	return large;
}/*End of largest()*/

int smallest(struct node *ptr)
{
	int small=ptr->info;
	while(ptr!=NULL)
	{
		if(ptr->info < small)
			small = ptr->info;
		ptr=ptr->link;
	}
	return small;
}/*End of smallest()*/

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

