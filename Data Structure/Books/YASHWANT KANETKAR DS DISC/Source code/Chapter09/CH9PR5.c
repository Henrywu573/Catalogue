/* CH9PR5.C: Program to maintain a threaded binary tree. */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

enum boolean
{
	false = 0,
	true = 1
} ;

struct thtree
{
	enum boolean isleft ;
	struct thtree *left ;
	int data ;
	struct thtree *right ;
	enum boolen isright ;
} ;

void insert ( struct thtree **, int ) ;
void del ( struct thtree **, int ) ;
void search ( struct thtree **, int, struct thtree **,
				struct thtree **, int * ) ;
void inorder ( struct thtree * ) ;
void deltree ( struct thtree ** ) ;

int main( )
{
	struct thtree *th_head ;

	th_head = NULL ;  /* empty tree */

	insert ( &th_head, 11 ) ;
	insert ( &th_head, 9 ) ;
	insert ( &th_head, 13 ) ;
	insert ( &th_head, 8 ) ;
	insert ( &th_head, 10 ) ;
	insert ( &th_head, 12 ) ;
	insert ( &th_head, 14 ) ;
	insert ( &th_head, 15 ) ;
	insert ( &th_head, 7 ) ;

	system ( "cls" ) ;
	printf ( "Threaded binary tree before deletion:\n" ) ;
	inorder ( th_head ) ;

	del ( &th_head, 10 ) ;
	printf ( "\n" ) ;
	printf ( "Threaded binary tree after deletion:\n" ) ;
	inorder ( th_head ) ;

	del ( &th_head, 14 ) ;
	printf ( "\n" ) ;
	printf ( "Threaded binary tree after deletion:\n" ) ;
	inorder ( th_head ) ;

	del ( &th_head, 8 ) ;
	printf ( "\n" ) ;
	printf ( "Threaded binary tree after deletion:\n" ) ;
	inorder ( th_head ) ;

	del ( &th_head, 13 ) ;
	printf ( "\n" ) ;
	printf ( "Threaded binary tree after deletion:\n" ) ;
	inorder ( th_head ) ;

	deltree ( &th_head ) ;

	return 0 ;
}

/* inserts a node in a threaded binary tree */
void insert ( struct thtree **s, int num )
{
	struct thtree *p, *z, *head = *s ;

	/* allocating a new node */
	z = ( struct thtree * ) malloc ( sizeof ( struct thtree ) ) ;

	z -> isleft = true ;  /* indicates a thread */
	z -> data = num ;  /* assign new data */
	z -> isright = true ;  /* indicates a thread */

	/* if tree is empty */
	if ( *s == NULL )
	{
		head = ( struct thtree * ) malloc ( sizeof ( struct thtree ) ) ;

		/* the entire tree is treated as a left sub-tree of the head node */
		head -> isleft = false ;
		head -> left = z ;  /* z becomes leftchild of the head node */
		head -> data = -9999 ;  /* no data */
		head -> right = head ;  /* right link will always be pointing
									to itself */
		head -> isright = false ;

		*s = head ;

		z -> left = head ;  /* left thread to head */
		z -> right = head ;  /* right thread to head */
	}
	else  /* if tree is non-empty */
	{
		p = head -> left ;

		/* traverse till the thread is found attached to the head */
		while ( p != head )
		{
			if ( p -> data > num )
			{
				if ( p -> isleft != true )  /* checking for a thread */
					p = p -> left ;
				else
				{
					z -> left = p -> left ;
					p -> left = z ;
					p -> isleft = false ;  /* indicates a link */
					z -> isright = true ;
					z -> right = p ;
					return ;
				}
			}
			else
			{
				if ( p -> data < num )
				{
					if ( p -> isright != true )
						p = p -> right ;
					else
					{
						z -> right = p -> right ;
						p -> right = z ;
						p -> isright = false ;  /* indicates a link */
						z -> isleft = true ;
						z -> left = p ;
						return ;
					}
				}
			}
		}
	}
}

/* deletes a node from the binary search tree */
void del ( struct thtree **root, int num )
{
	int found ;
	struct thtree *parent, *x, *xsucc ;

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
	if ( found == false )
	{
		printf ( "Data to be deleted, not found.\n" ) ;
		return ;
	}

	/* if the node to be deleted has two children */
	if ( x -> isleft == false && x -> isright == false )
	{
		parent = x ;
		xsucc = x -> right ;

		while ( xsucc -> isleft == false )
		{
			parent = xsucc ;
			xsucc = xsucc -> left ;
		}

		x -> data = xsucc -> data ;
		x = xsucc ;
	}

	/* if the node to be deleted has no child */
	if ( x -> isleft == true && x -> isright == true )
	{
		/* if node to be deleted is a root node */
		if ( parent == NULL )
		{
			( *root ) -> left = *root ;
			( *root ) -> isleft = true ;

			free ( x ) ;
			return ;
		}

		if ( parent -> right == x )
		{
			parent -> isright = true ;
			parent -> right = x -> right ;
		}
		else
		{
			parent -> isleft = true ;
			parent -> left = x -> left ;
		}

		free ( x ) ;
		return ;
	}

	/* if the node to be deleted has only rightchild */
	if ( x -> isleft == true && x -> isright == false )
	{
		/* node to be deleted is a root node */
		if ( parent == NULL )
		{
			( *root ) -> left = x -> right ;
			free ( x ) ;
			return ;
		}

		if ( parent -> left == x )
		{
			parent -> left = x -> right ;
			x -> right -> left = x -> left ;
		}
		else
		{
			parent -> right = x -> right ;
			x -> right -> left = parent ;
		}

		free ( x ) ;
		return ;
	}

	/* if the node to be deleted has only left child */
	if ( x -> isleft == false && x -> isright == true )
	{
		/* the node to be deleted is a root node */
		if ( parent == NULL )
		{
			parent = x ;
			xsucc = x -> left ;

			while ( xsucc -> isright == false )
				xsucc = xsucc -> right ;

			xsucc -> right = *root ;

			( *root ) -> left = x -> left ;

			free ( x ) ;
			return ;
		}

		if ( parent -> left == x )
		{
			parent -> left = x -> left ;
			x -> left -> right = parent ;
		}
		else
		{
			parent -> right = x -> left ;
			x -> left -> right = x -> right ;
		}

		free ( x ) ;
		return ;
	}
}

/* returns the address of the node to be deleted, address of its parent and
	whether the node is found or not */
void search ( struct thtree **root, int num, struct thtree **par,
				struct thtree **x, int *found )
{
	struct thtree *q ;

	q = ( *root ) -> left ;
	*found = false ;
	*par = NULL ;

	while ( q != *root )
	{
		/* if the node to be deleted is found */
		if ( q -> data == num )
		{
			*found = true ;
			*x = q ;
			return ;
		}

		*par = q ;

		if ( q -> data > num )
		{
			if ( q -> isleft == true )
			{
				*found = false ;
				x = NULL ;
				return ;
			}
			q = q -> left ;
		}
		else
		{
			if ( q -> isright == true )
			{
				*found = false ;
				*x = NULL ;
				return ;
			}
			q = q -> right ;
		}
	}
}

/* traverses the threaded binary tree in inorder */
void inorder ( struct thtree *root )
{
	struct thtree *p ;

	p = root -> left ;

	while ( p != root )
	{
		while ( p -> isleft == false )
			p = p -> left ;

		printf ( "%d\t", p -> data ) ;

		while ( p -> isright == true )
		{
			p = p -> right ;

			if ( p == root )
				break ;

			printf ( "%d\t", p -> data ) ;

		}
		p = p -> right ;
	}
}

void deltree ( struct thtree **root )
{
	while ( ( *root ) -> left != *root )
		del ( root, ( *root ) -> left -> data ) ;
}

