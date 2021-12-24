/*P8.14 Program of sorting records using bubble sort algorithm*/
#include <stdio.h>
#define MAX 100

struct record 
{
	char name[20];
	int age;
	int salary;
};

main()
{
	struct record arr[MAX], temp;
	int i,j,n, xchanges;
	
	printf("Enter the number of records : ");
	scanf("%d",&n);
	
	for( i=0; i<n; i++ )
	{
		printf("Enter record  %d : \n",i+1);
		printf("Enter name : ");
		scanf("%s",arr[i].name);
		printf("Enter age : ");
		scanf("%d", &arr[i].age);
		printf("Enter salary : ");
		scanf("%d", &arr[i].salary);
		printf("\n");
	}
	
	for( i=0; i<n-1; i++ )
	{
		xchanges = 0;
		for( j=0; j<n-1-i; j++)
		{
			if( arr[j].age >  arr[j+1].age )
			{		
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp ;
				xchanges++;
			}
		}
		if( xchanges == 0 )
			break;
	}

	printf("List of Records Sorted on age \n");
	for( i=0; i<n; i++ )
	{
		printf("%s\t\t", arr[i].name);
		printf("%d\t", arr[i].age);
		printf("%d\n", arr[i].salary);
	}
	printf("\n");
}/*End of main()*/






