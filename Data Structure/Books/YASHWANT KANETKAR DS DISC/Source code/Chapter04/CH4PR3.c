/* CH4PR3.C: Program to swap elements of array of pointers to strings. */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define MAX 6

char *names[MAX] ;
int count ;

int add ( char * ) ;
void swap ( int, int ) ;
void show( ) ;

int main( )
{
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
	printf ( "Names before swapping:\n" ) ;
	show ( ) ;

	swap ( 2, 3 ) ;
	printf ( "Names after swapping:\n" ) ;
	show( ) ;

	return 0 ;
}

/* adds given string */
int add ( char *s )
{
	if ( count < MAX )
	{
		names[count] = s ;
		count++ ;
		return 1 ;
	}
	else
		return 0 ;
}

/* swaps the names at given two positions */
void swap ( int i, int j )
{
	char *temp ;
	temp = names[i] ;
	names[i] = names[j] ;
	names[j] = temp ;
}

/* displays the elements */
void show ( )
{
	int i ;
	for ( i = 0 ; i < count ; i++ )
		puts ( names[i] ) ;
	printf ( "\n" ) ;
}

