#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)

void main()
{
	double area_triangle, r, base, height, angle, sides, result;
	
	
	while(scanf("%lf %lf",&r,&sides)==2)
	{
		angle = 360/sides;	

		angle = (180-angle)/2.00;
		
		angle = (angle*pi)/180.00 ;    

		base = cos(angle)*r;
		
		height = sqrt( (r*r) - (base*base));
		 
		area_triangle = base*height;

		result = area_triangle*sides;

		printf("%.3lf\n",result);
	}
}


