/* CH4PR4.C: Program to allocate memory dynamically for strings, and store
			 their addresses in array of pointers to strings. */
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>

int main( )
{
	char *name[5] ;
	char str[20] ;
	int i ;

	system ( "cls" ) ;

	for ( i = 0 ; i < 5 ; i++ )
	{
		printf ( "Enter a String: " ) ;
		gets ( str ) ;
		name[i] = ( char * ) malloc ( strlen ( str ) + 1 ) ;
		strcpy ( name[i], str ) ;
	}

	printf ( "\n" ) ;

	printf ( "The strings are:\n" ) ;

	for ( i = 0 ; i < 5 ; i++ )
		printf ( "%s\n", name[i] ) ;

	for ( i = 0 ; i < 5 ; i++ )
		free ( name[i] ) ;

	return 0 ;
}
