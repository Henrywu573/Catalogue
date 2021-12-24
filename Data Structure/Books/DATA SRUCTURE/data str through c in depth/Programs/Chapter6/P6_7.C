/*P6.7 Program of Red black tree*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	enum {black, red} color;
	int info;
	struct  node *lchild;
	struct  node *rchild;
	struct  node *parent;
};

int find(int item,struct node **loc);
void insert (int);
void insert_balance(struct node *nptr );
void del(int);
void del_balance(struct node *ptr);
void RotateLeft(struct node *ptr);
void RotateRight(struct node *ptr);
struct node *succ(struct node *ptr);
void inorder(struct node *ptr);
void display(struct node *ptr,int level);

struct node *root;
struct node *sentinel;/*will be parent of root node and replace NULL */

main()
{
	int choice,num;
	
	sentinel = (struct node *) malloc(sizeof(struct node));
	sentinel->info = -1;
	sentinel->color = black;	
	root = sentinel;

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
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num);
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		 case 3:
			inorder(root);
			break;
		 case 4:
			display(root,0);
			break;
		 case 5:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/

int find(int item,struct node **loc)
{
	struct node *ptr;

	if(root==sentinel)/*Tree is empty*/
	{
		*loc=sentinel;
		return 0;
	}

	if(item==root->info)/*Item is at root*/
	{
		*loc=root;
		return 1;
	}

	/*Initialize ptr*/
	if(item < root->info)
		ptr=root->lchild;
	else
		ptr=root->rchild;

	while(ptr!=sentinel)
	{
		if(item == ptr->info)
		{       
			*loc=ptr;
			return 1;
		}
		if(item < ptr->info)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	 }//End of while
	 *loc=sentinel;		/*Item not found*/
	 return 0;
}/*End of find()*/

void insert (int ikey )
{
	struct node *tmp, *ptr, *par;
	
	par = sentinel;
	ptr = root;

	while( ptr != sentinel )
	{
		par = ptr;
		if( ikey < ptr->info )
			ptr = ptr->lchild;
		else if( ikey > ptr->info )
			ptr = ptr->rchild;
		else
		{
			printf("Duplicate\n");
			return;
		}
	}
	tmp = (struct node *) malloc(sizeof(struct node));
	tmp->info = ikey;
	tmp->lchild = sentinel;
	tmp->rchild = sentinel;
	tmp->color = red;
	tmp->parent = par;
	
	if(par==sentinel)
		root = tmp;
	else if(tmp ->info < par->info )
		par->lchild = tmp;
	else 
		par->rchild = tmp;
	
	insert_balance(tmp);
}/*End of insert( )*/

void insert_balance(struct node *nptr )
{
	struct node *uncle, *par, *grandPar;
	
	while( nptr->parent->color == red )
	{
		par = nptr->parent;
		grandPar = par->parent;
		
		if( par == grandPar->lchild )
		{
			uncle = grandPar->rchild; 
	
			if(uncle->color == red )	/* Case L_1 */
			{
				par->color = black;
				uncle->color = black;
				grandPar->color =red;
				nptr = grandPar;
			}
			else	/* Uncle is black */
			{
				if( nptr == par->rchild) /* Case L_2a */
				{
					RotateLeft(par);
					nptr = par;
					par = nptr->parent;
				}
				par->color = black;	 /* Case L_2b */
				grandPar->color = red;
				RotateRight(grandPar);
			}
		}
		else 
		{
			if(par == grandPar->rchild )
			{
				uncle = grandPar->lchild;  
				
				if(uncle->color == red )  /* Case R_1 */
				{
					par->color = black;
					uncle->color = black;
					grandPar->color =red;
					nptr = grandPar;
				}
				else	/*uncle is black */ 
				{
					if( nptr == par->lchild)   /* Case R_2a */
					{
						RotateRight(par);
						nptr = par;
						par = nptr->parent;
					}
					par->color = black;    /* Case R_2b */
					grandPar->color = red;
					RotateLeft(grandPar);
				}
			}
		}
	}
	root->color = black;
}/*End of insert_balance()*/

void del(int item)
{
	struct node *child,*ptr,*successor;
    
	if( ! find(item, &ptr) )
	{
		printf("item not present \n");
		return;
	}

	if(ptr->lchild != sentinel || ptr->rchild != sentinel )
	{
		successor = succ(ptr);
		ptr->info = successor->info;
		ptr=successor;
	}
		
	if( ptr->lchild !=sentinel )
		child = ptr->lchild;
	else
		child = ptr->rchild;
	
	child->parent = ptr->parent;
	
	if(ptr->parent == sentinel)
		root=child;
	else if( ptr == ptr->parent->lchild )
		ptr->parent->lchild = child;
	else 
		ptr->parent->rchild = child;
			
	if( child == root )
		child->color = black;
    else if( ptr->color == black )/*black node*/  
	{
		if( child != sentinel ) /*one child which is red*/
            child->color = black;
		else	/*no child*/
			del_balance(child);
	}
	
}/*End of del()*/

void del_balance(struct node *nptr)
{
	struct node *sib;

	while( nptr!=root )
	{
 	  if( nptr == nptr->parent->lchild )
	  {
		sib = nptr->parent->rchild;
		if( sib->color == red )/* Case L_1 */
		{
			sib->color = black;
			nptr->parent->color = red;
			RotateLeft(nptr->parent);
			sib = nptr->parent->rchild; /*new sibling*/
		}
		if(sib->lchild->color==black && sib->rchild->color==black)
		{
			sib->color=red;
			
			if(nptr->parent->color == red )/*Case L_2a*/
			{
				nptr->parent->color = black;
				return;
			}
			else
			    nptr=nptr->parent;	/* Case L_2b */
		}
		else 
		{
			if(sib->rchild->color==black)  /*Case L_3a*/
			{
				sib->lchild->color=black;
				sib->color=red;
				RotateRight(sib);
				sib = nptr->parent->rchild;
			}
			sib->color = nptr->parent->color;  /*Case L_3b*/
			nptr->parent->color = black;
			sib->rchild->color = black;
			RotateLeft(nptr->parent);
			return;	
		}
	  }
	  else
	  {
		sib = nptr->parent->lchild;
		if( sib->color == red )/* Case R_1 */
		{
			sib->color =black;
			nptr->parent->color = red;
			RotateRight(nptr->parent);
			sib = nptr->parent->lchild;
		}
		
		if( sib->rchild->color==black && sib->lchild->color==black)
		{
			sib->color=red;
			if(nptr->parent->color == red )/*Case R_2a*/
			{
				nptr->parent->color = black;
				return;
			}
			else
				nptr=nptr->parent; /*Case R_2b */
		}
        else 
		{
			if(sib->lchild->color==black)  /*Case R_3a*/
			{
				sib->rchild->color=black;
				sib->color=red;
				RotateLeft(sib);
				display(root,0);
				sib = nptr->parent->lchild;
			}
				
			sib->color = nptr->parent->color;/*case R_3b*/
			nptr->parent->color = black;
			sib->lchild->color = black;
			RotateRight(nptr->parent);
			return;
		}
	  }
	}/*End of while*/
}/*End of del_balance*/

void RotateLeft(struct node *pptr)
{
	struct node *aptr;

	aptr = pptr->rchild;	/*aptr is right child of pptr*/
	pptr->rchild= aptr->lchild; 
	
	if(aptr->lchild !=sentinel)
        aptr->lchild->parent = pptr;
	
	aptr->parent = pptr->parent;
	
	if(pptr->parent == sentinel )
		root = aptr;
	else if( pptr == pptr->parent->lchild )	
		pptr->parent->lchild = aptr;
	else
		pptr->parent->rchild = aptr;
    aptr->lchild = pptr;		
	pptr->parent = aptr;
}/*End of RoatateLeft( )*/

void RotateRight(struct node *pptr)
{
	struct node *aptr;
	
	aptr = pptr->lchild;	
	pptr->lchild= aptr->rchild; 
	
	if(aptr->rchild !=sentinel )
        aptr->rchild->parent = pptr;

	aptr->parent = pptr->parent;

	if(pptr->parent == sentinel )
		root = aptr;
	else if( pptr == pptr->parent->rchild )	
		pptr->parent->rchild = aptr;
	else
		pptr->parent->lchild = aptr;

	aptr->rchild = pptr;		
	pptr->parent = aptr;
}/*End of RotateRight( )*/
struct node *succ(struct node *loc)
{
	struct node *ptr=loc->rchild;
	while(ptr->lchild!=sentinel)
	{
		ptr=ptr->lchild;
	}
	return ptr;
}/*End of succ()*/


void inorder(struct node *ptr)
{
	if(ptr!=sentinel)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}/*End of inorder()*/

void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=sentinel )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for(i=0; i<level; i++)
			printf("    ");
		printf("%d", ptr->info);
		if(ptr->color==red)
			printf("^");
		else
			printf("*");
		display(ptr->lchild, level+1);
	}
}/*End of display()*/
