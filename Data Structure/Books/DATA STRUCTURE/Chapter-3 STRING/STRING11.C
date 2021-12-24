
/**  STRING11.C **/

# include<stdio.h>
# include<string.h>
# include<malloc.h>

void deletion ( char *, int , int , char * );

/* Function delete */

void  deletion (char *text, int position, int length, char *p)
{
	while(position)
	{
		*p++ = *text++ ; /* copying the pattern */
		position--;
	}

	while(length)
	{
		*text++; /* skipping the pattern */
		length --;
	}

	*p++ = ' ';
	while(*text)
	{
		*p++ = *text++ ; /* copying the rest of text */
	}
	*p = '\0';
}

/* Function main */

void main()
{
	char *point ;
	char text[128]="COMPUTER SCIENCE AND ENGINEERING";
	int length = 3 ;
	int position = 17 ;

	point = (char *) malloc(128);

	printf("\n      TEXT IS AS FOLLOWS           ");
	printf("\n********************************\n");
	printf("\n %s", text);
	printf("\n********************************\n");
	deletion (text, position, length , point);
	printf("\nOUTPUT AFTER DELETION OF PATTERN");
	printf("\n********************************\n");
	printf("\n %s", point);
	printf("\n********************************\n");
	printf("\n Press a key");
	getchar();
}

