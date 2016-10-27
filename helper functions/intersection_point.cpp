/*** LINE INTERSECTION ***/
//** return NONE if they are parallel*/
//** return LINE if they are in the same line*/
//** otherwise return the intersection point*/

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

line line_between(point p1,point p2);
bool parallel_line(line l1,line l2);
bool same_line(line l1,line l2);
point intersection_point(line l1,line l2);


int main()
{
	int test;
	point p1,p2;
	line l1,l2;
	
	printf("INTERSECTING LINES OUTPUT\n");
	scanf("%d",&test);
	while(test--)
	{
		scanf("%lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y);
		l1 = line_between(p1,p2);
		scanf("%lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y);
		l2 = line_between(p1,p2);


		if(same_line(l1,l2))
			printf("LINE\n");
		else if( parallel_line(l1,l2))
			printf("NONE\n");
		else
		{
			p1 = intersection_point(l1,l2);
			printf("POINT %.2lf %.2lf\n",p1.x,p1.y);
		}

	}

	printf("END OF OUTPUT\n");
	return 0;

}

line line_between(point p1,point p2)
{
	line l;
	if(fabs(p1.x-p2.x)<ERR)
	{
		l.a=1;
		l.b=0;
		l.c=-p1.x;
	}
	else
	{
		l.b=1;
		l.a=-(p1.y-p2.y)/(p1.x-p2.x);
		l.c=-(l.a*p1.x)-(l.b*p1.y);
	}
	return l;
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
	if(same_line(l1,l2)||parallel_line(l1,l2))
	{
		p.x=p.y=0.0;
		return p;
	}
	p.x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
	if(fabs(l1.b)<ERR)
		p.y=-(l2.a*p.x+l2.c)/l2.b;
	else
		p.y=-(l1.a*p.x+l1.c)/l1.b;
	return p;
}

