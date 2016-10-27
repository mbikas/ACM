#include<stdio.h>
#include<math.h>

#define ERR 0.0000001 

void main()
{
	double area,ma,mb,mc;
	while(scanf("%lf %lf %lf",&ma,&mb,&mc)==3)
	{

		p = (ma+mb+mc)*(mb+mc-ma)*(ma+mc-mb)*(ma+mb-mc);
		
		if(p<=0)
			area = 0;
		else
			area = sqrt(p)/3.0;

		if(fabs(area-0)<ERR)
			printf("-1.000\n");
		else
			printf("%.3lf\n",area);
	
	
	}


}