/* shell sort */
/* ShellSort.C */
#include <stdio.h>
#include <stdlib.h>

typedef int T;          /* type of item to be sorted */
typedef int tblIndex;   /* type of subscript */

#define compGT(a,b) (a > b)

void shellSort(T *a, tblIndex lb, tblIndex ub) {
    tblIndex n, h, i, j;
    T t;

   /**************************
    *  sort array a[lb..ub]  *
    **************************/

    /* compute largest increment */
    n = ub - lb + 1;
    h = 1;
    if (n < 14)
        h = 1;
    else if (sizeof(tblIndex) == 2 && n > 29524)
        h = 3280;
    else {
        while (h < n) h = 3*h + 1;
        h /= 3;
        h /= 3;
    }

    while (h > 0) {

        /* sort-by-insertion in increments of h */
        for (i = lb + h; i <= ub; i++) {
            t = a[i];
            for (j = i-h; j >= lb && compGT(a[j], t); j -= h)
                a[j+h] = a[j];
            a[j+h] = t;
        }

        /* compute next increment */
        h /= 3;
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
    shellSort(a, lb, ub);

    return 0;
}
