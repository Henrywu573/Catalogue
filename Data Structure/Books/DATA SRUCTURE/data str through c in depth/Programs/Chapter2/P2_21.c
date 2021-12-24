/*P2.21 Program to understand the use of realloc() function*/
#include<stdio.h>
#include<stdlib.h>
main( )
{
	int i, *ptr;
	ptr = (int *)malloc(5 *sizeof(int));
	if(ptr == NULL)
	{
		printf("Memory not available\n");
		exit(1);
	}
	printf("Enter 5 integers : ");
	for(i=0; i<5; i++)
		scanf("%d", ptr+i);
	/*Allocate memory for 4 more integers*/
	ptr = (int *)realloc(ptr, 9*sizeof(int)); 
	if(ptr == NULL) 
	{
		printf("Memory not available\n");
		exit(1);
	}
	printf("Enter 4 more integers : ");
	for(i=5; i<9; i++)
		scanf("%d", ptr+i);
	for(i=0; i<9; i++)
		printf("%d ", *(ptr+i));
}
