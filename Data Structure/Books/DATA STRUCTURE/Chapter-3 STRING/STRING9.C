/* STRING9.C */

/* Length function */

# include<stdio.h>
# include<string.h>

int length(char *p);

/* Definition of the length function */

int length(char *p)
{
	int len = 0 ;
	while(*p++)
	{
		len ++;
	}
	return (len) ;
}

/* Function main */

void main()
{
	char  string[60];
	printf(" Input the string : ");
	gets(string);
	printf("Length of Input String = %i", length(string));
	getchar();
}
