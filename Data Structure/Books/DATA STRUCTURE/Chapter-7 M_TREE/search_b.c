/* Searching Binary Tree */
/* SEARCH_B.C */

# include<stdio.h>
# include<malloc.h>

struct NODE
{
	char Info;
	struct NODE *Left_Child;
	struct NODE *Right_Child;
};

int flag = 0;
struct NODE *Binary_Tree (char *, int, int);
void Output(struct NODE *, int );
int Search_Node(struct NODE *, char);

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
		printf("%c", T->Info);
		Output(T->Left_Child, Level+1);
	}
}

/* Insert a node in the tree */

int Search_Node(struct NODE *Node, char Info)
{
	while (Node != NULL)
	{
		if (Node->Info == Info)
		{
			flag = 1;
			return(flag);
		}
		else
			if(Info < Node->Info)
			{
				Node = Node->Left_Child;
			}
			else
			{
				Node = Node->Right_Child;
			}
	}
	return(flag);
}

/* Function main */

void main()
{
	int flag;
	char List[100];
	int Number = 0;
	char Info ;
	char choice;
	struct NODE *T = (struct NODE *) malloc(sizeof(struct NODE));
	T = NULL;
	printf("\n Input choice 'b' to break:");
	choice = getchar();
	while(choice != 'b')
	{
		fflush(stdin);
		printf("\n Input information of the node: ");
		scanf("%c", &Info);
		List[Number++] = Info;
		fflush(stdin);
		printf("\n Input choice 'b' to break:");
		choice = getchar();
	}
	Number --;
	printf("\n Number of elements in the list is %d", Number+1);
	T = Binary_Tree(List, 0, Number);
	printf("\n Tree is \n");
	Output(T, 1);
	fflush(stdin);
	printf("\n Input the information of the node to which want to search: ");
	scanf("%c", &Info);
	flag = Search_Node(T, Info);
	if (flag)
	{
		printf("\n Search is successful \n");
	}
	else 
		printf("Search unsuccessful");
}

