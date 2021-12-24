
/* Calloc function*/
/* CALLOC.C */

# include<malloc.h>
# include<stdlib.h>
# include<stdio.h>

/* Function main*/

void main()
{
	int *p, i;
	if((p =(int *) calloc(800, 2)) == NULL)
	{
		printf("\n Out of Memory \n");
		exit(0);
	}
	for (i = 0; i < 800; i++)
	{
		printf("  0x%x", (p+i));
		printf(" %d", *(p+i));
	}

	getchar();

	for (i = 0; i < 800; i++)
	{
		*(p+i) = 77;
	}

	for (i = 0; i < 800; i++)
	{
		printf(" 0x%x", (p+i));
		printf(" %d", *(p+i));

	}
	getchar();
}
