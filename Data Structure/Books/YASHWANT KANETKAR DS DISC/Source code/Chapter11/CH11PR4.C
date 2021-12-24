/* CH11PR4.C: Program to find the shortes path. */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define INF 9999

int main( )
{
	int arr[4][4] ;
	int cost[4][4] = {
						7, 5, 0, 0,
						7, 0, 0, 2,
						0, 3, 0, 0,
						4, 0, 1, 0
					} ;
	int i, j, k, n = 4 ;

	system ( "cls" ) ;

	for ( i = 0 ; i < n ; i++ )
	{
		for ( j = 0; j < n ; j++ )
		{
			if ( cost[i][j] == 0 )
				arr[i][j] = INF ;
			else
				arr[i][j] = cost[i][j] ;
		}
	}

	printf ( "Adjacency matrix of cost of edges:\n" ) ;
	for ( i = 0 ; i < n ; i++ )
	{
		for ( j = 0; j < n ; j++ )
			printf ( "%d\t", arr[i][j] ) ;
		printf ( "\n" ) ;
	}

	for ( k = 0 ; k < n ; k++ )
	{
		for ( i = 0 ; i < n ; i++ )
		{
			for ( j = 0 ; j < n ; j++ )
			{
				if ( arr[i][j] > arr[i][k] + arr[k][j] )
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	printf ( "\n" ) ;
	printf ( "Adjacency matrix of lowest cost between the vertices:\n" ) ;
	for ( i = 0 ; i < n ; i++ )
	{
		for ( j = 0; j < n ; j++ )
			printf ( "%d\t", arr[i][j] ) ;
		printf ( "\n" ) ;
	}

	return 0 ;
}
