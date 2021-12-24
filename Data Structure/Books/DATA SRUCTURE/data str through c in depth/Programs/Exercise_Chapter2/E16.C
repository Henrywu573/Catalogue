/*E16*/
#include<stdio.h>
main( )
{
	struct  A {
			int marks;
			char grade;
	};
	struct  A  A1, B1;
	A1.marks = 80;
	A1.grade = 'A';
	printf("Marks = %d\t", A1.marks);
	printf("Grade = %c\t", A1.grade);
	B1 = A1;
	printf("Marks = %d\t", B1.marks);
	printf("Grade = %c\n", B1.grade);
}
