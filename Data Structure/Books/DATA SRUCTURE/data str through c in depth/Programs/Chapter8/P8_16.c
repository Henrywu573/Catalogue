/*P8.16 Program of sorting by address using bubble sort algorithm*/
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
	struct record arr[MAX], *ptr[MAX], *temp;
	int i,j,n, xchanges;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter record  %d : \n",i+1);
		printf("Enter name : ");
		scanf("%s",arr[i].name);
		printf("Enter age : ");
		scanf("%d", &arr[i].age);
		printf("Enter salary : ");
		scanf("%d", &arr[i].salary);
		printf("\n");
		ptr[i] = &arr[i];	
	}
	
	for(i=0; i<n-1; i++)
	{
		xchanges = 0;
		for(j=0; j<n-1-i ; j++)
		{
			if(ptr[j]->age > ptr[j+1]->age)
			{		
				temp = ptr[j];
				ptr[j] = ptr[j+1];
				ptr[j+1] = temp ;
				xchanges++;
			}
		}
		if(xchanges==0)
			break;
	}

	printf("List of Records Sorted on age \n");
	for(i=0; i<n; i++)
	{
		printf("%s\t\t", ptr[i]->name);
		printf("%d\t\t", ptr[i]->age);
		printf("%d\n", ptr[i]->salary);
	}
	printf("\n");
}/*End of main()*/






