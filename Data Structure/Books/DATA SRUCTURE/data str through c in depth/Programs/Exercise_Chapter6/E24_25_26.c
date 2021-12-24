/*
E24 Copy of binary tree.
E25 Check whether two binary trees are similar or not.   
E26 Check whether two Binary trees are identical or not. 
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};
struct node *insert(struct node *ptr, int ikey);
int isIdentical(struct node *, struct node *);
struct node *copy_tree(struct node *ptr);
int isSimilar(struct node *p1, struct node *p2);

main()
{
	struct node *root1=NULL, *root2=NULL,*root3=NULL, *root4=NULL;
	
	root1 = insert(root1, 10);
	root1 = insert(root1, 2);
	root1 = insert(root1, 9);
	root1 = insert(root1, 5);
	
	root2 = insert(root2, 6);
	root2 = insert(root2, 3);
	root2 = insert(root2, 8);
	root2 = insert(root2, 7);
	root2 = insert(root2, 1);
	root2 = insert(root2, 4);
			
	root3 = insert(root3, 16);
	root3 = insert(root3, 13);
	root3 = insert(root3, 18);
	root3 = insert(root3, 17);
	root3 = insert(root3, 11);
	root3 = insert(root3, 14);

	
	if(isSimilar(root1,root2))
		printf("Tree 1 and 2 are Similar\n");
	else
		printf("Tree 1 and 2 are Not Similar\n");

	if(isIdentical(root1,root2))
		printf("Tree 1 and 2 are Identical\n");
	else
		printf("Tree 1 and 2 are Not Identical\n");
	
	if(isSimilar(root2,root3))
		printf("Tree 2 and 3 are Similar\n");
	else
		printf("Tree 2 and 3 are Not Similar\n");

	if(isIdentical(root2,root3))
		printf("Tree 2 and 3 are Identical\n");
	else
		printf("Tree 2 and 3 are Not Identical\n");

	root4=copy_tree(root3);
	if(isSimilar(root3,root4))
		printf("Tree 3 and 4 are Similar\n");
	else
		printf("Tree 3 and 4 are Not Similar\n");

	if(isIdentical(root3,root4))
		printf("Tree 3 and 4 are Identical\n");
	else
		printf("Tree 3 and 4 are Not Identical\n");
}/*End of main( )*/

struct node *copy_tree(struct node *ptr)
{
	struct node *copyptr;
	if(ptr == NULL)
		return NULL;
	copyptr=(struct node *)malloc(sizeof(struct node));
	copyptr->info=ptr->info;
	copyptr->lchild=copy_tree(ptr->lchild);
	copyptr->rchild=copy_tree(ptr->rchild);
	return copyptr;
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

int isSimilar(struct node *p1, struct node *p2)
{
	if(p1==NULL && p2==NULL)
		return 1;
	if(p1!=NULL && p2!=NULL)
		if(isSimilar(p1->lchild, p2->lchild) && isSimilar(p1->rchild, p2->rchild))
			return 1;
	return 0;
}

struct node *insert(struct node *ptr, int ikey)
{
	if(ptr==NULL)	
	{
		ptr = (struct node *) malloc(sizeof(struct node));
		ptr->info = ikey;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
	}
	else if(ikey < ptr->info)	/*Insertion in left subtree*/
		ptr->lchild = insert(ptr->lchild, ikey);
	else if(ikey > ptr->info)	/*Insertion in right subtree */
		ptr->rchild = insert(ptr->rchild, ikey);  
	else
		printf("Duplicate key\n");
	return(ptr);
}/*End of insert()*/
