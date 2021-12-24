/* P3.10 Program of polynomial addition and multiplication using linked list */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	float coef;
	int expo;
	struct node *link;
};

struct node *create(struct node *);
struct node *insert_s(struct node *,float,int);
struct node *insert(struct node *,float,int);
void display(struct node *ptr);
void poly_add(struct node *,struct node *);
void poly_mult(struct node *,struct node *);
main( )
{
	struct node *start1=NULL,*start2=NULL;
	
	printf("Enter polynomial 1 :\n");
	start1=create(start1);

	printf("Enter polynomial 2 :\n");
	start2=create(start2);

	printf("Polynomial 1 is :  ");
	display(start1);
	printf("Polynomial 2 is :  ");
	display(start2);
		
	poly_add(start1, start2);
	poly_mult(start1, start2);
}/*End of main()*/

struct node *create(struct node *start)
{
	int i,n,ex;
	float co;
	printf("Enter the number of terms : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter coeficient for term %d : ",i);
		scanf("%f",&co);
		printf("Enter exponent for term %d : ",i);
		scanf("%d",&ex);
		start=insert_s(start,co,ex);
	}
	return start;
}/*End of create()*/
struct node *insert_s(struct node *start,float co,int ex)
{
	struct node *ptr,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->coef=co;
	tmp->expo=ex;
	/*list empty or exp greater than first one */
	if(start == NULL || ex > start->expo)
	{
		tmp->link=start;
		start=tmp;
	}
	else	
	{
		ptr=start;
		while(ptr->link!=NULL && ptr->link->expo >= ex)
			ptr=ptr->link;
		tmp->link=ptr->link;
		ptr->link=tmp;
	}
	return start;
}/*End of insert()*/
	
struct node *insert(struct node *start,float co,int ex)
{
	struct node *ptr,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->coef=co;
	tmp->expo=ex;
	/*If list is empty*/
	if(start==NULL)
	{
		tmp->link=start;
		start=tmp;
	}
	else	/*Insert at the end of the list*/
	{
		ptr=start;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		tmp->link=ptr->link;
		ptr->link=tmp;
	}
	return start;
}/*End of insert
()*/

void display(struct node *ptr)
{
	if(ptr==NULL)
	{
		printf("Zero polynomial\n");
		return;
	}
	while(ptr!=NULL)
	{
		printf("(%.1fx^%d)", ptr->coef,ptr->expo);
		ptr=ptr->link;
		if(ptr!=NULL)
			printf(" + ");
		else 
			printf("\n");
	}
}/*End of display()*/
void poly_add(struct node *p1,struct node *p2)
{
	struct node *start3;
	start3=NULL;
	
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->expo > p2->expo)
		{
			start3=insert(start3,p1->coef,p1->expo);
			p1=p1->link;
		}
		else if(p2->expo > p1->expo)
		{
			start3=insert(start3,p2->coef,p2->expo);
			p2=p2->link;
		}
		else if(p1->expo==p2->expo)
		{
			start3=insert(start3,p1->coef+p2->coef,p1->expo);
			p1=p1->link;
			p2=p2->link;
		}
	}
	/*if poly2 has finished and elements left in poly1*/
	while(p1!=NULL)
	{
		start3=insert(start3,p1->coef,p1->expo);
		p1=p1->link;
	}
	/*if poly1 has finished and elements left in poly2*/
	while(p2!=NULL)
	{
		start3=insert(start3,p2->coef,p2->expo);
		p2=p2->link;
	}
	printf("Added polynomial is : ");
	display(start3);
}/*End of poly_add() */

void poly_mult(struct node *p1, struct node *p2)
{
	struct node *start3;
	struct node *p2_beg = p2;
	start3=NULL;
	if(p1==NULL || p2==NULL)
	{
		printf("Multiplied polynomial is zero polynomial\n");
		return;
	}
	while(p1!=NULL)
	{
		p2=p2_beg;
		while(p2!=NULL)
		{
			start3=insert_s(start3,p1->coef*p2->coef,p1->expo+p2->expo);
			p2=p2->link;	
		}
		p1=p1->link;
	}	
	printf("Multiplied polynomial is : ");
	display(start3);
}/*End of poly_mult()*/		
