
/*Recursive operations in Binary Search Tree*/
/*display() function displays the tree from left to right instead of top to bottom
root is displayed at the leftmost position*/

#include<stdio.h>
#include<stdlib.h>
#define STOP getchar()

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};

struct node *search(struct node *ptr, int skey);
struct node *insert(struct node *ptr, int ikey);
struct node *del(struct node *ptr, int dkey);

int height(struct node *ptr);
struct node *minimum(struct node *ptr);
struct node *maximum(struct node *ptr);
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
int height(struct node *ptr);
void display(struct node *ptr,int level);

main( )
{
	struct node *root=NULL,*ptr;
	int choice,k;

	while(1)
	{
		printf("\n");
		printf("1.Search\n");
		printf("2.Insert\n");
		printf("3.Delete\n");
		printf("4.Preorder Traversal\n");
		printf("5.Inorder Traversal\n");
		printf("6.Postorder Traversal\n");
		printf("7.Height of tree\n");
		printf("8.Find minimum and maximum\n");
		printf("9.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		printf("\nTree is -->\n.......................\n\n");
		display(root,0);
		printf("\n\n.......................\n\n");

		switch(choice)
		{
		case 1: 
			printf("Enter the key to be searched : ");
			scanf("%d",&k);
			ptr = search(root, k);
			if(ptr==NULL)
				printf("Key not present\n");
			else
				printf("Key present\n");
			break;
		case 2:
			printf("Enter the key to be inserted : ");
			scanf("%d",&k);
			printf("\nInserting %d\n\n",k);
			root = insert(root, k);
			break;
		case 3:
			printf("Enter the key to be deleted : ");
			scanf("%d",&k);
			root = del(root,k);
			break;
		 case 4:
			preorder(root);
			break;
		 case 5:
			inorder(root);
			break;
		 case 6:
			postorder(root);
			break;
		 case 7:
			 printf("Height of tree is %d\n", height(root));
			 break;
		 case 8:
			ptr = minimum(root);
			if(ptr!=NULL)
				printf("Minimum key is %d\n", ptr->info );
			ptr = maximum(root); 	
			if(ptr!=NULL)
				printf("Maximum key is %d\n", ptr->info );
			break;
		 case 9:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main( )*/

struct node *search(struct node *ptr, int skey)
{
	
	if(ptr!=NULL)
		printf("search() fn called for ptr = Address of %d\n", ptr->info);
	STOP;
	
	if(ptr==NULL)	
	{	
		printf("search() fn called for ptr = NULL\n");
		printf("Base Case 1 Reached, Recursion stops\n");
		printf("key %d is not found in the tree\n", skey);
		return NULL;
	}
	else if(skey < ptr->info)/*search in left subtree*/	
	{
		printf("Search in left subtree of %d\n",ptr->info);
		return search(ptr->lchild, skey);	
	}
	else if(skey > ptr->info)/*search in right subtree*/
	{
		printf("Search in left subtree of %d\n",ptr->info);
		return search(ptr->rchild, skey);
	}

	else 
	{
		printf("Base Case 2 Reached, Recursion stops\n");
		printf("key %d found in the tree\n", skey);
		return ptr;
	}

}

struct node *insert(struct node *ptr, int ikey )
{
	
	if(ptr!=NULL)
		printf("insert() fn called for ptr = Address of %d\n", ptr->info);
	STOP;
	if(ptr==NULL)	
	{
		printf("insert() fn called for ptr = NULL \n");
		printf("Base Case 1 Reached, Recursion stops\n");
		printf("key %d is not in the tree and so it can be inserted\n", ikey);
		ptr = (struct node *) malloc(sizeof(struct node));
		ptr->info = ikey;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		printf("Now ptr points to %d\n",ptr->info); 
		STOP;
		printf("Unwinding phase begins and all recursive calls are returned\n");
	}
	else if(ikey < ptr->info)	/*Insertion in left subtree*/
	{	
		printf("Insertion to be done in left subtree of %d\n",ptr->info);
		ptr->lchild = insert(ptr->lchild, ikey);
		printf("ptr points to %d and its left child is assigned address of %d\n",ptr->info, ptr->lchild->info);
	}
	else if(ikey > ptr->info)				/*Insertion in right subtree */
	{
		printf("Insertion to be done in right subtree of %d\n",ptr->info);
		ptr->rchild = insert(ptr->rchild, ikey);  
		printf("ptr points to %d and its right child is assigned address of %d\n", ptr->info, ptr->rchild->info);
	}
	else
	{
		printf("Base Case 2 Reached, Recursion stops");
        printf("\nkey %d is already present, can't be inserted\n",ikey);
		STOP;
		printf("Unwinding phase begins and all recursive calls are returned\n");
	}
	STOP;
	printf("Returning address of %d\n\n", ptr->info);
	return(ptr);
}/*End of insert( )*/

struct node *del(struct node *ptr, int dkey)
{
	struct node *tmp, *succ;

	if( ptr == NULL)
	{
		printf("dkey not found\n");
		return(ptr);
	}
	if( dkey < ptr->info )/*delete from left subtree*/
		ptr->lchild = del(ptr->lchild, dkey);
	else if( dkey > ptr->info )/*delete from right subtree*/
		ptr->rchild = del(ptr->rchild, dkey);
	else
	{
		/*Node to be deleted is found*/
		if( ptr->lchild!=NULL  &&  ptr->rchild!=NULL )  /*2 children*/
		{
			succ=ptr->rchild;
			while(succ->lchild)
				succ=succ->lchild;
			ptr->info=succ->info;
			ptr->rchild = del(ptr->rchild, succ->info);
		}
		else	
		{
			tmp = ptr;
			if( ptr->lchild != NULL ) /*only left child*/
				ptr = ptr->lchild;
			else if( ptr->rchild != NULL) /*only right child*/
				ptr = ptr->rchild;
			else	/* no child */
				ptr = NULL;
			free(tmp);
		}						
	}
	return ptr; 
}/*End of del( )*/

struct node *minimum(struct node *ptr)
{
	if(ptr==NULL)
		return NULL;
	else if(ptr->lchild==NULL)
        return ptr;
	else 
		return minimum(ptr->lchild);
}/*End of minimum()*/

struct node *maximum(struct node *ptr)
{
	if(ptr==NULL)	
		return NULL;
	else if(ptr->rchild==NULL)
        return ptr;
	else 
		return maximum(ptr->rchild);
}/*End of maximum()*/

void preorder(struct node *ptr)
{
	if(ptr == NULL )	/*Base Case*/
		return;
	else
	{
		printf("%d  ",ptr->info);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}/*End of preorder( )*/

void inorder(struct node *ptr)
{
	if(ptr == NULL )/*Base Case*/
		return;
	else
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}/*End of inorder( )*/

void postorder(struct node *ptr)
{
	if(ptr == NULL )/*Base Case*/
		return;
	else
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ",ptr->info);
	}
}/*End of postorder( )*/

int height(struct node *ptr)
{
	int h_left, h_right; 

	if (ptr == NULL) /*Base Case*/
		return 0; 
	
	h_left =  height(ptr->lchild); 
	printf("Height of left subtree of %d is %d\n", ptr->info, h_left);
	
	h_right = height(ptr->rchild); 
	printf("Height of right subtree of %d is %d\n", ptr->info, h_right);
	
	if (h_left > h_right) 
	{
		printf("Height of tree %d is %d\n", ptr->info, 1 + h_left);
		return 1 + h_left; 
	}
	else 
	{
		printf("Height of subtree %d is %d\n", ptr->info, 1 + h_right);
		return 1 + h_right; 
	}
}/*End of height()*/

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
