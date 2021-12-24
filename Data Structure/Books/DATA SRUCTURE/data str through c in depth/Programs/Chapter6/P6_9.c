/*P6.9 Program for performing various operations in a B-tree*/
#include<stdio.h>
#include<stdlib.h>

#define M 5	/*order of B tree*/
#define MAX (M-1)	/*Maximum number of permissible keys in a node*/

#if M%2==0
#define CEIL_Mdiv2 (M/2)
#else
#define CEIL_Mdiv2 ((M+1)/2)
#endif

#define MIN (CEIL_Mdiv2-1)	/*Minimum number of permissible keys in a node except root*/

struct node
{
	int count;
	int key[MAX+1];
	struct node *child[MAX+1];
};

struct node *Search(int skey,struct node *p,int *pn);
int search_node(int skey,struct node *p,int *pn);
void display(struct node *ptr,int blanks);
void inorder(struct node *ptr);

/*Functions used in insertion*/
struct node *Insert(int ikey,struct node *proot);
int rec_ins(int ikey,struct node *p,int *pk,struct node **pkrchild);
void insertByShift(int k,struct node *krchild,struct node *p,int n);
void split(int k,struct node *krchild,struct node *p,int n,int *upkey,struct node **newnode);

/*Functions used in Deletion*/
struct node *Delete(int dkey,struct node *root);
void rec_del(int dkey,struct node *p);
void delByShift(struct node *p,int n);
int copy_succkey(struct node *p,int n);
void restore(struct node *p,int n);
void borrowLeft(struct node *p,int n);
void borrowRight(struct node *p,int n);
void combine(struct node *p,int m);

int main()
{
	struct node *root = NULL, *ptr;
	int key,choice,n;
	while(1)
	{
		printf("1.Search\n2.Insert\n3.Delete\n");
		printf("4.Display\n5.Inorder traversal\n6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the key to be searched : ");
				scanf("%d",&key);
				if( (ptr=Search(key, root, &n)) == NULL )
					printf("Key not present\n");
				else
					printf("Node %p, Position %d\n",ptr,n);
				break;
			case 2:
				printf("Enter the key to be inserted : ");
				scanf("%d",&key);
				root = Insert(key, root);
				break;
			case 3:
				printf("Enter the key to be deleted : ");
				scanf("%d",&key);
				root = Delete(key, root);
				break;
			case 4:
				printf("Btree is :\n\n");
				display( root, 0 );
				printf("\n\n");
				break;
			case 5:
				inorder(root);
				printf("\n\n");
				break;
			case 6:
				exit(1);
			default:
				printf("Wrong choice\n");
				break;
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/

struct node *Search(int skey, struct node *p, int *pn)
{
	if( p == NULL )  /* Base Case 1 : if key not found */
		return NULL;
	else if( search_node(skey, p, pn ) )	/* Base Case 2 : if key found in node p  */ 
		return p;
	else         /*Recursive case : Search in node p->child[*pn] */
		return Search( skey, p->child[*pn], pn); 
}/*End of Search()*/

int search_node(int skey, struct node *p, int *pn)
{
	if( skey < p->key[1] )
	{
		*pn = 0;
		return 0;
	}
	*pn = p->count;
	while( ( skey < p->key[*pn] ) && *pn>1 )
		(*pn)--;
	if( skey == p->key[*pn] )
		return 1;
	else
		return 0;
}/*End of search_node()*/

struct node *Insert(int ikey, struct node *proot)
{
	int k, taller;
	struct node *krchild, *temp;
	
	taller = rec_ins(ikey, proot, &k, &krchild);
	
	if( taller )  /* tree grown in height, new root is created*/
	{
		temp = (struct node *)malloc( sizeof(struct node) );
		temp->count = 1;
		temp->child[0] = proot;	
		temp->key[1] = k;
		temp->child[1] = krchild;
		proot = temp;
	}
	return proot;
}/*End of Insert()*/

int rec_ins(int ikey, struct node *p, int *pk, struct node **pkrchild)
{
	int n;
	int flag;

	if( p == NULL )  /* Base case 1 */ 
	{
		*pk = ikey;
		*pkrchild = NULL;
		return 1;   
	}
	
	if( search_node( ikey, p, &n) ) /* Base Case 2 */
	{
		printf("Duplicate keys are not allowed\n");
		return 0;
	}

	flag = rec_ins( ikey, p->child[n], pk, pkrchild );
	if( flag )
	{
		if( p->count < MAX )
		{
			insertByShift(*pk, *pkrchild, p, n);
			return 0;
		}
		else
		{
			split(*pk, *pkrchild, p, n, pk, pkrchild );
			return 1;  /*median key to be inserted*/
		}
	}
	return 0;
}/*End of rec_ins()*/

void insertByShift( int k, struct node *krchild, struct node *p, int n)
{
	int i;
	
	for( i = p->count; i > n; i-- )
	{
		p->key[i+1] = p->key[i];
		p->child[i+1] = p->child[i];
	}
	p->key[n+1] = k;
	p->child[n+1] = krchild;
	p->count++;
}/*End of insertByShift()*/

void split(int k, struct node *krchild, struct node *p, int n, int *upkey, struct node **newnode)
{
	int i,j;
	int lastkey;
	struct node *lastchild;
	int d = CEIL_Mdiv2;

	if( n == MAX )
	{
		lastkey = k;
		lastchild = krchild;
	}
	else
	{
		lastkey = p->key[MAX];
		lastchild = p->child[MAX];
		for( i = p->count-1; i > n; i-- )
		{
			p->key[i+1] = p->key[i];
			p->child[i+1] = p->child[i];
		}
		p->key[i+1] = k;
		p->child[i+1] = krchild;
	}
	*newnode = (struct node *)malloc(sizeof(struct node) );
	*upkey = p->key[d];
	
	for( i=1, j=d+1; j<=MAX; i++,j++ )
	{
		(*newnode)->key[i] = p->key[j];
		(*newnode)->child[i] = p->child[j];
	}
	
	(*newnode)->child[0] = p->child[d];
	p->count = d-1;/*Number of keys in the left splitted node*/
	(*newnode)->count = M - d;  /*Number of keys in the right splitted node*/
	(*newnode)->key[M-d] = lastkey;
	(*newnode)->child[M-d] = lastchild;
}/*End of split()*/

struct node *Delete(int dkey, struct node *root)
{
	struct node *temp;
	rec_del( dkey, root);
	
	if( root!=NULL && root->count == 0 )/*If tree becomes shorter, root is changed*/
	{
		temp = root;
		root = root->child[0];
		free(temp);
	}
	return root;
}/*End of Delete()*/

void rec_del(int dkey, struct node *p)
{
	int n, flag, succkey;
	if( p == NULL )/*reached leaf node ,key does not exist*/
		printf("Value %d not found\n", dkey);
	else
	{
		flag = search_node(dkey, p, &n);
		if( flag )/*found in current node p */
		{
				if( p->child[n]==NULL )/*node p is a leaf node */
					delByShift( p, n);
				else /*node p is a non leaf node */
				{	
					succkey = copy_succkey( p, n );
					rec_del(succkey, p->child[n]);
				}
		}
		else	/*not found in current node p */
				rec_del(dkey, p->child[n]);

		if( p->child[n] != NULL )/*if p is not a leaf node*/ 
		{
			if( p->child[n]->count < MIN ) /*check underflow in p->child[n]*/
				restore( p, n);
		}
	}
}/*End of rec_del()*/

void delByShift( struct node *p, int n)
{
	int i;
	for( i = n+1; i <= p->count; i++ )
	{
		p->key[i-1] = p->key[i];
		p->child[i-1] = p->child[i];
	}
	p->count--;
}/*End of delByShift()*/

int copy_succkey(struct node *p, int n)
{
	struct node *ptr;
	ptr = p->child[n]; /*point to the right subtree*/

	while( ptr->child[0]!=NULL )   /*move down till leaf node arrives*/
		ptr = ptr->child[0];

	p->key[n] = ptr->key[1];
	return ptr->key[1];
}/*End of copy_succkey()*/

void restore(struct node *p, int n)
{
	if( n!=0  &&  p->child[n-1]->count > MIN )      
		borrowLeft(p, n);
	else if( n!=p->count && p->child[n+1]->count > MIN )
		borrowRight(p, n);   
	else
	{	
		if(n==0)  /*if underflow node is leftmost node*/
			combine(p, n+1);	/*combine with right sibling*/
		else 
			combine(p, n);		/*combine with left sibling*/
	}
}/*End of restore()*/

void borrowLeft(struct node *p, int n)
{
	int i;
	struct node *u;		/* underflow node*/
	struct node *ls;	/* left sibling of node u */

	u = p->child[n];
	ls = p->child[n-1];

	/*Shift all the keys and pointers in underflow node u one position right*/
	for(i = u->count; i>0; i--)
	{
		u->key[i+1] = u->key[i];
		u->child[i+1] = u->child[i];
	}
	u->child[1] = u->child[0];

	/* Move the separator key from parent node p to underflow node u */
	u->key[1] = p->key[n];
	u->count++;

	/* Move the rightmost key of node ls to the parent node p */
	p->key[n] = ls->key[ls->count];

	/*Rightmost child of ls becomes leftmost child of node u */
	u->child[0] = ls->child[ls->count];
	
	ls->count--;
}/*End of borrowLeft()*/

void borrowRight(struct node *p,int n)
{
	int i;
	struct node *u;		/* underflow node */
	struct node *rs;	/* right sibling of node u */

	u = p->child[n];
	rs = p->child[n+1];

	/* Move the separator key from the parent node p to the underflow node u */
	u->count++;
	u->key[u->count] = p->key[n+1];

	/* Leftmost child of node rs becomes the rightmost child of node u */
	u->child[u->count] = rs->child[0];

	/*Move the leftmost key from node rs to parent node p */
	p->key[n+1] = rs->key[1];
	rs->count--;
	
	/*Shift all the keys and pointers of node rs one position left*/
	rs->child[0] = rs->child[1];
	for(i=1; i<=rs->count; i++)
	{
		rs->key[i] = rs->key[i+1];
		rs->child[i] = rs->child[i+1];
	}
}/*End of borrowRight()*/

void combine(struct node *p, int m)
{
	int i;    
	struct node *x;        
	struct node *y;	

	x = p->child[m];
	y = p->child[m-1];
	/* Move the key from the parent node p to node y */
	y->count++;
	y->key[y->count] = p->key[m];
	/*Shift the keys and pointers in p one position left to fill the gap */
	for(i=m; i<p->count; i++)   
	{
		p->key[i] = p->key[i+1];
		p->child[i] = p->child[i+1];
	}
	p->count--;

	/*Leftmost child of x becomes rightmost child of y */
	y->child[y->count] = x->child[0];
	/*Insert all the keys and pointers of node x at the end of node y */
	for( i = 1; i<=x->count; i++)
	{
		y->count++;
		y->key[y->count] = x->key[i];
		y->child[y->count] = x->child[i];
	}
	free(x);
}/*End of combine()*/

void display(struct node *ptr, int blanks)
{
	if(ptr)
	{
		int i;
		for(i=1; i<=blanks; i++)
			printf(" ");
		for(i=1; i<=ptr->count; i++)
			printf("%d ",ptr->key[i]);
		printf("\n");
		for(i=0; i<=ptr->count; i++)
			display(ptr->child[i], blanks+10);
	}
}/*End of display()*/

void inorder(struct node *ptr)
{
	int i;
	if(ptr!=NULL )
	{
		for(i=0; i<ptr->count; i++)
		{
			inorder(ptr->child[i]);
			printf("%d\t",ptr->key[i+1] );
		}
		inorder(ptr->child[i]);
	}
}/*End of inorder()*/
