/* Replace a sub-string in a string */
/* REPLACE.C*/

# include<stdio.h>
# include<string.h>

int index_str1,index_str2,k;
int c[100];

int str_rep(char *, char *, int *);

/* Function str that finds first location of the sub-string */

int str_rep(char *s1, char *s2, int c[])
{
	int count = 0;
	int l =0;
	int j, i = 0;
	char s3[]= "Jaunpur";
	for(index_str1 = 0;  s1[index_str1]; index_str1++)
		for(index_str2=index_str1, k = 0; s1[index_str2] == s2[k]&&s1[index_str1]; index_str2++, k++)
			if(!s2[k+1])
			{
				count ++;
				c[l++] = index_str1;
				for(j = index_str1; j < strlen(s3)+index_str1;  j++)
					s1[j] = s3[i++];
				printf("\n %s ", s1);
			}

	return(count);
}

/* Function main */

void main()
{
	char *s;
	int c[100];
	char s1[]="Ram Bahadur Bahadur Patel";
	char s2[] ="Bahadur";
	int count;
	str_rep(s1, s2,c);
}

