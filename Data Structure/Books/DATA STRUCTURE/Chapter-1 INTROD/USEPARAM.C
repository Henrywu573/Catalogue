/* useparam.c */

#include <stdio.h>

/* The swap() function enterchnage two elements */

void swap(int *a, int *b)
 {
   int temp = *a;
   *a = *b;
   *b = temp;
 }

/* The swap() function enterchnage four elements  */

void swap(int *a, int *b, int *c, int *d)
 {
   int temp = *a;
   *a = *b;
   *b = temp;
   temp = *c;
   *c = *d;
   *d = temp;
 }

void main(void)
 {
   int a = 1, b = 2 , c = 3, d = 4;

   printf("\n a = %d", a);
   printf("\n b = %d", b);
   printf("\n c = %d", c);
   printf("\n d = %d", d);

   swap(&a, &b); /* Invoking function swap() */

   printf("\n Swapped a: %d and b: %d", a,  b);
   a = 1;
   b = 2;
   c = 3;
   d = 4;
   printf("\n a = %d", a);
   printf("\n b = %d", b);
   printf("\n c = %d", c);
   printf("\n d = %d", d);

   swap(&a, &b, &c, &d);
   printf("\n Swapped four a = %d b= %d c = %d d = %d", a, b, c, d);
 }

