/* 
 RadSort.h -
   a single method which sorts arrays of items with
   keys that can be split into groups of bits -
   useful for unsigned integers or characters
*/
#ifndef TRUE
#define TRUE	1
#define FALSE	0
#endif

#ifndef RADIX_SORT_H
#define RADIX_SORT_H

int SetRadices( int n_bits, int n_radices );
/* Set the radices to sort numbers with n_bits using n_radices
   phases
*/
	
int *RSort( int *ip, int n );
/* Sort n numbers in array ip, using RadixSort */

#endif

