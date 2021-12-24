/* insert sort */
/* Insertion.C */
#include <stdio.h>
#include <stdlib.h>

typedef int T;          /* type of item to be sorted */
typedef int tblIndex;   /* type of subscript */

#define compGT(a,b) (a > b)

void insertSort(T *a, tblIndex lb, tblIndex ub) {
    T t;
    tblIndex i, j;

   /**************************
    *  sort array a[lb..ub]  *
    **************************/
    for (i = lb + 1; i <= ub; i++) {
        t = a[i];

        /* Shift elements down until */
        /* insertion point found.    */
        for (j = i-1; j >= lb && compGT(a[j], t); j--)
            a[j+1] = a[j];

        /* insert */
        a[j+1] = t;
    }
}

void fill(T *a, tblIndex lb, tblIndex ub) {
    tblIndex i;
    srand(1);
    for (i = lb; i <= ub; i++) a[i] = rand();
}

int main(int argc, char *argv[]) {
    tblIndex maxnum, lb, ub;
    T *a;
    maxnum = atoi(argv[1]);
    lb = 0; ub = maxnum - 1;
    if ((a = malloc(maxnum * sizeof(T))) == 0) {
        fprintf (stderr, "insufficient memory (a)\n");
        exit(1);
    }

    fill(a, lb, ub);
    insertSort(a, lb, ub);

    return 0;
}
