/* CH5PR1.C: Program to maintain a linked list */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

/* structure containing a data part and link part */
struct node
{
	int data ;
	struct node * link ;
} ;

void append ( struct node **, int ) ;
void addatbeg ( struct node **, int ) ;
void addafter ( struct node *, int, int ) ;
void display ( struct node * ) ;
int count ( struct node * ) ;
void del ( struct node **, int ) ;

int main( )
{
	struct node *p ;
	p = NULL ;  /* empty linked list */

	printf ( "No. of elements in the Linked List = %d\n", count ( p ) ) ;
	append ( &p, 14 ) ;
	append ( &p, 30 ) ;
	append ( &p, 25 ) ;
	append ( &p, 42 ) ;
	append ( &p, 17 ) ;

	system ( "cls" ) ;

	display ( p ) ;

	addatbeg ( &p, 999 ) ;
	addatbeg ( &p, 888 ) ;
	addatbeg ( &p, 777 ) ;

	display ( p ) ;

	addafter ( p, 7, 0 ) ;
	addafter ( p, 2, 1 ) ;
	addafter ( p, 5, 99 ) ;

	display ( p ) ;
	printf ( "No. of elements in the Linked List = %d\n", count ( p ) ) ;

	del ( &p, 99 ) ;
	del ( &p, 1 ) ;
	del ( &p, 10 ) ;

	display ( p ) ;
	printf ( "No. of elements in the linked list = %d\n", count ( p ) ) ;
	return 0 ;
}

/* adds a node at the end of a linked list */
void append ( struct node **q, int num )
{
	struct node *temp, *r ;

	if ( *q == NULL )  /* if the list is empty, create first node */
	{
		temp = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
		temp -> data = num ;
		temp -> link = NULL ;
		*q = temp ;
	}
	else
	{
		temp = *q ;

		/* go to last node */
		while ( temp -> link != NULL )
			temp = temp -> link ;

		/* add node at the end */
		r = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
		r -> data = num ;
		r -> link = NULL ;
		temp -> link = r ;
	}
}

/* adds a new node at the beginning of the linked list */
void addatbeg ( struct node **q, int num )
{
	struct node *temp ;

	/* add new node */
	temp = ( struct node * ) malloc ( sizeof ( struct node ) ) ;

	temp -> data = num ;
	temp -> link = *q ;
	*q = temp ;
}

/* adds a new node after the specified number of nodes */
void addafter ( struct node *q, int loc, int num )
{
	struct node *temp, *r ;
	int i ;

	temp = q ;
	/* skip to desired portion */
	for ( i = 0 ; i < loc ; i++ )
	{
		temp = temp -> link ;

		/* if end of linked list is encountered */
		if ( temp == NULL )
		{
			printf ( "There are less than %d elements in list\n", loc ) ;
			return ;
		}
	}

	/* insert new node */
	r = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
	r -> data = num ;
	r -> link = temp -> link ;
	temp -> link = r ;
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
int count ( struct node * q )
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

/* deletes the specified node from the linked list */
void del ( struct node **q, int num )
{
	struct node *old, *temp ;

	temp = *q ;

	while ( temp != NULL )
	{
		if ( temp -> data == num )
		{
			/* if node to be deleted is the first node in the linked list */
			if ( temp == *q )
				*q = temp -> link ;

			/* deletes the intermediate nodes in the linked list */
			else
				old -> link = temp -> link ;

			/* free the memory occupied by the node */
			free ( temp ) ;
			return ;
		}

		/* traverse the linked list till the last node is reached */
		else
		{
			old = temp ;  /* old points to the previous node */
			temp = temp -> link ;  /* go to the next node */
		 }
	}

	printf ( "Element %d not found\n", num ) ;
}
