/* CH9PR6.C: Program to reconstruct a binary search tree. */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

#define MAX 101

struct node
{
	struct node *left ;
	int data ;
	struct node *right ;
} ;

void insert ( struct node **, int ) ;
void preorder ( struct node * ) ;
void postorder ( struct node * ) ;
void inorder ( struct node * ) ;
struct node * recons ( int *, int *, int ) ;
void deltree ( struct node * ) ;

int in[MAX], pre[MAX], x ;

int main( )
{
	struct node *t ;
	int req, i, num ;

	t = NULL ;  /* empty tree */

	system ( "cls" ) ;
	printf ( "Specify the number of items to be inserted: " ) ;
	while ( 1 )
	{
		scanf ( "%d", &req ) ;
		if ( req >= MAX || req <= 0 )
			printf ( "Enter number between 1 to 100.\n" ) ;
		else
			break ;
	}

	for ( i = 0 ; i < req ; i++ )
	{
		printf ( "Enter the data: " ) ;
		scanf ( "%d", &num ) ;
		insert ( &t, num ) ;
	}

	printf ( "\n" ) ;
	printf ( "In-order   Traversal:\n" ) ;
	x = 0 ;
	inorder ( t ) ;

	printf ( "\n" ) ;
	printf ( "Pre-order  Traversal:\n" ) ;
	x = 0 ;
	preorder ( t ) ;

	printf ( "\n" ) ;
	printf ( "Post-order Traversal:\n" ) ;
	x = 0 ;
	postorder ( t ) ;

	deltree ( t ) ;
	t = NULL ;
	t = recons ( in, pre, req ) ;

	printf ( "\n" ) ;
	printf ( "After reconstruction of the binary tree:\n" ) ;

	x = 0 ;
	printf ( "\n" ) ;
	printf ( "In-order   Traversal:\n" ) ;
	inorder ( t ) ;

	x = 0 ;
	printf ( "\n" ) ;
	printf ( "Pre-order  Traversal:\n" ) ;
	preorder ( t ) ;

	x = 0 ;
	printf ( "\n" ) ;
	printf ( "Post-order Traversal:\n" ) ;
	postorder ( t ) ;

	deltree ( t ) ;
	return 0 ;
}

/* inserts a new node in a binary search tree */
void insert ( struct node **sr, int num )
{
	if ( *sr == NULL )
	{
		*sr = ( struct node * ) malloc ( sizeof ( struct node ) ) ;

		( *sr ) -> left = NULL ;
		( *sr ) -> data = num ;
		( *sr ) -> right = NULL ;
		return ;
	}
	else  /* search the node to which new node will be attached */
	{
		/* if new data is less, traverse to left */
		if ( num < ( *sr ) -> data )
			insert ( &( ( *sr ) -> left ), num ) ;
		else
			/* else traverse to right */
			insert ( &( ( *sr ) -> right ), num ) ;
	}
}

void preorder ( struct node *t )
{
	if ( t != NULL )
	{
		printf ( "%d\t", pre[x++]= t -> data ) ;
		preorder ( t -> left ) ;
		preorder ( t -> right ) ;
	}
}

void postorder ( struct node *t )
{
	if ( t != NULL )
	{
		postorder ( t -> left ) ;
		postorder ( t -> right ) ;
		printf ( "%d\t", t -> data ) ;
	}
}

void inorder ( struct node *t )
{
	if ( t != NULL )
	{
		inorder ( t -> left ) ;
		printf ( "%d\t", in[x++]= t -> data ) ;
		inorder ( t -> right ) ;
	}
}

struct node * recons ( int *inorder, int *preorder, int noofnodes )
{
	struct node *temp, *left, *right ;
	int tempin[100], temppre[100], i, j ;

	if ( noofnodes == 0 )
		return NULL ;

	temp = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
	temp -> data = preorder[0] ;
	temp -> left = NULL ;
	temp -> right = NULL ;

	if ( noofnodes == 1 )
		return temp ;
	for ( i = 0 ; inorder[i] != preorder[0] ; )
		i++ ;

	if ( i > 0 )
	{
		for ( j = 0 ; j <= i  ; j++ )
			tempin[j] = inorder[j] ;

		for ( j = 0 ; j < i  ; j++ )
			temppre[j] = preorder[j + 1] ;
	}

	left = recons ( tempin, temppre, i ) ;
	temp -> left = left ;

	if ( i < noofnodes - 1 )
	{
		for ( j = i ; j < noofnodes - 1 ; j++ )
		{
			tempin[j - i] = inorder[j + 1] ;
			temppre[j - i] = preorder[j + 1] ;
		}
	}

	right = recons ( tempin, temppre, noofnodes - i - 1 ) ;
	temp -> right = right ;

	return temp ;
}

void deltree ( struct node *t )
{
	if ( t != NULL )
	{
		deltree ( t -> left ) ;
		deltree ( t -> right ) ;
	}
	free ( t ) ;
}

