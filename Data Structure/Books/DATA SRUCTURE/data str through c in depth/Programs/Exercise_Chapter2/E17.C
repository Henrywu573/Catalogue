/*E17*/
#include<stdio.h>
void func(struct tag v);
main()
{ 
	struct tag{
		      int i;
	 	      char c;
	 	    };
	struct tag var = {2,'s'};
	func(var);
}
void func(struct tag v)
{
	printf("%d  %c\n",v.i,v.c);
}
