/*E15 and E16*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int isEmpty(int top, int stack_arr[]);
void PFactors( int num);
void push(int x, int *top, int stack_arr[]);
int pop(int *top, int stack_arr[]);
void DecToBin(int num);

main()
{
	int num;
	printf("Enter an integer : ");
	scanf("%d",&num);
	printf("Binary Equivalent is : ");
	DecToBin(num);
	printf("Prime factors are : ");
	PFactors(num);
}/*End of main()*/

void DecToBin(int num)
{
	int stack[MAX], top=-1, rem;
	while(num!=0)
	{
		rem = num%2;
		push(rem, &top, stack);
		num/=2;
	}
	while(top!=-1)
		printf("%d", pop(&top, stack));
	printf("\n");
}

void PFactors( int num)
{
	int stack[MAX], top=-1, i;
	for(i=2; num!=1; i++)
		while(num%i == 0)
		{
			push(i, &top, stack);	
			num = num/i;
		}
	while(top!=-1)
	{
		printf("%d ",stack[top]);		
		pop(&top, stack);
	}
	printf("\n");
}/*End of PFactors()*/

void push(int x, int *top, int stack_arr[])
{	
	if(*top == (MAX-1))
		printf("Stack Overflow\n");
	else
	{
		*top=*top+1;
		stack_arr[*top] = x;
	}
}/*End of push()*/

int pop(int *top, int stack_arr[])
{
	int x;
	if(*top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);	
	}
	else
	{
		x = stack_arr[*top];
		*top=*top-1;
	}
	return x;
}/*End of pop()*/
