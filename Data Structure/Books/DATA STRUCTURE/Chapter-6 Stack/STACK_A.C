/* IMPLEMENTATION OF THE STACK USING ARRAYS */
/* STACK_A.C */

# include<stdio.h>
# include<string.h>
# include<ctype.h>

# define size  100


int top = -1;
int flag = 0;
int stack[size];

void push(int *, int);
int pop(int *);
void display(int *);

/* Definition of the push function */

void push(int s[], int d)
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

/* Definition of the pop function */

int pop(int s[])
{
	int popped_element;
	if(top == -1)
	{
		popped_element = 0;
		flag = 0;
	}
	else
	{
		flag = 1;
		popped_element = s[top];
		--top;
	}
	return (popped_element);
}

/* Definition of the display function */

void display(int s[])
{
	int i;
	if(top == -1)
	{
		printf("\n Stack is empty");
	}
	else
	{
		for(i = top; i >= 0; --i)
			printf("\n %d", s[i] );
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
		printf(" \nPush->i Pop->p Quit->q:");
		printf("\nInput the choice : ");
		do
		{
			choice = getchar();
			choice =tolower(choice);
		}while(strchr("ipq",choice)==NULL);
		printf("Your choice is: %c",choice);

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
			data = pop(stack);
			if(flag)
			{
				printf("\n Data is popped: %d", data);
				printf("\n Rest data in stack is as follows:\n");

				display(stack);
			}
			else
				printf("\n Stack underflow" );
			break;
		case 'q': 
			q = 1;
		}
	} while(!q);
}

