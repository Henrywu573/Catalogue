/* IN_ORDER Tree traversal */
/* CREAT_BT.C */

# include<stdio.h>
# include<malloc.h>
#define SIZE 10

struct tree
{
	struct tree *left_child;
	int info;
	struct tree *right_child;
};
typedef struct tree Tnode;
/*Prototype declaration*/
void push(Tnode *);
Tnode *pop();

/*Global variable declaration*/
Tnode *root=NULL,*ptr,*par,*New;
int top=SIZE;
Tnode *stack[SIZE];
Tnode *temp;

void main()
{
	char x,choice;
	clrscr();
	do
	{
	/* create  new node */
	New= (Tnode *) malloc(sizeof(Tnode));
	printf("Enter element:->");
	scanf("%d",&x);
	New->info=x;
	New->left_child=NULL;
	New->right_child=NULL;
	/* attach new node in to its correct position */

	if(root==NULL)  /* insert at root */
	  {
	  root=New;
	  }
	else
	{
	 /* locate the leaf node */
	 ptr=root;
	 while(ptr!=NULL)
	   {
	     if(x==ptr->info)
	       {
		printf("already present");
		exit(0);
	       }
	     par=ptr;
	     if(x<ptr->info)
	       ptr=ptr->left_child;
	     else
	       ptr=ptr->right_child;
	    }
	  if(x<par->info)  /* insert as left child */
	       par->left_child=New;
	  else
	       par->right_child=New;  /* insert as right child */

	}
	printf("more element:->");
	fflush(stdin);
	choice=getchar();
	}while(choice=='y');
 /* in_order tree traversal  */
	printf("\n in order traversal is:->");
	ptr=root;
IN_BEGIN: while(ptr!=NULL)
	     {
		push(ptr);               /* push the root of sub tree on stack */
		ptr=ptr->left_child;     /* move to left subtree */
	     }
	      temp=pop();
	      ptr=temp;
	while(ptr!=NULL)
	  {
	      printf("%d  ",ptr->info);    /* process the root */
	      if(ptr->right_child!=NULL)
		{
		 ptr=ptr->right_child;
		 goto IN_BEGIN;
		}
	     temp=pop();
	     ptr=temp;
	  }
     getch();
 }

 void push(Tnode *x)
    {
      if(top==0)
	 printf("stack is full");
      else
	 {
	 top=top-1;
	 stack[top]=x;
	 }
     }

 Tnode *pop()
   {
     Tnode *x;
     if(top==SIZE)  /*tree has been traversed*/
       {
	printf("\n tree has been traversed");
	return NULL;
       }
     else
       {
	x=stack[top];
	top=top+1;
       }
      return(x);
   }
