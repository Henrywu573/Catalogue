/* Malloc function*/
/* MALLOC.C */

# include<malloc.h>
# include<stdlib.h>
# include<stdio.h>


void main()
{
	int *p, i;
	p = (int *) malloc(200* sizeof(int));

	for (i = 0; i < 200; i++)
	{
		*(p+i) = 88;
	}

	for (i = 0; i < 200; i++)
	{
		printf(" 0x%x", (p+i));
		printf(" %d", *(p+i));
	}
	getchar();
}
 