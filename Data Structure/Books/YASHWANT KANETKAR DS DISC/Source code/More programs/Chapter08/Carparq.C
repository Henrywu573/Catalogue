/* a car garage simulation using de-queue (link list implementation) */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>

#define TOP 1
#define BOT 2

struct node
{
	char plate [15] ;
	struct node *link ;
} *front[5], *rear[5] ;

char plate[15], temp[15] ;
int i ;

void add_dq ( struct node**, struct node**, int, char* ) ;
char* del_dq ( struct node**, struct node**, int ) ;
void push ( struct node**, char* ) ;
char* pop ( struct node** ) ;
void q_display ( struct node * ) ;
int count ( struct node * ) ;
int search ( struct node *, char * ) ;

int main( )
{
	char ad ;
	int s, lane = -1, min ;

	system ( "cls" ) ;
	while ( 1 )
	{
		for ( i = 0 ; i < 5 ; i++ )
		{
			printf( "lane %d: ", i ) ;
			q_display ( front[i] ) ;
		}

		printf( "\nArrival/Departure/Quit? ( A/D/Q ): " ) ;
		ad = getch( ) ;

		if ( toupper ( ad ) == 'Q' )
			exit ( 1 ) ;

		printf ( "\nEnter license plate num:" ) ;
		gets ( plate ) ;
		ad = toupper ( ad ) ;

		if ( ad == 'A' )  /* arrival of car */
		{
			lane = -1 ;  /* assume no lane is available */
			min = 10 ;
			for ( i = 0 ; i < 5 ; i++ )
			{
				s = count ( front[i] ) ;
				if ( s < min )
				{
					min = s ;
					lane = i ;
				}
			}

			if ( lane == -1 )
				printf ( "\nNo room available" ) ;
			else
			{
				add_dq ( &front[ lane ], &rear[ lane ], BOT, plate ) ;
				printf ( "\npark car at lane %d slot %d\n", lane, s ) ;
			}
		}
		else
		{
			if ( ad == 'D' )  /* departure of car */
			{
				for ( i = 0 ; i < 5 ; ++i )
				{
					s = search ( front[i], plate ) ;
					if ( s != -1 )
					{
						lane = i ;
						break ;
					}
				}
            	if ( i == 5 )
					printf ( "\nno such car!!\n" ) ;
				else
				{
					printf ( "\ncar found at lane %d slot %d\n", lane, s ) ;
					del_dq ( &front[ lane ], &rear[ lane ], s ) ;
				}
			}
			else
				if ( ad == 'Q' )
					exit ( 1 ) ;
        }
    }
  return 0 ;
}

/* adds a new element at the end of queue */
void add_dq ( struct node **f, struct node **r, int tb, char *p )
{
	struct node *q ;
	/* create new node */
	q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
	strcpy ( q -> plate, p ) ;
	q -> link = NULL ;

	/* if the queue is empty */
	if ( *f == NULL )
		*f = q ;
	else
	{
		if ( tb == BOT )
			( *r ) -> link = q ;
		else
		{
			q -> link = *f ;
			*f = q ;
			return ;
		}
	}
	*r = q ;
}

char* del_dq ( struct node **f, struct node **r, int n )
{
	struct node *q, *top = NULL ;
	/* if queue is empty */
	if ( *f == NULL )
		printf ( "queue is empty" ) ;
	else
	{
		if ( n == 0 )
		{
			strcpy ( temp, ( *f ) -> plate ) ;
			q = *f ;
			*f = ( *f ) -> link ;
			free ( q ) ;
			return temp ;
		}

		/* locate node */
		for ( i = 0 ; i < n ; i++ )
		{
			/* drive out cars */
			push ( &top, ( *f ) -> plate ) ;

			/* delete the node */
			q = *f ;
			*f = q -> link ;
			free ( q ) ;
		}

		/* delete the nth node */
		q = *f ;
		*f = q -> link ;
		free ( q ) ;

		for ( i = 0 ; i < n ; i++ )
		{
			strcpy ( temp, pop ( &top ) ) ;

			/* add the node */
			add_dq ( f, r, TOP, temp ) ;
		}
	}
}

int count ( struct node *q )
{
	int c = 0 ;

	/* traverse the entire linked list */
	while ( q!= NULL )
	{
		q = q -> link ;
		c++ ;
	}
	return c ;
}

int search ( struct node *q, char *p )
{
	int s = -1, c = 0 ;

	while ( q != NULL )
	{
		if ( strcmp ( p, q -> plate ) == 0 )
		{
			s = c ;
			break ;
		}
		else
		{
			q = q -> link ;
			c++ ;
		}
	}
	return ( s ) ;
}

/* adds a new element to the top of stack */
void push ( struct node **s, char* item )
{
	struct node *q ;
	q = ( struct node* ) malloc ( sizeof ( struct node ) ) ;
	strcpy ( q -> plate, item ) ;
	q -> link = *s ;
	*s = q ;
}

/* removes an element from top of stack */
char* pop ( struct node **s )
{
	struct node *q ;

	/* if stack is empty */
	if ( *s == NULL )
	{
		return NULL ;
	}
	else
	{
		q = *s ;
		strcpy ( temp, q -> plate ) ;
		*s = q -> link ;
		free ( q ) ;
		return ( temp ) ;
	}
}

void q_display ( struct node *q )
{
	while( q != NULL )
	{
		printf ( "%s", q -> plate ) ;
		q = q -> link ;
	}
	printf ( "\n" ) ;
}