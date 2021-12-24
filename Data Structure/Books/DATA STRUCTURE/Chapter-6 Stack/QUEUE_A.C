/* INSERTION AND DELETION IN A QUEUE ARRAY IMPLEMENTATION */
/* queue_a.c */

# include<stdio.h>
# include<string.h>
# include<ctype.h>
# include<stdlib.h>

# define size 10

int rear, front;
int ch;
int q[size];

int rear = 0;
int front = 0;
void Insert_queue();
void Delete_queue();
void Display_queue();

/* Function to create queue */

void  Insert_queue()
{
	printf("\n Input the element :");
	scanf("%d", &ch);
	if(rear < size)
	{
		rear ++;
		q[rear] = ch ;
		if(front == 0)
			front = 1;
	}
	else
		printf("\n Queue is overflow");
}

/* Function to perform delete operation */

void Delete_queue()
{
	if (front == 0)
	{
		printf("\n Underflow");
		return ;
	}
	else
	{
		ch = q[front];

		printf("\n Element deleted : %d", ch);
	}
	if(front == rear)
	{
		front = 0;
		rear = 0;
	}
	else
		front = front + 1;
}

/* Output function */

void Display_queue()  //char q[])
{
	int i;
	if (front == 0)
		return;
	for(i = front ; i <= rear; i++)
		printf(" %d ", q[i]);
}

/* Function main */

void main()
{
	int k = 0;
	char choice;

	do
	{
		printf("\nInsert->i Delete->d Quit->q:");
		printf("\nInput the choice : ");
		do
		{
			choice = getchar();
			choice = tolower(choice);
		}while(strchr("idq",choice)==NULL);
		printf("Your choice is: %c ", choice);

		switch(choice)
		{
		case 'i' :
			Insert_queue();
			printf("\nQueue after inserting ");
			Display_queue();
			break;

		case 'd' : 
			Delete_queue();
			printf("\nQueue content after deleteion is as follows:\n");
			Display_queue();
			break;

		case 'q': 
			k = 1;
		}
	} while(!k);
}
