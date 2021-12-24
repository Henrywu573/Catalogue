/*
E30 number of nodes at a level. 
E31 width of a binary tree.
E32 display nodes on a level from right to left. 
E33 traverse a tree in spiral order
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
int NodesAtLevel(struct node *ptr, int level) ;
int height(struct node *ptr);
void SpiralOrder(struct node* root);  
void displayLevel_RtoL(struct node* root, int level);
void displayLevel_LtoR(struct node* root, int level);  
int Width(struct node *ptr);

main( )
{
	struct node *root=NULL;

	root = insert(root, 6);
	root = insert(root, 3);
	root = insert(root, 8);
	root = insert(root, 7);
	root = insert(root, 1);
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 9);
	root = insert(root, 10);
	root = insert(root, 11);
	
	display(root,0);
	printf("\n");
	displayLevel_LtoR(root,2);
	printf("\n");
	displayLevel_RtoL(root,2);
	printf("\n");
	SpiralOrder(root);  
	printf("\n");
	printf("\n");
	printf("Width of tree = %d\n",Width(root));
}/*End of main( )*/

int NodesAtLevel(struct node *ptr, int level) 
{
	if(ptr==NULL)
		return 0;
	if(level==0) 
		return 1;
	return NodesAtLevel(ptr->lchild,level-1) + NodesAtLevel(ptr->rchild,level-1);
}/*End of NodesAtLevel()*/

int Width(struct node *root)
{
	int i, n, max = 0; 
	for(i=0; i<height(root); i++)	
		if( (n=NodesAtLevel(root,i)) > max )
			max = n; 
	return max;	
}/*End of Width()*/

/*Displays nodes on a level from left to right*/
void displayLevel_LtoR(struct node* ptr, int level)  
{  
	if(ptr == NULL)  
		return;  
	if(level == 0)  
		printf("%d ", ptr->info);  
	displayLevel_LtoR(ptr->lchild, level-1); 
	displayLevel_LtoR(ptr->rchild, level-1);  
}/*End of displayLevel_LtoR()*/ 

/*Displays nodes on a level from right to left*/
void displayLevel_RtoL(struct node* ptr, int level)  
{  
	if(ptr == NULL)  
		return;  
	if(level == 0)  
		printf("%d ", ptr->info);  
	displayLevel_RtoL(ptr->rchild, level-1);  
	displayLevel_RtoL(ptr->lchild, level-1);
}/*End of displayLevel_RtoL()*/  

void SpiralOrder(struct node* root)  
{  
	int i,h = height(root);  
	for(i=0; i<height(root); i++)	
		if(i%2==0)
			displayLevel_LtoR(root,i);
		else
			displayLevel_RtoL(root,i);
}/*End of SpiralOrder()*/       

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

   
     
