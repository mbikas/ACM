#include<stdio.h>
#include<math.h>

#define PI 2*acos(0.0)

void main()
{
	long n,cases=1;
	double area_r,area_R;
	double spectators,officials,area;

	while(scanf("%ld %lf",&n,&area)==2 && n>=3)
	{
		
		area_r = (PI) * (area/(n*tan((PI)/n))); 
		area_R = (PI) * 2*area/(n*sin(2*(PI)/n));

		spectators = area_R - area; 
		officials = area - area_r; 

		printf("Case %ld: %.5lf %.5lf\n",cases++,spectators,officials);
	}




}