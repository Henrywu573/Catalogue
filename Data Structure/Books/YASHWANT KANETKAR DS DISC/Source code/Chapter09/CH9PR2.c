/* CH9PR2.C: Program to build a binary search tree from an array. */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

struct node
{
	struct node *left ;
	char data ;
	struct node *right ;
} ;

struct node * buildtree ( int ) ;
void inorder ( struct node * ) ;

char a[ ] = {
			'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0', '\0', 'H', '\0',
			'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'
		    } ;

int main( )
{
	struct node *root ;

	system ( "cls" ) ;

	root = buildtree ( 0 ) ;
	printf ( "In-order Traversal:\n" ) ;
	inorder ( root ) ;

	return 0 ;
}

struct node * buildtree ( int n )
{
	struct node *temp = NULL ;
	if ( a[n] != '\0' )
	{
		temp = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
		temp -> left = buildtree ( 2 * n + 1 ) ;
		temp -> data = a[n] ;
		temp -> right = buildtree ( 2 * n + 2 ) ;
	}
	return temp ;
}

void inorder ( struct node *root )
{
	if ( root != NULL )
	{
		inorder ( root -> left ) ;
		printf ( "%c\t", root -> data ) ;
		inorder ( root -> right ) ;
	}
}

