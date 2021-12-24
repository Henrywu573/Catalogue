/* Program that creates random numbers in a given file. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main( )
{
	FILE *fp ;
	char str [ 67 ] ;
	int i, noofr, j ;

	system ( "cls" ) ;

	printf ( "Enter file name: " ) ;
	scanf ( "%s", str ) ;

	printf ( "Enter number of records: " ) ;
	scanf ( "%d", &noofr ) ;

	fp = fopen ( str, "wb" ) ;
	if ( fp == NULL )
	{
		printf ( "Unable to create file." ) ;
		exit ( 0 ) ;
	}

	srand ( ( unsigned ) time ( NULL ) ) ;

	for ( i = 0 ; i < noofr ; i++ )
	{
		j = rand( ) % 1000 ;
		fwrite ( &j, sizeof ( int ), 1, fp ) ;
		printf ( "%d\t", j ) ;
	}

	fclose ( fp ) ;

	printf ( "File is created.\nPress any key to continue.\n" ) ;

	return 0 ;
}