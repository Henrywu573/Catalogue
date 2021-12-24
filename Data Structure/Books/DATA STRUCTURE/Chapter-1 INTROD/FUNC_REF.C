
/* FUNCT_REF.C */

# include<stdio.h>

void exchange (float *x , float *y )
{
	float t ;
	t = *x ;   /* copy x into t */
	*x = *y ;  /* copy y into x */
	*y = t ;   /* copy x into y */
}

void exchange(float * , float * ) ; /* prototype */

void main()
{
	float x , y ;
	printf("\n Input value for x and y : ");
	scanf(" %f", &x);
	scanf(" %f", &y);
	printf("\n Values before function call ");
	printf("\n Value of x = %f", x);
	printf("\n Value of y = %f ", y);

	printf("\n Values after function call ");
	exchange(&x,&y);
	printf("\n Value of x = %f", x);
	printf("\n Value of y = %f ", y);
}


