/* CH10PR9.C: Heap Sort. */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

void makeheap ( int [ ], int ) ;
void heapsort ( int [ ], int ) ;

int main( )
{
	int arr[10] = { 11, 2, 9, 13, 57, 25, 17, 1, 90, 3 } ;
	int i ;

	system ( "cls" ) ;
	printf ( "Heap Sort\n\n" ) ;
	makeheap ( arr, 10 ) ;

	printf ( "Before Sorting:\n" ) ;
	for ( i = 0 ; i <= 9 ; i++ )
		printf ( "%d\t", arr[i] ) ;

	heapsort ( arr, 10 ) ;
	printf ( "\n" ) ;
	printf ( "After Sorting:\n" ) ;
	for ( i = 0 ; i <= 9 ; i++ )
		printf ( "%d\t", arr[i] ) ;

	return 0 ;
}

/* creates heap from the tree*/
void makeheap ( int x[ ], int n )
{
	int i, val, s, f ;
	for ( i = 1 ; i < n ; i++ )
	{
		val = x[i] ;
		s = i ;
		f = ( s - 1 ) / 2 ;
		while ( s > 0 && x[f] < val )
		{
			x[s] = x[f] ;
			s = f ;
			f = ( s - 1 ) / 2 ;
		}
		x[s] = val ;
	}
}

/* sorts heap */
void heapsort ( int x[ ], int n )
{
	int i, s, f, ivalue ;
	for ( i = n - 1 ; i > 0 ; i-- )
	{
		ivalue = x[i] ;
		x[i] = x[0] ;
		f = 0 ;

		if ( i == 1 )
			s = -1 ;
		else
			s = 1 ;

		if ( i > 2 && x[2] > x[1] )
			s = 2 ;

		while ( s >= 0 && ivalue < x[s] )
		{
			x[f] = x[s] ;
			f = s ;
			s = 2 * f + 1 ;

			if ( s + 1 <= i - 1 && x[s] < x[s + 1] )
				s++ ;
			if ( s > i - 1 )
				s = -1 ;
		}
		x[f] = ivalue ;
	}
}
