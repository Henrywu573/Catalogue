/* POST_ORDER Tree traversal */
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

struct stack
{
 int flag;
 Tnode *sub_tree;
};
typedef struct stack stk;

Tnode *root=NULL,*ptr,*par,*New;
int top=SIZE;
stk stack[SIZE];
stk temp;
void push(int,Tnode *);
stk pop();

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

	printf("\n post order traversal is:->");
	ptr=root;
POST_BEGIN:  while(ptr!=NULL)
		{
	//	    if(ptr->right_child!=NULL)   /* push the right sub tree on stack */
		    push(0,ptr);
		    if(ptr->right_child!=NULL)    /* move to left subtree */
		       push(1,(ptr->right_child));
		    ptr=ptr->left_child;
		  }
		  temp=pop();
		  while(temp.flag==0)
		     {
		       ptr=temp.sub_tree;
		       printf("%d  ",ptr->info);    /* process the root */
		       temp=pop();
		      }
		   if(temp.flag==1)
		     {
		      ptr=temp.sub_tree;
		      goto POST_BEGIN;
		     }

	    getch();
	}

 void push(int f,Tnode *x)
    {
      if(top==0)
	 printf("stack is full");
      else
	 {
	 top=top-1;
	 stack[top].flag=f;
	 stack[top].sub_tree=x;
	 }
     }

 stk pop()
   {
     stk x;
     if(top==SIZE)  /*tree has been traversed*/
       exit(0);
     else
       {
	x=stack[top];
	top=top+1;
       }
      return(x);
   }
