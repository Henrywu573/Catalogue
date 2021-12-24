/*E5*/

#include<stdio.h>
void func1(int,int);
void func2(int,int);

main( )
{
	func1(10,18); 
	printf("\n");
	func2(10,18);
}/*End of main()*/

void func1(int a,int b)
{
	if(a>b)
		return;
    printf("%d  ",b);
	func1(a,b-1);
}

void func2(int a,int b)
{
	if(a>b)
		return;
    func2(a,b-1);
	printf("%d  ",b);
}
