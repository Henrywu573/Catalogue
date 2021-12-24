
/**    STRING7.C   **/

/** In this program segment the text    **/
/** provided through file               **/

# include<stdio.h>
# include<string.h>
# include<malloc.h>
# include<stdlib.h>

int index(char *buffer, char *string);

/**         Global Parameters          **/

char *buffer;
char string[] = "language";
char *s;
char s1[8];
int size ;
int i, j;
int length;
int l ;
int position ;
int back1, back2 ;

/**             end                     **/

void main()
{
	FILE *fp;
	char file[13];

	printf("\nEnter Text File ");
	gets(file);
	fp = fopen(file,"r");
	if( fp == NULL )
	{
		puts(file);
		perror("ERROR : ");
		exit(0);
	}

	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	printf("\n SIZE OF FILE: %d", size);
	printf("\n Press a key");
	getchar();
	buffer = (char *) malloc(size+1);
	fseek(fp,0L,0);
	fread(buffer, size, 1, fp) ;
	buffer[size+1] = '\0';
	printf("\n Enter The Pattern ");
	fflush(stdin);
	gets(string);

	printf("TEXT PROVIDED IS AS FOLLOWS \n");
	printf("***************************\n\n");
	printf(buffer);
	printf("\n Press a key");
	getchar();
	fclose(fp);
	printf("\n Index value: %d", index(buffer, string));
}

/* Index function */

int index(char *buffer, char *string)
{
	length = strlen(string);
	s = ( char *) malloc(length);
	printf("Length: %d", length);
	back1 = length ;
	back2 = size ;

	i = 0 ;
	j = 0 ;
	l = 0 ;

	position = 0 ;

	while(size!= 0)
	{
		size --;
		while(length)
		{
			position ++ ;
			if ( buffer[i] == string[j])
			{
				s[j] = buffer[i];
				l ++ ;
				i ++ ;
				j ++ ;
				length --;
				if( l == back1)
				{
					s[j] = '\0';
					printf("\nPattern is found");
					printf("\nSize of Pattern: %d", l);
					printf("\n Pattern is : %s", s);
					printf("\n Pattern Found at %d", position-back1);

					free(s);

					return(position-back1);
				}
			}
			else
			{
				i++;
				j = 0;
				l = 0;
				length = back1;
			}
		}
	}
	free(buffer);
}
