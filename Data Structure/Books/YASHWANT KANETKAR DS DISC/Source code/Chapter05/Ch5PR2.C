/* CH5PR2.C: Program to add a new node to the asscending order linked list. */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

/* structure containing a data part and link part */
struct node
{
	int data ;
	struct node *link ;
} ;

void add ( struct node **, int ) ;
void display ( struct node * ) ;
int count ( struct node * ) ;

int main( )
{
	struct node *p ;
	p = NULL ;  /* empty linked list */

	add ( &p, 5 ) ;
	add ( &p, 1 ) ;
	add ( &p, 6 ) ;
	add ( &p, 4 ) ;
	add ( &p, 7 ) ;

	display ( p ) ;
	printf ( "No. of elements in Linked List = %d\n", count ( p ) ) ;
	return 0 ;
}

/* adds node to an ascending order linked list */
void add ( struct node **q, int num )
{
	struct node *r, *temp = *q ;

	r = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
	r -> data = num ;

	/* if list is empty or if new node is to be inserted before the first node */
	if ( *q == NULL || ( *q ) -> data > num )
	{
		*q = r ;
		( *q ) -> link = temp ;
	}
	else
	{
		/* traverse the entire linked list to search the position to insert the 
			new node */
		while ( temp != NULL )
		{
			if ( temp -> data <= num && (temp -> link == NULL || 
					temp -> link -> data > num	) )
			{
				r -> link = temp -> link ;
				temp -> link = r ;
				return ;
			}
			temp = temp -> link ;  /* go to the next node */
		}
	}
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

/* counts the number of nodes present in the linked list */
int count ( struct node *q )
{
	int c = 0 ;

	/* traverse the entire linked list */
	while ( q != NULL )
	{
		q = q -> link ;
		c++ ;
	}

	return c ;
}
