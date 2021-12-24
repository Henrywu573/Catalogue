/* Defintion of structure */
/* STRUCT.C */

# include<stdio.h>

/* Structure declaration for address */

struct Addr
{
	char Street[30];
	char City [30];
	char State[20];
	long int Pin_Code;
};

/* Nested structure declaration */

struct Customer
{
	char Name[20];
	char Account_No [10];
	char Profession[30];
	struct Addr Address;
};

/* Function main */

void main()
{
	struct Customer *List[100];
	int i, n;

	printf("\n Input number of record you want to process: ");
	scanf("%d", &n);
	fflush(stdin);

	printf("\n Input the information of customer\n");
	for(i=0; i< n; i++)
	{
		printf("\n Name: ");
		gets(List[i]->Name);
		printf("\n Account Number:");
		gets(List[i]->Account_No);
		printf("\n Profession:");
		gets(List[i]->Profession);
		printf("\n*** Address***");
		printf("\n**************\n");
		printf("\n Street:");
		gets(List[i]->Address.Street);
		printf("\n City:");
		gets(List[i]->Address.City);
		printf("\n State:");
		gets(List[i]->Address.State);
		printf("\n Pin Code:");
		scanf("%ld", &List[i]->Address.Pin_Code);
		fflush(stdin);
	}

	printf("\n List of the customer");
	printf("\n ********************\n");
	for(i= 0; i< n; i++)
	{
		printf("\n Name: %s", List[i]->Name);
		printf("\n Account Number: %s", List[i]->Account_No);
		printf("\n Professiion: %s", List[i]->Profession);
		printf("\n *** Address ***\n");
		printf("\n ***************\n");
		printf("\n Street: %s", List[i]->Address.Street);
		printf("\n City: %s", List[i]->Address.City);
		printf("\n State: %s", List[i]->Address.State);
		printf("\n Pin code: %ld", List[i]->Address.Pin_Code);
	}
}
