/* program to check if given strings form an acrostic */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define MAX1 5
#define MAX2 6

int main( )
{
	char str[MAX1][MAX2] ;
	int i ;
	int check ( char * ) ;

  system ( "cls" ) ;

	strcpy ( str[0], "ROTAS" ) ;
	strcpy ( str[1], "OPERA" ) ;
	strcpy ( str[2], "TENET" ) ;
	strcpy ( str[3], "AREPO" ) ;
	strcpy ( str[4], "SATOR" ) ;

	printf ( "The strings are:\n" ) ;
	for ( i = 0 ; i < MAX1 ; i++ )
    		printf ( "%s\n", str[i] ) ;

	i = check ( str[0] ) ;

	if ( i == 1 )
		printf ( "The given strings form an acrostic.\n" ) ;
	else
		printf ( "The given strings do not form an acrostic.\n" ) ;

  return 0 ;
}

/* checks if forms an acrostic */
int check ( char *s )
{
	int i, j ;
	j = ( MAX1 * MAX2 ) - 2 ;

	for ( i = 0 ; i < 15 ; i++, j-- )
	{
		if ( * ( s + i ) == * ( s + j ) )
			continue ;
		else
			break ;
	}

	if ( i == 15 )
		return 1 ;
	else
		return 0 ;
}