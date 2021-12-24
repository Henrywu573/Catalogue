/* Sorting of a sturcture of multiple keys. */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

struct stud
{
	char name[25] ;
	int age ;
	float height ;
} ;

int main( )
{
	int i, j ;
	struct stud s[5], temp ;

	float ff ( float ) ;

	system ( "cls" ) ;

	printf ( "Enter student's name, age and height in cm :-\n") ;
	for ( i = 0 ; i <= 4 ; i++ )
	{
		fflush ( stdin ) ;
		gets ( s[i].name ) ;
		scanf ( "%d %f", &s[i].age, &s[i].height ) ;
	}

	system ( "cls" ) ;

	for ( i = 0 ; i <= 3 ; i++ )
	{
		for ( j = 0 ; j <= 3 - i ; j++ )
		{
			if ( strcmp ( s[j].name, s[j + 1].name ) >= 0 )
			{
				if ( strcmp ( s[j].name, s[j + 1].name ) == 0 )
				{
					if ( s[j].age > s[j + 1].age )
					{
						temp = s[j] ;
						s[j] = s[j + 1] ;
						s[j + 1] = temp ;
					}
				}
				else
				{
					temp = s[j] ;
					s[j] = s[j + 1] ;
					s[j + 1] = temp ;
				}
			}
		}
	}

	printf ( "Records after sorting :-\n") ;
	printf ( "Students Name\t\tAge Height\n" ) ;

	for ( i = 0 ; i <= 4 ; i++ )
	{
		printf ( "%-20s %2d %.2f\n", s[i].name, s[i].age, s[i].height ) ;
	}

	return 0 ;
}

float ff ( float f )
{
	float *f1 = &f ;
    return *f1 ;
}