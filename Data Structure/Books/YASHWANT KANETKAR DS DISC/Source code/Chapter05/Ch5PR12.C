/* CH5PR12.C: Program to add a new node at the end of linked list using recursion*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

struct node
{
	int data ;
	struct node *link ;
} ;

void addatend ( struct node **, int ) ;
void display ( struct node * ) ;

int main( )
{
	struct node *p ;

	p = NULL ;

	addatend ( &p, 1 ) ;
	addatend ( &p, 2 ) ;
	addatend ( &p, 3 ) ;
	addatend ( &p, 4 ) ;
	addatend ( &p, 5 ) ;
	addatend ( &p, 6 ) ;
	addatend ( &p, 10 ) ;

	system ( "cls" ) ;

	display ( p ) ;
	return 0 ;
}

/* adds a new node at the end of the linked list */
void addatend ( struct node **s, int num )
{
	if ( *s == NULL )
	{
		*s = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
		( *s ) -> data = num ;
		( *s ) -> link = NULL ;
	}
	else
		addatend ( &( ( *s ) -> link ), num ) ;
}

/* displays the contents of the linked list */
void display ( struct node *q )
{
	/* traverse the entire linked list */
	while ( q != NULL )
	{
		printf ( "%d ", q -> data ) ;
		q = q -> link ;
	}
	printf ( "\n" ) ;
}
