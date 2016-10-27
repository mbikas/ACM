/*
program: Graham Scan Convex Hull
Md.Abu Naser Bikas
Cse, Sust
*/

#define EPSILON 1e-10
#define SIZE 100


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int hull_end=0;

struct point
{
	double x, y;
};

point reference;

bool equals(point p1, point p2)
{
	return(fabs(p1.x - p2.x) <= EPSILON && fabs(p1.y - p2.y) <= EPSILON);
}


//Swap 'p1' and 'p2'.
void swap(point *p1, point *p2)
{
	point temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//Return the distance between the points 'p1' and 'p2'.
double point_to_point_distance(point p1,point p2)
{
	if (equals(p1, p2)) return(0.0);
	return(sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}

//Check whether point 'p2' is clockwise or counter-clockwise from 'p1' with //respect to 'p0'.
//Return positive if 'p2' is counter-clockwise from 'p1'.
//Return negative if 'p2' is clockwise from 'p1' with respect to 'p0'.
//Return 0 if 'p2' and 'p1' are collinear with respect to 'p0'.
double direction(point p0,point p1,point p2)
{
	return((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
}

int sort_point_on_angle(point t1,point t2)
{

	double d = direction(reference, t1, t2);	
	if (fabs(d) <= EPSILON)
	{
		if (point_to_point_distance(reference, t1) < point_to_point_distance(reference, t2))
			return(-1);
		else return(1);
	}	
	if (d < 0.0) return(1);
	else return(-1);
}

void graham_convex_hull(point *p, int n, int *hull, int& hull_end)
{
	int i,j, min;
	for(i = 1, min = 0; i < n; i++)
	{
		if (fabs(p[i].y - p[min].y) <= EPSILON)
		{
			if (p[i].x < p[min].x) min = i;
		}
		else
		{
			if (p[i].y < p[min].y) min = i;
		}
	}

	swap(&p[0], &p[min]);
	reference = p[0];

	for(i=2;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(sort_point_on_angle(p[j],p[j+1])==1)
			{
				//swap(&p[j],&p[j+1]);
				point temp = p[j];
				p[j] = p[j+1];
				p[j+1]=temp;
			}
		}
	}
	

	for(i=0;i<n;i++)
		printf("%lf %lf\n",p[i].x,p[i].y);

	hull_end = 0;
	hull[hull_end++] = 0;
	hull[hull_end++] = 1;

	for(i = 2; i < n; hull[hull_end++] = i++)
	{
		while(hull_end >= 2 && direction(p[hull[hull_end-2]], p[hull[hull_end-1]], p[i]) <= EPSILON)
			hull_end--;

	}

	printf("hull_end = %d\n",hull_end);

	for(i=0;i<hull_end;i++)
	{
		printf("%lf %lf\n",p[hull[i]].x,p[hull[i]].y);
	}
}

int main()
{
	int i,n,hulls[100];

	point points[100];

	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%lf %lf",&points[i].x,&points[i].y);

	graham_convex_hull(points, n, hulls,hull_end);

	for(i=0;i<hull_end;i++)
		printf("%d ",hulls[i]);
	printf("\n");




	return 0;


}