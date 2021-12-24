/* Sorting of a structure on names using bubble sort */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main( )
{
	struct emp
	{
		char empid[7] ;
		char name[25] ;

		int age ;
		float sal ;
	} ;

	int i, j ;
	struct emp e[5] ;
	char id[5][7], temp[7] ;
	float ff ( float ) ;

	system ( "cls" ) ;
	printf ( "Enter empid, name, age and salary :-\n") ;
	for ( i = 0 ; i <= 4 ; i++ )
	{
		scanf ( "%s %s %d %f", e[i].empid, e[i].name, &e[i].age, &e[i].sal ) ;
		strcpy ( id[i], e[i].empid ) ;
	}

	for ( i = 0 ; i <= 3 ; i++ )
	{
		for ( j = 0 ; j <= 3 - i ; j++ )
		{
			if ( strcmp ( id[j], id[j + 1] ) > 0 )
			{
				strcpy ( temp, id[j] ) ;
				strcpy ( id[j], id[j + 1] ) ;
				strcpy ( id[j + 1], temp ) ;
			}
		}
	}

	printf ( "\nRecords after sorting") ;
	printf ( "\nName, age and salary after sorting :-\n") ;
	for ( i = 0 ; i <= 4 ; i++ )
	{
		for ( j = 0 ; j <= 4 ; j++ )
		{
			if ( strcmp( id[i], e[j].empid ) == 0 )
				printf ( "%s %s %d %f\n", e[j].empid, e[j].name, e[j].age, e[j].sal ) ;
		}
	}

	return 0 ;
}

float ff ( float f )
{
	float *f1 = &f ;
    return *f1 ;
}