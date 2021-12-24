/*P2.28 Program to understand how a structure variable is sent to a function */
#include<stdio.h>
struct student {
		char name[20];
		int rollno;
		int marks;
	       };
void display(struct student);
main( )
{
	struct student stu1 = {"John", 12 , 87 };
	struct student stu2 = {"Mary", 18, 90};
	display(stu1);
	display(stu2);
}
void display( struct student stu)
{
	printf("Name   - %s\t", stu.name);
	printf("Rollno - %d\t", stu.rollno);
	printf("Marks  - %d\n", stu.marks);
}
