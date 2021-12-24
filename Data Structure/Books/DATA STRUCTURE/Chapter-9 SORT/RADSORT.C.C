/*
 RadSort.c -
   a single method which sorts arrays of items with
   keys that can be split into groups of bits -
   useful for unsigned integers or characters
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>

#include "Bins.c"
#include "RadSort.h"

/* These parameters control the whole operation,
   they are set up once by a call to SetRadices
   They do not need to be re-set unless the radices change
*/
static int *n_bins;
static unsigned int mask;
static int *shifts;
static int n_phases;

int SetRadices( int n_bits, int n_radices ) {
	int i, tot_bits, bits_per_phase;

	/* Calculate how many bits in each phase */
	bits_per_phase = n_bits/n_radices;
	if( (n_radices*bits_per_phase) < n_bits ) {
		bits_per_phase++;
		}
	/* Set up the mask */
	mask = (1<<bits_per_phase) - 1;

	/* Now set up the count of the number of bins and
     the shifts appropriate for each phase */
	n_bins = malloc( n_radices*sizeof(int) );
	shifts = malloc( n_radices*sizeof(int) );
	tot_bits = 0;
	for(i=0;i<n_radices;i++) {
		shifts[i] = tot_bits;
		tot_bits += bits_per_phase;
		/* Last phase may not need so many bins */
		if ( tot_bits > n_bits ) {
			bits_per_phase = n_bits - tot_bits + bits_per_phase;
			}
		n_bins[i] = 1<<bits_per_phase;
		}
	n_phases = n_radices;

	printf("Bits %d, radices %d, mask %x\n", n_bits, n_phases, mask );
	for(i=0;i<n_phases;i++) {
		printf("%d: sh %d bins %d, ", i, shifts[i], n_bins[i] );
		}
	printf("\n");
	return TRUE;
	}
		
/* Function to return bin number to use for phase */
/* int bin_number( int x, int phase ) {
	return (x>>shifts[phase])&mask;
	} */
/* Implemented as a macro for speed! */
#define bin_number(x,phase) ((x>>shifts[phase])&mask)
	
int *RSort( int *ip, int n ) {
	Bins b1, b2;
	int i, bn, phase;

	b2 = NULL;
	for(phase=0;phase<n_phases;phase++) {

		b1 = ConsBins( n_bins[phase], n );
		for(i=0;i<n;i++) {
			bn = bin_number( ip[i], phase );
			AddItem( b1, ip[i], bn );
			}
		ip = MergeBins( b1, ip );
		DeleteBins( b1 );
		}
	return ip;
	}

int VerifySort( int *ip, int n ) {
	int k;
	for(k=0;k<(n-1);k++) {
		if ( ip[k+1]<ip[k] ) {
			printf("Order error %d: %d s/b < %d\n",
				k, ip[k], ip[k+1] );
			return FALSE;
			}
		}
	return TRUE;
	}
	

