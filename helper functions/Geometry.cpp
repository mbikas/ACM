/*** SOME GEOMETRIC FUNCTIONS ON LINE AND POINTS ***/

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

line point_to_line(point p1,point p2);
line line_through(point p,double m);
bool parallel_line(line l1,line l2);
bool same_line(line l1,line l2);
point intersection_point(line l1,line l2);
point closest_point(point p,line l);
double signed_triangle_area(point a,point b,point c);
double triangle_area(point a,point b,point c);
double signed_perp_distance(line l,point p);
double perp_distance(line l,point p);

void main()
{
	long test;
	line l,l1,l2,l3,l4;
	point p1,p2;
	scanf("%ld",&test);

	
	

	while(test--)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y,&x1,&y1,&x2,&y2);
		l = point_to_line(p1,p2);
		printf("%lf %lf %lf\n",l1.a,l1.b,l1.c);

		//lop line
		p1.x = x1;
		p1.y = y1;
		p2.x = x2;
		p2.y = y1;
		l1 = point_to_line(p1,p2);

		//left line
		p1.x = x1;
		p1.y = y1;
		p2.x = x1;
		p2.y = y2;
		l2 = point_to_line(p1,p2);

		//right line
		p1.x = x2;
		p1.y = y2;
		p2.x = x2;
		p2.y = y1;
		l3 = point_to_line(p1,p2);

		//bottom line
		p1.x = x2;
		p1.y = y2;
		p2.x = x1;
		p2.y = y2;
		l4 = point_to_line(p1,p2);

		


	
	
	}
}

//covert two point to a line equation ax+by+c
line point_to_line(point p1,point p2)
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

line line_through(point p,double m)
{
	line l;
	l.a=-m;
	l.b=1;
	l.c=-((l.a*p.x)+(l.b*p.y));
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

	//identical line ; all points intersect
	if(same_line(l1,l2))
	{
		p.x=p.y=0.0;
		return p;
	}

	//parallel line
	if(parallel_line(l1,l2))
	{
		printf("PARALLEL LINE\n");
		return;
	}
	p.x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
	if(fabs(l1.b)<ERR)
		p.y=-(l2.a*p.x+l2.c)/l2.b;
	else
		p.y=-(l1.a*p.x+l1.c)/l1.b;
	return p;
}

point closest_point(point p,line l)
{
	line perp;
	point pout;
	if(fabs(l.b)<ERR)
	{
		pout.x=-(l.c);
		pout.y=p.y;
		return(pout);
	}
	if(fabs(l.a)<ERR)
	{
		pout.x=p.x;
		pout.y=-(l.c);
		return(pout);
	}
	perp=line_through(p,1.0/l.a);
	pout=intersection_point(l,perp);
	return(pout);
}

double signed_triangle_area(point a,point b,point c)
{
	return((a.x*b.y-a.y*b.x+a.y*c.x-a.x*c.y+b.x*c.y-c.x*b.y)/2.0);
}

double triangle_area(point a,point b,point c)
{
	return(fabs(signed_triangle_area(a,b,c)));
}

double signed_perp_distance(line l,point p)
{
	return((l.a*p.x+l.b*p.y+l.c)/sqrt(l.a*l.a+l.b*l.b));
}

double perp_distance(line l,point p)
{
	return(fabs(signed_perp_distance(l,p)));
}