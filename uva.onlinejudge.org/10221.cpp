#include<stdio.h>
#include<string.h>
#include<math.h>
#define pi acos(-1)
#define radius_earth 6440

double distance(double angle, long radius);

void main()
{
	long s,a;
	char ch[5];
	double angle,cord_dis,arc_dis;
	long radius;

	while(scanf(" %ld %ld %s",&s,&a,ch)==3)
	{
		radius = radius_earth + s;

		if(ch[0]=='m')
		{	// 60 minute = 1 degree
			angle = a/60.00;  	
		}
		else
			angle = a;
		
		
		
		if(angle>180)angle = 360 - angle;

		//1 deg = pi/180 radian
		//now angle are in radian
		angle = (angle*pi)/180; 


		//s = radius*angle
		arc_dis = radius*angle;	
		
		cord_dis = distance(angle,radius);
		printf("%.6lf %.6lf\n",arc_dis,cord_dis);
		
	}
}


double distance(double angle, long radius)
{
    double result;  

	angle = ( 180*angle )/( 2*pi);

	angle = 90 - angle;
	angle = angle*pi/180.00;	

	

	result = 2*radius*cos(angle);
	
	return result;
}