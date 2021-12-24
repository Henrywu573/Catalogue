/* CH11PR3.C: Program to find the minimum cost of a spanning tree. */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

struct lledge
{
	int v1, v2 ;
	float cost ;
	struct lledge *next ;
} ;

int stree[5] ;
int count[5] ;
float mincost ;

struct lledge * kminstree ( struct lledge *, int ) ;
int getrval ( int ) ;
void combine ( int, int ) ;
void del ( struct lledge * ) ;

int main( )
{
	struct lledge *temp, *root ;
	int i ;

	system ( "cls" ) ;

	root = ( struct lledge * ) malloc ( sizeof ( struct lledge ) ) ;

	root -> v1 = 4 ;
	root -> v2 = 3 ;
	root -> cost = 1 ;
	temp = root -> next = ( struct lledge * ) malloc ( sizeof ( struct lledge ) ) ;

	temp -> v1 = 4 ;
	temp -> v2 = 2 ;
	temp -> cost = 2 ;
	temp -> next = ( struct lledge * ) malloc ( sizeof ( struct lledge ) ) ;

	temp = temp -> next ;
	temp -> v1 = 3 ;
	temp -> v2 = 2 ;
	temp -> cost = 3 ;
	temp -> next = ( struct lledge * ) malloc ( sizeof ( struct lledge ) ) ;

	temp = temp -> next ;
	temp -> v1 = 4 ;
	temp -> v2 = 1 ;
	temp -> cost = 4 ;
	temp -> next = NULL ;

	root = kminstree ( root, 5 ) ;

	for ( i = 1 ; i <= 4 ; i++ )
		printf ( "stree[%d] -> %d\n", i, stree[i] ) ;
	printf ( "The minimum cost of spanning tree is %d\n", mincost ) ;
	del ( root ) ;

	return 0 ;
}

struct lledge * kminstree ( struct lledge *root, int n )
{
	struct lledge *temp = NULL ;
	struct lledge *p, *q ;
	int noofedges = 0 ;
	int i, p1, p2 ;

	for ( i = 0 ; i < n ; i++ )
		stree[i] = i ;
	for ( i = 0 ; i < n ; i++ )
		count[i] = 0 ;

	while ( ( noofedges < ( n - 1 ) ) && ( root != NULL ) )
	{
		p = root ;

		root = root -> next ;

		p1 = getrval ( p -> v1 ) ;
		p2 = getrval ( p -> v2 ) ;

		if ( p1 != p2 )
		{
			combine ( p -> v1, p -> v2 ) ;
			noofedges++ ;
			mincost += p -> cost ;
			if ( temp == NULL )
			{
				temp = p ;
				q = temp ;
			}
			else
			{
				q -> next = p ;
				q = q -> next ;
			}
			q -> next = NULL ;
		}
	}
	return temp ;
}

int getrval ( int i )
{
	int j, k, temp ;
	k = i ;
	while ( stree[k] != k )
		k = stree[k] ;
	j = i ;
	while ( j != k )
	{
		temp = stree[j] ;
		stree[j] = k ;
		j = temp ;
	}
	return k ;
}

void combine ( int i, int j )
{
	if ( count[i] < count[j] )
		stree[i] = j ;
	else
	{
		stree[j] = i ;
		if ( count[i] == count[j] )
			count[j]++ ;
	}
}

void del ( struct lledge *root )
{
	struct lledge *temp ;

	while ( root != NULL )
	{
		temp = root -> next ;
		free ( root ) ;
		root = temp ;
	}
}

