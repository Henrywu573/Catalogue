/* Defintion of Pointer and arrays */
/* pointer.c */

# include<stdio.h>
# define rows 5
# define cols 5

void main()
{
	int i, j;
	int Table[rows][cols] = {
						{10,11,12,13,14},
						{15,16,17,18,19},
						{20,21,22,23,24},
						{25,26,27,28,29},
						{30,31,32,33,34}	};

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf(" 0x%x", *(Table+i)+j);
			printf(" %d", *(*(Table+i)+j));
		}
		printf("\n");
	}
}
 