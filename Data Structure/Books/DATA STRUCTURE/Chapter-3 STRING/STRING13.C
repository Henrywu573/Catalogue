
/**   STRING13.C   **/

# include<stdio.h>
# include<string.h>
# include<malloc.h>
# include<stdlib.h>

void markov(char *, char *, char * );

/**           Global parameters               **/

char *buffer;
char ch;
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
	printf("SIZE OF FILE: %d", size);
	printf("\n Press a key\n");
	getchar();
	buffer = (char *) malloc(size+1);
	fseek(fp,0L,0);
	fread(buffer, size, 1, fp) ;
	buffer[size] = '\0' ;
	printf("%s", buffer);
	getchar();
	fclose(fp);

	do
	{
		fflush(stdin);
		printf("Enter choice n for break ");
		ch = getchar();
		fflush(stdin);
		printf("\n ENTER PATTERN TO WHICH WANT TO REPLACE: ");
		gets(pattern1);
		fflush(stdin);
		printf("\n ENTER NEW PATTERN : ");
		gets(pattern2);

		markov(buffer, pattern1, pattern2);
	} while( ch !='n');
}

void markov(char *buffer, char *pattern1, char *pattern2)
{
	int k, b;
	char *temp ;

	length = strlen(pattern1);
	s = ( char *) malloc(length);
	printf("\n Length = %d", length);
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
					printf(" LENGTH OF PATTERN  =  %d", l);
					printf("\n PATTERN IS : %s", s);
					printf("\n Starting Position = %i", (position-l));

					/*  REPLACEMENT SECTION */

					k = 0;
					for( k = 0 ; k < (position-l) ; k++ )
					{
						temp[k] = buffer[k] ;
					}
					j = 0 ;
					b =   (k+ strlen(pattern2));

					for (  ; k < b ; k ++)
					{
						temp[k] = pattern2[j] ;
						j++ ;
					}
					temp[k] = '\0';
					getchar();

					b = k ;
					k = position + 1;

					for (  ;  k < back2 ; k ++)
					{
						temp[b] = buffer[k] ;
						b++ ;
					}
					temp[b] = '\0';
					buffer = temp ;

					/* END OF REPLACEMENT SECTION */

					l= 0 ;
					j = 0 ;
					printf("\nPATTERN REPLACEMENT IN PROGRESS");
					printf("\n*******************************\n");
					printf("\nSEE AFTER FIRST PATTERN REPLACEMENT ");
					printf("\n***********************************\n");
					printf("%s", buffer);

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
