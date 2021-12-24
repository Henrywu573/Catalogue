/* Constant*/
/* CONSTANT.C */

# include<stdio.h>

void main()
{
	const int I = 12345;
	const long int L =99999L;
	const float F = 123456.345f;
	const int O = 01234;
	const int H = 0x1abc;
	const int U = 123u;
	printf("\n Integer: %d",I);
	printf("\n Long integer: %ld ", L);
	printf("\n Float ",F);
	printf("\n Octal %o",O);
	printf("\n Hexadecimal %X",H);
	printf("\n Unsigned integer: %u ", U);
}
