/* Sorting of dates using bubble sort. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int d, m ;
long int y ;

int main( )
{
	char dates[5][12], temp[12] ;
	long int arr[5], t ;
	int i, j, valid ;

	int isvalid( ) ;
	long int getnum ( char * ) ;

	system ( "cls" ) ;

	printf ( "Enter any five dates (dd\\mm\\yyyy) :-\n" ) ;
	for ( i = 0 ; i <= 4 ; i++ )
	{
		printf("%d) ",i + 1 ) ;
		scanf ( "%s", dates[i] ) ;

		/* Converts date in string to equivalent integer values. */
		arr[i] = getnum ( dates[i] ) ;

		/* Checks for valid date. */
		valid = isvalid( ) ;

		if ( !valid )
		{
			printf ( "This date does not exists. " ) ;
			printf ( "Enter any other date.\n" ) ;
			i-- ;
		}
	}

	/* Sorting of dates using Bubble sort method. */
	for ( i = 0 ; i <= 3 ; i++ )
	{
		for ( j = 0 ; j <= 3 - i ; j++ )
		{
			if ( arr[j] > arr[j + 1] )
			{
				t = arr[j] ;
				arr[j] = arr[j + 1] ;
				arr[j + 1] = t ;

				strcpy ( temp, dates[j] ) ;
				strcpy ( dates[j], dates[j + 1]) ;
				strcpy ( dates[j + 1], temp ) ;
			}
		}
	}

	printf ( "Dates in sorted order are :- \n" ) ;
	for ( i = 0 ; i <= 4 ; i++ )
		printf ( "%s\n", dates[i] ) ;

	return 0 ;
}

/* checks valid date */
int isvalid ( )
{
	int isleap ( long int ) ;

	if ( y <= 0 || m <= 0 || d <= 0 || m > 12 || y > 16384 ||
		 ( m == 2 && !isleap ( y ) && d > 28 ) ||
		 ( m == 2 && isleap ( y ) && d > 29 ) ||
		 ( ( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10
		  || m == 12 ) && d > 31 ) || ( ( m == 4 || m == 6 || m == 9 ||
			 m == 11 ) && d > 30 ) )
		return 0 ;
	else
		return 1 ;
}

/* checks whether the given year is leap or not */
int isleap ( long int y )
{
	return ( y % 4 == 0 ) ^ ( y % 100 == 0 ) ^ ( y % 400 == 0 ) ;
}

/* converts dates in string into equivalent integer values */
long int getnum ( char *date )
{
	char *p, str[15] ;
	long int num = 0 ;

	strcpy ( str, date ) ;

	d = m = y = 0 ;
	p = strtok ( str, "\\" ) ;
	if ( p != NULL )
		d = num = atoi ( p )  ;

	p = strtok(NULL, "\\");
	if ( p != NULL )
		m = atoi ( p ) ;
	num += m * 32 ;

	p = strtok(NULL, "\\");
	if ( p != NULL )
		y = atol ( p ) ;
	num += y * 512L ;

	return num ;
}