/* 
E27 - Detecting and Removing a cycle in a single linked list 
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
struct node *findCycle(struct node *start);
int lengthList(struct node *start, struct node *C);

main()
{
	struct node *start=NULL;	
	struct node *p,*psave=NULL, *prev, *ptr;		
	int len,i;

	start=create_list(start);
	if(start==NULL)
		exit(1);

    /*Insert a cycle at node containing 14*/
	prev=p=start;
	while(p!=NULL)
	{
		if(p->info==14)
			psave=p;
		prev=p;
		p=p->link;
	}
	if(psave!=NULL)
		prev->link=psave;

	ptr = findCycle(start);
	
	if(ptr==NULL)
		printf("List is NULL terminated\n");
	else
	{
		printf("There is a cycle in the list\n");	
		len = lengthList(start, ptr);
		printf("Length of the list is : %d\n",len);
		ptr=start;
		for(i=1;i<len;i++)
			ptr=ptr->link;
		ptr->link=NULL;	
		printf("Cycle Removed, now the list is NULL terminated\n");
	}
	display(start);
}/*End of main()*/

/*Returns NULL if the list is NULL terminated otherwise returns the node where both pointers meet*/
struct node *findCycle(struct node *start)
{
	struct node *slowP, *fastP;
	if(start->link==NULL) /*only one element*/
		return NULL;
	slowP=fastP=start;
	while(fastP!=NULL && fastP->link!=NULL)
	{
		slowP=slowP->link;
		fastP=fastP->link->link;
		if( slowP==fastP )
			return slowP;
	}
	return NULL;
}/*End of findCycle()*/

int lengthList(struct node *start, struct node *C)
{
	struct node *p1, *p2;
	int len_Cycle, len_remainingList;
		
	printf("Node at which the cycle was detected is %d\n",C->info);
	
	p1=p2=C;	
	len_Cycle=0;
	do
	{
		len_Cycle++;
		p2=p2->link;
	}while(p1!=p2);
	printf("Length of cycle is : %d\n",len_Cycle);
	
	len_remainingList=0;
	p1=start;
	while(p1!=p2)
	{
		len_remainingList++;
		p1=p1->link;
		p2=p2->link;
	}
	printf("Node that causes cycle is : %d\n",p1->info);
	printf("Number of nodes not included in the cycle are : %d\n",len_remainingList);
	
	return len_Cycle + len_remainingList;
}/*End of lengthList()*/

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

