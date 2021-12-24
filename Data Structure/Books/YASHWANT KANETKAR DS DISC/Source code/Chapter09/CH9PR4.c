/* CH9PR4.C: Program to insert and delete a node
			 from the binary search tree. */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0

struct btreenode
{
	struct btreenode *leftchild ;
	int data ;
	struct btreenode *rightchild ;
} ;

void insert ( struct btreenode **, int ) ;
void del ( struct btreenode **, int ) ;
void search ( struct btreenode **, int, struct btreenode **,
				struct btreenode **, int * ) ;
void inorder ( struct btreenode * ) ;

int main( )
{
	struct btreenode *bt ;
	int i = 0, a[ ] = { 11, 9, 13, 8, 10, 12, 14, 15, 7 } ;

	bt = NULL ;  /* empty tree */

	system ( "cls" ) ;

	while ( i <= 8 )
	{
		insert ( &bt, a[i] ) ;
		i++ ;
	}
	system ( "cls" ) ;
	printf ( "Binary tree before deletion:\n" ) ;
	inorder ( bt ) ;

	del ( &bt, 10 ) ;
  	printf ( "\n" ) ;
	printf ( "Binary tree after deletion:\n" ) ;
	inorder ( bt ) ;

	del ( &bt, 14 ) ;
  	printf ( "\n" ) ;
	printf ( "Binary tree after deletion:\n" ) ;
	inorder ( bt ) ;

	del ( &bt, 8 ) ;
  	printf ( "\n" ) ;
	printf ( "Binary tree after deletion:\n" ) ;
	inorder ( bt ) ;

	del ( &bt, 13 ) ;
  	printf ( "\n" ) ;
	printf ( "Binary tree after deletion:\n" ) ;
	inorder ( bt ) ;

	return 0 ;
}

/* inserts a new node in a binary search tree */
void insert ( struct btreenode **sr, int num )
{
	if ( *sr == NULL )
	{
		*sr = ( struct btreenode * ) malloc ( sizeof ( struct btreenode ) ) ;

		( *sr ) -> leftchild = NULL ;
		( *sr ) -> data = num ;
		( *sr ) -> rightchild = NULL ;
	}
	else  /* search the node to which new node will be attached */
	{
		/* if new data is less, traverse to left */
		if ( num < ( *sr ) -> data )
			insert ( &( ( *sr ) -> leftchild ), num ) ;
		else
			/* else traverse to right */
			insert ( &( ( *sr ) -> rightchild ), num ) ;
	}
}

/* deletes a node from the binary search tree */
void del ( struct btreenode **root, int num )
{
	int found ;
	struct btreenode *parent, *x, *xsucc ;

	/* if tree is empty */
	if ( *root == NULL )
	{
		printf ( "Tree is empty.\n" ) ;
		return ;
	}

	parent = x = NULL ;

	/* call to search function to find the node to be deleted */
	search ( root, num, &parent, &x, &found ) ;

	/* if the node to deleted is not found */
	if ( found == FALSE )
	{
		printf ( "Data to be deleted, not found.\n" ) ;
		return ;
	}

	/* if the node to be deleted has two children */
	if ( x -> leftchild != NULL && x -> rightchild != NULL )
	{
		parent = x ;
		xsucc = x -> rightchild ;

		while ( xsucc -> leftchild != NULL )
		{
			parent = xsucc ;
			xsucc = xsucc -> leftchild ;
		}

		x -> data = xsucc -> data ;
		x = xsucc ;
	}

	/* if the node to be deleted has no child */
	if ( x -> leftchild == NULL && x -> rightchild == NULL )
	{
		if ( parent -> rightchild == x )
			parent -> rightchild = NULL ;
		else
			parent -> leftchild = NULL ;

		free ( x ) ;
		return ;
	}

	/* if the node to be deleted has only rightchild */
	if ( x -> leftchild == NULL && x -> rightchild != NULL )
	{
		if ( parent -> leftchild == x )
			parent -> leftchild = x -> rightchild ;
		else
			parent -> rightchild = x -> rightchild ;

		free ( x ) ;
		return ;
	}

	/* if the node to be deleted has only left child */
	if ( x -> leftchild != NULL && x -> rightchild == NULL )
	{
		if ( parent -> leftchild == x )
			parent -> leftchild = x -> leftchild ;
		else
			parent -> rightchild = x -> leftchild ;

		free ( x ) ;
		return ;
	}
}

/*returns the address of the node to be deleted, address of its parent and
   whether the node is found or not */
void search ( struct btreenode **root, int num, struct btreenode **par, struct
		btreenode **x, int *found )
{
	struct btreenode *q ;

	q = *root ;
	*found = FALSE ;
	*par = NULL ;

	while ( q != NULL )
	{
		/* if the node to be deleted is found */
		if ( q -> data == num )
		{
			*found = TRUE ;
			*x = q ;
			return ;
		}

		*par = q ;

		if ( q -> data > num )
			q = q -> leftchild ;
		else
			q = q -> rightchild ;
	}
}

/* traverse a binary search tree in a LDR (Left-Data-Right) fashion */
void inorder ( struct btreenode *sr )
{
	if ( sr != NULL )
	{
		inorder ( sr -> leftchild ) ;

		/* print the data of the node whose leftchild is NULL or the path  has
			already been traversed */
		printf ( "%d\t", sr -> data ) ;

		inorder ( sr -> rightchild ) ;
	}
}

