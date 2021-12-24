/* Input-restricted deque program using array. */

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
void addqatend ( struct dqueue *, int item ) ;
int delqatbeg ( struct dqueue * ) ;
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
	addqatend ( &dq, 12 ) ;
	addqatend ( &dq, 13 ) ;
	addqatend ( &dq, 14 ) ;
	addqatend ( &dq, 15 ) ;
	addqatend ( &dq, 16 ) ;
	addqatend ( &dq, 17 ) ;
	addqatend ( &dq, 18 ) ;
	addqatend ( &dq, 19 ) ;
	addqatend ( &dq, 20 ) ;

    display ( dq ) ;

	n = count ( dq ) ;
	printf ( "\nTotal elements: %d", n ) ;

	i = delqatbeg ( &dq ) ;
  if ( i != NULL ) 
	  printf ( "\nItem extracted = %d", i ) ;

	i = delqatbeg ( &dq ) ;
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

	addqatend ( &dq, 19 ) ;
	addqatend ( &dq, 20 ) ;
	addqatend ( &dq, 21 ) ;
	addqatend ( &dq, 22 ) ;
	addqatend ( &dq, 23 ) ;
	addqatend ( &dq, 24 ) ;

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
		for ( i = k = p -> front - 1 ; i < p -> rear ; i++ )
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

/* deletes item from begining of dqueue */
int delqatbeg ( struct dqueue *p )
{
    int item ;

	if ( p -> front == -1 && p -> rear == -1 )
	{
		printf ( "\nQueue is empty.\n" ) ;
		return 0 ;
	}

	item = p -> arr[p -> front] ;
	p -> arr[p -> front] = 0 ;
	( p -> front )++ ;

	if ( p -> front == MAX )
		p -> front = -1 ;

	return item ;
}

/* deletes item from end of dqueue */
int delqatend ( struct dqueue *p )
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
void display ( struct dqueue dq )
{
    int i ;

    printf ( "\n front -> " ) ;

	for ( i = 0 ; i < MAX ; i++ )
		printf ( "%d\t", dq.arr[i] ) ;
	printf ( " <- rear" ) ;
}

/* counts the number of items in dqueue */
int count ( struct dqueue dq )
{
	int c, i ;

	for ( i = c = 0 ; i < MAX ; i++ )
	{
		if ( dq.arr[i] != 0 )
			c++ ;
	}
	return c ;
}