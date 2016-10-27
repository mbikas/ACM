#include<stdio.h>
#include<math.h>

#define angle  1.0673956817111818692592637626711

void main()
{
	double F,S;

	while(scanf("%lf",&F)==1)
	{

		//angle1 = 108
		//angle2 = 63
		//S = sin(angle1)/sin(angle2)*F

		S = angle *F;

		printf("%.10lf\n",S);
	
	}
}