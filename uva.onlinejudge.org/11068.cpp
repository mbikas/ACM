#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define ERR .00000000001

typedef struct{
	double x,y;
}point;

typedef struct{
	double a,b,c;
}line;


bool parallel_line(line l1,line l2);
bool same_line(line l1,line l2);
point intersection_point(line l1,line l2);

void main()
{
	line l1,l2;
	point p;


	while(scanf("%lf %lf %lf %lf %lf %lf",&l1.a,&l1.b,&l1.c,&l2.a,&l2.b,&l2.c)==6)
	{
		if(l1.a==0&&l1.b==0&&l1.c==0&&l2.a==0&&l2.b==0&&l2.c==0)
			break;

		if ( fabs (l1.a*l2.b - l2.a*l1.b) < ERR )
			printf("No fixed point exists.\n");

		else
		{
			p= intersection_point(l1,l2);

			printf("The fixed point is at %.2lf %.2lf.\n",-p.x,-p.y);
		}
	}

}


bool parallel_line(line l1,line l2)
{
	return((fabs(l1.a-l2.a)<ERR)&&(fabs(l1.b-l2.b)<ERR));
}

bool same_line(line l1,line l2)
{
	return(parallel_line(l1,l2)&&(fabs(l1.c-l2.c)<ERR));
}

point intersection_point(line l1,line l2)
{
	point p;

	p.x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
	if(fabs(l1.b)<ERR)
		p.y=-(l2.a*p.x+l2.c)/l2.b;
	else
		p.y=-(l1.a*p.x+l1.c)/l1.b;
	return p;
}


