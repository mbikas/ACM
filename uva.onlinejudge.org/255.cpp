#include <stdio.h>

int main ()
{
	int k, q, qm,r, rm, rk, first, last ;
	
	while ( scanf ( "%d %d %d", &k, &q, &qm ) == 3 )
	{
		if ( k == q ) printf ( "Illegal state\n" ) ;

		else
		{
			r = q % 8 ;
			rm = qm % 8 ;
			rk = k % 8 ;
			first = q - r ;
			last = first + 7 ;

			if ( qm == q || k == qm || ( r != rm && ( ( qm < first || qm > last)
			|| ( ( qm < k && k < q ) || ( qm > k && k > q ) ) ) || ( ( rm == r
			&& r == rk ) && ( ( qm < k && k < q ) || ( qm > k && k > q ) ) ) ) )
			
				printf ( "Illegal move\n" ) ;

			else
			{
				if ( ( qm == k + 1 && rk != 7 ) || ( qm == k - 1 && rk != 0 )
				|| ( qm == k - 8 ) || ( qm == k + 8 ) )

					printf ( "Move not allowed\n" ) ;

				else
				{
					if ( ( k == 0 && qm == 9 ) || ( k == 7 && qm == 14 )
					|| ( k == 56 && qm == 49 ) || ( k == 63 && qm == 54 ) )

						printf ( "Stop\n" ) ;

					else printf ( "Continue\n" ) ;
				}
			}
		}
	}
	return 0;
}