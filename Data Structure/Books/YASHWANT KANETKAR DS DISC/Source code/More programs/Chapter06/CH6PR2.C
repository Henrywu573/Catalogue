/* CH6PR2.C: Program to transpose a sparse matrix */

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
void transpose ( struct sparse *, struct sparse ) ;
void display_transpose ( struct sparse ) ;
void delsparse ( struct sparse * ) ;

int main( )
{
	struct sparse s[3] ;
    int c, i ;

    for ( i = 0 ; i <= 2 ; i++ )
	    initsparse ( &s[i] ) ;

   system ( "cls" ) ;

	create_array ( &s[0] ) ;

	printf ( "\nElements in Sparse Matrix: " ) ;
	display ( s[0] ) ;

	c = count ( s[0] ) ;
	printf ( "\n\nNumber of non-zero elements: %d", c ) ;

	create_tuple ( &s[1], s[0] ) ;
	printf ( "\n\nArray of non-zero elements: " ) ;
	display_tuple ( s[1] ) ;

	transpose ( &s[2], s[1] ) ;
	printf ( "\n\nTranspose of array: " ) ;
	display_transpose ( s[2] ) ;

	for ( i = 0 ; i <= 2 ; i++ )
	    delsparse ( &s[i] ) ;

  return 0 ;
}

/* initialises data members */
void initsparse ( struct sparse *p )
{
	p -> sp = NULL ;
}

/* dynamically creates the matrix of size MAX1 x MAX2 */
void create_array ( struct sparse *p )
{
	int n, i ;

	p -> sp = ( int * ) malloc ( MAX1 * MAX2 * sizeof ( int ) )  ;

	for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
			printf ( "Enter element no. %d:", i ) ;
			scanf ( "%d", &n ) ;

			* ( p -> sp + i ) = n ;
	}
}

/* displays the contents of the matrix */
void display ( struct sparse s )
{
	int i ;

	/* traverses the entire matrix */
	for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
		/* positions the cursor to the new line for every new row */
		if ( i % MAX2 == 0 )
		    printf ( "\n" ) ;
		printf ( "%d\t", * ( s.sp + i ) ) ;
	}
}

/* counts the number of non-zero elements */
int count ( struct sparse s )
{
	int cnt = 0, i ;

	for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
		if ( * ( s.sp + i ) != 0 )
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

/* obtains transpose of an array */
void transpose ( struct sparse *p, struct sparse s )
{
	int x, q, pos_1, pos_2, col, elem, c, y ;

    /* allocate memory */
    p -> sp = ( int * ) malloc ( s.row * 3 * sizeof ( int ) ) ;
    p -> row = s.row ;

    /* store total number of rows, cols
       and non-zero elements */
    * ( p -> sp + 0 ) = * ( s.sp + 1 ) ;
    * ( p -> sp + 1 ) = * ( s.sp + 0 ) ;
    * ( p -> sp + 2 ) = * ( s.sp + 2 ) ;

    col = * ( p -> sp + 1 ) ;
    elem = * ( p -> sp + 2 ) ;

    if ( elem <= 0 )
        return ;

    x = 1 ;

    for ( c = 0 ; c < col ; c++ )
    {
        for ( y = 1 ; y <= elem ; y++ )
        {
            q = y * 3 + 1 ;
            if ( * ( s.sp + q ) == c )
            {
                pos_2 = x * 3 + 0 ;
                pos_1 = y * 3 + 1 ;
                * ( p -> sp + pos_2 ) = * ( s.sp + pos_1 ) ;

                pos_2 = x * 3 + 1 ;
                pos_1 = y * 3 + 0 ;
                * ( p -> sp + pos_2 ) = * ( s.sp + pos_1 ) ;

                pos_2 = x * 3 + 2 ;
                pos_1 = y * 3 + 2 ;
                * ( p -> sp + pos_2 ) = * ( s.sp + pos_1 ) ;

                x++ ;
            }
        }
    }
}

/* displays 3-tuple after transpose operation */
void display_transpose ( struct sparse p )
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

