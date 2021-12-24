/* removes_d.c */
/* This program segment removes a node from a doubly linked list */

#include <stdio.h>
#include <malloc.h>

void main(void)
{
	int i, found;

	struct ListEntry {
		int number;
		struct ListEntry *next;
		struct ListEntry *previous;
	} start, *node;

	start.next = NULL;  
	/* Empty list */
	    start.previous = NULL;
	node = &start;      
	/* Point to the start of the list */

	    for (i = 1; i <= 10; i++)
	{
		node->next = (struct ListEntry *) malloc(sizeof(struct ListEntry));
		node->next->previous = node;
		node = node->next;
		node->number = 50 + i;
		node->next = NULL;
	}

	/* Display the list */

	printf("\n List before deletion \n");
	node = start.next;
	do {
		printf("%d ", node->number);
		node = node->next;
	} while (node);

	/* Remove the entry */

	node = start.next;
	found = 0;

	do {
		if (node->number == 57)
		{
			found = 1;
			node->previous->next = node->next;
			node->next->previous = node->previous;
			free(node);
		}
		else
			node = node->next;
	} while ((node) && (! found));

	/* Display the list */

	printf("\n List after deletion \n");
	node = start.next;

	do {
		printf("%d ", node->number);
		node = node->next;
	} while (node);
}


