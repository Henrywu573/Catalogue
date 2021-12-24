#include<conio.h>
#include<stdio.h>
#define SIZE 10

int TOP=SIZE;
int stack[SIZE];

void push(int);
int pop();

void main()
  {
   char postfix[100],c;
   int i=0,r1,r2,r,x;
   printf("Enter the exp.");
   scanf("%s",postfix);
   while((c=postfix[i])!='\0')
      {

      switch(c)
	 {
	  case'+':
		  r1=pop();
		  r2=pop();
		  r=r2+r1;
		  push(r);
		  break;
	  case'-':
		  r1=pop();
		  r2=pop();
		  r=r2-r1;
		  push(r);
		  break;
	  case'*':
		  r1=pop();
		  r2=pop();
		  r=r2*r1;
		  push(r);
		  break;
	  case'/':
		  r1=pop();
		  r2=pop();
		  r=r2/r1;
		  push(r);
		  break;

	   default:printf("Enter the value of %c",c);
		   scanf("%d",&x);
		   push(x);
	  }

	 i++;
     }
	 r=pop();
	 printf("result of exp:->%d",r);
	 getch();
   }
 void push(int x)
    {
      if(TOP==0)
	 printf("stack is full");
      else
	 {
	 TOP=TOP-1;
	 stack[TOP]=x;
	 }
     }
 int pop()
   {
     int x;
     if(TOP==SIZE)
       printf("stack is empty");
     else
       {
	x=stack[TOP];
	TOP=TOP+1;
       }
      return(x);
   }
