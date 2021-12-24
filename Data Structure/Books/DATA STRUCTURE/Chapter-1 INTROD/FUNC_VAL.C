/* FUNC_VAL.CPP */

# include<stdio.h>
# include<math.h>

float m_payment(float  , float , int ) ;  /* prototype */

void main()
{
	float A , I ; /* mortgage amount A , I interest rate */
	int D ;       /* Duration is D */

	printf("\n Input mortgage Amount = ");
	scanf(" %f", &A);
	printf("\n Input interest rate = ");
	scanf(" %f", &I);
	printf("\n Input Duration  = ");
	scanf(" %d", &D);
	printf("\n Monthly Payment = %f", m_payment(A,I,D));
}

/* Definition of function */

float m_payment( float a, float i, int d)
{
	float num;
	float deno;
	float payment;
	num = ( a * i /12 );
	deno = pow( (1/(1+i/12)), d*12);
	payment = num / ( 1 - deno );
	return(payment);
}


