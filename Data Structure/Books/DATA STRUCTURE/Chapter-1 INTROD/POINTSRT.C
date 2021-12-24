/* Pointer and Array */
/* POINTSRT.C */

# include<stdio.h>
# include<string.h>
# include<ctype.h>

/* PROTOTYPE */

void sort(char **, int );

/* Definition of function */

void sort(char **str, int n)
{
	int i,j, flag;
	char *temp = (char *)malloc(50);
	for(i =0; i < n; i++)
	{
		flag = 1;
		for (j=0; j <(n-i-1); j++)
		{
			if (strcmp (str[j], str[j+1])>0)
			{
				flag = 0;
				temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
		if (flag)
			break;
	}
}

/* Function main */

void main()
{
	char choice;
	int i, n = 0;
	char *string[100];
	do
	{
		string[n] = (char *) malloc(50);
		printf("Input string: ");
		gets(string[n]);
		n++;
		fflush(stdin);
		printf("\n Input another Y/N? ");
		choice = getchar();
		fflush(stdin);
	}while(toupper(choice) == 'Y');
	printf("Unsorted list \n");
	printf("************\n");
	for (i = 0; i < n; i++)
	{
		printf(" 0x%x", &string[i]);
		printf(" ");
		printf("%s", string[i]);
		printf("\n");
	}
	sort(string, n);
	printf("\n Sorted list");
	printf("\n************\n");
	for (i = 0; i < n; i++)
	{
		printf(" 0x%x", &string[i]);
		printf(" %s", string[i]);
		printf("\n");
	}
}
