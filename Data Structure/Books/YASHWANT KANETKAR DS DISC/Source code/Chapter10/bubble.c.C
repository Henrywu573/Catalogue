/* CH10PR4.C: Bubble sort. */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main( )
{
	int arr[5] = { 25, 17, 31, 13, 2 } ;
	int i, j, temp ;

	system ( "cls" ) ;

	printf ( "Bubble sort.\n\n" ) ;
	printf ( "Array before sorting:\n") ;

	for ( i = 0 ; i <= 4 ; i++ )
		printf ( "%d\t", arr[i] ) ;

	for ( i = 0 ; i <= 3 ; i++ )
	{
		for ( j = 0 ; j <= 3 - i ; j++ )
		{
			if ( arr[j] > arr[j + 1] )
			{
				temp = arr[j] ;
				arr[j] = arr[j + 1] ;
				arr[j + 1] = temp ;
			}
		}
	}

	printf ( "\n" ) ;
	printf ( "Array after sorting:\n") ;

	for ( i = 0 ; i <= 4 ; i++ )
		printf ( "%d\t", arr[i] ) ;

	return 0 ;
}

