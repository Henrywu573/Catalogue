/*
E27 Swap right and left children of a binary tree
E28 Find whether two binary trees are mirror image of each other or not.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};
struct node *insert(struct node *ptr, int ikey);
void display(struct node *ptr,int level);
void SwapChildren(struct node* ptr);
int isIdentical( struct node *p1, struct node *p2);
int isMirrorImage(struct node *root1, struct node *root2);
struct node *Node(int item);

main( )
{
	struct node *root, *root1, *root2, *root3;
	root = Node(32);
	root->lchild = Node(43);
	root->rchild = Node(25);
	root->rchild->lchild = Node(65);
	root->rchild->rchild = Node(14);
	root->lchild->rchild = Node(16);

	display(root,0);
	printf("\n\n");
	SwapChildren(root);
	printf("\n");
	printf("Mirror image of tree is :\n");
	display(root,0);
	printf("\n");

	root1 = Node(32);
	root1->lchild = Node(23);
	root1->rchild = Node(13);
	root1->lchild->rchild = Node(45);
	root1->rchild->lchild = Node(48);

	root2 = Node(42);
	root2->lchild = Node(60);
	root2->rchild = Node(19);
	root2->lchild->rchild = Node(36);
	root2->rchild->lchild = Node(41);
	
	root3 = Node(32);
	root3->lchild = Node(13);
	root3->rchild = Node(23);
	root3->lchild->rchild = Node(48);
	root3->rchild->lchild = Node(45);
	
	if( isMirrorImage(root1, root2))
		printf("Tree 1 is mirror image of tree 2\n");
	else
		printf("Tree 1 is not mirror image of tree 2\n");

	if( isMirrorImage(root1, root3))
		printf("Tree 1 is mirror image of tree 3\n");
	else
		printf("Tree 1 is not mirror image of tree 3\n");

}/*End of main( )*/

struct node *Node(int item)
{  
	struct node* tmp = (struct node *)malloc(sizeof(struct node));  
	tmp->info = item;  
	tmp->lchild = tmp->rchild = NULL;  
	return tmp;  
}

int isMirrorImage(struct node *root1, struct node *root2)
{
	int flag;
	SwapChildren(root1);
	if( isIdentical(root1, root2))
		flag=1;
	else
		flag=0;
	SwapChildren(root1);
	return flag;
}

void SwapChildren(struct node* ptr)
{ 
	struct node* tmp; 
	if (ptr==NULL) 
		return; 
	SwapChildren(ptr->lchild); 
	SwapChildren(ptr->rchild); 
    tmp = ptr->lchild; 
    ptr->lchild = ptr->rchild; 
    ptr->rchild = tmp; 
} 

int isIdentical( struct node *p1, struct node *p2)
{
	if(p1==NULL && p2==NULL)
		return 1;
	if(p1!=NULL && p2!=NULL && p1->info == p2->info)
		if(isIdentical(p1->lchild, p2->lchild) && isIdentical(p1->rchild, p2->rchild))
			return 1;
	return 0;
}

void display(struct node *ptr,int level)
{
	int i;
	if(ptr == NULL )/*Base Case*/
		return;
	else
    {
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->lchild, level+1);
	}
}/*End of display()*/
