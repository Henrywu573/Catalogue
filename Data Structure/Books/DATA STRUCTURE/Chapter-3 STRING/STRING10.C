
/**  STRING10.C **/

# include<stdio.h>
# include<string.h>
# include<malloc.h>
# include<ctype.h>

void insertion ( char *, int , char *, char *);

/* Function insert */

void insertion ( char *text , int position, char *s, char *p)
{
	char ch ;
	while(position)
	{
		*p++ = *text++ ;
		position--;
	}
	while(*s)
	{
		*p++ = *s++ ;
	}
	printf("\n After insertion of the pattern\n ");
	printf("there needs blank at right side of the pattern(y): ");
	ch  = getchar() ;
	ch = toupper(ch);

	if (ch == 'Y')
		*p++ = ' ';
	while(*text)
	{
		*p++ = *text++ ;
	}
	*p = '\0';
}

/* FUnction main */

void main()
{
	char *point ;
	char text[128]="COMPUTER SCIENCE ENGINEERING";
	char s[4] ="AND";
	int position = 17 ;
	point =(char*) malloc(128);
	printf("\n********************************\n");
	printf(" TEXT AND PATTERN ARE AS FOLLOWS\n");
	printf("\n********************************\n");
	printf("\n %s", text);
	printf("\n%s", s);
	printf("\n*******************************\n");
	insertion ( text, position, s, point);
	printf("\n*******************************\n");
	printf("\n %s", point);
	printf("\n*******************************\n");
	printf("\n Press a key");
	getchar();
}

