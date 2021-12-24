/* CH10PR3.C: Binary search in a sorted array. */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main( )
{
	int arr[10] = { 1, 2, 3, 9, 11, 13, 17, 25, 57, 90 } ;
	int mid, lower = 0 , upper = 9, num, flag = 1 ;

	system ( "cls" ) ;

	printf ( "Enter number to search: " ) ;
	scanf ( "%d", &num ) ;

	for ( mid = ( lower + upper ) / 2 ; lower <= upper ;
		mid = ( lower + upper ) / 2 )
	{
		if ( arr[mid] == num )
		{
			printf ( "The number is at position %d in the array.\n", 
                               mid ) ;
			flag = 0 ;
			break ;
		}
		if ( arr[mid] > num )
			upper = mid - 1 ;
		else
			lower = mid + 1 ;
	}

	if ( flag )
		printf ( "Element is not present in the array.\n" ) ;

	return 0 ;
}
