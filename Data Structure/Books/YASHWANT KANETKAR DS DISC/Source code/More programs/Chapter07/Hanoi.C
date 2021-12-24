/* Program of towers of hanoi. */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

void move ( int, char, char, char ) ;

int main( )
{
	int n = 3 ;

	system ( "cls" ) ;

	move ( n, 'A', 'B', 'C' ) ;

	return 0 ;
}

void move ( int n, char sp, char ap, char ep )
{
	if ( n == 1 )
		printf ("\nMove from %c to %c ", sp, ep ) ;
	else
	{
		move ( n - 1, sp, ep, ap ) ;
		move ( 1, sp, ' ', ep ) ;
		move ( n - 1, ap, sp, ep ) ;
	}
}

