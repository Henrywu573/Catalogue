
/**  STRING8.C  **/

# include<stdio.h>
# include<string.h>

void concatenate( char *, char *, char *);

void main()
{
	char str1[128];
	char str2[128];
	char output_str[257];

	printf(" Input the first string: ");
	gets(str1);
	printf("\nInput the second string: ");
	gets(str2);

	concatenate(str1, str2, output_str);
	puts(output_str);
}

/* This function concatenate two strings */

void concatenate( char *s1, char *s2, char *rs)
{
	while(*s1)
	{
		*rs++ = *s1++ ;
	}

	while(*s2)
	{
		*rs++ = *s2++ ;
	}
	*rs = '\0';
}
