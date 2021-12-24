/* sortlist.c */

#include <stdio.h>
#include <dirent.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	DIR *directory_pointer;
	struct dirent *entry;

	struct FileList {
		char filename[64];
		struct FileList *next;
	} start, *node, *previous, *new;


	if ((directory_pointer = opendir(argv[1])) == NULL)
		printf("Error opening %s\n", argv[1]);
	else
	{
		start.next = NULL;

		while (entry = readdir(directory_pointer))
		{
			/* Find the correct location */
			    previous = &start;
			node = start.next;
			while ((node) && (strcmp(entry->d_name, node->filename) > 0))
			{
				node = node->next;
				previous = previous->next;
			}

			new = (struct FileList *) malloc(sizeof(struct FileList));
			if (new == NULL)
			{
				printf("Insufficient memory to store list\n");
				exit(1);
			}
			new->next = node;
			previous->next = new;
			strcpy(new->filename, entry->d_name);
		}

		closedir(directory_pointer);


		node = start.next;

		while (node)
		{
			printf("%s\n", node->filename);
			node = node->next;
		}

	}
}


