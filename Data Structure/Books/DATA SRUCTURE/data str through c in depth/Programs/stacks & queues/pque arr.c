/*P4.3 Program of queue using array*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue_arr[MAX];
int rear=-1;
int front=-1;

void insert(int item);
int del();
int peek();
void display();
int isFull();
int isEmpty();

main()
{
	int choice,item;
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("Input the element for adding in queue : ");
			scanf("%d",&item);
			insert(item);
			break;
		case 2:
			item=del();
			printf("Deleted element is  %d\n",item);
			break;
		case 3:
			printf("Element at the front is %d\n",peek());
			break;
		case 4:
			display();
			break;
		case 5:
			exit(1);
		default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/

void insert(int item)
{
	if( isFull() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if( front == -1 )  
		front=0;
	rear=rear+1;
	queue_arr[rear]=item ;
}/*End of insert()*/

int del()
{
	int item;
	if( isEmpty() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	item=queue_arr[front];
	front=front+1;
	return item;
}/*End of del()*/

int peek()
{
	if( isEmpty() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return queue_arr[front];
}/*End of peek()*/

int isEmpty()
{
	if( front==-1 || front==rear+1 )
		return 1;
	else
		return 0;
}/*End of isEmpty()*/

int isFull()
{
	if( rear==MAX-1 )
		return 1;
	else
		return 0;
}/*End of isFull()*/

void display()
{
	int i;
	if ( isEmpty() )
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue is :\n\n");
	for(i=front;i<=rear;i++)
		printf("%d  ",queue_arr[i]);
	printf("\n\n");
}/*End of display() */
