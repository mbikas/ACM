#include<stdio.h>
#include<math.h>
#define pi (2*acos(0))

double get_distance(double x1,double y1,double x2,double y2)
{
	  return (sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}

void main()
{
	double x1,y1,x2,y2,CMD,ENF,AB,BASE,AM,AN;

	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&CMD,&ENF)==6)
	{
	
		AB = get_distance(x1,y1,x2,y2);

		//printf("AB = %lf\n",AB);

		CMD = (CMD*pi)/180;
		ENF = (ENF*pi)/180;


		AM = AB/tan(CMD);
		AN = AB/tan(ENF);

		BASE = AM + AN;

		printf("%.3lf\n",BASE);
	
	}

}