
/*P5.13 Linked list and Recursion*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};
struct node *create_list(struct node *start);
void display(struct node *ptr);
void Rdisplay(struct node *ptr);
int length(struct node *ptr);
int sum (struct node *ptr);
int search(struct node *ptr, int item );
struct node *insertLast(struct node *ptr, int value);
struct node *delLast(struct node *ptr );
struct node *reverse(struct node *ptr);

main()
{
	struct node *start=NULL;	
	int choice,data;
		
	while(1)
	{
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Display in reverse order\n");
		printf("4.Count\n");
		printf("5.Sum of elements\n");
		printf("6.Search\n");
		printf("7.Insert at last\n");
		printf("8.Delete the last node\n");
		printf("9.Reverse the list\n");
		printf("10.Quit\n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
		 case 1:
			start=create_list(start);
			break;
		 case 2:
			display(start);
			printf("\n\n");
			break;
		 case 3:
			Rdisplay(start);
			printf("\n\n");
			break;
		 case 4:
			printf("Number of elements = %d\n\n",length(start));
			break;
		 case 5:
			printf("Sum of elements = %d\n\n",sum(start));
			break;		
		 case 6:
			printf("Enter the element to be searched : ");
			scanf("%d",&data);
			if( search(start,data) == 1 )
				printf("Element present\n\n");
			else
				printf("Element not present\n\n");
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=insertLast(start,data);
			break;
		 case 8:
			start=delLast(start);	
			printf("Last node deleted......\n");
			break;
		 case 9:
			start=reverse(start);
			break;
		 case 10:
			 exit(1);
		 default:
			 printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/

struct node *create_list(struct node *start)
{
	int i,n,value;
	struct node *q,*tmp;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	for(i=1;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&value);

		tmp= malloc(sizeof(struct node));
		tmp->info=value;
		tmp->link=NULL;

		if(start==NULL) /*If list is empty */
			start=tmp;
		else
		{       /*Element inserted at the end */
			q=start;
			while(q->link!=NULL)
				q=q->link;
			q->link=tmp;
		}
	}
	return start;
}/*End of create_list()*/

void display(struct node *ptr)
{
	if(ptr==NULL)
		return;
	printf("%d ",ptr->info);
	display(ptr->link);
}/*End of display()*/

void Rdisplay(struct node *ptr)
{
	if(ptr==NULL)
		return;
	Rdisplay(ptr->link);
	printf("%d ",ptr->info);
}/*End of Rdisplay()*/

int length(struct node *ptr)
{
	if(ptr==NULL)
		return 0;
	return 1 + length(ptr->link);

}/*End of length()*/

int sum (struct node *ptr)
{
	if (ptr == NULL)
		return 0;
	return ptr->info + sum(ptr->link);
}/*End of sum()*/

int search(struct node *ptr, int item )
{
	if(ptr==NULL)
		return 0;
	if( ptr->info == item )
		return 1;
	return search(ptr->link, item);
}/*End of search()*/

struct node *insertLast(struct node *ptr, int item)
{
	struct node *temp;
	if (ptr == NULL)
	{
		temp = malloc(sizeof(struct node));
		temp->info = item;
		temp->link = NULL;	
		return temp;
	}
	ptr->link = insertLast(ptr->link, item);
    return ptr;
}/*End of insertLast()*/

struct node *delLast(struct node *ptr )
{
	if( ptr->link == NULL )
	{
		free(ptr);
		return NULL;
	}	
	ptr->link = delLast(ptr->link);
	return ptr;
}/*End of delLast()*/

struct node *reverse(struct node *ptr) 
{ 
	struct node *temp; 
	if( ptr->link == NULL )
		return ptr;
	temp=reverse(ptr->link); 
	ptr->link->link=ptr; 
	ptr->link=NULL; 
	return temp; 
}/*End of reverse()*/

/*Reverse function with printf( ) statements*/
/*
struct node *reverse(struct node *ptr) 
{ 
	struct node *temp; 
	printf(".............................\nCalled for %d \n",ptr->info);
	
	if( ptr->link == NULL )
	{
		printf("\nRecursion stopped : \n");
		return ptr;
	}

	temp=reverse(ptr->link); 
	
	printf("Put address of %d in link part of %d\n", ptr->info, ptr->link->info);  
	ptr->link->link=ptr; 
	printf("Put NULL in link part of %d\n", ptr->info);  
	ptr->link=NULL; 
	printf("Return %d\n\n", temp->info);  
	return temp; 
}
