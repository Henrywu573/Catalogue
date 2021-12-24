/* Find locations of a substring in a string */
/* LO_NO.C */

# include<stdio.h>
# include<string.h>

int index_str1,index_str2,k;
int c[100];

int str(char *, char *, int *);
int Number_occ(char *, char *, int *);

/* Function str that finds locations of the sub-string */

int str(char *s1, char *s2, int c[])
{
	int count = 0;
	int l =0;
	for(index_str1 = 0;  s1[index_str1]; index_str1++)
		for(index_str2=index_str1, k = 0; s1[index_str2] == s2[k]&&s1[index_str1]; index_str2++, k++)
			if(!s2[k+1])
			{
				count ++;
				c[l++] = index_str1;
			}

	return(count);
}

/* Function main */

void main()
{
	char *s;
	int c[100];
	int location ;
	char s1[]="Ram Bahadur Bahadur Patel";
	char s2[] ="Baha";
	int i, loc;
	int count;

	count = str (s1, s2,c);

	printf("\n Number of occurences = %d", count);

	for(i = 0;i < count; i++)
	{
		location = c[i];
		s = &s2[0];
		printf("\n Starting location = %d|", location+1);
		while(*(s++))
		{
			putchar(s1[location++]);
		}
	}
}

