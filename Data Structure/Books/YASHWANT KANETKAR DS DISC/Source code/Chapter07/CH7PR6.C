/* CH7PR6.C: Program to convert an expression in
			 postfix form to an infix form */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define MAX 50

struct postfix
{
	char stack[MAX][MAX], target[MAX] ;
	char temp1[2], temp2[2] ;
	char str1[MAX], str2[MAX], str3[MAX] ;
	int i, top ;
} ;

void initpostfix ( struct postfix * ) ;
void setexpr ( struct postfix *, char * ) ;
void push ( struct postfix *, char * ) ;
void pop ( struct postfix *, char * ) ;
void convert ( struct postfix * ) ;
void show ( struct postfix ) ;

int main( )
{
	struct postfix q ;
	char expr[MAX] ;

	system ( "cls" ) ;

	initpostfix ( &q ) ;

	printf ( "Enter an expression in postfix form:\n" ) ;
	gets ( expr ) ;

	setexpr ( &q, expr ) ;
	convert ( &q ) ;

	printf ( "The infix expression is:\n" ) ;
	show ( q ) ;
	return 0 ;
}

/* initializes structure elements */
void initpostfix ( struct postfix *p )
{
	p -> i = 0 ;
	p -> top = -1 ;
	strcpy ( p -> target, "" ) ;
}

/* copies given expression to target string */
void setexpr ( struct postfix *p, char *c )
{
	strcpy ( p -> target, c ) ;
}

/* adds an expr. to the stack */
void push ( struct postfix *p, char *str )
{
	if ( p -> top == MAX - 1 )
		printf ( "Stack is full.\n" ) ;
	else
	{
		p -> top++ ;
		strcpy ( p -> stack[p -> top], str ) ;
	}
}

/* pops an expr. from the stack */
void pop ( struct postfix *p, char *a )
{
	if ( p -> top == -1 )
	{
		printf ( "Stack  is empty.\n" ) ;
		return NULL ;
	}
	else
	{
		strcpy ( a, p -> stack[p -> top] ) ;
		p -> top-- ;
	}
}

/* converts given expr. to infix form */
void convert ( struct postfix *p )
{
	while ( p -> target[p -> i] )
	{
		/* skip whitespace, if any */
		if( p -> target[p -> i] == ' ' )
			p -> i++ ;
		if ( p -> target[p -> i] == '%' || p -> target[p -> i] == '*' ||
			 p -> target[p -> i] == '-' || p -> target[p -> i] == '+' ||
			 p -> target[p -> i] == '/' || p -> target[p -> i] == '$' )
		{
			pop ( p, p -> str2 ) ;
			pop ( p, p -> str3 ) ;
			p -> temp1[0] = p -> target[p -> i] ;
			p -> temp1[1] = '\0' ;
			strcpy ( p -> str1, p -> str3 ) ;
			strcat ( p -> str1, p -> temp1 ) ;
			strcat ( p -> str1, p -> str2 ) ;
			push ( p, p -> str1 ) ;
		}
		else
		{
			p -> temp1[0] = p -> target[p -> i] ;
			p -> temp1[1] = '\0' ;
			strcpy ( p -> temp2, p -> temp1 ) ;
			push ( p, p -> temp2 ) ;
		}
		p -> i++ ;
	}
}

/* displays the expression */
void show ( struct postfix p )
{
	char *t ;
	t = p.stack[0] ;
	while ( *t )
	{
		printf ( "%c ", *t ) ;
		t++ ;
	}
}
