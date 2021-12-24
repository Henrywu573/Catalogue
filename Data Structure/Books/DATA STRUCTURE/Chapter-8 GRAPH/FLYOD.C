/* FLYOD'S METHOD */
/* FLYOD.C */

  # include<stdio.h>

  # define Infinity 9999
  # define size 20

	 int i,k,j;
	 void Input(int , int a[size][size]);
		void Output(int , int a[size][size]);
		void Flyod(int , int a[size][size], int r[size][size]);

/* Input function */

  void Input(int n, int a[size][size])
     {
int i, j;
      printf("\n Input adjacency matrix\n");
       for (i = 0; i < n; i++)
	{
	  for (j = 0; j < n; j++)
	   {
	scanf("%d", &a[i][j]);
	   }
	 printf("\n");
       }
    }

/* Output function */

 void Output (int n, int a[size][size])
     {
int i, j;
      for (i =0; i < n; i++)
	{
	  for (j =0; j < n; j++)
	   {
	     printf(" %d", a[i][j]);
	   }
	 printf("\n");
       }
    }

/* Shortest path evaluation function */

  void Flyod(int n, int a[size][size], int r[size][size])
       {
	 for (i = 0; i < n; i ++)
	   a[i][i] = 0; 	/* Set diagonal elements zero */
	   printf("\n After setting diagonal elements to zero \n");
	   Output(n, a);
	   for (i = 0; i < n; i++)
	     {
	      for (j = 0; j < n; j++)
	       {
		if ((a[i][j] == 0) && (i != j))
		 r[i][j] = Infinity;
		 else
		  r[i][j] = a[i][j];
	       }
	    }
	    printf("\n Replacing zeros by very large value \n");
	    Output(n, r);
	  for (k = 0; k < n; k++)
	  {
	   for (i = 0; i < n; i++)
	     {
	      for (j = 0; j < n; j++)
	       {
		  if (r[i][k] + r[k][j]< r[i][j])
		     {
		      printf("\n r[%d][%d] = %d ", i, k, r[i][k]);
		      printf("\n r[%d][%d] = %d ", k, j, r[k][j]);
		      printf("\n r[%d][%d] = %d ", i, j, r[i][j]);
		      r[i][j] = r[i][k] +  r[k][j];
		      printf("\n r[%d][%d] = r[%d][%d] + r[%d][%d] = %d ", i, j, i, k, k, j, r[i][j]);
		     }
		     else
		     {
		       r[i][j] = r[i][j];
		      printf("\n r[%d][%d] = r[%d][%d] = %d ", i, j, i, j, r[i][j]);
		     }
	      }
	      printf("\n");
	    }
	    printf("\n Step %d \n", k);
	    Output (n,r);
	}
      }

/* Function main */

    void main()
       {
	 int a[size][size];
	 int r[size][size];
	 int n;
	 printf("\n Input number of vertices in the graph: ");
	 scanf("%d", &n);
	 Input(n,a);
	 printf("\n Adjacency matrix\n");
	Output(n,a);
	Flyod(n,a,r);
	printf("\n Shortest path matrix \n");
	 Output(n,r);
      }

