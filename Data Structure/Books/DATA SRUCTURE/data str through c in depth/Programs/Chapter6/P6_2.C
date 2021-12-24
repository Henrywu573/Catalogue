/*P6.2 Program for constructing a binary tree from inorder and postorder */

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
}*post=NULL, *in=NULL;

void display(struct treenode *ptr,int level);
struct listnode *addtoempty(struct listnode *start,int data);
struct listnode *addatend(struct listnode *start,int data);
struct listnode *create_list(struct listnode *start, int n);
struct treenode *construct(struct listnode *inptr,struct listnode *postptr, int num);
void inorder(struct treenode *ptr);
void preorder(struct treenode *ptr);
void postorder(struct treenode *ptr);

main()
{
	int n;

	printf("Enter the number of nodes  :  ");
	scanf("%d",&n);

	printf("Enter inorder\n");
	in = create_list(in,n);

	printf("Enter postorder\n");
	post = create_list(post,n);

	root = construct(in,post,n);

	printf("Inorder : ");  inorder(root);
	printf("\nPostorder : ");  postorder(root);
	printf("\nPreorder : "); preorder(root);
	printf("\n\nTree is : \n");
	display(root,0);
	printf("\n");
}/*End of main()*/

struct treenode *construct(struct listnode *inptr,struct listnode *postptr, int num)
{
	struct treenode *temp;
	struct listnode *q, *ptr;

	int i,j;
	if(num==0)
		return NULL;
	
	ptr=postptr;
	for(i=1;i<num;i++)
		ptr = ptr->next;

	/*Now ptr points to last node of postorder which is root*/
	
	temp=(struct treenode *)malloc(sizeof(struct treenode));
	temp->info=ptr->info;
	temp->lchild = NULL;
	temp->rchild = NULL;

	if(num==1)/*if only one node in tree */
		return temp;
		
	q=inptr;
	for(i=0; q->info!=ptr->info; i++ )
		q = q->next;

	/*Now i denotes the number of nodes in left subtree
	and q points to root node in inorder list*/	
	
	/*For left subtree*/
	temp->lchild = construct(inptr, postptr, i);
			
	/*For right subtree*/
	for(j=1;j<=i;j++)
		postptr = postptr->next;
	temp->rchild = construct(q->next, postptr, num-i-1);
		
	return temp;
}/*End of construct()*/

struct listnode *create_list(struct listnode *start, int n)
{
	int i,data;
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

void display(struct treenode *ptr,int level)
{
	int i;
	if(ptr!=NULL)
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->lchild, level+1);
	}
}/*End of display()*/


