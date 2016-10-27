#include <stdio.h>
#include <math.h>

void main()
{
	double radius,s,x,y,z;


	while(scanf ("%lf %lf %lf",&x,&y,&z)==3)
	{
		s=(x+y+z)/2;

		if(s<=0.0000001)
		  radius=0;

		else
		 {
		  radius=(s-x)*(s-y)*(s-z)/s;
		  if(radius<0.0000001)
			{ radius=radius*-1;
			  radius=(sqrt)(radius);
           radius=radius*-1;
			}
		  else
			radius=sqrt(radius);

		 }


		printf ("The radius of the round table is: %.3lf\n",radius);
	}

}



