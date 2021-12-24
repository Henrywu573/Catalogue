/* Bins.c:  Possible bin array for RadixSort */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Bins.h"

struct t_bins {
  int n_bins, max_items;
  int *bin_cnt;
  TYPE **bin_pts;
  };

/* Construct an array of n_bins bins,
   each with items_per_bin spaces */
Bins ConsBins( int n_bins, int items_per_bin ) {
  Bins b;
  int i;
#ifdef ONE_LARGE
  int max;
  TYPE *bins;
#endif
/* fprintf(stdout, "ConsBins %d/%d ", n_bins, items_per_bin ); fflush( stdout ); */
  b = (Bins)malloc( sizeof( struct t_bins ) );
  if ( b != NULL ) {
    b->n_bins = n_bins;
    b->max_items = items_per_bin;
    b->bin_pts = (TYPE **)malloc( n_bins*sizeof(TYPE *) );
    b->bin_cnt = (int *)calloc( n_bins, sizeof(int) );
    if ( b->bin_pts != NULL ) {
#ifdef ONE_LARGE  
      /* Allocate a single large bin */
      max = n_bins*items_per_bin*sizeof(TYPE);
      bins = malloc( max );
      if( bins == NULL ) {
        printf("ConsBins: insuff mem %d bytes needed\n", max );
        return NULL;
        }
      /* Divide it into n_bins, each holding items_per_bin items */
      for(i=0;i<n_bins;i++) {
        b->bin_pts[i] = bins;
        bins += (items_per_bin);
        }
#else              
      /* Allocate n_bins individual bins */
      for(i=0;i<n_bins;i++) {
        b->bin_pts[i] = (TYPE *)malloc( items_per_bin*sizeof(TYPE) );
        if( b->bin_pts[i] == NULL ) {
          printf("ConsBins: insuff mem after %d bins\n", i );
          b = NULL; break;
        }
      }
#endif
    }
  }
  else {
    fprintf( stdout, "Insuff mem\n");
  }
  return b;
  }
  
int AddItem( Bins b, TYPE item, int bin_index ) {
/* Add item to bin bin_index
   Pre: b != NULL && item != NULL &&
        bin_index >= 0 && bin_index < n_bins
*/
  int k;
  assert( b != NULL );
  assert( bin_index >= 0 );
  assert( bin_index < b->n_bins );
  k = b->bin_cnt[bin_index];
  assert( (k>=0) && (k<b->max_items) );
  assert( (b->bin_pts[bin_index]) != NULL );
  (b->bin_pts[bin_index])[k] = item;
  b->bin_cnt[bin_index]++;
  return 1;
  }

TYPE *MergeBins( Bins b, TYPE *list ) {
/* Merge the bins by copying all the elements in bins 1..n_bins-1
   into list
   return a pointer to list 
   (This pointer can be used in the next phase!)
*/
  int j, k;
  TYPE *lp;
  assert( b != NULL );
  assert( list != NULL );

  lp = list;
  for( j = 0; j<b->n_bins; j++ ) {
    for(k=0;k<b->bin_cnt[j];k++) {
      *lp++ = (b->bin_pts[j])[k];
      }
    }
  return list;
  }

void FreeUnusedBins( Bins b  ) {
/* Free bins 1 .. n_bins-1 in preparation for next phase */
  int k;
  assert( b != NULL );
#ifdef ONE_LARGE
  free( b->bin_pts[0] );
#else
  for(k=0;k<b->n_bins;k++) {
    assert( b->bin_pts[k] != NULL );
    free( b->bin_pts[k] );
    }
#endif
  free( b->bin_pts );
  }

void DeleteBins( Bins b ) {
/* Destructor .. frees all space used by b */
  assert( b != NULL );
  FreeUnusedBins( b );
  free( b->bin_cnt );
  free( b );
  }
