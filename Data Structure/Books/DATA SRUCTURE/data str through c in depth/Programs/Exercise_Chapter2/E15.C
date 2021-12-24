/*E15*/
#include<stdio.h>
void func(int a[] );
main( )
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	func(arr+3);
}
void func(int a[])
{
	int i;
	for(i=0; a[i]!=8; i++)
            printf("%d ", a[i]);
}
       