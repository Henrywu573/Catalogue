/* SHORTEST PATH */
/* SPATH.C */

 # include<stdio.h>
 # define size 10
 # define infinity 9999

	 int a[size][size];
		int m[size][size];
		int i,k,j;
		int n;

	 void Input ();
		void Short ();
		void Output ();

 /* Input function */

 void Input()
     {
       printf("\n Input the number of vetices: ");
       scanf("%d", &n);
       printf("\n Input adjacency matrix\n");
       for (i = 0; i < n; i++)
	 {
	   for (j = 0; j < n; j++)
	    {
	      scanf("%d", &a[i][j]);
	    }
	   printf("\n");
	 }
	 printf("\n Adjacency matrix \n");
	for ( i = 0; i < n; i++)
	 {
	   for ( j = 0; j < n; j++)
	    {
	      printf("  %i", a[i][j]);
	    }
	   printf("\n");
	 }
     }

 /* Output function */

 void Output()
     {
       for ( i = 0; i < n; i++)
	 {
	   for ( j = 0; j < n; j++)
	    {
	      printf("   %d", m[i][j]);
	    }
	   printf("\n");
	 }
     }

 /* Shortest path function */

 void  Short ()
     {
     /* Initialization of matrix m */

       for ( i = 0; i < n; i++)
	 {
	   for ( j = 0; j < n; j++)
	    {
	      if (a[i][j] == 0)
	      m[i][j] = infinity;
	      else
	      m[i][j] = a[i][j];
	    }
	 }
	printf("\n Adjacency matrix after replacing zeros by very large value");
	Output();

/*  Shortest path evaluation start from here */

       for ( k = 0; k < n; k++)
	 {
       for ( i = 0; i < n; i++)
	 {
	   for ( j = 0; j < n; j++)
	    {
	      if ( m [i][j] <= m [i][k] + m [k][j] )
	      m [i][j] = m [i][j];
	      else
	      m [i][j] = m[i][k] + m [k][j];
	    }
	 }
	 printf("\n STEP %d \n", k);
	 Output();
       }
    }

/* Function main */

  void main()
       {
	 Input();
	 Short();
	 printf("\n Shortest path matrix is as follows\n");
	 Output();
       }
