/*P8.10 Binary tree Sort*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};

struct node *stack[MAX];
int top=-1;
void push_stack(struct node *item);
struct node *pop_stack();
int stack_empty();

struct node *insert(struct node *ptr, int item );
void inorder(struct node *ptr, int arr[]);
struct node *Destroy(struct node *ptr);

main()
{
	struct node *root=NULL;
	int arr[MAX], n, i;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	for(i=0; i<n; i++)
		root = insert(root, arr[i]);

	inorder(root, arr);
    
	printf("\nSorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
   	root=Destroy(root);
}/*End of main( )*/

struct node *insert(struct node *root, int ikey)
{       
	struct node *tmp,*par,*ptr;
	
	ptr = root;
	par = NULL;

	while(ptr!=NULL)
	{
		par = ptr;
		if(ikey < ptr->info)
			ptr = ptr->lchild;	
		else 
			ptr = ptr->rchild;
	}
	
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=ikey;
	tmp->lchild=NULL;
	tmp->rchild=NULL;

	if(par==NULL)
		root=tmp;
	else if(ikey < par->info)
		par->lchild=tmp;
	else
		par->rchild=tmp;
	
	return root;
}/*End of insert( )*/

void inorder(struct node *root, int arr[])
{
	struct node *ptr=root;
	int i=0;
	if( ptr==NULL )
	{
		printf("Tree is empty\n");
		return;
	}
	while(1)
	{
      while(ptr->lchild!=NULL )
		{
			push_stack(ptr);
			ptr = ptr->lchild;
		}
			
		while( ptr->rchild==NULL )
		{
			arr[i++]=ptr->info;
			if(stack_empty())
				return;
			ptr = pop_stack();
		}
		arr[i++]=ptr->info;
		ptr = ptr->rchild;
	}
	printf("\n");
}/*End of inorder( )*/

/*Delete all nodes of the tree*/
struct node *Destroy(struct node *ptr)
{
	if(ptr!=NULL)
	{
		Destroy(ptr->lchild);
		Destroy(ptr->rchild);
		free(ptr);
	}
	return NULL;
}/*End of Destroy()*/

/*Functions for implementation of stack*/
void push_stack(struct node *item)
{
	if(top==(MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	stack[++top]=item;
}/*End of push_stack()*/

struct node *pop_stack()
{
	struct node *item;
	if(top==-1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	item=stack[top--];
	return item;
}/*End of pop_stack()*/

int stack_empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
} /*End of stack_empty*/


