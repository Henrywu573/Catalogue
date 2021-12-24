/*Demo Program of sorting using address calculation sort*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct  node
{
	int info ;
	struct node *link;
};

struct node *head[5];
int n,arr[MAX];
int large;

void addr_sort();
void insert(int num,int addr);
int hash_fn(int number);

main()
{

	int i;
	printf("Enter the number of elements in the list : ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}/*End of for */

	printf("Unsorted list is :\n");
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");

	for(i=0;i<n;i++)
	{
		if(arr[i] > large)
			large = arr[i];
	}
	
	addr_sort();

	printf("Sorted list is :\n");
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
}/*End of main()*/

void addr_sort()
{
	int i,k;
	struct node *p;
	int addr;
	
	for(i=0;i<=5;i++)
		head[i]=NULL;

	for(i=0;i<n;i++)
	{
		addr=hash_fn( arr[i] );
		insert(arr[i],addr);
	}

	for(i=0; i<=5 ; i++)
	{
		printf("head(%d) -> ",i);
		p=head[i];
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->link;
		}
		printf("\n");
	}

	/*Taking the elements of linked lists in array*/
	i=0;
	for(k=0;k<=5;k++)
	{
		p=head[k];
		while(p!=NULL)
		{
			arr[i++]=p->info;
			p=p->link;
		}
	}
}/*End of addr_sort()*/

/*Inserts the number in sorted linked list*/
void insert(int num,int addr)
{
	struct node *q,*tmp;
	tmp= malloc(sizeof(struct node));
	tmp->info=num;
	/*list empty or item to be added in begining */
	if(head[addr] == NULL || num < head[addr]->info)
	{
		tmp->link=head[addr];
		head[addr]=tmp;
		return;
	}
	else
	{
		q=head[addr];
		while(q->link != NULL && q->link->info <= num)
			q=q->link;
		tmp->link=q->link;
		q->link=tmp;
	}
}/*End of insert()*/

int hash_fn(int number)
{
	int addr;
	float tmp;
	tmp=(float)number/large;
	addr=tmp*5;
	return(addr);
}/*End of hash_fn()*/





