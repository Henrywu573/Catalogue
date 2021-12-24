/* Binary tree traversal */
/* BT_TRAV.C */

# include<stdio.h>

struct NODE
{
	char Info;
	struct NODE *Left_Child;
	struct NODE *Right_Child;
};

struct NODE *Binary_Tree (char *, int, int);
void Output(struct NODE *, int );
void Pre_order(struct NODE *);
void In_order(struct NODE *);
void Post_order(struct NODE *);

/* Function to create an binary tree */

struct NODE *  Binary_Tree (char *List, int Lower, int Upper)
{
	struct NODE *Node;
	int Mid = (Lower + Upper)/2;
	Node = (struct NODE*) malloc(sizeof(struct NODE));

	Node->Info = List [Mid];
	if ( Lower>= Upper)
	{
		Node->Left_Child = NULL;
		Node->Right_Child = NULL;
		return (Node);
	}

	if (Lower <= Mid - 1)
		Node->Left_Child = Binary_Tree (List, Lower, Mid - 1);
	else
		Node->Left_Child = NULL;
	if (Mid + 1 <= Upper)
		Node->Right_Child = Binary_Tree (List, Mid + 1, Upper);
	else
		Node->Right_Child = NULL;
	return(Node);
}

/* Output function */

void Output(struct NODE *T, int Level)
{
	int i;
	if (T)
	{
		Output(T->Right_Child, Level+1);
		printf("\n");
		for (i = 0; i < Level; i++)
			printf("   ");
		printf(" %c", T->Info);
		Output(T->Left_Child, Level+1);
	}
}

/* Pre-order traversal */

void Pre_order (struct NODE *Node)
{
	if (Node)
	{
		printf(" %c", Node->Info);
		Pre_order(Node->Left_Child);
		Pre_order(Node->Right_Child);
	}
}

/* In-order traversal */

void In_order (struct NODE *Node)
{
	if (Node)
	{
		In_order(Node->Left_Child);
		printf(" %c", Node->Info);
		In_order(Node->Right_Child);
	}
}

/* Post-order traversal */

void Post_order (struct NODE *Node)
{
	if (Node)
	{
		Post_order(Node->Left_Child);
		Post_order(Node->Right_Child);
		printf(" %c", Node->Info);
	}
}

/*  Function main */

void main()
{
	char List[100];
	int Number = 0;
	char Info;
	char choice;
	struct NODE *T = (struct NODE *) malloc(sizeof(struct NODE));
	T = NULL;
	printf("\n Input choice 'b' to break:");
	choice = getchar();
	fflush(stdin);
	while(choice != 'b')
	{
		printf("\n Input information of the node: ");
		scanf("%c", &Info);
		List[Number++] = Info;
		fflush(stdin);
		printf("\n Input choice 'b' to break:");
		choice = getchar();
		fflush(stdin);
	}
	Number --;
	printf("\n Number of elements in the list is %d", Number);
	T = Binary_Tree(List, 0, Number);
	Output(T,1);
	printf("\n Pre-order traversal\n");
	Pre_order (T);
	printf("\n In-order traversal\n");
	In_order (T);
	printf("\n Post-order traversal\n");
	Post_order (T);
}

