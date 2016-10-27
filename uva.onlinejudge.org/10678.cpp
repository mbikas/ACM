#include<stdio.h>
#include<math.h>

#define PI 2*acos(0.0)

void main()
{

	long test;
	double a,b,area,L,D;

	scanf("%ld",&test);

	while(test--)
	{
		scanf("%lf %lf",&D,&L);

		a = L/2; //(the rope+two pillars form a line)
        b = sqrt((L/2)*(L/2) - (D/2)*(D/2)); // (the rope+two pillars form a triangle)

		area = PI*a*b;

		printf("%.3lf\n",area);	
	
	}
}