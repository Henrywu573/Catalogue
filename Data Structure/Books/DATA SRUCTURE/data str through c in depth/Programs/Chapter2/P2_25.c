/*P2.25 Program to understand arrays within structures*/
#include<stdio.h>
struct student{
		char name[20];
		int rollno;
		int submarks[4];
		};
main( )
{
	int i, j;
	struct student stuarr[3];
	for(i=0; i<3; i++)
	{
		printf("Enter data for student %d\n", i+1);
		printf("Enter name : ");
		scanf("%s", stuarr[i].name );
		printf("Enter roll number : ");
		scanf("%d", &stuarr[i].rollno);
		for(j=0; j<4; j++)
		{
			printf("Enter marks for subject %d : ", j+1);
			scanf("%d", &stuarr[i].submarks[j] );
		}
	}
	for(i=0; i<3; i++)
	{
		printf("Data of student %d\n", i+1);
		printf("Name : %s, Roll number : %d\nMarks : ", stuarr[i].name, stuarr[i].rollno);
		for(j=0; j<4; j++)
			printf("%d   ", stuarr[i].submarks[j] );
		printf("\n");
	}
}
