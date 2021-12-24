/* CH6PR5.C: Program to store sparse matrix as a linked list */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

#define MAX1 3
#define MAX2 3

/* structure for col headnode */
struct cheadnode
{
	int colno ;
	struct node *down ;
	struct cheadnode *next ;
} ;

/* structure for row headnode */
struct rheadnode
{
	int rowno ;
	struct node * right ;
	struct rheadnode *next ;
} ;

/* structure for node to store element */
struct node
{
	int row ;
	int col ;
	int val ;
	struct node *right ;
	struct node *down ;
} ;

/* structure for special headnode */
struct spmat
{
	struct rheadnode *firstrow ;
	struct cheadnode *firstcol ;
	int noofrows ;
	int noofcols ;
} ;

struct sparse
{
	int *sp ;
	int row  ;
	struct spmat *smat ;
	struct cheadnode *chead[MAX2] ;
	struct rheadnode *rhead[MAX1] ;
	struct node *nd ;
} ;

void initsparse ( struct sparse * ) ;
void create_array ( struct sparse * ) ;
void display ( struct sparse ) ;
int count ( struct sparse ) ;
void create_triplet ( struct sparse *, struct sparse ) ;
void create_llist ( struct sparse * ) ;
void insert ( struct sparse *, struct spmat *, int, int, int ) ;
void show_llist ( struct sparse ) ;
void delsparse ( struct sparse * ) ;

int main( )
{
	struct sparse s1, s2 ;

	system ( "cls" ) ;

	initsparse ( &s1 ) ;
	initsparse ( &s2 ) ;

	create_array ( &s1 ) ;

	printf ( "Elements in sparse matrix:" ) ;
	display ( s1 ) ;

	create_triplet ( &s2, s1 ) ;

	create_llist ( &s2 ) ;
	printf ( "Information stored in linked list :" ) ;
	show_llist ( s2 ) ;

	delsparse ( &s1 ) ;
	delsparse ( &s2 ) ;

	return 0 ;
}

/* initializes structure elements */
void initsparse ( struct sparse *p )
{
	int i ;
	/* create row headnodes */
	for ( i = 0 ; i < MAX1 ; i++ )
		p -> rhead[i] = ( struct rheadnode * ) malloc ( sizeof ( struct 
                                                                                        rheadnode ) ) ;

	/* initialize and link row headnodes together */
	for ( i = 0 ; i < MAX1 - 1 ; i++ )
	{
		p -> rhead[i] -> next = p -> rhead[i + 1] ;
		p -> rhead[i] -> right = NULL ;
		p -> rhead[i] -> rowno = i ;
	}
	p -> rhead[i] -> right = NULL ;
	p -> rhead[i] -> next = NULL ;

	/* create col headnodes */
	for ( i = 0 ; i < MAX1 ; i++ )
		p -> chead[i] = ( struct cheadnode * ) malloc ( sizeof ( struct cheadnode ) ) ;

	/* initialize and link col headnodes together */
	for ( i = 0 ; i < MAX2 - 1 ; i++ )
	{
		p -> chead[i] -> next = p -> chead[i + 1] ;
		p -> chead[i] -> down = NULL ;
		p -> chead[i] -> colno = i ;
	}
	p -> chead[i] -> down = NULL ;
	p -> chead[i] -> next = NULL ;

	/* create and initialize special headnode */
	p -> smat = ( struct spmat * ) malloc ( sizeof ( struct spmat ) ) ;
	p -> smat -> firstcol = p -> chead[0] ;
	p -> smat -> firstrow = p -> rhead[0] ;
	p -> smat -> noofcols = MAX2 ;
	p -> smat -> noofrows = MAX1 ;
}

/* creates, dynamically the matrix of size MAX1 x MAX2 */
void create_array ( struct sparse *p )
{
	int n, i ;

	p -> sp = ( int * ) malloc ( MAX1 * MAX2 * sizeof ( int ) ) ;

	/* get the element and store it */
	for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
		printf ( "Enter element no. %d: ", i ) ;
		scanf ( "%d", &n ) ;
		* ( p -> sp + i ) = n ;
	}
	printf ( "\n" ) ;
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
	printf ( "\n\n" ) ;
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

/* creates an array of triplet containing info. about non-zero elements */
void create_triplet ( struct sparse *p, struct sparse s )
{
	int r = 0 , c = -1, l = -1, i ;

	p -> row = count ( s ) ;
	p -> sp = ( int * ) malloc ( p -> row * 3 * sizeof ( int ) ) ;

	for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
	{
		c++ ;
		/* sets the row and column values */
		if ( ( ( i % MAX2 ) == 0 ) && ( i != 0 ) )
		{
			r++ ;
			c = 0 ;
		}

		/* checks for non-zero element. Row, column and
		    non-zero element value is assigned to the matrix */

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

/* stores information of triplet in a linked list form */
void create_llist ( struct sparse *p )
{
	int j = 0, i ;
	for ( i = 0 ; i < p -> row ; i++, j+= 3 )
		insert ( p, p -> smat, * ( p -> sp + j ), * ( p -> sp + j + 1 ),
												* ( p -> sp + j + 2) ) ;
}

/* inserts element to the list */
void insert ( struct sparse *p, struct spmat *smat , int r, int c, int v )
{
	struct node *temp1, *temp2 ;
	struct rheadnode *rh ;
	struct cheadnode *ch ;
	int i, j ;

	/*  allocate and initialize memory for the node */
	p -> nd = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
	p -> nd -> col = c ;
	p -> nd -> row = r ;
	p -> nd -> val = v ;

	/* get the first row headnode */
	rh = smat -> firstrow ;

	/* get the proper row headnode */
	for ( i = 0 ; i < r ; i++ )
		rh = rh -> next ;
	temp1 = rh -> right ;

	/* if no element added in a row */
	if ( temp1 == NULL )
	{
		rh -> right = p -> nd ;
		p -> nd -> right = NULL ;
	}
	else
	{
		/* add element at proper position */
		while ( ( temp1 != NULL  ) && ( temp1 -> col < c ) )
		{
			temp2 = temp1 ;
			temp1 = temp1 -> right ;
		}
		temp2 -> right = p -> nd ;
		p -> nd -> right = NULL ;
	}

	/* link proper col headnode with the node */
	ch = p -> smat -> firstcol ;
	for ( j = 0 ; j < c ; j++ )
		ch = ch -> next ;
	temp1 = ch -> down ;

	/* if col not pointing to any node */
	if ( temp1 == NULL )
	{
		ch -> down = p -> nd ;
		p -> nd -> down = NULL ;
	}
	else
	{
		/* link previous node in column with next node in same column */
		while ( ( temp1 != NULL ) && ( temp1 -> row < r ) )
		{
			temp2 = temp1 ;
			temp1 = temp1 -> down ;
		}
		temp2 -> down = p -> nd ;
		p -> nd -> down = NULL ;
	}
}

void show_llist ( struct sparse s )
{
	struct node *temp ;
	/* get the first row headnode */
	int r = s.smat -> noofrows ;
	int i ;

	printf ( "\n" ) ;

	for ( i = 0 ; i < r ; i++ )
	{
		temp = s.rhead[i] -> right ;
		if ( temp != NULL )
		{
			while ( temp -> right != NULL )
			{
				printf ( "Row: %d Col: %d Val: %d\n", temp -> row, 
                                                                                 temp -> col, temp -> val ) ;
				temp = temp -> right ;
			}
			if ( temp -> row == i )
				printf ( "Row: %d Col: %d Val: %d\n", temp -> row, 
                                                                                 temp -> col, temp -> val ) ;
		}
	}
}

/* deallocates memory */
void delsparse ( struct sparse *p )
{
	int r = p -> smat -> noofrows ;
	struct rheadnode *rh ;
	struct node *temp1, *temp2 ;
	int i, c ;

	/* deallocate memeory of nodes by traversing rowwise */
	for ( i = r - 1 ; i >= 0 ; i-- )
	{
		rh = p -> rhead[i] ;
		temp1 = rh -> right ;
		while ( temp1 != NULL )
		{
			temp2 = temp1 -> right ;
			free ( temp1 ) ;
			temp1 = temp2 ;
		}
	}

	/* deallocate memory of row headnodes */
	for ( i = r - 1 ; i >= 0 ; i-- )
		free ( p -> rhead[i] ) ;

	/* deallocate memory of col headnodes */
	c = p -> smat -> noofcols ;
	for ( i = c - 1 ; i >= 0 ; i-- )
		free ( p -> chead[i] ) ;
}

