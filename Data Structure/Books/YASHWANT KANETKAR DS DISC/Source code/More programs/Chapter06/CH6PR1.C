/* CH6PR1.C: Program to create a 3-tuple from a given matrix */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

#define MAX1 3
#define MAX2 3

struct sparse
{
	int *sp ;
	int row ;
} ;

void initsparse ( struct sparse * ) ;
void create_array ( struct sparse * ) ;
void display ( struct sparse ) ;
int count ( struct sparse ) ;
void create_tuple ( struct sparse *, struct sparse ) ;
void display_tuple ( struct sparse ) ;
void delsparse ( struct sparse * ) ;

int main( )
{
	struct sparse s1, s2 ;
    int c ;

	system ( "cls" ) ;

    initsparse ( &s1 ) ;
    initsparse ( &s2 ) ;

    create_array ( &s1 ) ;
    printf ( "\nElements in Sparse Matrix: " ) ;
	display ( s1 ) ;

	c = count ( s1 ) ;
	printf ( "\n\nNumber of non-zero elements: %d", c ) ;

	create_tuple ( &s2, s1 ) ;
	printf ( "\n\nArray of non-zero elements: " ) ;
    display_tuple ( s2 ) ;

    delsparse ( &s1 ) ;
    delsparse ( &s2 ) ;

    return 0 ;
}

/* initialises element of structure */
void initsparse ( struct sparse *p )
{
	p -> sp = NULL ;
}

/* dynamically creates the matrix of size MAX1 x MAX2 */
void create_array ( struct sparse *p )
{
	int n, i ;

	p -> sp = ( int * ) malloc ( MAX1 * MAX2 * sizeof ( int ) ) ;

	for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
			printf ( "Enter element no. %d: ", i ) ;
			scanf ( "%d", &n ) ;
			* ( p -> sp + i ) = n ;
	}
}

/* displays the contents of the matrix */
void display ( struct sparse p )
{
	int i ;

	/* traverses the entire matrix */
	for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
		/* positions the cursor to the new line for every new row */
		if ( i % MAX2 == 0 )
			printf ( "\n" ) ;
		printf ( "%d\t", * ( p.sp + i ) ) ;
	}
}

/* counts the number of non-zero elements */
int count ( struct sparse p )
{
	int cnt = 0, i ;

	for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
		if ( * ( p.sp + i ) != 0 )
			cnt++ ;
	}
	return cnt ;
}

/* creates an array that stores information about non-zero elements */
void create_tuple ( struct sparse *p, struct sparse s )
{
	int r = 0 , c = -1, l = -1, i ;

	p -> row = count ( s ) + 1 ;

	p -> sp = ( int * ) malloc ( p -> row * 3 * sizeof ( int ) ) ;
    * ( p -> sp + 0 ) = MAX1 ;
    * ( p -> sp + 1 ) = MAX2 ;
    * ( p -> sp + 2 ) = p -> row - 1 ;

    l = 2 ;

	for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
		c++ ;

		/* sets the row and column values */
		if ( ( ( i % MAX2 ) == 0 ) && ( i != 0 ) )
		{
			r++ ;
			c = 0 ;
		}

		/* checks for non-zero element
		   row, column and non-zero element value
		   is assigned to the matrix */
		if ( * ( s.sp + i ) != 0 )
		{
			l++ ;
			* ( p -> sp + l ) = r ;
			l++ ;
			* ( p -> sp + l ) = c ;
			l++ ;
			* ( p -> sp + l ) = * ( s.sp + i ) ;
		}
	}
}

/* displays the contents of 3-tuple */
void display_tuple ( struct sparse p )
{
    int i ;

	for ( i = 0 ; i < p.row * 3 ; i++ )
	{
		if ( i % 3 == 0 )
			printf ( "\n" ) ;
		printf ( "%d\t", * ( p.sp + i ) ) ;
	}
}

/* deallocates memory */
void delsparse ( struct sparse *p )
{
	free ( p -> sp ) ;
}

