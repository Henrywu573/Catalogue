/* HOW THE DIR FUNCTION  OF DOS WORK SEE IT THROUGH LINKED LIST */
/* LINK_DIR.C */

# include<stdio.h>
# include <dirent.h>
# include <malloc.h>
# include <string.h>
# include <stdlib.h>

struct File_List
{
	char filename[64];
	struct File_List *next;
} start, *node;

void main(int argc, char *argv[])
{
	DIR *directory_pointer;
	struct dirent *entry;

	if ((directory_pointer = opendir(argv[1])) == NULL)
	{
		perror("Error opening :");
		printf("%s", argv[1]);
	}
	else
	{
		start.next = NULL;
		node = &start;

		while (entry = readdir(directory_pointer))
		{
			node->next = (struct File_List *) malloc(sizeof(struct File_List));
			if (node == NULL)
			{
				printf("Insufficient memory to store list\n");
				exit(1);
			}
			node = node->next;

			strcpy(node->filename,(char *) entry); /* char * convert dirent to char * constant */

			node->next = NULL;
		}

		closedir(directory_pointer);

		node = start.next;

		while (node)
		{
			printf("\n %s", node->filename);
			node = node->next;
		}
	}
}
