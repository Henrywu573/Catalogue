/*
E17 size of a binary tree 
E18 total number of leaf nodes in a binary tree 
E19 minimum height 
E20 Destroy all the nodes of a binary tree.
E21 Display all the ancestors of a node in a binary tree.
E22 Display all root to leaf paths
E23 Display a binary tree from left to right
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

int LeafNodes(struct node *ptr);
int size(struct node *ptr);
int minHt(struct node *p);
struct node *Destroy(struct node *ptr);
void DisplayAncestors(struct node *root, int item);
void displayPaths(struct node* ptr, int path[], int n);
struct node *insert(struct node *ptr, int ikey);
void display(struct node *ptr,int level);

main( )
{
	struct node *root=NULL;
	int item, path[MAX];
	root = insert(root, 16);
	root = insert(root, 3);
	root = insert(root, 19);
	root = insert(root, 20);
	root = insert(root, 1);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 21);
	root = insert(root, 0);
	root = insert(root, 18);
	root = insert(root, 17);
	
	printf("Tree is : \n\n");
	display(root,0);
	printf("\n\n");
	printf("Total number of nodes = %d \n",size(root));
	printf("Leaf nodes are : ");
	printf("\nNumber of Leaf nodes = %d \n",LeafNodes(root));
	printf("Enter an item whose ancestors are to be displayed : ");
    scanf("%d",&item);
	DisplayAncestors(root, item);
	printf("\nAll root to leaf paths are : \n");
	displayPaths(root, path, 0);
	printf("\nMinimum height of tree is %d\n",minHt(root));
	root = Destroy(root);
	display(root,0);
}/*End of main( )*/

int LeafNodes(struct node *ptr)  
{  
	if(ptr == NULL)  
		return 0;  
	if(ptr->lchild == NULL && ptr->rchild==NULL)  
	{
		printf("%d ",ptr->info);	
		return 1;  
	}
	else 
		return LeafNodes(ptr->lchild) +  LeafNodes(ptr->rchild);  
}/*End of LeafNodes()*/  

int size(struct node *ptr)  
{  
	if(ptr == NULL)  
		return 0;  
	else 
		return 1 + size(ptr->lchild) + size(ptr->rchild);  
}/*End of size()*/  

int minHt(struct node *ptr)
{
	int h_left, h_right; 

	if(ptr == NULL) /*Base Case*/
		return 0; 
	
	h_left = minHt(ptr->lchild);
	h_right = minHt(ptr->rchild);
	
	if(h_left==0 && h_right!=0)
		return 1 + h_right;
	if(h_right==0 && h_left!=0)
		return 1 + h_left;
	
	if(h_left < h_right)
		return 1 + h_left;
	else
		return 1 + h_right;
}/*End of minHt()*/

/*this will give shortest path from root to a NULL child and not to a leaf node*/
/*int minHt(struct node *ptr)
{
	int h_left, h_right; 

	if (ptr == NULL) 
		return 0; 
	
	h_left = minHt(ptr->lchild);
	h_right = minHt(ptr->rchild);
	
	if( h_left < h_right )
		return 1 + h_left;
	else
		return 1+ h_right;
}*/

void DisplayAncestors(struct node *ptr, int item)
{
	if( ptr == NULL  || ptr->info==item )
		return;
	if( item < ptr->info )
		DisplayAncestors(ptr->lchild, item);
	else
		DisplayAncestors(ptr->rchild, item);
	printf("%d ",ptr->info);
}/*End of DisplayAncestors()*/

/*Postorder traversal used to destroy nodes*/
struct node *Destroy(struct node *ptr)
{
	if(ptr!=NULL)
	{
		Destroy(ptr->lchild);
		Destroy(ptr->rchild);
		free(ptr);
	}
	return NULL;
}/*End of Destroy()*/

void displayPaths(struct node* ptr, int path[], int n) 
{ 
	int i;
	if(ptr==NULL) 
		return; 
	path[n++] = ptr->info; 
	
	if(ptr->lchild==NULL && ptr->rchild==NULL) 
	{
		for (i=0; i<n; i++) 
			printf("%d ", path[i]); 
		printf("\n"); 
	}	
	else 
	{ 
	    displayPaths(ptr->lchild, path, n); 
		displayPaths(ptr->rchild, path, n); 
	} 
}/*End of displayPaths()*/

struct node *insert(struct node *ptr, int ikey )
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
}/*End of insert( )*/

void display(struct node *ptr,int level)
{
	int i;
	if(ptr == NULL )/*Base Case*/
		return;
	else
    {
		display(ptr->rchild, level+1);
		printf("\n");
		for (i=0; i<level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->lchild, level+1);
	}
}/*End of display()*/
