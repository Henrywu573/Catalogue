/* LINK.C */
/* This program segment defines linked list having a character type node */

# include <stdio.h>
# include <malloc.h>

struct link_list
{
	int info;
	struct link_list *next;
};
typedef struct link_list node;

     void main()
     {
	      node *start,*ptr, node1, node2 , node3 , node4;
	      int i ;
	      clrscr();
	      start = &node1;
	      node1.info = 'A' ;
	      node1.next = &node2;

	      node2.info = 'B' ;
	      node2.next = &node3;

	      node3.info = 'C' ;
	      node3.next = &node4;
	      node4.info = 'D' ;
	      node4.next = NULL;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%c", ptr->info);
		ptr = ptr->next ;
		printf("\nPress a key");
		getch();
	 }
     }

