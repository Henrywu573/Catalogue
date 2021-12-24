/* LINK_N.C */
/* This program segment define linked list having string type node */

# include<stdio.h>
# include<malloc.h>

struct list
{
	char data[30];
	struct list *next ;
};

typedef  struct list linked;

void main()
{
	linked *start, node1, node2 , node3 , node4;
	int i ;

	start = (struct list *) malloc(sizeof(linked));
	start = &node1;

	gets(node1.data);

	node1.next = &node2;

	gets(node2.data) ;
	node2.next = &node3;

	gets(node3.data) ;
	node3.next = &node4;
	gets(node4.data);

	node4.next = '\0' ;
	printf("\n Output is\n");	
	do
	{
		printf("\n %s",start->data);
		printf("\n Press a key");
		getchar() ;
		start = start->next ;
	} while(start->next!='\0');
}

