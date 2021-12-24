/* CH3PR5.C: Program to add two polynomials. */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define MAX 10

struct term
{
	int coeff ;
	int exp ;
} ;

struct poly
{
	struct term t [10] ;
	int noofterms ;
} ;


void initpoly ( struct poly * ) ;
void polyappend ( struct poly *, int c, int e ) ;
struct poly polyadd ( struct poly, struct poly ) ;
void display ( struct poly ) ;

int main( )
{
	struct poly p1, p2, p3 ;

	system ( "cls" ) ;

	initpoly ( &p1 ) ;
	initpoly ( &p2 ) ;
	initpoly ( &p3 ) ;

	polyappend ( &p1, 1, 7 ) ;
	polyappend ( &p1, 2, 6 ) ;
	polyappend ( &p1, 3, 5 ) ;
	polyappend ( &p1, 4, 4 ) ;
	polyappend ( &p1, 5, 2 ) ;

	polyappend ( &p2, 1, 4 ) ;
	polyappend ( &p2, 1, 3 ) ;
	polyappend ( &p2, 1, 2 ) ;
	polyappend ( &p2, 1, 1 ) ;
	polyappend ( &p2, 2, 0 ) ;

	p3 = polyadd ( p1, p2 ) ;

	printf ( "First polynomial:\n" ) ;
	display ( p1 ) ;

	printf ( "Second polynomial:\n" ) ;
	display ( p2 ) ;

	printf ( "Resultant polynomial:\n" ) ;
	display ( p3 ) ;

	return 0 ;
}

/* initializes elements of struct poly */
void initpoly ( struct poly *p )
{
	int i ;
	p -> noofterms = 0 ;
	for ( i = 0 ; i < MAX ; i++ )
	{
		p -> t[i].coeff = 0 ;
		p -> t[i].exp = 0 ;
	}
}

/* adds the term of polynomial to the array t */
void polyappend ( struct poly *p, int c, int e )
{
	p -> t[p -> noofterms].coeff = c ;
	p -> t[p -> noofterms].exp =  e ;
	( p -> noofterms ) ++ ;
}

/* displays the polynomial equation */
void display ( struct poly p )
{
	int flag = 0, i ;
	for ( i = 0 ; i < p.noofterms ; i++ )
	{
		if ( p.t[i].exp != 0 )
			printf ( "%d x^%d + ", p.t[i].coeff, p.t[i].exp ) ;
		else
		{
			printf ( "%d", p.t[i].coeff ) ;
			flag = 1 ;
		}
	}
	if ( !flag )
		printf ( "\b\b  " ) ;
	printf ( "\n\n" ) ;
}

/* adds two polynomials p1 and p2 */
struct poly polyadd ( struct poly p1, struct poly p2 )
{
	int i, j, c ;
	struct poly p3 ;
	initpoly ( &p3 ) ;

	if ( p1.noofterms > p2.noofterms )
		c = p1.noofterms ;
	else
		c = p2.noofterms ;

	for ( i = 0, j = 0 ; i <= c ; p3.noofterms++ )
	{
		if ( p1.t[i].coeff == 0 && p2.t[j].coeff == 0 )
			break ;
		if ( p1.t[i].exp >= p2.t[j].exp )
		{
			if ( p1.t[i].exp == p2.t[j].exp )
			{
				p3.t[p3.noofterms].coeff = p1.t[i].coeff + p2.t[j].coeff ;
				p3.t[p3.noofterms].exp = p1.t[i].exp ;
				i++ ;
				j++ ;
			}
			else
			{
				p3.t[p3.noofterms].coeff = p1.t[i].coeff ;
				p3.t[p3.noofterms].exp = p1.t[i].exp ;
				i++ ;
			}
		}
		else
		{
			p3.t[p3.noofterms].coeff = p2.t[j].coeff ;
			p3.t[p3.noofterms].exp = p2.t[j].exp ;
			j++ ;
		}
	}
	return p3 ;
}
