/* CH10PR1.C: Linear search in an unsorted array. */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main( )
{
	int arr[10] = { 11, 2, 9, 13, 57, 25, 17, 1, 90, 3 } ;
	int i, num ;

	system ( "cls" ) ;

	printf ( "Enter number to search: " ) ;
	scanf ( "%d", &num ) ;

	for ( i = 0 ; i <= 9 ; i++ )
	{
		if ( arr[i] == num )
			break ;
	}

	if ( i == 10 )
		printf ( "Number is not present in the array.\n" ) ;
	else
		printf ( "The number is at position %d in the array.\n", i ) ;

	return 0 ;
}

