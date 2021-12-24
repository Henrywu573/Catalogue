/* Program on deque that implements a linked list. */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

struct node
{
	int data ;
	struct node *link ;
} ;

struct dqueue
{
	struct node *front ;
	struct node *rear ;
} ;

void initdqueue ( struct dqueue * ) ;
void addqatend ( struct dqueue *, int item ) ;
void addqatbeg ( struct dqueue *, int item ) ;
int delqatbeg ( struct dqueue * ) ;
int delqatend ( struct dqueue * ) ;
void display ( struct dqueue ) ;
int count ( struct dqueue ) ;
void deldqueue ( struct dqueue * ) ;

int main( )
{
	struct dqueue dq ;
    int i, n ;

  system ( "cls" ) ;

    initdqueue ( &dq ) ;

	addqatend ( &dq, 11 ) ;
	addqatbeg ( &dq, 10 ) ;
	addqatend ( &dq, 12 ) ;
	addqatbeg ( &dq, 9 ) ;
	addqatend ( &dq, 13 ) ;
	addqatbeg ( &dq, 8 ) ;
	addqatend ( &dq, 14 ) ;
	addqatbeg ( &dq, 7 ) ;

	display ( dq ) ;

	n = count ( dq ) ;
	printf ( "\nTotal elements: %d", n ) ;

	i = delqatbeg ( &dq ) ;
  if ( i != NULL )
	  printf ( "\nItem extracted = %d", i ) ;

	i = delqatbeg ( &dq ) ;
  if ( i != NULL )
    printf ( "\nItem extracted = %d", i ) ;

	i = delqatbeg ( &dq ) ;
  if ( i != NULL )
    printf ( "\nItem extracted = %d", i ) ;

	i =	 delqatend ( &dq ) ;
  if ( i != NULL )
    printf ( "\nItem extracted = %d", i ) ;

	display ( dq ) ;
	n = count ( dq ) ;
	printf ( "\nElements Left: %d", n ) ;

    deldqueue ( &dq ) ;

  return 0 ;
}

/* initializes elements of structure */
void initdqueue ( struct dqueue *p )
{
	p ->  front = p -> rear = NULL ;
}

/* adds item at the end of dqueue */
void addqatend ( struct dqueue *p, int item )
{
	struct node *temp ;

	temp = ( struct node * ) malloc ( sizeof ( struct node )  );
	temp -> data = item ;
	temp -> link = NULL ;

	if ( p -> front == NULL )
		p -> front = temp ;
	else
		p -> rear -> link = temp ;
	p -> rear = temp ;
}

/* adds item at begining of dqueue */
void addqatbeg ( struct dqueue *p, int item )
{
	struct node *temp ;
	temp = ( struct node * ) malloc ( sizeof ( struct node )  );
	temp -> data = item ;
	temp -> link = NULL ;

	if ( p -> front == NULL )
		p -> front = p -> rear = temp ;
	else
	{
		temp -> link = p -> front ;
		p -> front = temp ;
	}
}

/* deletes item from begining of dqueue */
int delqatbeg ( struct dqueue *p )
{
	struct node *temp = p -> front ;
	int item ;
	if ( temp == NULL )
	{
		printf ( "\nQueue is empty." ) ;
		return 0 ;
	}
	else
	{
		temp = p -> front ;
		item = temp -> data ;
		p -> front = temp -> link ;
		free ( temp ) ;

		if ( temp == NULL )
			p -> rear = NULL ;
		return ( item ) ;
	}
}

/* deletes item from end of dqueue */
int delqatend ( struct dqueue *p )
{
	struct node *temp , *rleft, *q ;
	int item ;
	temp = p -> front ;
	if ( p -> rear == NULL )
	{
		printf ( "\nQueue is empty." ) ;
		return 0 ;
	}
	else
	{
		while ( temp != p -> rear )
		{
			rleft = temp ;
			temp = temp -> link ;
		}
		q = p -> rear ;
		item = q -> data ;
		free ( q ) ;
		p -> rear = rleft ;
		p -> rear -> link = NULL ;
		if ( p -> rear == NULL )
			p -> front = NULL ;
		return ( item ) ;
	}
}

/* displays the queue */
void display ( struct dqueue dq )
{
	struct node *temp = dq.front ;

	printf ( "\nfront -> " ) ;
	while ( temp != NULL )
	{
		if ( temp -> link == NULL )
		{
			printf ( "\t%d", temp -> data ) ;
			printf ( " <- rear" ) ;
		}
		else
			printf ( "\t%d", temp -> data ) ;
		temp = temp -> link ;
	}
	printf ( "\n" ) ;
}

/* counts the number of items in dqueue */
int count ( struct dqueue dq )
{
	int c = 0 ;
	struct node *temp = dq.front ;

	while ( temp != NULL )
	{
		temp = temp -> link ;
		c++ ;
	}

	return c ;
}

/* deletes the queue */
void deldqueue ( struct dqueue *p )
{
    struct node *temp ;

	if ( p -> front == NULL )
		return ;

	while ( p -> front != NULL )
	{
		temp = p -> front ;
		p -> front = p -> front -> link ;
		free ( temp ) ;
	}
}

