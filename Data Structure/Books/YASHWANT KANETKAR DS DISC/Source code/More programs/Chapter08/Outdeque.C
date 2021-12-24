/* Output-restricted deque program using array. */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

#define MAX 10

struct dqueue
{
	int arr[MAX] ;
	int front, rear ;
} ;

void initdqueue ( struct dqueue * ) ;
void addqatbeg ( struct dqueue *, int ) ;
void addqatend ( struct dqueue *, int ) ;
int delqatend ( struct dqueue * ) ;
void display ( struct dqueue ) ;
int count ( struct dqueue ) ;

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
	addqatend ( &dq, 15 ) ;
	addqatbeg ( &dq, 6 ) ;
	addqatend ( &dq, 16 ) ;
	addqatbeg ( &dq, 5 ) ;

	display ( dq ) ;

	n = count ( dq ) ;
	printf ( "\nTotal elements: %d", n ) ;

	i = delqatend ( &dq ) ;
  if ( i != NULL )
	  printf ( "\nItem extracted = %d", i ) ;

	i = delqatend ( &dq ) ;
  if ( i != NULL )
	  printf ( "\nItem extracted = %d", i ) ;

	i = delqatend ( &dq ) ;
  if ( i != NULL )
	  printf ( "\nItem extracted = %d", i ) ;

	i =	 delqatend ( &dq ) ;
  if ( i != NULL )
	  printf ( "\nItem extracted = %d", i ) ;

	n = count ( dq ) ;
	printf ( "\nElements Left: %d", n ) ;

	display ( dq ) ;

	addqatbeg ( &dq, 5 ) ;
	addqatbeg ( &dq, 4 ) ;
	addqatbeg ( &dq, 3 ) ;
	addqatbeg ( &dq, 2 ) ;

	display ( dq ) ;

  return 0 ;
}

/* initializes elements of structure */
void initdqueue ( struct dqueue *p )
{
    int i ;

	p -> front = p -> rear = -1 ;

	for ( i = 0 ; i < MAX ; i++ )
		p -> arr[i] = 0 ;
}

/* adds item at begining of dqueue */
void addqatbeg ( struct dqueue *p, int item )
{
	int c, i, k ;

	if ( p -> front == 0 && p -> rear == MAX )
	{
	   printf ( "\nQueue is full.\n" ) ;
	   return ;
	}

	if ( p -> front == -1 && p -> rear == -1 )
	{
		p -> front = p -> rear = 0 ;
		p -> arr[p -> front] = item ;
		return ;
	}

	if ( p -> rear != MAX )
	{
		c = count ( *p ) ;
		k = p -> rear ;

		for ( i = 1 ; i <= c ; i++ )
		{
			p -> arr[k] = p -> arr[k - 1] ;
			k-- ;
		}

		p -> arr[k] = item ;
		p -> front = k ;
		( p -> rear )++ ;
	}
	else
	{
		( p -> front )-- ;
		p -> arr[p -> front] = item ;
	}
}

/* adds item at the end of dqueue */
void addqatend ( struct dqueue *p, int item )
{
	int i, k ;

	if ( p -> front == 0 && p -> rear == MAX )
	{
	   printf ( "\nQueue is full.\n" ) ;
	   return ;
	}

	if ( p -> rear == -1 && p -> front == -1 )
	{
		p -> rear = p -> front = 0 ;
		p -> arr[p -> rear] = item ;
		( p -> rear )++ ;
        return ;
	}

	if ( p -> rear == MAX )
	{
		k = p -> front - 1 ;

		for ( i = p -> front - 1 ; i < p -> rear ; i++ )
		{
			k = i ;
			if ( k == MAX - 1 )
				p -> arr[k] = 0 ;
			else
				p -> arr[k] = p -> arr[i + 1] ;
		}
		( p -> rear )-- ;
		( p -> front )-- ;
	}

	p -> arr[p -> rear] = item ;
	( p -> rear )++ ;
}

/* deletes item from end of dqueue */
int delqatend( struct dqueue *p )
{
    int item ;

	if ( p -> front == -1 && p -> rear == -1 )
	{
		printf ( "\nQueue is empty.\n" ) ;
		return 0 ;
	}

	( p -> rear )-- ;
	item = p -> arr[p -> rear] ;
	p -> arr[p -> rear] = 0 ;

	if ( p -> rear == 0 )
		p -> rear = -1 ;

	return item ;
}

/* displays the queue */
void display( struct dqueue dq )
{
	int i ;

	printf ( "\n front -> " ) ;

	for ( i = 0 ; i < MAX ; i++ )
		printf ( "\t%d", dq.arr[i] ) ;

	printf ( " <- rear " ) ;
}

/* counts the number of items in dqueue */
int count( struct dqueue dq )
{
	int c, i ;
	for ( i = c = 0 ; i < MAX ; i++ )
	{
		if ( dq.arr[i] != 0 )
			c++ ;
	}
	return c ;
}