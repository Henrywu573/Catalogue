/* UPDATING A STACK IMPLEMENTED WITH THE HELP OF ARRAYS.*/
/* UPDATE.C */

# include<stdio.h>
# include<string.h>
# include<ctype.h>

# define size  100

int top = -1;
int flag = 0;

int stack[100];
int data;

void push (int *, int);
int update (int *);
void display (int *);

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

int update(int s[])
{
	int i;
	int update_element;
	printf("\n Input the information number to which you want to update: ");
	scanf("%d", &i);

	if(top - i + 1 < 0)
	{
		update_element = 0;
		flag = 0;
	}
	else
	{
		flag = 1;
		update_element = s[top-i +1];
		printf("\n Input the new value: ");
		scanf("%d", &s[top-i+1]);
	}
	return (update_element);
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
			printf("  %d", s[i]);
	}
}

void main()
{
	int stack[size];
	int  data;
	char choice;
	int q = 0;
	int top = -1;

	do
	{
		printf(" \nPush->i Update->u Quit->q: ");
		printf("\nInput the choice : ");
		do
		{
			fflush(stdin);
			choice = getchar();
			choice = tolower(choice);
		}while(strchr("iuq",choice)==NULL);
		printf("Your choice is -> %c", choice);

		switch(choice)
		{
		case 'i' :
			printf("\n Input the element to pushed: ");
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

		case 'u' : 
			data = update(stack);
			if(flag)
			{
				printf("\n Data is peepped: %d", data);
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