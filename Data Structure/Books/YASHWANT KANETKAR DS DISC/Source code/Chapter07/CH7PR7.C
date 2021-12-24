/* CH7PR7.C: Program to evaluate an expression entered in postfix form */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>

#define MAX 50

struct postfix
{
	int stack[MAX] ;
	int top, nn ;
	char *s ;
} ;

void initpostfix ( struct postfix * ) ;
void setexpr ( struct postfix *, char * ) ;
void push ( struct postfix *, int ) ;
int pop ( struct postfix * ) ;
void calculate ( struct postfix * ) ;
void show ( struct postfix ) ;

int main( )
{
	struct postfix q ;
	char expr[MAX] ;

	system ( "cls" ) ;

	initpostfix ( &q ) ;

	printf ( "Enter postfix expression to be evaluated:\n" ) ;
	gets ( expr ) ;

	setexpr ( &q, expr ) ;
	calculate ( &q ) ;
	show ( q ) ;

	return 0 ;
}

/* initializes structure elements */
void initpostfix ( struct postfix *p )
{
	p -> top = -1 ;
}

/* sets s to point to the given expr. */
void setexpr ( struct postfix *p, char *str )
{
	p -> s = str ;
}

/* adds digit to the stack */
void push ( struct postfix *p, int item )
{
	if ( p -> top == MAX - 1 )
		printf ( "Stack is full.\n" ) ;
	else
	{
		p -> top++ ;
		p -> stack[p -> top] = item ;
	}
}

/* pops digit from the stack */
int pop ( struct postfix *p )
{
	int data ;
	if ( p -> top == -1 )
	{
		printf ( "Stack is empty.\n" ) ;
		return NULL ;
	}

	data = p -> stack[p -> top] ;
	p -> top-- ;

	return data ;
}

/* evaluates the postfix expression */
void calculate( struct postfix *p )
{
	int n1, n2, n3 ;
	while ( *( p -> s ) )
	{
		/* skip whitespace, if any */
		if ( *( p -> s ) == ' ' || *( p -> s ) == '\t' )
		{
			p -> s++ ;
			continue ;
		}

		/* if digit is encountered */
		if ( isdigit ( *( p -> s ) ) )
		{
			p -> nn = *( p -> s ) - '0' ;
			push ( p, p -> nn ) ;
		}
		else
		{
			/* if operator is encountered */
			n1 = pop ( p ) ;
			n2 = pop ( p ) ;
			switch ( *( p -> s ) )
			{
				case '+' :
					  n3 = n2 + n1 ;
					  break ;

				case '-' :
					  n3 = n2 - n1 ;
					  break ;

				case '/' :
					  n3 = n2 / n1 ;
					  break ;

				case '*' :
					  n3 = n2 * n1 ;
					  break ;

				case '%' :
					  n3 = n2 % n1 ;
					  break ;

				case '$' :
					  n3 = ( int ) pow ( n2 , n1 ) ;
					  break ;

				default :
					  printf ( "Unknown operator\n" ) ;
					  exit ( 1 ) ;
			}

			push ( p, n3 ) ;
		}
		p -> s++ ;
	}
}

/* displays the result */
void show ( struct postfix p )
{
	p.nn = pop ( &p ) ;
	printf ( "Result is: %d", p.nn ) ;
}

