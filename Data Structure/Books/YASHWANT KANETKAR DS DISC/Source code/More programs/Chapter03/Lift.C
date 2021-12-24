#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

void showstatus( ) ;
void allotlift ( int *, int, int, char ) ;

/* show current status, i.e. the floor no. on which
   the lifts are standing */
void showstatus ( int *lf )
{
    int i ;

	for ( i = 0 ; i < 5 ; i++ )
		printf ( "Lift : %d is on %d floor\n", i, lf[i] ) ;
}

/* allot the lift to the user */
void allotlift ( int *lf, int flnos, int flnot, char d )
{
	/* struct p to store the difference between 2 lifts */
	struct p
	{
		int lfno[5] ;
		 int pos[5] ;
		int diff[5] ;
	} arr ;

	int lno = -1 ;	  /* to store the lift no. that can be made available */
	int i, j, k, t1, t2, t3 ;

	/* initialize array */
	for ( i = 0; i < 5; i++ )
	{
		arr.lfno[i] = i ;
		arr.pos[i] = 0 ;
		arr.diff[i] = 0 ;
	}

	while ( lno == -1 )
	{
		/* get the current position of a lift */
		for ( i = 0 ; i < 5; i++ )
			arr.pos[i] = lf[i] ;

		for ( i = 0; i < 5; i++ )
		{
			/* get the diff. between floor on which lift is standing
			   and the floor on which the user is standing */
			arr.diff[i] = abs ( arr.pos[i] - flnos ) ;
		}

		/* sort array */
		for ( i = 0; i < 5; i++ )
		{
			for ( j = 0; j < 4; j++ )
			{
				if ( arr.diff[i] < arr.diff[j] )
				{

					t1 = arr.lfno[i] ;
					t2 = arr.pos[i] ;
					t3 = arr.diff[i] ;
					arr.lfno[i] = arr.lfno[j] ;
					arr.pos[i] = arr.pos[j] ;
					arr.diff[i] = arr.diff[j] ;
					arr.lfno[j] = t1 ;
					arr.pos[j] = t2 ;
					arr.diff[j] = t3 ;
				}
			}
		}

		/* check for the lift that can be alloted
		   depending on the direction */
		for ( i = 0, k = 0; i < 5; i++ )
		{
			k = arr.lfno[i] ;

			if ( ( d == 'u' ) && (
				 ( lf[k] < flnos ) ||
				 ( lf[k] == 0 ) ||
				 ( lf[k] == flnos ) ) )
			{
				lno = k ;
				break ;
			}

			if ( ( d == 'd' ) && (
				 ( lf[k] > flnos ) ||
				 ( lf[k] == 0 ) ||
				 ( lf[k] == flnos ) ) )
			{
				lno = k ;
				break ;
			}
		}

		/* if none of the lift has been alloted */
		j = 30 ;
		if ( lno == -1 )
		{
			for ( i = 0; i < 5; i++ )
			{
				if ( j > arr.diff[i] )
				{
					j = arr.diff[i] ;
					lno = i ;
				}
			}
		}
	}

	printf ( "\nThe lift available to you would be: %d\n\n", lno ) ;

	lf[lno] = flnot ;
}

/* the main menu */
int showmenu( )
{
	int c ;

	printf ( " -------------------- Lift Program -------------------- \n" ) ;
	printf ( " There are 5 lifts available for your service. \n" ) ;
	printf ( " Select 1 if you want to use a lift. \n" ) ;
	printf ( " Selecting 2 would show, for each of the 5 lifts, \n" ) ;
	printf ( " the floor no. on which the lift is currently standing. \n" ) ;
	printf ( " Select 3 to quit the program \n" ) ;
	printf ( " ------------------------------------------------------ \n" ) ;
	printf ( " 1. Do you wish to use lift?\n" ) ;
	printf ( " 2. Show status of lift\n" ) ;
	printf ( " 3. Exit\n" ) ;
	printf ( " ------------------------------------------------------ \n" ) ;
	scanf ( "%d", &c ) ;

	return c ;
}

void validate ( int *fs, int *ft, char *d )
{
	int flnos, flnot ;
	char dir ;
	int flag ;

	flnos = flnot = -1 ;
	flag = 0 ;

	while ( flnos < 0 || flnos > 29 )
	{
		printf ( "Enter the floor no. where you are standing : " ) ;
		scanf ( "%d", &flnos ) ;

		if  ( flnos < 0 || flnos > 29 )
		{
			printf ( "\nIncorrect floor no.! Enter floor no. in a range of 0 - 29 \n\n" ) ;
		}
	}

	while ( flag == 0 )
	{
		dir = 'j' ;
		while ( tolower ( dir ) != 'u' && tolower ( dir ) != 'd' )
		{
			printf ( "Do you wish to go up or down (up/down): " ) ;
            fflush ( stdin ) ;
			scanf ( "%c", &dir ) ;
			printf ( "\n" ) ;

			if ( dir != 'u' && dir != 'd' )
				printf ( "Incorrect direction! Enter again\n" ) ;
		}

		if ( flnos == 0 && dir == 'd' )
		{
			printf ( "\nYou are already standing on ground floor.\n" ) ;
			printf ( "Cannot go further down.\n" ) ;

			flag = 0 ;
		}
		else
			flag = 1 ;
	}
	flag = 0 ;

	while ( flag == 0 )
	{
		printf ( "\nEnter the floor no. where you want to go: " ) ;
		scanf ( "%d", &flnot ) ;

		if ( ( flnos == 0 && flnot == 0 ) ||
			 ( flnot < 0 || flnot > 29 ) ||
			 ( flnos == flnot ) ||
			 ( ( flnos != 0 ) && ( dir == 'd' && ( flnos - flnot < 0 ) ) ) ||
			 ( ( flnos != 0 ) && ( dir == 'u' && ( flnot < flnos ) ) ) )
		{
			printf ( "\nIncorrect floor no. or trying to move to the same \n" ) ;
			printf ( "floor where you are standing, or either the \n" ) ;
			printf ( " direction given is incorrect or the floor number \n" ) ;
			printf ( " is incorrect. Try again \n") ;
			flag = 0 ;
		}
		else
			flag = 1 ;
	}

	*fs = flnos ;
	*d =  dir ;
	*ft = flnot ;
}

int main( )
{
	int ch ; 	   /* stores the no. entered as a choice for the menu */
	int flnos ;    /* to store floor no. where the user stands */
	int flnot ;    /* to store the target floor no. */
	char dir ;     /* to store the direction */
	char chr[20] ;     /* a temporary variable */
    int lf[5] = { 0, 0, 0, 0, 0 } ;

	void validate ( int *, int *, char * ) ;

	flnos = flnot = -1 ;

    system ( "cls" ) ;

    while ( 1 )
	{
		/* display main menu */
		ch = showmenu( ) ;

		/* switch-case for menu options to be handled */
		switch ( ch )
		{
			case 1 :

					/* actual program logic */
                    printf ( "Allot lift: \n" ) ;
					validate ( &flnos, &flnot, &dir ) ;
					allotlift ( lf, flnos, flnot, dir ) ;
					break ;

			case 2 :

					/* getstaus */
                    printf ( "Current status of lifts: \n" ) ;
					showstatus ( lf ) ;
					break ;

			case 3 :

					/* exit program */
					exit ( 0 ) ;
					break ;

			default :

					/* wrong choice */
					printf ( "Incorrect choice! try again!" ) ;
		}

		printf ( "\n\n" ) ;
		printf ( "Press key to continue..." ) ;
        fflush ( stdin ) ;
        scanf ( "%c", &chr ) ;
	}
  return 0 ;
}