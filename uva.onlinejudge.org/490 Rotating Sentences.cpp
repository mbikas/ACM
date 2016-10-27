#include <stdio.h>
#include <string.h>

char in [105][105] ;
char out [105][105] ; 

void main ()
{
	int i, lines, len[105], k, maxlen = 0, r1, r2, c1, c2, Rmax ;

	//freopen ( "rotate.txt", "r", stdin ) ;
	//freopen ( "output.txt", "w", stdout ) ;
	
	for ( i = 0; scanf ( " %[^\n]", in[i] ) == 1; i++ ) 
	{
		len[i] = strlen ( in[i] ) ;

		if ( maxlen < len[i] )
			maxlen = len[i] ;
	}
	lines = i ;

	for ( i = 0; i < lines; i++ )

		if ( len[i] < maxlen )
		{
        	for ( k = len[i]; k < maxlen; k++ )
				in[i][k] = ' ' ;
			in[i][maxlen] = NULL ;
		}

	for ( Rmax = 0, r1 = 0, c2 = lines - 1; r1 < lines; r1++, c2-- )
	{
		for ( r2 = 0, c1 = 0; in[r1][c1] != NULL; r2++, c1++ )

			out[r2][c2] = in[r1][c1] ;
			
		if ( Rmax < r2 - 1 ) Rmax = r2 - 1 ;
	}

	for ( i = 0; i <= Rmax; i++ )
		
		printf( "%s\n", out[i] ) ;	
}