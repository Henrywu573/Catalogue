/* PEEP OPERATION ON THE STACK USING ARRAYS */
/* PEEPCH.C */

# include<stdio.h>
# include<string.h>
# include<ctype.h>

# define size  100

int top = -1;
int flag = 0;

int stack[100];
int data;

void push(int *, int);
int peep(int *);
void display(int *);

/* Definition of the push function */

void  push(int s[], int d)
{
	if(top ==(size-1))
		flag = 0;
	else
	{
		flag = 1;
		++top;
		s[top] = d;

	}
}

/* Definition of the peep function */

int peep(int s[])
{
	int i;
	int peeped_element;
	printf("\n Input the information number to which you want access:");
	scanf("%d", &i);

	if(top - i + 1 < 0)
	{
		peeped_element = 0;
		flag = 0;
	}
	else
	{
		flag = 1;
		peeped_element = s[top-i +1];
	}
	return (peeped_element);
}

/* Definition of the display function */
void display(int s[])
{
	int i;
	if(top == -1)
	{
		printf("Stack is empty");
	}
	else
	{
		for(i = top; i>=0; --i)
			printf(" %d  ", s[i]);
	}
}

/* Function main */

void main()
{
	int  data;
	char choice;
	int q = 0;
	int top = -1;

	do
	{
		printf(" \nPush->i Peep->p Quit->q:");
		printf("\nInput the choice : ");
		do
		{
			choice = getchar();
			choice =tolower(choice);
		}while(strchr("ipq",choice)==NULL);
		printf("Your choice is: ", choice);

		switch(choice)
		{
		case 'i' :
			printf("\n Input the element to push:");
			scanf("%d", &data);
			push(stack, data);
			if(flag)
			{
				printf("\n After inserting ");
				display(stack);
				if(top == (size-1))
					printf("\n Stack is full");
			}
			else
				printf("\n Stack overflow after pushing");
			break;

		case 'p' : 
			data = peep(stack);
			if(flag)
			{
				printf("\n Data is peeped: %d", data);
				printf("\n Stack is as follows:\n");

				display(stack);
			}
			else
				printf("\n Stack underflow");
			break;
		case 'q': 
			q = 1;
		}
	} while(!q);
}

