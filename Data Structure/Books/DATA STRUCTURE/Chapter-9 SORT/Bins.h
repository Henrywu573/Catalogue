/* Bins.h
   Possible bin array for RadixSort
*/
#define TYPE	int

typedef struct t_bins *Bins;

Bins ConsBins( int n_bins, int items_per_bin );
/* Construct an array of n_bins bins,
   each with items_per_bin spaces */

int AddItem( Bins b, TYPE item, int bin_index );
/* Add item to bin bin_index
   Pre: b != NULL && item != NULL &&
        bin_index >= 0 && bin_index < n_bins
*/

TYPE *MergeBins( Bins b, TYPE *list );
/* Merge the bins by copying all the elements in bins 
   into list, return a pointer to list 
*/

void DeleteBins( Bins b );
/* Destructor .. frees all space used by b */
