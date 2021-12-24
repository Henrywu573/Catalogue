/* CH5PR13.C: Program to maintain a doubly linked list */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

/* structure representing a node of the doubly linked list */
struct dnode
{
	struct dnode *prev ;
	int data ;
	struct dnode * next ;
} ;

void d_append ( struct dnode **, int ) ;
void d_addatbeg ( struct dnode **, int ) ;
void d_addafter ( struct dnode *, int , int ) ;
void d_display ( struct dnode * ) ;
int d_count ( struct dnode *  ) ;
void d_delete ( struct dnode **, int ) ;

int main( )
{
	struct dnode *p ;

	p = NULL ;  /* empty doubly linked list */

	d_append ( &p , 11 ) ;
	d_append ( &p , 2 ) ;
	d_append ( &p , 14 ) ;
	d_append ( &p , 17 ) ;
	d_append ( &p , 99 ) ;

	system ( "cls" ) ;

	d_display ( p ) ;
	printf ( "No. of elements in the DLL = %d\n\n", d_count ( p ) ) ;

	d_addatbeg ( &p, 33 ) ;
	d_addatbeg ( &p, 55 ) ;

	d_display ( p ) ;
	printf ( "No. of elements in the DLL = %d\n\n", d_count ( p ) ) ;

	d_addafter ( p, 4, 66 ) ;
	d_addafter ( p, 2, 96 ) ;

	d_display ( p ) ;
	printf ( "No. of elements in the DLL = %d\n\n", d_count ( p ) ) ;

	d_delete ( &p, 55 ) ;
	d_delete ( &p, 2 ) ;
	d_delete ( &p, 99 ) ;

	d_display ( p ) ;
	printf ( "No. of elements in the DLL = %d\n\n", d_count ( p ) ) ;
	return 0 ;
}

/* adds a new node at the end of the doubly linked list */
void d_append ( struct dnode **s, int num )
{
	struct dnode *r, *q = *s ;

	/* if the linked list is empty */
	if ( *s == NULL )
	{
		/*create a new node */
		*s = ( struct dnode * ) malloc ( sizeof ( struct dnode ) ) ;
		( *s ) -> prev = NULL ;
		( *s ) -> data = num ;
		( *s ) -> next = NULL ;
	}
	else
	{
		/* traverse the linked list till the last node is reached */
		while ( q -> next != NULL )
			q = q -> next ;

		/* add a new node at the end */
		r = ( struct dnode * ) malloc ( sizeof ( struct dnode ) ) ;
		r -> data = num ;
		r -> next = NULL ;
		r -> prev = q ;
		q -> next = r ;
	}
}

/* adds a new node at the begining of the linked list */
void d_addatbeg ( struct dnode **s, int num )
{
	struct dnode *q ;

	/* create a new node */
	q = ( struct dnode * ) malloc ( sizeof ( struct dnode ) ) ;

	/* assign data and pointer to the new node */
	q -> prev = NULL ;
	q -> data = num ;
	q -> next = *s ;

	/* make new node the head node */
	( *s ) -> prev = q ;
	*s = q ;
}

/* adds a new node after the specified number of nodes */
void d_addafter ( struct dnode *q, int loc, int num )
{
	struct dnode *temp ;
	int i ;

	/* skip to desired portion */
	for ( i = 0 ; i < loc ; i++ )
	{
		q = q -> next ;
		/* if end of linked list is encountered */
		if ( q == NULL )
		{
			printf ( "There are less than %d elements\n", loc );
			return ;
		}
	}

	/* insert new node */
	q = q -> prev ;
	temp = ( struct dnode * ) malloc ( sizeof ( struct dnode ) ) ;
	temp -> data = num ;
	temp -> prev = q ;
	temp -> next = q -> next ;
	temp -> next -> prev = temp ;
	q -> next = temp ;
}

/* displays the contents of the linked list */
void d_display ( struct dnode *q )
{
	/* traverse the entire linked list */
	while ( q != NULL )
	{
		printf ( "%2d\t", q -> data ) ;
		q = q -> next ;
	}
	printf ( "\n" ) ;
}

/* counts the number of nodes present in the linked list */
int d_count ( struct dnode * q )
{
	int c = 0 ;

	/* traverse the entire linked list */
	while ( q != NULL )
	{
		q = q -> next ;
		c++ ;
	}

	return c ;
}

/* deletes the specified node from the doubly linked list */
void d_delete ( struct dnode **s, int num )
{
	struct dnode *q = *s ;

	/* traverse the entire linked list */
	while ( q != NULL )
	{
		/* if node to be deleted is found */
		if ( q -> data == num )
		{
			/* if node to be deleted is the first node */
			if ( q == *s )
			{
				*s = ( *s ) -> next ;
				( *s ) -> prev = NULL ;
			}
			else
			{
				/* if node to be deleted is the last node */
				if ( q -> next == NULL )
					q -> prev -> next = NULL ;
				else
				/* if node to be deleted is any intermediate node */
				{
					q -> prev -> next = q -> next ;
					q -> next -> prev = q -> prev ;
				}
				free ( q ) ;
			}
			return ;  /* return back after deletion */
		}
		q = q -> next ; /* go to next node */
	}
	printf ( "%d not found.\n", num ) ;
}
