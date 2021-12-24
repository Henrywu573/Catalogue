/* CH6PR3.C: Program to add two sparse matrices */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

#define MAX1 3
#define MAX2 3
#define MAXSIZE 9
#define BIGNUM 100

struct sparse
{
	int *sp ;
	int row ;
	int *result ;
} ;

void initsparse ( struct sparse * ) ;
void create_array ( struct sparse * ) ;
int count ( struct sparse ) ;
void display ( struct sparse ) ;
void create_tuple ( struct sparse *, struct sparse ) ;
void display_tuple ( struct sparse ) ;
void addmat ( struct sparse *, struct sparse, struct sparse ) ;
void display_result ( struct sparse ) ;
void delsparse ( struct sparse * ) ;

int main( )
{
    struct sparse s[5] ;
    int i ;

    system ( "cls" ) ;

    for ( i = 0 ; i <= 4 ; i++ )
    	initsparse ( &s[i] ) ;

	create_array ( &s[0] ) ;

	create_tuple ( &s[1], s[0] ) ;
	display_tuple ( s[1] ) ;

	create_array ( &s[2] ) ;

	create_tuple ( &s[3], s[2] ) ;
	display_tuple ( s[3] ) ;

	addmat ( &s[4], s[1], s[3] ) ;

	printf ( "\nResult of addition of two matrices: " ) ;
	display_result ( s[4] ) ;

    for ( i = 0 ; i <= 4 ; i++ )
		delsparse ( &s[i] ) ;

  return 0 ;
}

/* initialises structure elements */
void initsparse ( struct sparse *p )
{
	p -> sp = NULL ;
	p -> result = NULL ;
}

/* dynamically creates the matrix */
void create_array ( struct sparse *p )
{
	int n, i ;

	/* allocate memory */
	p -> sp = ( int * ) malloc ( MAX1 * MAX2 * sizeof ( int ) ) ;

	/* add elements to the array */
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

	/* get the total number of non-zero elements
	   and add 1 to store total no. of rows, cols, and non-zero values */
	p -> row = count ( s ) + 1 ;

	/* allocate memory */
	p -> sp = ( int * ) malloc ( p -> row * 3 * sizeof ( int ) ) ;

	/* store information about
	   total no. of rows, cols, and non-zero values */
	* ( p -> sp + 0 ) = MAX1 ;
	* ( p -> sp + 1 ) = MAX2 ;
	* ( p -> sp + 2 ) = p -> row - 1 ;

	l = 2 ;

	/* scan the array and store info. about non-zero values
	   in the 3-tuple */
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

/* displays the contents of the matrix */
void display_tuple ( struct sparse s )
{
    int i, j ;

	/* traverses the entire matrix */
	printf ( "\nElements in a 3-tuple: \n" ) ;

	j = ( * ( s.sp + 2 ) * 3 ) + 3 ;

	for ( i = 0 ; i < j ; i++ )
	{
		/* positions the cursor to the new line for every new row */
		if ( i % 3 == 0 )
			printf ( "\n" ) ;
		printf ( "%d\t", * ( s.sp + i ) ) ;
	}
    printf ( "\n" ) ;
}

/* carries out addition of two matrices */
void addmat ( struct sparse *p, struct sparse s1, struct sparse s2 )
{
	int i = 1, j = 1, k = 1 ;
	int elem = 1 ;
	int max, amax, bmax ;
	int rowa, rowb, cola, colb, vala, valb ;

	/* get the total number of non-zero values
	   from both the matrices */
	amax = * ( s1.sp + 2 ) ;
	bmax = * ( s2.sp + 2 ) ;
	max = amax + bmax ;

	/* allocate memory for result */
	p -> result = ( int * ) malloc ( MAXSIZE * 3 * sizeof ( int ) ) ;

	while ( elem <= max )
	{
		/* check if i < max. non-zero values
		   in first 3-tuple and get the values */
		if ( i <= amax )
		{
			rowa =  * ( s1.sp + i * 3 + 0 ) ;
			cola =  * ( s1.sp + i * 3 + 1 ) ;
			vala =  * ( s1.sp + i * 3 + 2 ) ;
		}
		else
			rowa = cola = BIGNUM ;

		/* check if j < max. non-zero values
		   in secon 3-tuple and get the values */
		if ( j <= bmax )
		{
			rowb = * ( s2.sp + j * 3 + 0 ) ;
			colb = * ( s2.sp + j * 3 + 1 ) ;
			valb = * ( s2.sp + j * 3 + 2 ) ;
		}
		else
		    rowb = colb = BIGNUM ;

		/* if row no. of both 3-tuple are same */
		if ( rowa == rowb )
		{
			/* if col no. of both 3-tuple are same */
			if ( cola == colb )
			{
				/* add tow non-zero values
				   store in result */
				* ( p -> result + k * 3 + 0 ) = rowa ;
				* ( p -> result + k * 3 + 1 ) = cola ;
				* ( p -> result + k * 3 + 2 ) = vala + valb ;
				i++ ;
				j++ ;
				max-- ;
			}

			/* if col no. of first 3-tuple is < col no. of
			   second 3-tuple, then add info. as it is
			   to result */
			if ( cola < colb )
			{
				* ( p -> result + k * 3 + 0 ) = rowa ;
				* ( p -> result + k * 3 + 1 ) = cola ;
				* ( p -> result + k * 3 + 2 ) = vala ;
				i++ ;
			}

			/* if col no. of first 3-tuple is > col no. of
			   second 3-tuple, then add info. as it is
			   to result */
			if ( cola > colb )
			{
				* ( p -> result + k * 3 + 0 ) = rowb ;
				* ( p -> result + k * 3 + 1 ) = colb ;
				* ( p -> result + k * 3 + 2 ) = valb ;
				j++ ;
			}
			k++ ;
	    }

		/* if row no. of first 3-tuple is < row no. of
		   second 3-tuple, then add info. as it is
	       to result */
		if ( rowa < rowb )
		{
			* ( p -> result + k * 3 + 0 ) = rowa ;
			* ( p -> result + k * 3 + 1 ) = cola ;
			* ( p -> result + k * 3 + 2 ) = vala ;
			i++ ;
			k++ ;
        }

		/* if row no. of first 3-tuple is > row no. of
		   second 3-tuple, then add info. as it is
		   to result */
		if ( rowa > rowb )
		{
			* ( p -> result + k * 3 + 0 ) = rowb ;
			* ( p -> result + k * 3 + 1 ) = colb ;
			* ( p -> result + k * 3 + 2 ) = valb ;
			j++ ;
			k++ ;
		}
		elem++ ;
	}

	/* add info about the total no. of rows,
	   cols, and non-zero values that the resultant array
	   contains to the result */
	* ( p -> result + 0 ) = MAX1 ;
	* ( p -> result + 1 ) = MAX2 ;
	* ( p -> result + 2 ) = max ;
}

/* displays the contents of the matrix */
void display_result ( struct sparse s )
{
    int i ;

	/* traverses the entire matrix */
	for ( i = 0 ; i < ( * ( s.result + 0 + 2 ) + 1 ) * 3 ; i++ )
	{
		/* positions the cursor to the new line for every new row */
		if ( i % 3 == 0 )
			printf ( "\n" ) ;
		printf ( "%d\t", * ( s.result + i ) ) ;
	}
}

/* deallocates memory */
void delsparse ( struct sparse *p )
{
	if ( p -> sp != NULL )
		free ( p -> sp ) ;
	if ( p -> result != NULL )
		free ( p -> result ) ;
}

