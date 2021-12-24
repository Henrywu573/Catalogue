
/*Demo Program of AVL tree*/

#include <stdio.h>
#include <stdlib.h>

#define STOP getchar()

#define FALSE 0
#define TRUE 1

struct node
{
	struct  node *lchild;
	int info;
	struct  node *rchild;
	int balance;
};

void inorder(struct node *ptr);
void display(struct node *ptr,int level);
struct node *RotateLeft(struct node *pptr);
struct node *RotateRight(struct node *pptr);

struct node *insert(struct node *pptr, int ikey);
struct node *insert_left_check(struct node *pptr, int *ptaller);
struct node *insert_right_check(struct node *pptr, int *ptaller);
struct node *insert_LeftBalance(struct node *pptr);
struct node *insert_RightBalance(struct node *pptr);

struct node *del(struct node *pptr, int dkey);
struct node *del_left_check(struct node *pptr, int *pshorter);
struct node *del_right_check(struct node *pptr, int *pshorter);
struct node *del_LeftBalance(struct node *pptr, int *pshorter);
struct node *del_RightBalance(struct node *pptr, int *pshorter);

main()
{
	int choice,k;
	struct node *root = NULL;
    
	/*Insertion Example given in Book*/
	/*
	root = insert(root,50);display(root,0); printf("\n\n\n");
	root = insert(root,40);display(root,0); printf("\n\n\n");
	root = insert(root,35);display(root,0); printf("\n\n\n");
	root = insert(root,58);display(root,0); printf("\n\n\n");
	root = insert(root,48);display(root,0); printf("\n\n\n");
	root = insert(root,42);display(root,0); printf("\n\n\n");
	root = insert(root,60);display(root,0); printf("\n\n\n");
	root = insert(root,30);display(root,0); printf("\n\n\n");
	root = insert(root,33);display(root,0); printf("\n\n\n");
	root = insert(root,25);display(root,0); printf("\n\n\n");
	*/
	

	/*Deletion Example given in Book*/
	/*
	root = insert(root,48);display(root,0); printf("\n\n\n");
	root = insert(root,33);display(root,0); printf("\n\n\n");
	root = insert(root,58);display(root,0); printf("\n\n\n");
	root = insert(root,30);display(root,0); printf("\n\n\n");
	root = insert(root,40);display(root,0); printf("\n\n\n");
	root = insert(root,50);display(root,0); printf("\n\n\n");
	root = insert(root,60);display(root,0); printf("\n\n\n");
	root = insert(root,25);display(root,0); printf("\n\n\n");
	root = insert(root,35);display(root,0); printf("\n\n\n");
	root = insert(root,42);display(root,0); printf("\n\n\n");
	
	root = del(root,60); display(root,0); printf("\n\n\n");
	root = del(root,48); display(root,0); printf("\n\n\n");
	root = del(root,25); display(root,0); printf("\n\n\n");
	root = del(root,30); display(root,0); printf("\n\n\n");
	root = del(root,35); display(root,0); printf("\n\n\n");
	root = del(root,33); display(root,0); printf("\n\n\n");
	root = del(root,58); display(root,0); printf("\n\n\n");
	*/
	
	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			display(root,0); printf("\n\n");
			printf("Enter the number to be inserted : ");
			scanf("%d",&k);
			if(root!=NULL)
				printf("\nPath is ");		
			root = insert(root,k);
			display(root,0); printf("\n\n");
			break;
		 case 2:
			display(root,0); printf("\n\n");
			printf("Enter the number to be deleted : ");
			scanf("%d",&k);
			if(root->info!=k)
				printf("\nPath is ");		
			root = del(root,k);
			display(root,0); printf("\n\n");
			break;
		 case 3:
			inorder(root);
			break;
		 case 4:
			display(root,0);printf("\n\n");
			break;
		 case 5:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/

struct node *insert(struct node *pptr, int ikey)
{
	static int taller;
	if(pptr==NULL)	/*Base case*/
	{
		pptr = (struct node *) malloc(sizeof(struct node));
		pptr->info = ikey;
		pptr->lchild = NULL;
		pptr->rchild = NULL;
		pptr->balance = 0;
		taller = TRUE;
		STOP;
		printf("\n\nNew node with info = %d inserted, taller = TRUE ", ikey);
		STOP;
		printf("Unwinding Phase starts\n");
	}
	else if(ikey < pptr->info)	/*Insertion in left subtree*/
	{
		printf(" --> %d",pptr->info);
		pptr->lchild = insert(pptr->lchild, ikey);
		if(taller==TRUE)
		{
			printf("\nCheck node %d   ", pptr->info);
			STOP;
			pptr = insert_left_check( pptr, &taller );
		}
	}
	else if(ikey > pptr->info)	/*Insertion in right subtree */
	{
		printf(" --> %d",pptr->info);	
		pptr->rchild = insert(pptr->rchild, ikey);  
		if(taller==TRUE)
		{
			printf("\nCheck node %d   ", pptr->info);
			STOP;
			pptr = insert_right_check(pptr, &taller);
		}	
	}
	else  /*Base Case*/
	{
		printf("\nDuplicate key, taller = FALSE\n");
		printf("Unwinding Phase starts\n");
		taller = FALSE;
	}
	return(pptr);
}/*End of insert( )*/

struct node *insert_left_check(struct node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: /* Case L_A : was balanced */  
		 printf("Case L_A : was balanced now left heavy\n");
		 pptr->balance = 1;	/* now left heavy */
		break;
	 case -1: /* Case L_B: was right heavy */ 
		 printf("Case L_B : was right heavy now balanced\n");
		 pptr->balance = 0;	/* now balanced */
		*ptaller = FALSE;
		printf("taller becomes false, Stop checking\n");
		break;
	 case 1: /* Case L_C: was left heavy */   
		printf("Case L_C : was left heavy now unbalanced, left Balancing required\n");
		printf("Node %d becomes pivot node\n",pptr->info); 
		pptr = insert_LeftBalance(pptr);	/* Left Balancing */
		*ptaller = FALSE;
		printf("taller becomes false, Stop checking\n");
	}
	return pptr;
}/*End of insert_left_check( )*/

struct node *insert_right_check(struct node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0: /* Case R_A : was balanced */	
		printf("Case R_A : was balanced now right heavy\n");
		pptr->balance = -1;	/* now right heavy */
		break;
	 case 1: /* Case R_B : was left heavy */  
		printf("Case L_B : was left heavy now balanced\n");
		 pptr->balance = 0;	/* now balanced */ 
		*ptaller = FALSE;
		printf("taller becomes false, Stop checking\n");
		break;
	 case -1: /* Case R_C: Right heavy */   
		printf("Case R_C : was right heavy now unbalanced, right Balancing required\n"); 
		printf("Node %d becomes pivot node\n",pptr->info); 
		pptr = insert_RightBalance(pptr);	/* Right Balancing */
		*ptaller = FALSE;
		printf("taller becomes false, Stop checking\n");
	}
	return pptr;
}/*End of insert_right_check( )*/

struct node *insert_LeftBalance(struct node *pptr)
{
	struct node *aptr, *bptr;

	aptr = pptr->lchild;
	if(aptr->balance == 1)  /* Case L_C1 : Insertion in AL */ 
	{
		printf("Case L_C1\n");
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else		/* Case L_C2 : Insertion in AR */
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
		case -1:			/* Case L_C2a : Insertion in BR */   
			printf("Case L_C2a\n");
			pptr->balance = 0;
			aptr->balance = 1;
			break;
		case 1:					/* Case L_C2b : Insertion in BL */
			printf("Case L_C2b\n");
			pptr->balance = -1;
			aptr->balance = 0;
			break;
		case 0:					/* Case L_C2c : B is the newly inserted node */ 
			printf("Case L_C2c\n");
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}/*End of insert_LeftBalance( )*/

struct node *insert_RightBalance(struct node *pptr)
{
	struct node *aptr, *bptr;

	aptr = pptr->rchild;
	if(aptr->balance == -1) /* Case R_C1 : Insertion in AR */ 
	{
		printf("Case R_C1\n");
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else		/* Case R_C2 : Insertion in AL */
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
		case -1:	/* Case R_C2a : Insertion in BR */
			printf("Case R_C2a\n");
			pptr->balance = 1;  
			aptr->balance = 0;
			break;
		case 1:		/* Case R_C2b : Insertion in BL */
			printf("Case R_C2b\n");
			pptr->balance = 0;
			aptr->balance = -1;
			break;
		case 0:		/* Case R_C2c : B is the newly inserted node */
			printf("Case R_C2c\n");
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}/*End of insert_RightBalance( )*/

struct node *RotateLeft(struct node *pptr)
{
	struct node *aptr;
	printf("Rotate left about %d\n",pptr->info);
	aptr = pptr->rchild;	/*A is right child of P*/
	pptr->rchild = aptr->lchild; /*Left child of A becomes right child of P */
	aptr->lchild = pptr;  /*P becomes left child of A*/ 
	return aptr;  /*A is the new root of the subtree initially rooted at P*/
}/*End of RotateLeft( )*/

struct node *RotateRight(struct node *pptr)
{
	struct node *aptr;
	printf("Rotate Right about %d\n",pptr->info);
	aptr = pptr->lchild;	/*A is left child of P */
	pptr->lchild = aptr->rchild; /*Right child of A becomes left child of P*/  
	aptr->rchild = pptr;			/*P becomes right child of A*/
	return aptr; /*A is the new root of the subtree initially rooted at P*/
}/*End of RotateRight( )*/

struct node *del(struct node *pptr, int dkey)
{
	struct node *tmp, *succ;
	static int shorter;

	if( pptr == NULL) /*Base Case*/
	{
		printf("\nKey not present, shorter = FALSE\n");
		printf("Unwinding Phase begins\n");
		shorter = FALSE;
		return(pptr);
	}
	if( dkey < pptr->info )
	{
		printf(" --> %d",pptr->info);
		pptr->lchild = del(pptr->lchild, dkey);
		if(shorter == TRUE)
		{
			printf("Check node %d \n",pptr->info); 
			STOP;
			pptr = del_left_check(pptr, &shorter);
			STOP;
		}
	}
	else if( dkey > pptr->info )
	{
		printf(" --> %d",pptr->info);
		pptr->rchild = del(pptr->rchild, dkey);
		if(shorter==TRUE)
		{
			printf("Check node %d \n",pptr->info); 
			STOP;
			pptr = del_right_check(pptr, &shorter);
			STOP;
		}
	}
	else /* dkey == pptr->info, Base Case*/
	{
		printf("\n");
		/*pptr has 2 children*/
		if( pptr->lchild!=NULL  &&  pptr->rchild!=NULL )  
		{
			succ = pptr->rchild;
			while(succ->lchild)
				succ = succ->lchild;
			printf("Successor of Node %d is node %d\n", pptr->info, succ->info);
			printf("Info part of node %d is changed to %d and the successor node is deleted\n", pptr->info, succ->info);
			pptr->info = succ->info;
			
			if( pptr->rchild->info != succ->info )
				printf("Path is ");
			
			pptr->rchild = del(pptr->rchild, succ->info);
			if( shorter == TRUE )
			{
				printf("Check node %d \n",pptr->info); 
				pptr = del_right_check(pptr, &shorter);
				STOP;
			}
		}
		else	
		{
			tmp = pptr;
			if( pptr->lchild != NULL ) /*only left child*/
				pptr = pptr->lchild;
			else if( pptr->rchild != NULL) /*only right child*/
				pptr = pptr->rchild;
			else	/* no children */
				pptr = NULL;
			free(tmp);
			shorter = TRUE;
			printf("Node deleted, shorter = TRUE\n");
		}						
	}
	return pptr; 
}/*End of del( )*/

struct node *del_left_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0: /* Case L_A : was balanced */       
			printf("Case L_A, was balanced, now right heavy\n");
			pptr->balance = -1;	/* now right heavy */ 
			*pshorter = FALSE;
			printf("shorter = FALSE, stop checking\n");
			break;
		case 1: /* Case L_B : was left heavy */	 
			printf("Case L_B, was left heavy, now balanced\n");
			pptr->balance = 0;	/* now balanced */
			break;            
		case -1: /* Case L_C : was right heavy */   
			printf("Case L_C, was right heavy, now unbalanced, Right balancing required\n");
			printf("Pivot node is %d\n",pptr->info); 
			pptr = del_RightBalance(pptr, pshorter); /*Right Balancing*/
	}
	return pptr;
}/*End of del_left_check( )*/

struct node *del_right_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0:		/* Case R_A : was balanced */		
			printf("Case R_A, was balanced, now left heavy\n");
			pptr->balance = 1;	/* now left heavy */
			*pshorter = FALSE;
			printf("shorter = FALSE, stop checking\n");
			break;
		case -1: /* Case R_B : was right heavy */	
			printf("Case R_B, was right heavy, now balanced\n");
			pptr->balance = 0;	/* now balanced */
			break;
		case 1: /* Case R_C : was left heavy */	
			printf("Case R_C, was left heavy, now unbalanced, Left balancing required\n");
			printf("Pivot node is %d\n",pptr->info); 
			pptr = del_LeftBalance(pptr, pshorter );  /* Left Balancing */
	}
	return pptr;
}/*End of del_right_check( )*/

struct node *del_LeftBalance(struct node *pptr,int *pshorter)
{
	struct node *aptr, *bptr;
	aptr = pptr->lchild;
	if( aptr->balance == 0)  /* Case R_C1 */
	{
		printf("Case R_C1\n");
		pptr->balance = 1;
		aptr->balance = -1;
		*pshorter = FALSE;
		pptr = RotateRight(pptr);
		printf("shorter = FALSE, stop checking\n");
	}
	else if(aptr->balance == 1 ) /* Case R_C2 */
	{
		printf("Case R_C2\n");
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else						/* Case R_C3 */
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
			case 0:					/* Case R_C3a */
				printf("Case R_C3a\n");
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:					/* Case R_C3b */
				printf("Case R_C3b\n");
				pptr->balance = -1;		
				aptr->balance = 0;
				break;
			case -1:			/* Case R_C3c */
				printf("Case R_C3c\n");
				pptr->balance = 0;	
				aptr->balance = 1;
		}
		bptr->balance = 0;			
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}/*End of del_LeftBalance( )*/
struct node *del_RightBalance(struct node *pptr,int *pshorter)
{
	struct node *aptr, *bptr;

	aptr = pptr->rchild;
	if (aptr->balance == 0)	/* Case L_C1 */ 
	{
		printf("Case L_C1\n");
		pptr->balance = -1;
		aptr->balance = 1;
		*pshorter = FALSE;
		pptr = RotateLeft(pptr);			
		printf("shorter = FALSE, stop checking\n");
	}
	else if(aptr->balance == -1 )	/* Case L_C2 */ 
	{
		printf("Case L_C2\n");
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);			
	}
	else							/* Case L_C3 */
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
			case 0:					/* Case L_C3a */
				printf("Case L_C3a\n");
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:					/* Case L_C3b */ 
				printf("Case L_C3b\n");
				pptr->balance = 0;
				aptr->balance = -1;
				break;
			case -1:				/* Case L_C3c */
				printf("Case L_C3c\n");
				pptr->balance = 1;
				aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}/*End of del_RightBalance( )*/

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}/*End of inorder()*/

void display(struct node *ptr,int level)
{
	int i;
	if(ptr!=NULL)
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		if(ptr->balance == 1)
			printf("+");
		else if(ptr->balance == -1)
			printf("-");
		else
			printf("*");
		display(ptr->lchild, level+1);
	}
}/*End of display()*/




