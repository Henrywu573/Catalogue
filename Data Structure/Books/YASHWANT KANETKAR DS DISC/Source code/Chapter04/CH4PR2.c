/* CH4PR2: Program to check entered name in the master list. */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define MAX1 6
#define MAX2 10

char masterlist[MAX1][MAX2] ;
int count ;

int add ( char *s ) ;
int find ( char *s ) ;

int main( )
{
	char yourname[MAX2] ;
	int flag ;

	system ( "cls" ) ;

	flag = add ( "akshay" ) ;
	if ( flag == 0 )
		printf ( "Unable to add string\n" ) ;

	flag = add ( "parag" ) ;
	if ( flag == 0 )
		printf ( "Unable to add string\n" ) ;

	flag = add ( "raman" ) ;
	if ( flag == 0 )
		printf ( "Unable to add string\n" ) ;

	flag = add ( "srinivas" ) ;
	if ( flag == 0 )
		printf ( "Unable to add string\n" ) ;

	flag = add ( "gopal" ) ;
	if ( flag == 0 )
		printf ( "Unable to add string\n" ) ;

	flag = add ( "rajesh" ) ;
	if ( flag == 0 )
		printf ( "Unable to add string\n" ) ;

	printf ( "Enter your name: " ) ;
	gets ( yourname ) ;
	flag = find ( yourname ) ;
	if ( flag == 1 )
		printf ( "Welcome, you can enter the palace\n" ) ;
	else
		printf ( "Sorry, you are a trespasser\n" ) ;

	return 0 ;
}

/* adds string to the array */
int add ( char *s )
{
	if ( count < MAX1 )
	{
		if ( strlen ( s ) < MAX2 )
		{
			strcpy ( &masterlist[count][0], s ) ;
			count++ ;
			return 1 ;
		}
	}

	return 0 ;
}

/* finds the given string */
int find ( char *s )
{
	int flag = 0, i ;

	for ( i = 0 ; i < count ; i++ )
	{
		if ( strcmp ( &masterlist[i][0], s ) == 0 )
		{
			flag = 1 ;
			break ;
		}
	}

	return flag ;
}
