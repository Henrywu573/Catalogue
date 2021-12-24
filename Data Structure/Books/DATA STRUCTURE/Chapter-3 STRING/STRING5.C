
/**  STRING5.C **/

# include<stdio.h>
# include<string.h>
# include<malloc.h>
# include<stdlib.h>

void main()
{
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
	printf("SIZE OF INFORMATION: %d", size);
	printf("\n Press a key");
	getchar();
	buffer = (char *) malloc(size);
	fseek(fp,0L,0);
	fread(buffer, size, 1, fp) ;
	printf("\n");
	buffer[size]='\0';
	printf("\n %s", buffer);
	fclose(fp);
	fflush(stdin);
	printf("\n Input the Pattern: ");
	gets(string);

	length = strlen(string);
	s = ( char *) malloc(length);
	printf("Length => %d", length);
	back1 = length;
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

			if ( buffer[i] == string[j])
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
					printf("\n Pattern is found\n");
					printf(" Length of pattern: %d and Pattern is : %s ", l, s);
					printf("\n Starting Position -> %d", (position-l));
					printf("\n Press a key");
					getchar();
					l= 0 ;
					j = 0 ;
					for(i = (position - back1); i < position ; i++)
					{
						s1[j] = buffer[i] ;
						j++;
					}
					s1[j] = '\0';
					printf("\nThe old pattern is as follows ");
					printf("\n*****************************\n");
					puts(s1);
					fflush(stdin);
					printf("\n Enter New Pattern : ");
					gets(s1);
					printf("\nThe pattern replacement in progress");
					printf("\n***********************************\n");
					j = 0 ;
					for(i = (position - strlen(s1)); i < position ; i++)
					{
						buffer[i] = s1[j];
						putchar(buffer[i]);
						getchar();
						j++;
					}
					printf("\n After replacing the pattern");
					printf("\n ***************************\n");
					printf("\n %s", buffer);
				}
			}

			else
			{
				i++;
				j = 0;
				l = 0;
				size -- ;
				length = back1;
			}
		}
		length = back1 ;
	}
	fclose(fp);
}
