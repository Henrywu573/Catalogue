/* CH11PR1.C: Program that implements depth first search algorithm. */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0
#define MAX 8

struct node
{
	int data ;
	struct node *next ;
} ;

int visited[MAX] ;

void dfs ( int, struct node ** ) ;
struct node * getnode_write ( int ) ;
void del ( struct node * ) ;

int main( )
{
	struct node *arr[MAX] ;
	struct node *v1, *v2, *v3, *v4 ;
	int i ;

	system ( "cls" ) ;

	v1 = getnode_write ( 2 ) ;
	arr[0] = v1 ;
	v1 -> next = v2 = getnode_write ( 3 ) ;
	v2 -> next = NULL ;

	v1 = getnode_write ( 1 ) ;
	arr[1] = v1 ;
	v1 -> next = v2 = getnode_write ( 4 ) ;
	v2 -> next = v3 = getnode_write ( 5 ) ;
	v3 -> next = NULL ;

	v1 = getnode_write ( 1 ) ;
	arr[2] = v1 ;
	v1 -> next = v2 = getnode_write ( 6 ) ;
	v2 -> next = v3 = getnode_write ( 7 ) ;
	v3 -> next = NULL ;

	v1 = getnode_write ( 2 ) ;
	arr[3] = v1 ;
	v1 -> next = v2 = getnode_write ( 8 ) ;
	v2 -> next = NULL ;

	v1 = getnode_write ( 2 ) ;
	arr[4] = v1 ;
	v1 -> next = v2 = getnode_write ( 8 ) ;
	v2 -> next = NULL ;

	v1 = getnode_write ( 3 ) ;
	arr[5] = v1 ;
	v1 -> next = v2 = getnode_write ( 8 ) ;
	v2 -> next = NULL ;

	v1 = getnode_write ( 3 ) ;
	arr[6] = v1 ;
	v1 -> next = v2 = getnode_write ( 8 ) ;
	v2 -> next = NULL ;

	v1 = getnode_write ( 4 ) ;
	arr[7] = v1 ;
	v1 -> next = v2 = getnode_write ( 5 ) ;
	v2 -> next = v3 = getnode_write ( 6 ) ;
	v3 -> next = v4 = getnode_write ( 7 ) ;
	v4 -> next = NULL ;

	dfs ( 1, arr ) ;

	for ( i = 0 ; i < MAX ; i++ )
		del ( arr[i] ) ;

	return 0 ;
}

void dfs ( int v, struct node **p )
{
	struct node *q ;
	visited[v - 1] = TRUE ;

	printf ( "%d\t", v ) ;

	q = * ( p + v - 1 ) ;

	while ( q != NULL )
	{
		if ( visited[q -> data - 1] == FALSE )
			dfs ( q -> data, p ) ;
		else
			q = q -> next ;
	}
}

struct node * getnode_write ( int val )
{
	struct node *newnode ;
	newnode = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
	newnode -> data = val ;
	return newnode ;
}

void del ( struct node *n )
{
	struct node *temp ;

	while ( n != NULL )
	{
		temp = n -> next ;
		free ( n ) ;
		n = temp ;
	}
}

