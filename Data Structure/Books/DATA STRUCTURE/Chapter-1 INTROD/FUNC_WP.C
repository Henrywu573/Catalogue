/* FUNT_WP.C */

# include<stdio.h>
# include<math.h>

int x, y;  /* global  variable */
float xy_power(void) ;  /* prototype */

void main()
{

	printf("\n Input values of x , y: ");
	scanf(" %d", &x);
	scanf(" %d", &y);
	printf("\n y power x is = %f", xy_power());
}

/* Definition of the function xy_power() */

float xy_power(void)
{
	float result  ;
	int a , b ;
	a = x ;
	b = y ;
	result = pow(b,a) ;
	return(result) ;
}

