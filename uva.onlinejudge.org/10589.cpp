#include<stdio.h>
#include<math.h>
#define ERROR 0.000000001
int check_in_area(double x0, double y0, int a)
{
	double x,y,p,q;
	
	//lower_left center
	x = 0;
	y = 0;

	p = (x-x0)*(x-x0) + (y-y0)*(y-y0); 
	q = a * a;

	if(p>q)
		return 0;

	//lower_right center
	x = a;
	y = 0;

	p = (x-x0)*(x-x0) + (y-y0)*(y-y0);
	q = a * a;

	if(p>q)
		return 0;

	//upper_left center
	x = 0;
	y = a;

	p = (x-x0)*(x-x0) + (y-y0)*(y-y0); 
	q = a * a;

	if(p>q)
		return 0;

	//upper_right center
	x = a;
	y = a;

	p = (x-x0)*(x-x0) + (y-y0)*(y-y0); 
	q = a * a;

	if(p>q)
		return 0;

	return 1;
}

void main()
{
	long n, M, i,a;
	int check;
	double area, x0, y0;

	while(scanf("%ld %ld",&n, &a)==2 && n!=0)
	{
		M = 0;

		for(i=0;i<n;i++)
		{
			scanf("%lf %lf",&x0,&y0);

			check = check_in_area(x0, y0, a);

			if(check==1)
				M++;
		}
		
		area = M * a * a / (1.00*n);

		printf("%.5lf\n",area);
	}
}
