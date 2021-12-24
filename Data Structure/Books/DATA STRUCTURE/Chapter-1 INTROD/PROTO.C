/* PROTO.C */
/* RADIX FUNCTION DISCUSSES ABOUT PROTOTYPE DECLARATION */

# include<stdio.h>

float radix(float ) ; /* prototype */

void main()
{
	int x ;
	int r ;

	x = 20 ;
	r =  radix(x) ;
	printf("\n Resulting value is %d ", r);
}

/* Definition of function */

float radix(float n )
{
	int r ;
	r = n * 10 ;
	return(r) ;
}

