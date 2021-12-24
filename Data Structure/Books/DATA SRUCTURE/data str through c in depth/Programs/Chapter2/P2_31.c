/*P2.31 Program to understand how a pointer to structure is returned from a function */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student {
		char name[20];
		int rollno;
		int marks;
	       };
void display(struct student *);
struct student *func( );
struct student *ptr;
main( )
{
	struct student *stuptr;
	stuptr = func( );
	display(stuptr);
	free(stuptr);
}
struct student *func( )
{
	ptr = (struct student *) malloc(sizeof(struct student) );
	strcpy( ptr->name, "Joseph");
	ptr->rollno = 15;
	ptr->marks = 98;
	return ptr;
}
void display( struct student *stuptr)
{
	printf("Name  - %s\t", stuptr->name);
	printf("Rollno  - %d\t", stuptr->rollno);
	printf("Marks  - %d\n", stuptr->marks);
}
