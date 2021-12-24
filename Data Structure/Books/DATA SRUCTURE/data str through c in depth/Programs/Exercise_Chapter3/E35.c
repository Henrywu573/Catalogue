/*
E35
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	struct node *prev;
	int info;
	struct node *next;
};

void display(struct node *start);
struct node *addatend(struct node *start, int data);
struct node *addtoempty(struct node *start, int data);
struct node *create(struct node *start, char *str);
struct node *sum(struct node *start1, struct node *start2, struct node *start3 );
void display_num(struct node *start );

main( )
{
	struct node *start1 = NULL, *start2=NULL, *start3=NULL;
	char str[100];
	
	printf("Enter first integer : ");
	scanf("%s",str);
	
	start1 = create(start1, str);
	
	printf("Enter second integer : ");
	scanf("%s",str);

	start2 = create(start2, str);
	start3 = sum(start1, start2, start3);

	printf("Lists : \n");
	display(start1);
	display(start2);
	display(start3);

	printf("Numbers : \n");
	display_num(start1);
	display_num(start2);
	display_num(start3);
}

struct node *sum(struct node *start1, struct node *start2, struct node *start3 )
{
	int carry, total, num;
	struct node *p, *q;
	
	carry = 0;
	p=start1;
	q=start2;
	
	while(p!=NULL && q!=NULL)
	{
		total = p->info + q->info + carry;
		num = total % 10000;
		carry = total / 10000;
		if(start3 == NULL)
			start3 = addtoempty(start3, num);
		else
			start3 = addatend(start3, num); 
		p=p->next;
		q=q->next;
	}
	while(p!=NULL)
	{
		total = p->info + carry;
		num = total % 10000;
		carry = total / 10000;
		if(start3 == NULL)
			start3 = addtoempty(start3, num);
		else
			start3 = addatend(start3, num); 
		p=p->next;
	}
	
	while(q!=NULL)
	{
		total = q->info + carry;
		num = total % 10000;
		carry = total / 10000;
		if(start3 == NULL)
			start3 = addtoempty(start3, num);
		else
			start3 = addatend(start3, num); 
		q=q->next;
	}

	if(carry == 1)
		start3 = addatend(start3, carry); 
	return start3;
}


struct node *create(struct node *start, char *str)
{
	int i,j,num,x=0;
	char temp[100];
	i=strlen(str)-1;
	while(i!=-1)
	{
		if(i<3)
		{
			j=i;	
			x=i+1;
		}
		else
			j=3;	
		while( j!=-1 && i!=-1 )
		{
			temp[j]=str[i];
			j--;
			i--;
		}
		
		if(x==0 )
			temp[4]='\0';
		else
			temp[x]='\0';
		sscanf(temp, "%d",&num);
		if(start == NULL)
			start = addtoempty(start, num);
		else
			start = addatend(start, num);
	}
	return start;
}
void display(struct node *start )
{
	struct node *p;
	int d, num;
	if(start == NULL)
	{
		printf("List is empty\n\n");
		return;
	}
	p=start;
	while(p!=NULL)
	{
		if(p->next!=NULL)
		{
			num=p->info;		
			d=1;
			while(num/10!=0)
			{
				d++;	
				num/=10;
			}
			if( d == 1 )
				printf("000");
			else if(d == 2)
				printf("00");
			else if(d == 3)
				printf("0");
		}
		
		printf("%d -> ", p->info);
		p=p->next;
	}
	printf("\n");
}/*End of display() */

void display_num(struct node *start )
{
	struct node *p;
	int d,num;
	if(start == NULL)
	{
		printf("List is empty\n\n");
		return;
	}
	p=start;
	while(p->next!=NULL)
		p=p->next;
	
	while(p!=NULL)
	{
		if(p->next!=NULL)
		{
			/*if number is of 3 digits display 1 zero, if 2 digits display 2 zeros, if 1 digit display 3 zeros */
			num=p->info;		
			d=1;
			while(num/10!=0)
			{
				d++;	
				num/=10;
			}
			if( d == 1 )
				printf("000");
			else if(d == 2)
				printf("00");
			else if(d == 3)
				printf("0");
		}
		printf("%d", p->info);
		p=p->prev;
	}
	printf("\n");
}/*End of display_num()*/

struct node *addtoempty(struct node *start, int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	
	tmp->prev=NULL;
	tmp->next = NULL;
	start=tmp;
	return start;
}/*End of addtoemty( )*/

struct node *addatend(struct node *start, int data)
{
	struct node *tmp,*p;
	
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}/*End of addatend( )*/
