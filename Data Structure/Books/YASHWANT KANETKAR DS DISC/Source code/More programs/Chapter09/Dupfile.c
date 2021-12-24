/* Program to find files with duplicate names using binary search tree */
/* This program would work only in Turbo C / Turbo C++ */

#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <dir.h>
#include <string.h>
#include <malloc.h>

struct btreenode
{
	struct btreenode *leftchild ;
	char data[13] ; /* file name */
	char *loc ; /* location of filename */
	struct btreenode *rightchild ;
} *bt = NULL ;

void disktree( ) ;
int insert ( struct btreenode  **, char*, char* ) ;

int main( )
{
	char current_dir[32] ;

	clrscr( ) ;

	getcwd ( current_dir, 32 ) ;
	chdir ( "\\" ) ;
	disktree( ) ;
	chdir ( current_dir ) ;

  return 0 ;
}

void disktree( )
{
	struct ffblk file ;
	int flag ;
	char loc[80] ;

	getcwd ( loc, 80 ) ;
	flag =  findfirst ( "*.*", &file, FA_NORMAL | FA_RDONLY | FA_HIDDEN | 
					FA_SYSTEM | FA_LABEL | FA_DIREC | FA_ARCH ) ;

	while ( flag == 0 )
	{
		if ( file.ff_name[0] != '.' )
		{
			if ( file.ff_attrib == FA_DIREC && file.ff_fsize == 0 )
			{
				chdir ( file.ff_name ) ;
				disktree( ) ;
				chdir ( loc ) ;
			}
			else
				insert ( &bt, loc, file.ff_name ) ;
		}
		flag = findnext ( &file ) ;
	}
}

/* inserts a new node in a binary search tree */
int insert ( struct btreenode  **sr, char* l, char* f )
{
	char *p ;
	int flag ;

	if ( *sr == NULL )
	{
		*sr = ( struct btreenode * ) malloc ( sizeof ( struct btreenode ) ) ;

		if ( *sr == NULL )
		{
			printf ( "\nOut of memory." ) ;
			exit ( 1 ) ;
		}

		( *sr ) -> leftchild = NULL ;
		( *sr ) -> rightchild = NULL ;
		strcpy ( ( *sr ) -> data, f ) ;
		p = ( char * ) malloc ( ( strlen ( l ) + 1 ) ) ;

		if ( p == NULL )
		{
			printf ( "\nOut of memory." ) ;
			exit ( 1 ) ;
		}

		strcpy ( p, l ) ;
		( *sr ) -> loc = p ;
	}
	else
	{
		flag = strcmp ( ( *sr ) -> data, f ) ;

		if ( flag == 0 )
		{
			printf ( "org: %s", ( *sr ) -> loc ) ;

			if ( strlen ( ( *sr ) -> loc ) > 4 )
				printf ( "\\" ) ;

			printf ( "%s\n", ( *sr ) -> data ) ;
			printf ("dup: %s", l ) ;

			if ( strlen ( l ) > 4 )
				printf ( "\\" ) ;

			printf ( "%s\n\n", f ) ;
		}
		else if ( flag < 0 )
			insert ( &( ( *sr ) -> leftchild ), l, f ) ;
		else
			insert ( &( ( *sr ) -> rightchild ), l, f ) ;
	}
	return ;
}
