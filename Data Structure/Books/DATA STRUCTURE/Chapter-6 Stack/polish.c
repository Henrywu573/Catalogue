
/* polish.c */

  # include<malloc.h>
  # include<string.h>
  # include<stdlib.h>

  # define size 5

	void puch(char *, char , int *);
		  char pop( char *, int *);
		  int letter_match(char );
		  void push(char *, int *, char );
		  int match_number(char );
		  int match_operator(char );
		  int operator_precedence(char );
		  void polish_fun(char *, char *, int *);
		  void error(int, int );

/* Push function */

	void push( char s[], int *s_pointer, char ch)
	   {
	     if(*s_pointer == size)
	       {
		 printf("\n Stack overflow");
	       }
	       else
	       {
		 s[++(*s_pointer)] = ch ;
	       }
	 }

/* Pop function */

  char pop( char s[], int *s_pointer)
       {
	 if(*s_pointer < 0)
	  {
	   printf("\n Stack underflow");
	   return 0;
	  }
	  else
	  {
	   return(s[(*s_pointer) -- ]);
	  }
      }

/* Definition of function */

  int letter_match(char ch)
	    {
	      return(((ch>='A')&&(ch<='Z')) || ((ch>='a')&&(ch <= 'z')));
	    }

/* Definition of the function */

 int  match_number( char ch)
	  {
	     return((ch >='0') && (ch<='9'));
	  }

/* Definition of the function */

  int match_operator(char ch)
	  {
	  int i;
	    char operator[6];

		  operator[0] = '+';
		  operator[1] = '-';
		  operator[2] = '*';
		  operator[3] = '/';
		  operator[4] = '%';

	     for(i = 0; i < 5; i ++)
		 {
		    if(ch == operator[i])
		      return(1);
		     else
		      return(0);
		 }
	   }

/* Definition of the function */

  int operator_precedence(char ch)
     {
       int preced;
       switch(ch)
	  {
	    case '(' : preced = 0; break;
	    case '+' :
	    case '-' : preced = 1; break;
	    case '*' :
	    case '/' : preced = 2; break;
	    case '%' : preced = 3; break;
	  }
	  return(preced);
     }

/* Definition of the function */

   void polish_fun(char infix[], char suffix[], int *err)
       {
	 char ch, last =')';
	 char stack[size];
	 int i = 0;
	 int s_pointer = -1;
	 int bracket = 1;
	 int ifp,sfp = 0;

	 push(stack, &s_pointer,'(');

	   do
	     {
	       while(infix[i] ==' ')
	       ++i;
	       ifp = i;
	       ch = infix[ifp];
   switch(ch)
   {
   case '(': if(letter_match(last)||match_number(last) || (last == ')'))
	      {
		 *err = 1;
		 error(1,ifp+1);
	      }
	      ++bracket ;
	      push(stack,&s_pointer,ch);
	      break;
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':

      if(match_operator(last)||(!letter_match(last)&& !match_number(last)&&(last!=')')))
	 {
	   *err = 1;
	   error(2,ifp+1);
	 }

	 while(operator_precedence(stack[s_pointer] >=operator_precedence(ch))
	   suffix[sfp++]=pop(stack,&s_pointer);
	   push(stack,&s_pointer,ch);
	   break;

    case ')':
      if(match_operator(last)
	{ *err = 1;
	   error(2,ifp+1);
	}

	if(last == '(')
	   {
	      *err = 1;
	      error(2,ifp+1);
	      error(1,ifp+1);
	   }

	while(stack[s_pointer] != '(' && s_pointer > 0)
	  suffix[sfp++] = pop(stack, &s_pointer);
	  --s_pointer;
	  --bracket;
	  break;

    case  ' ': while(infix[ifp+1] == ' ' && !infix[ifp])
	     ++ifp;
	     break;
    default:
	      if(letter_match(last)||math_number(last))
	       {
		  *err = 1;
		  error(1,ifp+1);
		  error(5,ifp+1);
	       }

	       if (letter_match(ch))
		  suffix[sfp++] = infix[ifp];
		  else
		   if (match_number(ch))
		     {
		       while(match_number(infix[ifp]))
			  suffix[sfp++] = infix[ifp++];
			  --ifp;
		      }

		      else error(4,ifp+1);
		   } /* end of switch */

	last = infix[ifp];
	++ifp;
	i = ifp;
	} while(infix[ifp]);

	suffix[sfp] = 0;
	if(bracket)
	  {
	     *err =1;
	     error(3,ifp-1);
	   }
	}
	break;

/* Definition of the function */

	void input(char infix[])
	   {
	     int i = 0;
	     printf("\nInput the infix expression: ");
	     gets(infix);
	     i = strlen(infix);
	     printf("\n Entered expression is :");
	     gets(infix);
	     infix[i] = ')';
	     infix[i+1] = '\0';
	    }

 /* Definition of the function */

 void error(int n, int ifp)
    {
       switch(n)
	   {
	     case 1: printf("\n Error->1:Missing operator");
	     case 2: printf("\n Error->2:Missing operand");
	     case 3: printf("\n Error->3:Mismatched parentheses");
	     case 4: printf("\n Error->4:Illegal character is expression");
	     case 5: printf("\n Error->5:Multicharacter variable");
	    }
	 printf("\n Position of the cursor: %d", ifp);
     }

/* Definition of the function main */

	void main()
	   {
	     int err, ans;
	     char infix[size],suffix[size];
	     err = 0;
	     input(infix);
	     polish_fun(infix,suffix, &err);
	     if(!err)
	       {
		 printf("\n The suffix form of the given, expression is: ");
		 puts(suffix);
	       }
	   }

