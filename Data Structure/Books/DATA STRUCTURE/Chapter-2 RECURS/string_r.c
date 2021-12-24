/* RECURSION TO REVRSE A SSTRING */
/* STRING_R.C */

# include<stdio.h>

void recurs_string(char * );

/* Definition of the recurs_string() function */

void recurs_string(char *string)
{
	if (*string)
	{
		recurs_string(string+1);
		putchar(*string);
	}
}

void main(void)
{
	char str[100];
	printf("\n Input a string: ");
	gets(str);
	printf("\n Reverse of the string: %s", str);
	printf("\n Reverse string is: ");
	recurs_string(str);
}
