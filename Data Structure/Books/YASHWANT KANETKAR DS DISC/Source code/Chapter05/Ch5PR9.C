/* CH5PR9.C: Program to find the number of nodes in the linked list 
    using recursion */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

/* structure containing a data part and link part */
struct node
{
	int data ;
	struct node *link ;
} ;

void append ( struct node **, int ) ;
int length ( struct node * ) ;

int main( )
{
	struct node *p ;
	p = NULL ;  /* empty linked list */

	append ( &p, 1 ) ;
	append ( &p, 2 ) ;
	append ( &p, 3 ) ;
	append ( &p, 4 ) ;
	append ( &p, 5 ) ;

	system ( "cls" ) ;

	printf ( "Length of linked list = %d\n", length ( p ) ) ;
	return 0 ;
}

/* adds a node at the end of a linked list */
void append ( struct node **q, int num )
{
	struct node *temp ;
	temp = *q ;

	if ( *q == NULL )  /* if the list is empty, create first node */
	{
		*q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
		temp = *q ;
	}
	else
	{
		/* go to last node */
		while ( temp -> link != NULL )
			temp = temp -> link ;

		/* add node at the end */
		temp -> link = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
		temp = temp -> link ;
	}

	/* assign data to the last node */
	temp -> data = num ;
	temp -> link = NULL ;
}

/* counts the number of nodes in a linked list */
int length ( struct node *q )
{
	static int l ;

	/* if list is empty or if NULL is encountered */
	if ( q == NULL )
		return ( 0 ) ;
	else
	{
		/* go to next node */
		l = 1 + length ( q -> link ) ;
		return ( l ) ;
	}
}

