#include<stdio.h>
#include<math.h>

double get_distance(double x1,double x2,double y1,double y2)
{
	return (sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}

void main()
{
	double dis_gopher, dis_dog, gop_x, gop_y, dog_x, dog_y, x, y;
	long n, i, f;

	while(scanf("%ld %lf %lf %lf %lf",&n, &gop_x, &gop_y, &dog_x, &dog_y)==5)
	{
		f = 1;

		for(i=0;i<n;i++)
		{
			scanf("%lf %lf",&x,&y);

			if(f==1)
			{
				dis_gopher = get_distance(x,gop_x,y,gop_y);
				dis_dog = get_distance(x,dog_x,y,dog_y);
				
				if(dis_dog>=(2*dis_gopher) && f==1 )
				{
					printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",x,y);
					f = 0;
				}
			}
		}

		if(f==1)	printf("The gopher cannot escape.\n");
	}
}

