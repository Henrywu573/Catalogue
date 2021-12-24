/*P2.18  When an array is passed to a function, the receiving argument is declared as a pointer */
#include<stdio.h>
func(float f[ ] , int *i, char c[5]);
main( )
{
	float f_arr[5] ={1.4, 2.5, 3.7, 4.1, 5.9 };
	int i_arr[5] = { 1, 2, 3, 4, 5};
	char c_arr[5] = {'a', 'b', 'c', 'd', 'e'};
	printf("Inside main( )  :   ");
	printf("Size of f_arr = %u\t", sizeof(f_arr));
	printf("Size of i_arr = %u\t", sizeof(i_arr));
	printf("Size of c_arr = %u\n", sizeof(c_arr));
	func(f_arr, i_arr, c_arr);
}     
func(float f[ ], int *i, char c[5])
{
	printf("Inside func( )  : ");
	printf("Size of f = %u\t", sizeof(f)); 
	printf("Size of i = %u\t", sizeof(i));
	printf("Size of c = %u\n", sizeof(c));
}                                                
