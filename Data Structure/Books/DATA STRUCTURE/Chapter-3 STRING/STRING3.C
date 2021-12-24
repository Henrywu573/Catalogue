
/**   STRING3.C  **/

# include<stdio.h>

int i, choice;
char ch;

void display (int, char day[7][20]);
void update_fun (int, char day[7][20]);
void draw_back ( int, char day[7][20]);

/* Output function */

void display (int n, char weak_days[7][20])
{
	printf("\n **************************");
	printf("\n RECORD No.	INFORMATION");
	printf("\n **************************");
	for(i = 0 ; i < n ; i++)
	{
		printf("\n  %d		%s", i, weak_days[i]);
	}
	printf("\n **************************");
	printf("\nPress a key");
	getchar();
}

/* Update function */

void update_fun(int n, char weak_days[7][20])
{
	printf("\nInput the record number to which want to update: ");
	scanf("%d", &choice);

	printf("\nYou want to update it : %s", weak_days[choice]);
	printf("\n Input the new value : ");
	scanf("%s", weak_days[choice]);
}

/* Draw back function */
void draw_back(int n, char weak_days[7][20])
{
	printf("\n Draw back section Update");
	printf("\n ************************");
	printf("\nInput the record number to which want to update: ");
	scanf("%d", &choice);
	fflush(stdin);
	printf("\n You want to update it : %s", weak_days[choice]);
	printf("\nInput the new value : ");
	gets(weak_days[choice]);
	ch = getchar();
	i = 0 ;
	while(ch != '\n')
	{
		weak_days[choice][i++] = ch ;
		ch = getchar();
	}
}

/* Function main */

void main()
{
	char weak_days[7][20]= {
						"MONDAY",
						"TUESDAY",
						"WEDNESDAY",
						"THURSDAY",
						"FRIDAY",
						"SATURDAY",
						"SUNDAY"
							};

	int n = 7;
	printf("\n Information List ");
	display(n, weak_days);
	update_fun(n, weak_days);
	printf("\n List after update operation\n");
	display(n, weak_days);

	draw_back (n, weak_days);
	printf("\n List after Draw back operation\n");
	display(n, weak_days);
}
