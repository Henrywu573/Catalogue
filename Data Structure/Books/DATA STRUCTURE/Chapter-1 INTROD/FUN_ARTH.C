/* FUN_ARTH.C */

# include<stdio.h>

int fun (int, int);

/* Function main  */

void main()
{
	int x , y ;
	int result ;
	x = 20 ;
	y = 30 ;
	result = fun (x, y) * x / y ;
	printf(" Value = %d",result);
}

/* Definition of the function fun () */

int fun(int a , int b )
{
	int result ;
	result =  a*b ;

	return (result) ;
}
