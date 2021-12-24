
/**  STRING12.C **/

# include<stdio.h>
# include<string.h>
# include<malloc.h>
# include<stdlib.h>

/**           Global parameters               **/

char *buffer;
char pattern1[9];
char pattern2[9];

char *s;
char s1[8];
int size ;
int i, j;
int length;
int l ;
int position ;
int back1, back2 ;

void replacement(char *, char *, char * );

void replacement(char *buffer, char *pattern1, char *pattern2 )
{
	length = strlen(pattern1);
	s = ( char *) malloc(length);
	printf("Length => %d", length);
	back1 = length ;
	back2 = size ;
	getchar();

	i = 0 ;
	j = 0 ;
	l = 0 ;
	position = 0 ;

	while(size)
	{
		size --;
		while(length)
		{
			position ++ ;
			if ( buffer[i] == pattern1[j])
			{
				if ((position >= back2) || (position < 0))
					exit(0);
				s[j] = buffer[i];
				l ++ ;
				i ++ ;
				size --;
				j ++ ;
				length --;
				if( l == back1)
				{
					s[j] = '\0';
					printf("\nPATTERN IS FOUND");
					printf("\n****************\n");
					printf(" LENGTH OF PATTERN: %d ",l);
					printf("\n PATTERN IS: %s", s);
					printf("\n Starting Position = %d", (position-l));
					printf("\n Press a key");
					getchar();
					l= 0 ;
					j = 0 ;
					printf("\nPATTERN REPLACEMENT IN PROGRESS");
					printf("\n*******************************\n");

					for(i = (position - strlen(pattern2)); i < position ; i++)
					{
						buffer[i] = pattern2[j];
						putchar(buffer[i]);
						j++;
						getchar();
					}

					printf("\nSEE AFTER FIRST PATTERN REPLACEMENT ");
					printf("\n***********************************\n");

					printf("\n %s", buffer);
					printf("\n Press a key");
					getchar();

				} /* end of if */
			}  /* end of if */

			else
			{
				i++;
				j = 0;
				l = 0;
				size -- ;
				length = back1;
			}

		}  /* end first while */

		length = back1 ;
	}     /* end of second while */
}

void main()
{
	FILE *fp ;
	fp = fopen("TEST","r");
	if( fp == NULL )
	{
		printf(" FILE \n");
		perror("ERROR : ");
		exit(0);
	}
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	printf("SIZE OF FILE: %d ", size);
	printf("\n Press a key");
	getchar();
	buffer = (char *) malloc(size);
	fseek(fp,0L,0);
	fread(buffer, size, 1, fp) ;
	buffer[size+1] = '\0';
	printf("\n %s", buffer);
	printf("\nPress a key");
	getchar();
	fclose(fp);
	fflush(stdin);
	printf("\n ENTER PATTERN TO WHICH WANT TO REPLACE: ");
	gets(pattern1);
	fflush(stdin);
	printf("\n ENTER NEW PATTERN: ");
	gets(pattern2);

	replacement(buffer, pattern1, pattern2);
	printf("\n %s", buffer);
	printf("\nPress a key");
	getchar();
}

