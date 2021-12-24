/* Create TREE */
/* CREAT_T.C */

# include<stdio.h>
# include<malloc.h>

struct NODE
{
	int Info;
	struct NODE *Left_Child;
	struct NODE *Right_Child;
};

struct NODE *Create_Tree (int , struct NODE *);
void Output(struct NODE *, int );


/* Function to create a tree */

struct NODE * Create_Tree (int Info, struct NODE *Node)
{
	if (Node == NULL)
	{
		Node = (struct NODE *) malloc( sizeof(struct NODE ));
		Node->Info = Info;
		Node->Left_Child = NULL;
		Node->Right_Child = NULL;
		return (Node);
	}

	/* Test for the left child */
	if (Node->Info >= Info )
		Node->Left_Child = Create_Tree (Info, Node->Left_Child);
	else

		/* Set all the rest of the elements as right child */

		Node->Right_Child = Create_Tree (Info, Node->Right_Child);
	return(Node);
}

/* Output function */

void  Output(struct NODE *T, int Level)
{
	int i;
	if (T)
	{
		Output(T->Right_Child, Level+1);
		printf("\n ");
		for (i = 0; i < Level; i++)
			printf("   ");
		printf("%d", T->Info);
		printf("\n");
		Output(T->Left_Child, Level+1);
	}
}

/* Function main */

void main()
{
	int Info ;
	char choice;
	struct NODE *T = (struct NODE *) malloc(sizeof(struct NODE *));
	T = NULL;
	printf("\n Input choice 'b' to break:");
	choice = getchar();
	while(choice != 'b')
	{
		printf("\n Input information of the node: ");
		scanf("%d", &Info);
		T = Create_Tree (Info, T);
		printf("\n Tree is ");
		Output(T, 1);
		printf("\n Input choice 'b' to break:");
		choice = getchar();
	}
}

