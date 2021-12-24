/* BUBBLE SORT FOR SORTING STRINGS */
/* BUB_STR.C */

# include <stdlib.h>
# include <string.h>
# include <malloc.h>
# include <stdio.h>

void bubble_sort(char *list[], int );
void display(char *list[], int);

void bubble_sort(char *list[], int n)
{
	char *temp;
	int i, j;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-1-i; j++)
		{
			if (strcmp(list[j+1], list[j]) < 0)
			{
				temp =(char *) malloc(sizeof(list[i]));
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
		printf(" \n List after pass: %d", i+1);
		display(list, n);
	}
}
void display(char *list[], int n)
{
	int i;
	for(i = 0 ; i < n; i++)
	{
		printf(" %s ", list[i]);
	}
}

void main(void)
{
	int n;
	char *list[100] = {
		"MONDAY", "TUESDAY", "WEDNESDAY", "FRIDAY", "SATARDAY"	};
	n = 5;
	printf("\n Input list is as follows:");
	display(list, n);
	bubble_sort(list, n);
	printf("\n Sorted list is as follows:\n");
	display(list, n);
}

