/* CH9PR8.C: Program which maintains a B-tree of order 5. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>

#define MAX 4
#define MIN 2

struct btnode
{
	int count ;
	int value[MAX + 1] ;
	struct btnode *child[MAX + 1] ;
} ;

struct btnode * insert ( int, struct btnode * ) ;
int setval ( int, struct btnode *, int *, struct btnode ** ) ;
struct btnode * search ( int, struct btnode *, int * ) ;
int searchnode ( int, struct btnode *, int * ) ;
void fillnode ( int, struct btnode *, struct btnode *, int ) ;
void split ( int, struct btnode *, struct btnode *,
				int, int *, struct btnode ** ) ;
struct btnode * del ( int, struct btnode * ) ;
int delhelp ( int, struct btnode * ) ;
void clear ( struct btnode *, int ) ;
void copysucc ( struct btnode *, int ) ;
void restore ( struct btnode *, int ) ;
void rightshift ( struct btnode *, int ) ;
void leftshift ( struct btnode *, int ) ;
void merge ( struct btnode *, int ) ;
void display ( struct btnode * ) ;

int main( )
{
	struct btnode *root ;
	root = NULL ;

	system ( "cls" ) ;

	root = insert ( 27, root ) ;
	root = insert ( 42, root ) ;
	root = insert ( 22, root ) ;
	root = insert ( 47, root ) ;
	root = insert ( 32, root ) ;
	root = insert ( 2, root ) ;
	root = insert ( 51, root ) ;
	root = insert ( 40, root ) ;
	root = insert ( 13, root ) ;

	printf ( "B-tree of order 5:\n" ) ;
	display ( root ) ;

	root = del ( 22, root ) ;
	root = del ( 11, root ) ;

	printf ( "\n" ) ;
	printf ( "After deletion of values:\n" ) ;
	display ( root ) ;

	return 0 ;
}

/* inserts a value in the B-tree*/
struct btnode * insert ( int val, struct btnode *root )
{
	int i ;
	struct btnode *c, *n ;
	int flag ;

	flag = setval ( val, root, &i, &c ) ;
	if ( flag )
	{
		n = ( struct btnode * ) malloc ( sizeof ( struct btnode ) ) ;
		n -> count = 1 ;
		n -> value [1] = i ;
		n -> child [0] = root ;
		n -> child [1] = c ;
		return n ;
	}
	return root ;
}

/* sets the value in the node */
int setval ( int val, struct btnode *n, int *p, struct btnode **c )
{
	int k ;
	if ( n == NULL )
	{
		*p = val ;
		*c = NULL ;
		return 1 ;
	}
	else
	{
		if ( searchnode ( val, n, &k ) )
			printf ( "Key value already exists.\n" ) ;
		if ( setval ( val, n -> child [k], p, c ) )
		{
			if ( n -> count < MAX )
			{
				fillnode ( *p, *c, n, k ) ;
				return 0 ;
			}
			else
			{
				split ( *p, *c, n, k, p, c ) ;
				return 1 ;
			}
		}
		return 0 ;
	}
}

/* searches value in the node */
struct btnode * search ( int val, struct btnode *root, int *pos )
{
	if ( root == NULL )
		return NULL ;
	else
	{
		if ( searchnode ( val, root, pos ) )
			return root ;
		else
			return search ( val, root -> child [*pos], pos ) ;
	}
}

/* searches for the node */
int searchnode ( int val, struct btnode *n, int *pos )
{
	if ( val < n -> value [1] )
	{
		*pos = 0 ;
		return 0 ;
	}
	else
	{
		*pos = n -> count ;
		while ( ( val < n -> value [*pos] ) && *pos > 1 )
			( *pos )-- ;
		if ( val == n -> value [*pos] )
			return 1 ;
		else
			return 0 ;
	}
}


/* adjusts the value of the node */
void fillnode ( int val, struct btnode *c, struct btnode *n, int k )
{
	int i ;
	for ( i = n -> count ; i > k ; i-- )
	{
		n -> value [i + 1] = n -> value [i] ;
		n -> child [i + 1] = n -> child [i] ;
	}
	n -> value [k + 1] = val ;
	n -> child [k + 1] = c ;
	n -> count++ ;
}

/* splits the node */
void split ( int val, struct btnode *c, struct btnode *n,
				int k, int *y, struct btnode **newnode )
{
	int i, mid ;

	if ( k <= MIN )
		mid = MIN ;
	else
		mid = MIN + 1 ;

	*newnode = ( struct btnode * ) malloc ( sizeof ( struct btnode ) ) ;

	for ( i = mid + 1 ; i <= MAX ; i++ )
	{
		( *newnode ) -> value [i - mid] = n -> value [i] ;
		( *newnode ) -> child [i - mid] = n -> child [i] ;
	}

	( *newnode ) -> count = MAX - mid ;
	n -> count = mid ;

	if ( k <= MIN )
		fillnode ( val, c, n, k ) ;
	else
		fillnode ( val, c, *newnode, k - mid ) ;

	*y = n -> value [n -> count] ;
	( *newnode ) -> child [0] = n -> child [n -> count] ;
	n -> count-- ;
}

/* deletes value from the node */
struct btnode * del ( int val, struct btnode *root )
{
	struct btnode * temp ;
	if ( ! delhelp ( val, root ) )
	{
		printf ( "\n" ) ;
		printf ( "Value %d not found.\n", val ) ;
	}
	else
	{
		if ( root -> count == 0 )
		{
			temp = root ;
			root = root -> child [0] ;
			free ( temp ) ;
		}
	}
	return root ;
}

/* helper function for del( ) */
int delhelp ( int val, struct btnode *root )
{
	int i ;
	int flag ;
	if ( root == NULL )
		return 0 ;
	else
	{
		flag = searchnode ( val, root, &i ) ;
		if ( flag )
		{
			if ( root -> child [i - 1] )
			{
				copysucc ( root, i ) ;
				flag = delhelp ( root -> value [i], root -> child [i] ) ;
				if ( !flag )
				{
					printf ( "\n" ) ;
					printf ( "Value %d not found.\n", val ) ;
				}
			}
			else
				clear ( root, i ) ;
		}
		else
			flag = delhelp ( val, root -> child [i] ) ;

		if ( root -> child [i] != NULL )
		{
			if ( root -> child [i] -> count < MIN )
				restore ( root, i ) ;
		}
		return flag ;
	}
}

/* removes the value from the node and adjusts the values */
void clear ( struct btnode *node, int k )
{
	int i ;
	for ( i = k + 1 ; i <= node -> count ; i++ )
	{
		node -> value [i - 1] = node -> value [i] ;
		node -> child [i - 1] = node -> child [i] ;
	}
	node -> count-- ;
}

/* copies the successor of the value that is to be deleted */
void copysucc ( struct btnode *node, int i )
{
	struct btnode *temp ;

	temp = node -> child [i] ;

	while ( temp -> child[0] )
		temp = temp -> child [0] ;

	node -> value [i] = temp -> value [1] ;
}

/* adjusts the node */
void restore ( struct btnode *node, int i )
{
	if ( i == 0 )
	{
		if ( node -> child [1] -> count > MIN )
			leftshift ( node, 1 ) ;
		else
			merge ( node, 1 ) ;
	}
	else
	{
		if ( i == node -> count )
		{
			if ( node -> child [i - 1] -> count > MIN )
				rightshift ( node, i ) ;
			else
				merge ( node, i ) ;
		}
		else
		{
			if ( node -> child [i - 1] -> count > MIN )
				rightshift ( node, i ) ;
			else
			{
				if ( node -> child [i + 1] -> count > MIN )
					leftshift ( node, i + 1 ) ;
				else
					merge ( node, i ) ;
			}
		}
	}
}

/* adjusts the values and children while shifting the value from parent to right 
    child */
void rightshift ( struct btnode *node, int k )
{
	int i ;
	struct btnode *temp ;

	temp = node -> child [k] ;

	for ( i = temp -> count ; i > 0 ; i-- )
	{
		temp -> value [i + 1] = temp -> value [i] ;
		temp -> child [i + 1] = temp -> child [i] ;
	}

	temp -> child [1] = temp -> child [0] ;
	temp -> count++ ;
	temp -> value [1] = node -> value [k] ;

	temp = node -> child [k - 1] ;
	node -> value [k] = temp -> value [temp -> count] ;
	node -> child [k] -> child [0] = temp -> child [temp -> count] ;
	temp -> count-- ;
}

/* adjusts the values and children while shifting the value from parent to left 
    child */
void leftshift ( struct btnode *node, int k )
{
	int i ;
	struct btnode *temp ;

	temp = node -> child [k - 1] ;
	temp -> count++ ;
	temp -> value [temp -> count] = node -> value [k] ;
	temp -> child [temp -> count] = node -> child [k] -> child [0] ;

	temp = node -> child [k] ;
	node -> value [k] = temp -> value [1] ;
	temp -> child [0] = temp -> child [1] ;
	temp -> count-- ;

	for ( i = 1 ; i <= temp -> count ; i++ )
	{
		temp -> value [i] = temp -> value [i + 1] ;
		temp -> child [i] = temp -> child [i + 1] ;
	}
}

/* merges two nodes */
void merge ( struct btnode *node, int k )
{
	int i ;
	struct btnode *temp1, *temp2 ;

	temp1 = node -> child [k] ;
	temp2 = node -> child [k - 1] ;
	temp2 -> count++ ;
	temp2 -> value [temp2 -> count] = node -> value [k] ;
	temp2 -> child [temp2 -> count] = node -> child [0] ;

	for ( i = 1 ; i <= temp1 -> count ; i++ )
	{
		temp2 -> count++ ;
		temp2 -> value [temp2 -> count] = temp1 -> value [i] ;
		temp2 -> child [temp2 -> count] = temp1 -> child [i] ;
	}
	for ( i = k ; i < node -> count ; i++ )
	{
		node -> value [i] = node -> value [i + 1] ;
		node -> child [i] = node -> child [i + 1] ;
	}
	node -> count-- ;
	free ( temp1 ) ;
}

/* displays the B-tree */
void display ( struct btnode *root )
{
	int i ;

	if ( root != NULL )
	{
		for ( i = 0 ; i < root -> count ; i++ )
		{
			display ( root -> child [i] ) ;
			printf ( "%d\t", root -> value [i + 1] ) ;
		}
		display ( root -> child [i] ) ;
	}
}
