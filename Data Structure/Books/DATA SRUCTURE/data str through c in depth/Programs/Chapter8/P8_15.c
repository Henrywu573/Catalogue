/*P8.15 Program to sort the records on different keys using bubble sort*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct date
{
	int day;
	int month;
	int year;
};

struct employee
{
	char name[20];
	struct date dob;
	struct date doj;
	int salary;
};

void sort_name(struct employee emp[], int n);
void sort_dob(struct employee emp[], int n);
void sort_doj(struct employee emp[], int n);
void sort_salary(struct employee emp[], int n);
int datecmp(struct date date1, struct date date2 );

main( )
{
	struct employee emp[MAX];
	int i,n,choice;
	
	printf("Enter the number of employees : ");
	scanf("%d",&n);

	for( i=0; i<n; i++ )
	{
		printf("Enter name :");
		scanf("%s", emp[i].name);
		printf("Enter date of birth(dd/mm/yy): ");
		scanf("%d/%d", &emp[i].dob.day, &emp[i].dob.month);
		scanf("/%d", &emp[i].dob.year);
		printf("Enter date of joining(dd/mm/yy) : ");
		scanf("%d/%d", &emp[i].doj.day, &emp[i].doj.month);
		scanf("/%d", &emp[i].doj.year);
		printf("Enter salary : ");
		scanf("%d", &emp[i].salary);
		printf("\n");
	}
	while(1)
	{
		printf("1.Sort by name alphabetically\n");
		printf("2.Sort by date of birth, in descending order\n");
		printf("3.Sort by date of joining, in descending order\n");
		printf("4.Sort by salary in ascending order\n");
		printf("5.Exit\n");
		printf("Enter your choice :");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				sort_name(emp,n);
				break;
			case 2:
				sort_dob(emp,n);
				break;
			case 3:
				sort_doj(emp,n);
				break;
			case 4:
				sort_salary(emp,n);
				break;
			case 5:
				exit(1);
			default:
				printf("Wrong choice\n");
		}/*End of switch*/
	
		for( i=0; i<n; i++ )
		{
			printf("%s\t\t", emp[i].name);
			printf("%d/%d", emp[i].dob.day, emp[i].dob.month);
			printf("/%d\t\t", emp[i].dob.year);
			printf("%d/%d", emp[i].doj.day, emp[i].doj.month);
			printf("/%d\t\t", emp[i].doj.year);
			printf("%d\n", emp[i].salary);
		}
		printf("\n");
	}/*End of while*/
}/*End of main()*/

void sort_name(struct employee emp[], int n)
{
	struct employee temp;
	int i,j,xchanges;
	for( i=0; i<n-1; i++ )
	{
		xchanges=0;
		for( j=0; j<n-1-i; j++ )
		{
			if( strcmp(emp[j].name, emp[j+1].name) > 0 )
			{
				temp = emp[j];
				emp[j] = emp[j+1];
				emp[j+1] = temp;
				xchanges++;
			}
		}
		if( xchanges == 0)
			break;
	}
}/*End of sort_name()*/

void sort_dob(struct employee emp[], int n)
{
	struct employee temp;
	int i, j, xchanges;
	for( i=0; i<n-1; i++ )
	{
		xchanges = 0;
		for( j=0; j<n-1-i; j++ )
		{
			if( datecmp(emp[j].dob, emp[j+1].dob) > 0 )
			{
				temp = emp[j];
				emp[j] = emp[j+1];
				emp[j+1] = temp;
				xchanges++;
			}
		}
		if( xchanges == 0)
			break;
	}
}/*End of sort_dob()*/

void sort_doj(struct employee emp[], int n)
{
	struct employee temp;
	int i, j, xchanges;
	for( i=0; i<n-1; i++ )
	{
		xchanges = 0;
		for( j=0; j<n-1-i; j++ )
		{
  			if ( datecmp( emp[j].doj, emp[j+1].doj ) > 0 )
			{
				temp = emp[j];
				emp[j] = emp[j+1];
				emp[j+1] = temp;
				xchanges++;
			}
		}
		if( xchanges == 0)
			break;
	}
}/*End of sort_doj()*/

void sort_salary(struct employee emp[], int n)
{
	struct employee temp;
	int i, j, xchanges;
	for( i=0; i<n-1; i++ )
	{
		xchanges = 0;
		for( j=0; j<n-1-i; j++ )
		{
			if ( emp[j].salary > emp[j+1].salary  )
			{
				temp = emp[j];
				emp[j] = emp[j+1];
				emp[j+1] = temp;
				xchanges++;
			}
		}
		if( xchanges == 0 )
			break;
	}
}/*End of sort_salary()*/

/*Returns 1 if date1 < date2, returns -1 if date1 > date2, return 0 if equal*/
int datecmp(struct date date1, struct date date2 )
{
	if( date1.year < date2.year )
		return 1;
	if( date1.year > date2.year )
		return -1;
	if( date1.month < date2.month )
		return 1;
	if( date1.month > date2.month )
		return -1;
	if( date1.day < date2.day )
		return 1;
	if( date1.day > date2.day )
		return -1;
	return 0;
}/*End of datecmp()*/
