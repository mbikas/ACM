#include<stdio.h>
#include<math.h>

#define ERR 0.0000000001

void main()
{
	double ha,hb,hc,A,B,C,x,temp;
	long invalid;

	scanf("%ld",&invalid);

	while(invalid)
	{
		scanf("%lf%lf%lf",&ha,&hb,&hc);

		if((ha-0.0)<ERR||(hb-0.0)<ERR||(hc-0.0)<ERR)
		{
			printf("These are invalid inputs!\n");
			invalid--;
		}
		else
		{
			A=1/ha;
			B=1/hb;
			C=1/hc;
			temp=(A+B+C)*(-A+B+C)*(A-B+C)*(A+B-C);

			if((temp-0.0)<ERR)
			{
				printf("These are invalid inputs!\n");
				invalid--;
			}
			else
			{
				x=sqrt(1/temp);
				printf("%.3lf\n",x);
			}
		}
	}
}