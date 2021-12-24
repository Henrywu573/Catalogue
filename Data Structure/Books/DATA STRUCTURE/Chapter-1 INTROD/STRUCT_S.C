/* Pointer and structures */

/* STRUCT_S.C */

# include<string.h>
# include<stdio.h>
# include<malloc.h>

struct Record
{
	char *name;
	char *address;
	long Pin_code;
};

/* PROTOTYPE */

void sort(struct Record * , int );

void sort(struct Record *str, int n)
{
	int i,j, flag;
	struct Record temp;
	for(i =0; i <n-1; i++)
	{
		flag = 1;
	   	for (j=0; j <(n-i-1); j++)
		{
			if (strcmp (str[j].name, str[j+1].name)>0)
			{
				flag = 0;
				temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
		if (flag)
			break;
	}
}

/* Function main */

void main()
{
	char choice;
	int i, n = 0;
	struct Record string[10];
	printf("Input The List\n ");
	printf("\n**************\n");

	do
	{
		string[n].name = (char *) malloc(50);
		string[n].address= (char *) malloc(100);

		printf("Name: ");
		gets(string[n].name);
		printf("\n Address: ");

		gets(string[n].address);
		printf("Postal index number: ");
		scanf("%ld", &string[n].Pin_code);
		n++;
		fflush(stdin);
		printf("\n Input another y/n? ");
		choice = getchar();
		fflush(stdin);
	}while(choice == 'y');
	printf("Unsorted list \n");
	printf("\n********************\n");
	for (i =0; i < n ; i++)
	{
		printf("\n %s", string[i].name);
		printf("\n %s", string[i].address);
		printf("\n %ld", string[i].Pin_code);
		printf("\n********************\n");
	}
	getchar();
	sort(string, n);
	printf("\n Sorted list");
	printf("\n********************\n");
	for (i =0; i < n ; i++)
	{
		printf("\n %s", string[i].name);
		printf("\n %s", string[i].address);
		printf("\n %ld", string[i].Pin_code);
		printf("\n********************\n");
	}
	getchar();
}

