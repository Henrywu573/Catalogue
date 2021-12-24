
/**    STRING2.C  **/

# include<stdio.h>

void main()
{
	char s[128][128];
	int i, j;
	char ch;
	int n,m;
	j = 0;
	i = 0;
	printf("Enter size of information in line: ");
	scanf("%d", &n);
	fflush(stdin);
	while(n)
	{
		ch = getchar();
		s[i][j] = ch ;
		j++;
		if(ch == '\n')
		{
			s[i][j]='\0';
			printf("\n");
			j = 0;
			i++;
			n--;
		}
	}
	s[i][j]='\0';
	m = i;
	printf("\nm -->%d ", m);

	/**             Display section                 **/
	printf("\n");
	for( i = 0 ; i < m ; i++)
	{
		printf("\n %s\n ", s[i]);
	}
}
