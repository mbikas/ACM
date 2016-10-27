			/* PROBLEM # 138  STREET NUMBERS */

#include<stdio.h>
#include<math.h>
//#include<conio.h>
#include<time.h>

void main ()
{
	int i ;
	double X, odd, even, Home, Last ;

	for ( i = 3; i <= 8120; i += 2 )
	{
     	X = i * i ;

          odd = sqrt ( (X + 1) / 2 ) ;
     	even = sqrt ( (X-1) / 2 ) ;

          if ( ceil ( even ) == floor ( even ) )
          {
          	Last = X - 1 ;
          	Home = sqrt ( Last * (Last + 1) / 2 ) ;

          	printf ( "%10.0lf%10.0lf\n", Home, Last ) ;
          }

          if ( ceil ( odd ) == floor ( odd ) )
          {
          	Last = X ;
          	Home = sqrt ( Last * (Last + 1) / 2 ) ;

          	printf ( "%10.0lf%10.0lf\n", Home, Last ) ;
          }
     }
     //getch();
}
