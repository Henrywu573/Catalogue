/*P6.1 Program to construct a binary tree from inorder and preorder*/
#include<stdio.h>
#include<stdlib.h>

struct treenode
{
	int info;
	struct treenode *lchild;
	struct treenode *rchild;
}*root=NULL;

struct listnode
{
	struct listnode *prev;
	int info;
	struct listnode *next;
}*pre=NULL, *in=NULL;

void display(struct treenode *ptr,int level);
struct listnode *addtoempty(struct listnode *start,int data);
struct listnode *addatend(struct listnode *start,int data);
struct listnode *create_list(struct listnode *start, int n);
struct treenode *construct(struct listnode *inptr,struct listnode *preptr, int num);
void inorder(struct treenode *ptr);
void postorder(struct treenode *ptr);
void preorder(struct treenode *ptr);

main( )
{
	int n;
	
	printf("Enter the number of nodes  :  ");
	scanf("%d",&n);

	printf("Enter inorder\n");
	in = create_list(in, n);

	printf("Enter preorder\n");
	pre=create_list(pre, n);

	root = construct(in,pre,n);

	printf("Inorder : ");  inorder(root);
	printf("\nPostorder : ");  postorder(root);
	printf("\nPreorder : "); preorder(root);
	printf("\n\nTree is : \n");
	display(root,0);
	printf("\n");
}

struct treenode *construct(struct listnode *inptr,struct listnode *preptr, int num )
{
	struct treenode *temp;
	struct listnode *q;

	int i,j;
	if(num==0)
		return NULL;
	
	temp=(struct treenode *)malloc(sizeof(struct treenode));
	temp->info=preptr->info;
	temp->lchild = NULL;
	temp->rchild = NULL;

	if(num==1)/*if only one node in tree */
		return temp;
	
	q = inptr;	
	for(i=0; q->info != preptr->info; i++)
		q = q->next;
	
	/*Now q points to root node in inorder list and 
	 and number of nodes in its left subtree is i*/
	 
	/*For left subtree*/
	temp->lchild = construct(inptr, preptr->next, i);
	
	/*For right subtree*/
	for(j=1;j<=i+1;j++)
		preptr=preptr->next;
	temp->rchild = construct(q->next, preptr, num-i-1);
	 
	return temp;
}/*End of construct()*/

void display(struct treenode *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->lchild, level+1);
	}
}/*End of display()*/

struct listnode *create_list(struct listnode *start, int n)
{
	int i, data;
	start=NULL;
	for(i=1;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		if(start==NULL)
			start=addtoempty(start,data);
		else
			start=addatend(start,data);	
	}
	return start;
}/*End of create_list()*/

struct listnode *addtoempty(struct listnode *start,int data)
{
	struct listnode *tmp;
	tmp=malloc(sizeof(struct listnode));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}/*End of addtoempty( )*/
struct listnode *addatend(struct listnode *start,int data)
{
	struct listnode *tmp,*p;
	tmp=malloc(sizeof(struct listnode));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}/*End of addatend( )*/

void inorder(struct treenode *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}/*End of inorder( )*/
void postorder(struct treenode *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ",ptr->info);
	}
}/*End of postorder( )*/

void preorder(struct treenode *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		printf("%d  ",ptr->info);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}/*End of preorder( )*/

