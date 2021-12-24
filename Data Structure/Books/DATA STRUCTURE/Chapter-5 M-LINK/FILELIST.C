/* filelist.c */

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
	} *start, *ptr;


	if ((directory_pointer = opendir(argv[1])) == NULL)
		printf("Error opening %s\n", argv[1]);
	else
	{
		start = NULL;
		entry = readdir(directory_pointer);
		ptr = start= (struct FileList *) malloc(sizeof(struct FileList));
		while (entry == readdir(directory_pointer))
		{
			strcpy(ptr->filename, entry->d_name);
			ptr->next = (struct FileList *) malloc(sizeof(struct FileList));
			if (ptr == NULL)
			{
				printf("Insufficient memory to store list\n");
				exit(1);
			}
			ptr = ptr->next;
		}

		closedir(directory_pointer);
		ptr->next = NULL;

		ptr = start;

		while (ptr->next != NULL)
		{
			printf("%s\n", ptr->filename);
			ptr = ptr->next;
		}

	}
}


