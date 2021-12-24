/*E20*/
/* Program for conversion of postfix to prefix */
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50

char *pop();
char postfix[MAX];
char stack[MAX][MAX];
void push(char *str);
int isempty();
int white_space(char symbol);
void postfix_to_prefix();
int top;

main()
{
	top = -1;
	printf("Enter postfix : ");
	gets(postfix);
	postfix_to_prefix();

}/*End of main()*/

void postfix_to_prefix()
{
	unsigned int i;
	char operand1[MAX], operand2[MAX];
	char symbol;
	char temp[2];
	char strin[MAX];
	for(i=0;i<strlen(postfix);i++)
	{
		symbol=postfix[i];
		temp[0]=symbol;
		temp[1]='\0';
				
		if(!white_space(symbol))
		{
			switch(symbol)
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				strcpy(operand1,pop());
				strcpy(operand2,pop());
				strcpy(strin,temp);
				strcat(strin,operand2);
				strcat(strin,operand1);
				push(strin);
				break;
			default: /*if an operand comes*/
			     push(temp);
			}
		}
	}
	printf("prefix : ");
	puts(stack[0]);
}/*End of postfix_to_prefix()*/


void push(char *str)
{
	if(top > MAX)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	else
	{
		top=top+1;
		strcpy( stack[top], str); 
	}
}/*End of push()*/

char *pop()
{
	if(top == -1 )
	{
		printf("Stack underflow \n");
		exit(2);
	}
	else
		return (stack[top--]);
}/*End of pop()*/
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int white_space(char symbol)
{
	if( symbol == BLANK || symbol == TAB || symbol == '\0')
		return 1;
	else
		return 0;
}/*End of white_space()*/