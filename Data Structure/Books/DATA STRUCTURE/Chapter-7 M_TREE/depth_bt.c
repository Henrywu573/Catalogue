/*  Finding Depth of Binary Tree */
/* DEPTH_BT.C */

# include<stdio.h>
# include<malloc.h>

struct NODE
{
	char Info;
	struct NODE *Left_Child;
	struct NODE *Right_Child;
};

int depth = 0;

void Output (struct NODE *, int );
int Depth (struct NODE *, int );
struct NODE *Create_Tree (char , struct NODE *);

/* Output function */

void Output(struct NODE *T, int Level)
{
	int i;
	if (T)
	{
		Output(T->Right_Child, Level+1);
		printf("\n");
		for (i = 0; i < Level; i++)
			printf("  ");
		printf("%c", T->Info);
		Output(T->Left_Child, Level+1);
	}
}

/* Find depth of the tree */

int Depth (struct NODE *Node, int Level)
{
	if (Node != NULL)
	{
		if (Level > depth)
			depth = Level;
		Depth (Node->Left_Child, Level + 1);
		Depth (Node->Right_Child, Level + 1);
	}
	return (depth);
}

/*  Create binary tree */

struct NODE *  Create_Tree (char Info, struct NODE *Node)
{

	if (Node == NULL)
	{
		Node = (struct NODE *) malloc(sizeof(struct NODE));
		Node->Info = Info;
		Node->Left_Child = NULL;
		Node->Right_Child = NULL;
		return (Node);
	}

	/* Test for the left child */

	if (Info < Node->Info)

		Node->Left_Child = Create_Tree (Info, Node->Left_Child);

	else

		/*  Test for the right child */

		if (Info > Node->Info)

			Node->Right_Child = Create_Tree (Info, Node->Right_Child);
	return(Node);
}

/* Function main */

void main()
{
	int Number = 0;
	char Info ;
	char choice;
	int depth;
	struct NODE *T = (struct NODE *) malloc(sizeof(struct NODE));
	T = NULL;
	printf("\n Input choice 'b' to break:");
	choice = getchar();

	while(choice != 'b')
	{
		fflush(stdin);
		printf("\n Input information of the node: ");
		scanf("%c", &Info);
		T = Create_Tree(Info, T);
		Number++;
		fflush(stdin);
		printf("\n Input choice 'b' to break:");
		choice = getchar();
	}
	printf("\n Number of elements in the list is  %d", Number);
	printf("\n Tree is \n");
	Output(T, 1);

	depth = Depth(T, 0);
	printf("\n Depth of the above tree is:  %d", depth);
}

