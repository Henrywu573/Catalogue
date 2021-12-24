/*P5.11 Program to solve Tower of  Hanoi problem using recursion*/

#include<stdio.h>
void tofh(int ndisk, char source, char temp, char dest);

main( )
{
	char  source = 'A', temp = 'B', dest = 'C';
	int ndisk;
	printf("Enter the number of disks : ");
	scanf("%d", &ndisk );
	printf("Sequence is :\n");
	tofh(ndisk, source, temp, dest);
}/*End of main()*/

void tofh(int ndisk, char source, char temp, char dest)
{
	if(ndisk==1)
	{
		printf("Move Disk %d from %c-->%c\n", ndisk, source, dest);
		return;
	}
	tofh(ndisk-1, source, dest, temp);
	printf("Move Disk %d from %c-->%c\n", ndisk, source, dest);
	tofh(ndisk-1, temp, source, dest);

}/*End of tofh( )*/

