#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ERR .00000000001

typedef struct{
	double x,y;
}point;

typedef struct{
	point start,end;
}segment;

bool segment_intersect(segment s1,segment s2);
double direction(point p1,point p2,point p3);
bool on_segment(point p1,point p2,point p3);
double min(double x,double y);
double max(double x,double y);

int main()
{
	//freopen("191.in","rt",stdin);
	//freopen("out.txt","wt",stdout);
	segment s1,s2;
	bool res,flag;
	double xleft,ytop,xright,ybottom;
	long tcas,j;
	scanf("%ld",&tcas);
	while(tcas--){
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&s1.start.x,&s1.start.y,&s1.end.x,&s1.end.y,&xleft,&ytop,&xright,&ybottom);
		s2.start.x=xleft;
		s2.start.y=ytop;
		s2.end.x=xright;
		s2.end.y=ybottom;
		res=segment_intersect(s1,s2);
		flag=false;
		if(res){
			printf("T\n");
			flag=true;
			continue;
		}
		s2.start.x=xleft;
		s2.start.y=ybottom;
		s2.end.x=xright;
		s2.end.y=ybottom;
		res=segment_intersect(s1,s2);
		flag=false;
		if(res){
			printf("T\n");
			flag=true;
			continue;
		}
		s2.start.x=xleft;
		s2.start.y=ytop;
		s2.end.x=xright;
		s2.end.y=ytop;
		res=segment_intersect(s1,s2);
		flag=false;
		if(res){
			printf("T\n");
			flag=true;
			continue;
		}
		s2.start.x=xright;
		s2.start.y=ytop;
		s2.end.x=xright;
		s2.end.y=ybottom;
		res=segment_intersect(s1,s2);
		flag=false;
		if(res){
			printf("T\n");
			flag=true;
			continue;
		}
		if(!flag){
			if((s1.start.x>=xleft && s1.start.y>=ytop)&&(s1.end.x<=xright && s1.end.y<=ybottom)){
				printf("T\n");
			}
			else{
				printf("F\n");
			}
		}
	}
	return 0;
}

bool segment_intersect(segment s1,segment s2)
{
	double d1,d2,d3,d4;
	d1=direction(s2.start,s2.end,s1.start);
	d2=direction(s2.start,s2.end,s1.end);
	d3=direction(s1.start,s1.end,s2.start);
	d4=direction(s1.start,s1.end,s2.end);
	if(d1*d2<0&&d3*d4<0)
		return true;
	else
	{
		if(fabs(d1)<ERR&&on_segment(s2.start,s2.end,s1.start))
			return true;
		else
		{
			if(fabs(d2)<ERR&&on_segment(s2.start,s2.end,s1.end))
				return true;
			else
			{
				if(fabs(d3)<ERR&&on_segment(s1.start,s1.end,s2.start))
					return true;
				else
				{
					if(fabs(d4)<ERR&&on_segment(s1.start,s1.end,s2.end))
						return true;
					else
						return false;
				}
			}
		}
		
	}
}

double direction(point p1,point p2,point p3)
{
	double x1,x2,y1,y2;
	x1=p3.x-p1.x;
	y1=p3.y-p1.y;
	x2=p2.x-p1.x;
	y2=p2.y-p1.y;
	return(x1*y2-x2*y1);
}

bool on_segment(point p1,point p2,point p3)
{
	if(min(p1.x,p2.x)<=p3.x&&max(p1.x,p2.x)>=p3.x)
	{
		if(min(p1.y,p2.y)<=p3.y&&max(p1.y,p2.y)>=p3.y)
			return true;
		else
			return false;
	}
	return false;
}

double min(double x,double y)
{
	return (x<y)?x:y;
}

double max(double x,double y)
{
	return (x>y)?x:y;
}