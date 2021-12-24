/* Demo Program of sorting using insertion sort */
#include<stdio.h>
#define MAX 100
#define STOP getchar()

main()
{
	int arr[MAX],i,j,k,n,l;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for( i=0; i<n; i++ )
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}
	printf("Unsorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	/*Insertion sort*/
	for(i=1;i<n;i++)
	{
		STOP;
		printf(".....................................................................\n\n");
		printf("PASS %d - \n\n", i);
			
		k=arr[i]; /*k is to be inserted at proper place*/
		printf("Place %d in { ",k);
		for(l=0;l<i;l++)
			printf("%d  ",arr[l]);
		printf("}\n");
		
		for( j=i-1; j>=0 && k<arr[j]; j--)
		{
	
			printf("Shift %d : \n",arr[j]);
			arr[j+1]=arr[j];
			for (l = 0; l < n; l++)
			{
				if(l==j && l!=i)
					printf("_ ");
				if(l!=j)
					printf("%d ", arr[l]);
			}

			printf("\n");
			getch( );
		}
	
		arr[j+1]=k;
	
			
		if(i==j+1)
			printf("No need of shifting, %d is at proper place.\n", k);
		else
			printf("Place %d at proper place: \n",k);
		for (l = 0; l < n; l++)
			printf("%d ", arr[l]);
		printf("\n");

		printf("After pass %d elements are : \n",i);
		for (l = 0; l < n; l++)
		{
			if(l==i+1)
				printf(" .... ");
			printf("%d ", arr[l]);
		}
		printf("\n");
	}/*End of insertion sort*/

	printf("..................................................................");
	printf("\n\nSorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

}/*End of main()*/



