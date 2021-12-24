/* File allocation table */
/* This program will work only on machines where there is FAT file system */
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <dos.h>
#include <bios.h>


struct boot
{
	unsigned char jump[3] ;
	char OEMname[8] ;
	short int bps ;
	unsigned char spc ;
	short int reservedsec ;
	unsigned char fatcopies ;
	short int maxdirentries ;
	short int totalsec ;
	unsigned char mediadesc ;
	short int secperfat ;
	short int secpertrack ;
	short int noofsides ;
	long int hidden ;
	long int hugesec ;
	unsigned char drivenumber ;
	unsigned char reserved ;
	unsigned char bootsignature ;
	long int volumeid ;
	char volumelabel[11] ;
	char filesystype[8] ;
	unsigned char unused[450] ;
} ;

struct boot bs ;
char filetypestr[8] ;

void getfat_12 ( unsigned char * ) ;
void read_fat_info ( long ) ;
void fat_info( ) ;

int main( )
{
	char choice ;

	clrscr( ) ;

	printf ( "A. Drive A" ) ;
	printf ( "\nC. Drive C" ) ;
	printf ( "\n0. Exit" ) ;

	printf ( "\nEnter the drive (A/C): " ) ;
	scanf ( "%c", &choice ) ;

	if ( absread ( choice - 65, 1, 0, &bs ) == -1 )
	{
		printf ( "Error reading sector" ) ;
		exit ( 0 ) ;
	}
	else
	{
		strcpy ( filetypestr, bs.filesystype ) ;
		filetypestr[6] = '\0' ;
	}

	fat_info( ) ;
  return 0 ;
}

void getfat_12 ( unsigned char *pfat )
{
	int value ;
	int *fatentry ;
	int i, k ;

	for ( k = 2 ; k < 18 ; k++ )
	{
		i = k * 3 / 2 ;

		fatentry =  ( int* ) ( pfat + i ) ;

		if ( ( k % 2 ) == 0 )
			value = ( *fatentry & 0x0fff ) ;
		else
			value = ( *fatentry >> 4 ) ;

		printf ( "%03x   ", value ) ;
		if ( k % 9 == 0 )
			printf ( "\n" ) ;
	}
}

void read_fat_info ( long fat_num )
{
	int j, i ;

	unsigned char *p ;

	if ( strncmp ( "FAT12", filetypestr, 5 ) == 0 )
	{
		p = ( unsigned char* ) malloc ( bs.bps ) ;
		absread ( 0, 1, fat_num, p ) ;
		getfat_12( p ) ;
	}

	if ( strncmp ( "FAT16", filetypestr, 5 ) == 0 )
	{
		short int *pfat ;
		p = ( unsigned char* ) malloc ( bs.bps ) ;
		absread ( 2, 1, fat_num, p ) ;
		pfat = ( short int* ) p ;

		for ( j = 0 ; j < 2 ; j++ )
		{
			printf ( "\n%d   ", j * 8 ) ;
			for ( i = 0 ; i < 8 ; i++ )
			{
				printf ( "%04x  ", *pfat++ ) ;
			}
		}
	}
}

void fat_info( )
{
	long int first_fat, second_fat ;

	first_fat = bs.reservedsec ;
	second_fat = bs.reservedsec + bs.secperfat ;

	printf ( "\n%s Fat Information", filetypestr ) ;
	printf ( "\n-------------------------------" ) ;

	printf ( "\nFirst FAT Information\n" ) ;

	read_fat_info ( first_fat ) ;

	printf ( "\n\nSecond FAT Information\n" ) ;

	read_fat_info ( second_fat ) ;
	printf ( "\n-------------------------------\n" ) ;
}