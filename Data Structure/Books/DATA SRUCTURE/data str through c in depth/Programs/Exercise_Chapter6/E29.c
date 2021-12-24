/*
E29 - Find whether a binary tree is binary search tree or not
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};

void display(struct node *ptr,int level);
void inorder(struct node *ptr);
struct node *Node(int item);
int IsBST(struct node *ptr, int MIN, int MAX);

main( )
{
	struct node *root1, *root2;
	
	root1 = Node(32);
	root1->lchild = Node(23);
	root1->rchild = Node(36);
	root1->lchild->rchild = Node(25);
	root1->rchild->lchild = Node(33);

	root2 = Node(42);
	root2->lchild = Node(60);
	root2->rchild = Node(19);
	root2->lchild->rchild = Node(36);
	root2->rchild->lchild = Node(41);

	display(root1,1);
	printf("\n\n");
	inorder(root1);
	printf("\n\n");

	if( IsBST(root1,INT_MIN,INT_MAX) )  
		printf("Tree 1 is a BST\n");
	else
		printf("Tree 1 is not a BST\n");

	display(root2,1);
	printf("\n\n");
	inorder(root2);
	printf("\n\n");

	if( IsBST(root2,INT_MIN,INT_MAX) )  
		printf("Tree 2 is a BST\n");
	else
		printf("Tree 2 is not a BST\n");
}/*End of main( )*/

int IsBST(struct node *ptr, int MIN, int MAX)  
{ 
	if(ptr == NULL) 
		return 1; 
	if(ptr->info < MIN  ||  ptr->info > MAX)
		return 0;
	return ( IsBST(ptr->lchild,MIN,ptr->info) && IsBST(ptr->rchild,ptr->info,MAX)); 
}

struct node *Node(int item)
{  
	struct node* tmp = (struct node *)malloc(sizeof(struct node));  
	tmp->info = item;  
	tmp->lchild = tmp->rchild = NULL;  
	return tmp;  
}/*End of Node()*/

void inorder(struct node *ptr)
{
	if(ptr == NULL )/*Base Case*/
		return;
	inorder(ptr->lchild);
	printf("%d  ",ptr->info);
	inorder(ptr->rchild);
}/*End of inorder( )*/

void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->lchild, level+1);
	}
}/*End of display()*/

