
/**   STRING6.C  **/

# include<stdio.h> 
# include<malloc.h>

char *sub_string(char *, int , int );

void main()
{
	char string[] = "MY FATHER IS PRINCIPAL OF G.B.P.E.C";
	char *substr;

	substr = ( char *) malloc(9);

	printf("\n INPUT PATTERN IS ");
	printf("\n **************** \n");
	printf("\n %s", string);

	printf("\n\n PATTERN FOUND ");
	printf("\n ************* \n");
	substr = sub_string(string, 13, 9);
	printf("\n %s", substr);
	printf("\n Press a key");
	getchar();

}

/* This function finds the pattern */

char *sub_string(char *string, int strpos, int size )
{
	char *substring;
	int i = 0 ;
	substring = ( char *) malloc(size);
	while(size)
	{
		substring[i] = string[strpos];
		strpos ++;
		i ++;
		size --;
	}
	substring[i] = '\0';
	return(substring);
}
