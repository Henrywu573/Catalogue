/*P2.32 Program to understand how an array of structures is sent to a function */
#include<stdio.h>
struct student {
		char name[20];
		int rollno;
		int marks;
	       };
void display(struct student);
void dec_marks(struct student stuarr[ ]);
main( )
{
	int i;
	struct student stuarr[3] = {
					{"Mary", 12, 98}, 
					{"John", 11, 97}, 
					{"Tom", 12, 89}
				    };
	dec_marks(stuarr);
	for(i=0; i<3; i++ )
		display(stuarr[i]);
}
void dec_marks(struct student stuarr[])
{
	int i;
	for(i=0; i<3; i++)
		stuarr[i].marks = stuarr[i].marks-10;
}
void display(struct student stu)
{
	printf("Name  - %s\t", stu.name);
	printf("Rollno  - %d\t", stu.rollno);
	printf("Marks  - %d\n", stu.marks);
}
