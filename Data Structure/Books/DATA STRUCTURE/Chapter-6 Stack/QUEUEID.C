/* INSERTION AND DELETION IN A CIRCULAR QUEUE ARRAY IMPLEMENTATION */
/* QUEUEID.C */

# include<stdio.h>
# include<string.h>
# include<ctype.h>
# include<stdlib.h>

# define size 6

int L, U;  /* L means lower bound U means upper bound */

int rear, front;
int ch;
int q[size];

int rear = -1;
int front = -1;
void Insert_queue();
void Delete_queue();
void Display_queue();


/* Function to create queue */

void Insert_queue()
{
	if ((front == 0) && (rear == size-1))
	{
		printf("\n Overflow");
		rear = 1;
		return;
	}
	else
		if (front < 0) /* Insert first element */
		{
			front = 0;
			rear = 0;
			printf("\nInput the element :");
			scanf("%d", &ch);
			q[rear] = ch ;
		}
		else
			if (rear == size-1)
			{
				rear = 0;
				printf("\n Input the element :");
				scanf("%d", &ch);
				q[rear] = ch ;
			}

			else
			{
				rear ++;
				printf("\n Input the element :");
				scanf("%d", &ch);
				q[rear] = ch ;
			}
}

/* Function to perform delete operation */

void Delete_queue()
{
	if (front < 0)
	{
		printf("\nUnderflow");
		return ;
	}
	ch = q[front];
	q[front] = NULL;
	printf("\n Element deleted :", ch);
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
		if ( front == size-1)
		{
			front = 0;
		}
		else
		{
			front++ ;
		}

}

/* Output function */

void Display_queue()
{
	int i;
	if (front < 0)
		return;
	if ( rear >= front)
	{
		for(i = front; i <= rear; i++)
		{
			printf("\n i = %d", i);
			printf(" %d ", q[i]);
		}
	}
	else
	{
		for(i = front; i < size; i++)
		{
			printf("\n i = %d", i);
			printf(" %d", q[i]);
		}
		for(i = 0; i <= rear; i++)
		{
			printf("\n i = %d", i);
			printf(" %d ", q[i]);
		}
	}
}

/* Function main  */

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
		printf("Your choice is: %c",choice);

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