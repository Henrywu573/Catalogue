
/**   STRING4.C  **/

# include<stdio.h>
# include<malloc.h>


void gets1 (char **, int );
void display ( char **, int);
void input (char **, int );

/*  gets1() function to read a string */

void gets1(char **s, int i )
{
	int j;
	char ch;
	ch = getchar();
	while(ch != '\n')
	{
		s[i][j] = ch ;
		ch = getchar();
		j++;
	}
	s[i][j]='\0';
}

/* Output funtion */

void display(char **str, int n)
{
	int i;
	printf("\nEntered strings are follows");
	printf("\n***************************");
	for(i = 0 ; i < n; i++ )
	{
		printf("\n %s",  str[i]);
	}
	printf("\n Press a key");
	getchar();
}

/* Input function */

void input( char **str, int n)
{
	int i;
	int size;

	for ( i = 0 ; i < n ; i++ )
	{
		fflush(stdin);
		printf("\n Enter Approximate size of string->");
		scanf("%d", &size);
		fflush(stdin);
		str[i] = (char *) malloc(size);
		printf("\n Input the string: ");
		gets1(str,i);
	}
}

/*  Function main */

void main()
{
	int n;
	char *str[50];
	printf("\n Input number of strings want to process:");
	scanf("%d", &n);
	input(str, n);
	display(str, n);
}

