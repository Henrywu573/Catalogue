/*E36 Palindrome */

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
int isIdentical(struct node *p1, struct node *p2);
int isPalindrome(struct node *start);
struct node *reverse(struct node *start);

main()
{
	struct node *start=NULL;	
	start=create_list(start);
	display(start);
	if( isPalindrome(start) )
		printf("List is a Palindrome\n");
	else
		printf("List is not a Palindrome\n");
	display(start);
}/*End of main()*/

int isPalindrome(struct node *start)
{
	struct node *slowP, *fastP, *prev_slowP, *start_second;  
	int result;  
 
	if(start==NULL || start->link==NULL) /*List empty or only one element*/
	   return 1;
	prev_slowP = slowP = fastP = start;
	while(fastP->link!=NULL && fastP->link->link!=NULL)
	{
		prev_slowP = slowP;
		slowP=slowP->link;
		fastP=fastP->link->link;
	}
	start_second = slowP->link;  
	if(fastP->link == NULL)  /*odd number of elements in the list*/
    {  
		start_second = reverse(start_second);  /*reverse the second half*/
		prev_slowP->link = NULL; /*node pointed by prev_slowP is last node of first half, Middle element pointed by slowP will not be in any half*/  
		result = isIdentical(start, start_second);/*compare the first half and second half*/  
		start_second = reverse(start_second);  /*reverse second half to get the original order*/
		prev_slowP->link = slowP; /*Join first half with the middle element*/
		slowP->link = start_second;/*Join middle element with the second half*/  
    }  
	else /*even number of elements in the list*/
	{  
		start_second = reverse(start_second);  /*reverse the second half*/
		slowP->link = NULL; /*node pointed by slowP is the last node of first half*/  
		result = isIdentical(start, start_second);  /*compare the first half and second half*/  
		start_second = reverse(start_second);  /*reverse second half to get the original order*/  
		slowP->link = start_second; /*Join first half and second half*/ 
	}   
	return result;  
}/*End of isPalindrome()*/

struct node *reverse(struct node *start)
{
	struct node *prev, *ptr, *next;
	prev=NULL;
   	ptr=start;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	return start;
}/*End of reverse()*/

int isIdentical(struct node *p1, struct node *p2)
{
	while(1)
	{
		if((p1==NULL)&&(p2==NULL))  
			return 1;
		if((p1==NULL)||(p2==NULL))
			return 0;
		if(p1->info!=p2->info)
			return 0;
		p1 = p1->link;
		p2 = p2->link ;
	}
}/*End of Identical()*/

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

