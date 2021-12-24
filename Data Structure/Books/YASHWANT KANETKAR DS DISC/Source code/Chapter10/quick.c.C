/* CH10PR6.C: Quick sort. */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

void quicksort ( int *, int, int ) ;
int split ( int *, int, int ) ;

int main( )
{
	int arr[10] = { 11, 2, 9, 13, 57, 25, 17, 1, 90, 3 } ;
	int i ;

	system ( "cls" ) ;

	printf ( "Quick sort.\n\n" ) ;
	printf ( "Array before sorting:\n") ;

	for ( i = 0 ; i <= 9 ; i++ )
		printf ( "%d\t", arr[i] ) ;

	quicksort ( arr, 0, 9 ) ;

	printf ( "\n" ) ;
	printf ( "Array after sorting:\n") ;

	for ( i = 0 ; i <= 9 ; i++ )
		printf ( "%d\t", arr[i] ) ;

	return 0 ;
}

void quicksort ( int a[ ], int lower, int upper )
{
	int i ;
	if ( upper > lower )
	{
		i = split ( a, lower, upper ) ;
		quicksort ( a, lower, i - 1 ) ;
		quicksort ( a, i + 1, upper ) ;
	}
}

int split ( int a[ ], int lower, int upper )
{
	int i, p, q, t ;

	p = lower + 1 ;
	q = upper ;
	i = a[lower] ;

	while ( q >= p )
	{
		while ( a[p] < i )
			p++ ;

		while ( a[q] > i )
			q-- ;

		if ( q > p )
		{
			t = a[p] ;
			a[p] = a[q] ;
			a[q] = t ;
		}
	}

	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;

	return q ;
}

