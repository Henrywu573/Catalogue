/* Power Function */
/* POWER1.C */

# include<stdio.h>
# include<math.h>

double power_fract(double, float, float );
void expo();

/* The definition of the power_fract() function */

double power_fract(double a, float b, float i)
{
	if( b == 0)
	{
		return 1;
	}
	else if ( b< 0)
	{
		return( (a * power_fract(a,b + i,i)));
	}

	else
		return( a* power_fract(a,b - i,i));
}

/* The definition of the expo() function */

void expo()
{
	char str[50];
	char *pstr;
	char temp;
	int count = 0;
	char ch;
	int i = 0;
	float counter;
	float exponent;
	float mantissa;
	printf("\n Input the Mantissa: ");
	scanf("%f", &mantissa);
	printf(" Input the Exponent: ");
	fflush(stdin);

	ch = getchar();

	while( ch != '\n')
	{
		if((ch == '-') || (ch == '+'))
			count--;
		if( ch == '.')
			temp = ch;
		str[i] = ch;
		ch = getchar();
		i ++;
		count ++;
	}
	str[i]='\0';
	printf("\n\n Number of digits including '.' = %d", count);
	count = i;
	if (temp == '.')
	{
		i = 1;
		pstr = &str[0];
		while(*pstr != '.')
		{
			pstr++;
			i ++;
		}
	}
	printf("\n Number of digits including sign & period(.) character = %d",i);
	count = count - i;
	printf("\n Number of digits after decimal point = %d", count);
	exponent = atof(str);
	counter = 1/power_fract(10, -count,1);
	printf("\n Increment/Decrement counter = %f", counter);
	printf("\n\n Mantissa = %f", mantissa);
	printf("\n Exponent = %f", exponent);

	if(exponent < 0)
		printf("\n\n mantissa ^ exponent = %lf", 1/power_fract(mantissa,exponent,counter));
	else
		printf("\n\n mantissa ^ exponent = %lf", power_fract(mantissa,exponent,counter));
}

// Function main

void main()
{
	expo();
}
