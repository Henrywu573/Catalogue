/* removes.c */

#include <stdio.h>
#include <malloc.h>

void main(void)
{
	int i;

	struct ListEntry {
		int number;
		struct ListEntry *next;
	} start, *node, *previous;

	start.next = NULL;  /* Empty list */
	node = &start;      /* Point to the start of the list */

	for (i = 1; i <= 10; i++)
	{
		node->next = (struct ListEntry *) malloc(sizeof(struct ListEntry));
		node = node->next;
		node->number = 50+i;
		node->next = NULL;
	}

	/*  Remove the number 55 */
	node = start.next;
	printf("\n List before deletion\n");
	while (node)
	{
		printf("%d ", node->number);
		node = node->next;
	}

	node = start.next;
	previous = &start;
	while (node)
		if (node->number == 55)
		{
			previous->next = node->next;
			free(node);
			break;       /* End the loop */
		}
		else
		{
			node = node->next;
			previous = previous->next;
		}

	/* Display the list */
	node = start.next;
	printf("\n List after deletion \n");
	while (node)
	{
		printf("%d ", node->number);
		node = node->next;
	}
}


