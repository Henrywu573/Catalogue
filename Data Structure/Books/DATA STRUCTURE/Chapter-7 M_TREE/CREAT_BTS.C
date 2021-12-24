/* Create Binary TREE */
/* CREAT_BTS.C */

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

Tnode *root=NULL,*ptr,*par,*New;
int top=SIZE;
Tnode *stack[SIZE];

void create(Tnode *);
void display(Tnode *,int);
void push(Tnode *);
Tnode *pop();

void main()
{
	char x,choice;
	clrscr();
	create(root);
	printf("created tree is as follow:");
	display(root,1);
	getch();
}

void create(Tnode *ptr)
   {
      int x;
      char choice;
	do
	{
	New= (Tnode *) malloc(sizeof(Tnode));
	printf("Enter element:->");
	scanf("%d",&x);
	New->info=x;
	New->left_child=NULL;
	New->right_child=NULL;
	/* attach new node in to its correct position */

	if(root==NULL)  /* insert at root */
	  root=New;
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
}

void display(Tnode *ptr, int Level)
  {
	int i;
	if (ptr!=NULL)
	{
	display(root,1);
	/* pre_order tree traversal  */
	printf("\n pre order traversal is:->");
	ptr=root;
	while(ptr!=NULL)
	{
	    printf("%d  ",ptr->info);    /* process the root */
	    if(ptr->right_child!=NULL)   /* push the right sub tree on stack */
		push(ptr->right_child);
	  if(ptr->left_child!=NULL)    /* move to left subtree */
		ptr=ptr->left_child;
	    else
		ptr=pop();
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
     if(top==SIZE)
      {
       printf("\n tree has been traversed");
       exit(0);
      }
     else
       {
	x=stack[top];
	top=top+1;
       }
      return(x);
   }
