/* postfix.c */

# include<stdio.h>
# include<string.h>
# include<ctype.h>
# include<stdlib.h>

# define Arnold '\0'
# define Blank ' '
# define Tab '\t'

#define Maxlen 64

static char infix [Maxlen+1], stack[Maxlen], postfix[Maxlen+1];

# define Empty (-1) /* empty stack */
static int top;

/* symbol types */

#define Operator (-10)
# define Operand (-20)

# define LeftParen (-30)
# define RightParen (-40)

static char *symbols = "()+-%*/";

/* Symbol precedence */

# define LeftParenPrec 0  /* ( */
# define AddPrec 1 /* + */
# define SubPrec 1 /* - */
# define MultPrec 2 /* * */
# define DivPrec 2 /* / */
# define RemPrec 2 /* % */
# define None 999 /* all else */

void read_input(void);
void infix_to_postfix(void);
void write_output(void);
void push(char symbol);
char pop (void);

int get_type(char );
int get_prec(char );
int white_space(char );

void full_stack();
void empty_stack();

void main()
{
	char ans[2];
	do
	{
		top = Empty; /* reset stack */
		read_input();
		infix_to_postfix();
		write_output();

		/* Selection */

		printf("\n\n Another (y/n)");
		gets(ans);
	} while (toupper(ans[0]) == 'Y');
}

/* function infix to postfix conversion */
void infix_to_postfix(void)
{
	int i,p, len, type, precedence;
	char next ;

	/* i for infix, p for postfix */

	i = p = 0;
	len = strlen(infix);

	/* loop through input string */
	while(i < len)
	{
		/* ignore whitepsce in infix expression */
		if( !white_space(infix[i]))
		{
			type = get_type(infix[i]);
			switch(type)
			{
				/* push left paren onto stack */
			case LeftParen:
				push(infix[i]);
				break;

				/* pop stack until matching left paren */
			case RightParen:
				while((next = pop()) != '(')
					postfix[p++] = next;
				break;
			case Operand: postfix[p++] = infix[i];
				break;
				/* Pop stack until first operator of higher precedence and then stack this operator */

			case Operator:
				precedence = get_prec(infix[i]);

				/* Anything on stack to pop */
				while(top > Empty && precedence<= get_prec(stack[top]))
					postfix[p++] = pop();
				push(infix[i]);
				break;
			}
		}
		i++; /* next symbol in infix expression */
	}

	/* pop any remaining operators */
	while(top > Empty )
		postfix[p++] = pop();
	postfix[p] = Arnold ; /* ensure a string */
}

/* Function to find operator type */

int get_type(char symbol )
{
	switch(symbol)
	{
	case '(' :
		return (LeftParen);
	case ')':
		return (RightParen);
	case '+':
	case '-':
	case '%':
	case '*':
	case '/':
		return (Operator);
	default:
		return (Operand);
	}
}

/* Find precedence of the operator */

int get_prec(char symbol )
{
	switch(symbol)
	{
	case '+':
		return (AddPrec);
	case '-':
		return (SubPrec);
	case '*':
		return (MultPrec);
	case '/':
		return (DivPrec);
	case '%':
		return (RemPrec);
	case '(':
		return (LeftParenPrec);
	default:
		return (None);
	}
}

/* Function push */

void push(char symbol)
{
	/* check for overflow */
	if(top > Maxlen)
		full_stack();
	else
		stack[++top] = symbol;
}

/* Function pop */

char pop(void)
{
	/* check for underflow */
	if (top <= Empty )
		empty_stack();
	else
		return (stack[top--]);
}

/* Exit in case of overflow */

void full_stack(void )
{
	printf("\n Full Stsck ... exiting. \n");
	exit(1);
}

/* Exit in case of underflow */

void empty_stack(void)
{
	printf("\n Empty Stack ... exiting \n");
	exit(2);
}

void read_input(void)
{
	printf("\n Infix (up to %d chars): ", Maxlen);
	gets(infix);
}


/* Output function */
void write_output(void)
{
	printf("\n Infix: %s", infix);
	printf("\n Postfix: %s \n",postfix);
}

/* function white space checking */

int white_space(char symbol)
{
	return( symbol == Blank || symbol == Tab || symbol == Arnold);
}

