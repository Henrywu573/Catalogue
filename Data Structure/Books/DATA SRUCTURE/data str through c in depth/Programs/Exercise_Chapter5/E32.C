/*E32*/

#include<stdio.h>
int log2(int num);
int logN(int num, int base);

main()
{
	int num, base;

	printf("Enter a number :");
	scanf("%d",&num);
	printf("%d\n",log2(num));

	printf("Enter a number and a base :");
	scanf("%d%d",&num,&base);
	printf("%d\n",logN(num,base)) ;
}
int log2(int num) 
{ 
      if(num==1) 
           return 0;
      return 1 + log2(num/2);
}

int logN(int num,int base) 
{ 
      if(num<base) 
           return 0;
     return 1 + logN(num/base,base);
}

