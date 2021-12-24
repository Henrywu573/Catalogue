/* D9.C */

# include<stdio.h>

# define r 2
 void main()
 {
	int m[r][r][r][r][r][r][r][r][r];
	int a, b, c, d, e, f, g, h, i;

/* Input section */

      for (a = 0; a < r; a++)
	for (b = 0; b < r; b++)
	   for (c = 0; c < r; c++)

      for (d = 0; d < r; d++)
	for (e = 0; e < r; e++)
	   for (f = 0; f < r; f++)
      for (g = 0; g < r; g++)
	for (h = 0; h < r; h++)
	   for (i = 0; i < r; i++)

	   m[a][b][c][d][e][f][g][h][i] = a+b+c+d+e+f+g+h+i;

/* Output section row major order */

      printf("\n ADDRESS	ARRAY M WITH INDEX  VALUE \n");
      for (a = 0; a < r; a++)
	for (b = 0; b < r; b++)
	   for (c = 0; c < r; c++)
      for (d = 0; d < r; d++)
	for (e = 0; e < r; e++)
	   for (f = 0; f < r; f++)
      for (g = 0; g < r; g++)
	for (h = 0; h < r; h++)
	   for (i = 0; i < r; i++)
	   {
	    printf("\n 0x%x", &m[a][b][c][d][e][f][g][h][i]);

	    printf(" m[%d][%d][%d][%d][%d][%d][%d][%d][%d] = %d",a, b, c, d, e, f,
				   g, h, i, m[a][b][c][d][e][f][g][h][i]);
	   }

/* Column major order */

      printf("\n ADDRESS	ARRAY M WITH INDEX  VALUE \n");
      \
      for (i = 0; i < r; i++)
	for (h = 0; h < r; h++)
	   for (g = 0; g < r; g++)
      for (f = 0; f < r; f++)
	for (e = 0; e < r; e++)
	   for (d = 0; d < r; d++)
      for (c = 0; c < r; c++)
	for (b = 0; b < r; b++)
	   for (a = 0; a < r; a++)
	   {
	    printf("\n 0x%x", &m[a][b][c][d][e][f][g][h][i]);

	    printf("  m[%d][%d][%d][%d][%d][%d][%d][%d][%d] = %d",a, b, c, d, e, f,
			    g, h, i, m[a][b][c][d][e][f][g][h][i]);
	   }
      }

