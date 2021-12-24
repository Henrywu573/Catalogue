/* Find location of a substring first start in a string */
/*  LOCAT.C */

# include<stdio.h>

int index_str1,index_str2,k;
int str(char *, char *);

/* Function str that finds first location of the sub-string */

int str(char *s1, char *s2)
{
	for(index_str1 = 0;  s1[index_str1]; index_str1++)
		for(index_str2=index_str1, k =0; s1[index_str2] == s2[k]; index_str2++, k++)
			if( !s2[k+1])
			{
				return(index_str1);
			}
	return(NULL);
}

/*  Function main */

void main()
{
	char *s;
	char s1[]="Ram Bahadur Patel";
	char s2[] ="Baha";
	int location = str (s1, s2);
	s = s2;
	printf("\n Location = %d", location);
	while(*(s++))
	{
		putchar(s1[location++]);
	}
}

