#include<stdio.h>
#include<math.h>

void main()
{
	long L,f;
	double v,volume;

	while(scanf("%ld %ld",&L,&f)==2 && (L!=0 || f!=0))
	{
		v=  (double)sqrt(L*f*2.0);
		volume=(double) (v*3600)/(2*L);
		printf("%.8lf %.8lf\n",v,volume);
	}
}