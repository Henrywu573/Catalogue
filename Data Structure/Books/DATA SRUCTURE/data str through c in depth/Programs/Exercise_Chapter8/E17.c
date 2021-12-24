/*E17*/

#include <stdio.h>
#include<string.h>
#define MAX 100
#define LEN 50 

main()
{
	char arr[MAX][LEN], temp[LEN];
	int i,j,n,xchanges;
    
	printf("Enter the number of strings : ");
	scanf("%d",&n);

	for( i=0; i<n; i++ )
	{
		printf("Enter string %d : ",i+1);
		scanf("%s",arr[i]);
	}

	/*Bubble sort*/
	for( i=0; i<n-1 ;i++ )
	{
		xchanges=0;
		for( j=0; j<n-1-i; j++ )
		{
			if( strcmp(arr[j],arr[j+1]) > 0  )
			{
				strcpy(temp,arr[j]);
				strcpy(arr[j],arr[j+1]);
				strcpy(arr[j+1],temp);
				xchanges++;
			}
		}
		if(xchanges==0) /*If list is sorted*/
			break;
	}

	printf("Sorted list is :\n");
	for( i=0; i<n; i++)
		printf("%s ", arr[i]);
	printf("\n");
}/*End of main()*/


/*Sorting using array of pointers to strings*/
/*
#include <stdio.h>
#include<string.h>
#define MAX 100
#define LEN 50

main()
{
	char *arr[MAX], *temp, str[LEN];
	int i,j,n,xchanges;
    
	printf("Enter the number of strings : ");
	scanf("%d",&n);

	for( i=0; i<n; i++ )
	{
		printf("Enter string %d : ",i+1);
		scanf("%s",str);
		arr[i] = (char *)malloc( strlen(str)+1 );  
		strcpy(arr[i], str);
	}


	for( i=0; i<n-1 ;i++ )
	{
		xchanges=0;
		for( j=0; j<n-1-i; j++ )
		{
			if( strcmp(arr[j],arr[j+1]) > 0  )
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				xchanges++;
			}
		}
		if(xchanges==0)
			break;
	}

	printf("Sorted list is :\n");
	for( i=0; i<n; i++)
		printf("%s ", arr[i]);
	printf("\n");
}
*/