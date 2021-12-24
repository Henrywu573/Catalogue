/*P2.26 Program to understand pointers to structures*/
#include<stdio.h>
struct student {
		char name[20];
		int rollno;
		int marks;
	       };
main( )
{
	struct student stu = {"Mary", 25, 68};
	struct student *ptr = &stu;
	printf("Name  - %s\t", ptr->name);
	printf("Rollno  - %d\t", ptr->rollno);
	printf("Marks  - %d\n", ptr->marks);
}
