/* CH4PR1.C: Program to perform some basic operations on string. */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int xstrlen ( char * ) ;
void xstrcpy ( char *, char * ) ;
void xstrcat ( char *, char * ) ;
int xstrcmp ( char *, char * ) ;
void show ( char * ) ;

int main( )
{
	char s1[ ] = "kicit" ;
	char s2[ ] = "Nagpur" ;
	char s3[20] ;
	int len ;

	system ( "cls" ) ;

	printf ( "String s1: %s\n", s1 ) ;
	len = xstrlen ( s1 ) ;
	printf ( "length of the string s1: %d\n", len ) ;

	printf ( "String s2: %s\n", s2 ) ;

	xstrcpy ( s3, s1 ) ;
	printf ( "String s3 after copying s1 to it: %s\n", s3 ) ;

	xstrcat ( s3, s2 ) ;
	printf ( "String s3 after concatenation: %s\n", s3 ) ;

	if ( xstrcmp ( s1, s2 ) == 0 )
		printf ( "The strings s1 and s2 are similar\n" ) ;
	else
		printf ( "The strings s1 and s2 are not similar\n" ) ;

	return 0 ;
}

/* finds the length of the string */
int xstrlen ( char *s )
{
	int l = 0 ;
	while ( *s )
	{
		l++ ;
		s++ ;
	}
	return l ;
}

/* copies source string s to the target string t */
void xstrcpy ( char *t, char *s )
{
	while ( *s )
	{
		*t = *s ;
		t++ ;
		s++ ;
	}
	*t = '\0' ;
}

/* concatenates the two strings */
void xstrcat ( char *t, char *s )
{
	while ( *t )
		t++ ;
	while ( *s )
		*t++ = *s++ ;
	*t = '\0' ;
}

/* compares two strings s and t for equality */
int xstrcmp ( char *s, char *t )
{
	while ( *s == *t )
	{
		if ( ! ( *s ) )
			return 0 ;
		s++ ;
		t++ ;
	}
	return ( *s - *t ) ;
}

