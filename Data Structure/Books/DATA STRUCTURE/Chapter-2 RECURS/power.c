/* Power Function */
/* POWER.C */

# include<stdio.h>

double power_f(double, float );

/* Definition of the function power_f() */

double power_f(double a, float b)
{
	if( b == 0)
	{
		return 1;
	}
	else if ( b< 0)
	{
		return( (a * power_f(a,b+1)));
	}

	else
		return( a* power_f(a,b-1));
}

/* Function main */

void main()
{
	double mantissa;
	float exponent;

	printf("\n Input the Mantissa: ");
	scanf("%lf", &mantissa);
	printf("\n Input the exponent: ");
	scanf("%f", &exponent);
	if( exponent < 0)
		printf("\n maintissa ^ exponent: %lf", 1/ power_f(mantissa, exponent));
	else printf("\n maintissa ^ exponent: %lf", power_f(mantissa, exponent));
}
