/*Demo Program of sorting using radix sort*/

#include<stdio.h>
#include<stdlib.h>
#define STOP getchar()

struct  node
{
	int info ;
	struct node *link;
}*start=NULL;

main()
{
	struct node *tmp,*q;
	int i,n,item;

	printf("Enter the number of elements in the list : ");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&item);

		/* Inserting elements in the linked list */
		tmp= malloc(sizeof(struct node));
		tmp->info=item;
		tmp->link=NULL;

		if(start==NULL) /* Inserting first element */
			start=tmp;
		else
		{
			q=start;
			while(q->link!=NULL)
				q=q->link;
			q->link=tmp;
		}
	}/*End of for*/

	printf("Unsorted list is :\n");
	display();
	radix_sort();
	printf("\n");
	printf("Sorted list is :\n");
	display();
	
}/*End of main()*/

radix_sort()
{
	int i,k,dig,least_sig,most_sig;
	struct node *p, *rear[10], *front[10];

	least_sig=1;
	most_sig=large_dig(start);

	for(k=least_sig; k<=most_sig; k++)
	{
		printf("PASS %d :  \n",k);
		printf("Examining %dth digit from right-\n\n",k);

		for(i = 0 ; i <= 9 ; i++)
		{
			rear[i] = NULL;
			front[i] = NULL ;
		}
		p = start ;
		while( p != NULL)
		{
			/*Find kth digit in the number*/
			dig = digit(p->info, k);
		
			/*Add the number to queue of dig*/
			if(front[dig] == NULL)
				front[dig] = p ;
			else
				rear[dig]->link = p;
			rear[dig] = p ;
			p=p->link;/*Go to next number in the list*/
		}
		
		/*Add NULL to end of each queue to display it*/
		for(i=0; i<=9; i++)
		{
			if(rear[i]!=NULL)
				rear[i]->link=NULL;
		}

		for(i=0; i<=9; i++)
		{
			printf("%d  --  ",i);
			p = front[i];
			while(p!=NULL)
			{
				printf("%d  " ,p->info);
				p=p->link;
			}
			printf("\n");
		}
		
		/*Join all the queues to form the new linked list*/
		i=0;
		while(rear[i] == NULL)
			i++;
		start = front[i];	
		while(i<9) 
		{
			if(rear[i+1]!=NULL)
				rear[i]->link=front[i+1];
			else
				rear[i+1]=rear[i];
			i++;
		}
		rear[9]->link=NULL;
		printf("New list : ");
		display();
		printf("\n");
		STOP;
	}/*End for*/
}/*End of radix_sort*/

/* This function finds number of digits in the largest element of the list */
int large_dig()
{
	struct node *p=start ;
	int large = 0,ndig = 0 ;

	while(p != NULL)
	{
		if(p ->info > large)
			large = p->info;
		p = p->link ;
	}
	printf("\nLargest Element is %d , ",large);
	while(large != 0)
	{
		ndig++;
		large = large/10 ;
	}
	printf("Number of digits in it are %d\n\n",ndig);
	return(ndig);
} /*End of large_dig()*/

/*This function returns kth digit of a number*/
int digit(int number, int k)
{
	int digit, i ;
	for(i = 1 ; i <=k ; i++)
	{
		digit = number % 10 ;
		number = number /10 ;
	}
	return(digit);
}/*End of digit()*/

display()
{
	struct node *p=start;
	while( p !=NULL)
	{
		printf("%d ", p->info);
		p= p->link;
	}
	printf("\n");
}/*End of display()*/
