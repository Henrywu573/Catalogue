/* Sorting a directory contents with the help of linked list */
/* L_DIR_S.C */

# include <stdio.h>
# include <dirent.h>
# include <malloc.h>
# include <string.h>
# include <stdlib.h>

struct File_List
{
	char filename[64];
	struct File_List *next;
};

DIR *directory_pointer;
struct dirent *entry;

struct File_List  start, *node, *previous, *new1;

void dir_list(int k, char *l[])
{
	int number = 0;
	if ((directory_pointer = opendir(l[1])) == NULL)
	{
		perror("|ERROR\n");
		printf("\n OPENING FILE: %s", l[1]);
	}

	else
	{
		start.next = NULL;

		while (entry = readdir(directory_pointer))
		{
			/* Find the correct location */
			previous = &start;
			node = start.next;

			while ((node) && (strcmp((char *) entry, node->filename) > 0))
			{
				node = node->next;
				previous = previous->next;
			}

			new1 = (struct File_List *) malloc(sizeof(struct File_List));
			if (new1 == NULL)
			{
				printf("Insufficient memory to store list\n");
				exit(1);
			}
			new1->next = node;
			previous->next = new1;
			strcpy(new1->filename, (char *) entry);
			number++;
		}

		closedir(directory_pointer);

		node = start.next;

		while (node)
		{
			printf(" %s", node->filename);
			node = node->next;
			getchar();
		}
		printf(" Total Files listed: %d", number);
	}
}

/* Function main */

void main(int argc, char *argv[])
{
	dir_list(argc, argv);
}
