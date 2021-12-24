/* STACK IMPLEMENTATION USING LINKED LIST */
/* STACK_L.C */

# include<stdio.h>
# include<malloc.h>

struct link
{
	int info;
	struct link *next;
} *start;


void display(struct link *);
struct link *push(struct link *);
struct link *pop(struct link *);
int main_menu();

void display(struct link *rec)
{
	while(rec != NULL)
	{
		printf(" %d ",rec->info);
		rec = rec->next;
	}
}

struct link * push(struct link *rec)
{
	struct link *new_rec;
	printf("\n Input the new value for next location of the stack:");

	new_rec = (struct link *)malloc(sizeof(struct link));
	scanf("%d", &new_rec->info);
	new_rec->next = rec;
	rec = new_rec;
	return(rec);
}

struct  link * pop(struct link *rec)
{
	struct link *temp;

	if(rec == NULL)
	{
		printf("\n Stack is empty");
	}
	else
	{
		temp = rec->next;
		free(rec);
		rec = temp;
		printf("\n After pop operation the stack is as follows:\n");
		display(rec);
		if(rec  == NULL)
			printf("\n Stack is empty");
	}
	return(rec);
}

int main_menu ()
{
	int choice;
	do
	{
		printf("\n 1<-Push ");
		printf("\n 2<-Pop");
		printf("\n 3<-Quit");
		printf("\n Input your choice :");
		scanf("%d", &choice);
		if(choice <1 || choice >3)
			printf("\n Incorrect choice-> Try once again");
	} while(choice <1 || choice >3);

	return(choice);
}


/* main function */

void main()
{
	struct link *start ;
	int choice;
	start = NULL;
	do
	{
		choice = main_menu();
		switch(choice)
		{
		case 1:
			start = push(start);
			printf("\n After push operation stack is as follows:\n");
			display(start);
			break;
		case 2:
			start = pop(start);
			break;
		default : 
			printf("\n End of session");
		}
	} while(choice != 3);
}

