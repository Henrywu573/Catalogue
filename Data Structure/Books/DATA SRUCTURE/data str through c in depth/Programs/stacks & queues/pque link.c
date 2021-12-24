/*P4.4 Program of queue using linked list*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
}*front=NULL,*rear=NULL;

void insert(int item);
int del();
int peek();
int isEmpty();
void display();

main()
{
	int choice,item;
	while(1)
	{       
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display the element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert(item);
			break;
		case 2:
			printf("Deleted element is  %d\n",del());
			break;
		case 3:
			printf("Element at the front of the queue is %d\n", peek() );
			break;
		case 4:
			display();
			break;
		case 5:
			exit(1);
		default :
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/

void insert(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	tmp->info = item;
	tmp->link=NULL;
	if(front==NULL)		 /*If Queue is empty*/
		front=tmp;
	else
		rear->link=tmp;
	rear=tmp;
}/*End of insert()*/

int del()
{
	struct node *tmp;
	int item;
	if( isEmpty( ) )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	tmp=front;
	item=tmp->info;
	front=front->link;
	free(tmp);
	return item;
}/*End of del()*/

int peek()
{
	if( isEmpty( ) )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return front->info;
}/*End of peek()*/

int isEmpty()
{
	if(front==NULL)
		return 1;
	else
		return 0;

}/*End of isEmpty()*/

void display()
{
	struct node *ptr;
	ptr=front;
	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
	printf("\n\n");
}/*End of display()*/
