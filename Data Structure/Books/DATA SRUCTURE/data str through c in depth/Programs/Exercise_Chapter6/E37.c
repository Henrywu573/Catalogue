/*E37*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};
struct node *insert(struct node *ptr, int ikey);
int height(struct node *ptr);
int isAVL(struct node *ptr);
struct node *insert(struct node *ptr, int ikey );
main( )
{
	struct node *root=NULL,*copy_root=NULL, *root1=NULL;
	root = insert(root, 6);
	root = insert(root, 3);
	root = insert(root, 8);
	root = insert(root, 7);
	root = insert(root, 1);
	root = insert(root, 4);
	root = insert(root, 9);
	root = insert(root, 10);
	root = insert(root, 11);
	if( isAVL(root) )
		printf("AVL\n");
	else
		printf("Not AVL\n");
}/*End of main( )*/

int isAVL(struct node *ptr)  
{  
	int h_l, h_r, diff;
	if(ptr == NULL)  
		return 1;   
	h_l = height(ptr->lchild);  
	h_r = height(ptr->rchild);  
	diff = h_l>h_r ? h_l-h_r : h_r-h_l;
	if( diff<=1 &&  isAVL(ptr->lchild) && isAVL(ptr->rchild) )  
		return 1;  
	return 0;  
}  
   
int height(struct node *ptr)
{
	int h_left, h_right; 

	if (ptr == NULL) /*Base Case*/
		return 0; 

	h_left =  height(ptr->lchild); 
	h_right = height(ptr->rchild); 

	if (h_left > h_right) 
		return 1 + h_left; 
	else 
		return 1 + h_right; 
}/*End of height()*/


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
