/* Delete a substring from a string */
/* DELET.C */

# include<stdio.h>
# include<string.h>

int index_str1,index_str2,k;
int c[100];

int str_del_loc(char *, char *, int *);

/* Function str_del_loc that finds location of the sub-string and delete. */

int  str_del_loc(char *s1, char *s2, int c[])
{
	int j, count = 0;
	int i, l =0;
	for(index_str1 = 0;  s1[index_str1]; index_str1++)
		for(index_str2=index_str1, k = 0; s1[index_str2] == s2[k]&&s1[index_str1]; index_str2++, k++)
			if( !s2[k+1])
			{
				count ++;
				c[l++] = index_str1;
				for(j = index_str1, i = strlen(s2)+index_str1; s1[i]; j++, i++)
					s1[j] = s1[i];
				s1[j] = NULL;
				printf("\n After delete operation the output %s", s1);
			}
	return(count);
}

/* Function main */

void main()
{
	char *s;
	int c[100];
	char s1[]="Ram Bahadur Bahadur Patel";
	char s2[] ="Baha";
	int count;
	count = str_del_loc (s1, s2,c);
	printf("\n Number of occurences = %d", count);
}

