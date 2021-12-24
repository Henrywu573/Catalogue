/* Deletion in Binary Search Tree */
/* BST_DEL_BT.C */

# include<stdio.h>
# include<malloc.h>
# define SIZE 10

struct tree
{
	struct tree *left_child;
	int info;
	struct tree *right_child;
};
typedef struct tree Tnode;


Tnode *root=NULL,*ptr=NULL,*New=NULL;
Tnode *loc=NULL,*par=NULL;
int top=SIZE;
Tnode *stack[SIZE];

void create(Tnode *);
Tnode *search(int);
void display(Tnode *);
void Del_First_Case(Tnode *,Tnode *);
void Del_Second_Case(Tnode *,Tnode *);
void push(Tnode *);
Tnode *pop();

void main()
 {
   char choice;
   int x;

   create(root);
   display(root);
   printf("\n enter element to be deleted:->");
   scanf("%d",&x);
   loc=search(x);
   if(loc==NULL)
     {
      printf("element to be deleted not present");
      exit(0);
     }
   if(loc->left_child!=NULL && loc->right_child!=NULL)
     Del_Second_Case(loc,par);
   else
     Del_First_Case(loc,par);
   display(root);
   getch();
  }


void create(Tnode *ptr)
 {
   char choice;
   int x;
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
		printf("\n already present");
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

/* pre_order tree traversal  */
void display(Tnode *ptr)
 {
	Tnode *temp;
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
	      {
		temp=pop();
		ptr=temp;
	      }
	  }

  }

Tnode *search(int x)
  {
    if(root==NULL)
      { loc=par=NULL;return(loc);}
    if(x==root->info)
      {loc=root;par=NULL;return(loc);}
    else
       {
	 if(x<root->info)
	   {ptr=root->left_child;par=root;}
	 else
	   {ptr=root->right_child;par=root;}
	 while(ptr!=NULL && ptr->info!=x)
	   {
	    if(x<ptr->info)
	      {par=ptr;ptr=ptr->left_child;}
	    else
	       {par=ptr;ptr=ptr->right_child;}
	   }
	    if(ptr->info==x)
	      loc=ptr;
	    else
	      loc=NULL;
	  return(loc);
       }
  }
void Del_Second_Case(Tnode *loc,Tnode *par)
 {
    Tnode *ptr,*suc,*parsuc;
    ptr=loc->right_child;
    parsuc=loc;
    while(ptr->left_child!=NULL)
       {parsuc=ptr;ptr=ptr->left_child;}
    suc=ptr;
//    parsuc=par;
//    loc=suc;par=parsuc;
    Del_First_Case(suc,parsuc);
    if(par!=NULL)
      {
       if(loc==par->left_child)
	 par->left_child=suc;
       else
	 par->right_child=suc;
      }
    else
       root=suc;
    suc->left_child=loc->left_child;
    suc->right_child=loc->right_child;
 }

void Del_First_Case(Tnode *loc,Tnode *par)
  {
     Tnode *chld;
	  if(loc->left_child==NULL && loc->right_child==NULL)
	    chld=NULL;
	  else if(loc->left_child!=NULL)
	    chld=loc->left_child;
	  else
	    chld=loc->right_child;
	  if(par!=NULL)
	     {
	      if(loc==par->left_child)
		 par->left_child=chld;
	      else
		 par->right_child=chld;
	     }
	  else
	    root=chld;
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
	 printf("tree has been traversed");
	 return NULL;
       }
     x=stack[top];
	top=top+1;
      return(x);
   }

