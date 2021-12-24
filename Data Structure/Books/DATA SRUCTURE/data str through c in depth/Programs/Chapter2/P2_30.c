/*P2.30 Program to understand how a structure variable is returned from a function */
#include<stdio.h>
struct student {
		char name[20];
		int rollno;
		int marks;
	       };
void display(struct student);
struct student change(struct student stu);
main( )
{
	struct student stu1 = {"John", 12 , 87 };
	struct student stu2 = {"Mary", 18, 90};
	stu1 = change(stu1);
	stu2 = change(stu2);
	display(stu1);
	display(stu2);
}
struct student change(struct student stu)
{
	stu.marks = stu.marks + 5;
	stu.rollno = stu.rollno - 10;
	return stu;
}

void display(struct student stu)
{
	printf("Name   - %s\t", stu.name);
	printf("Rollno - %d\t", stu.rollno);
	printf("Marks  - %d\n", stu.marks);
}
