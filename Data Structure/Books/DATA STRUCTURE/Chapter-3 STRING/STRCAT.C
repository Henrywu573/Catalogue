/* strcat.c */

# include<stdio.h>

char *strcat1(char *target, const char *source)
{
	char *original = target;
	while(*target)
		target++;
	while (*target++= *source++)
		;
	return(original);
}

main()
{
	char Name[256]="Ram Bahadur ";
	char Title[256]="Patel";
	strcat1(Name, Title);
	puts(Name);
}

