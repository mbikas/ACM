#include<stdio.h>
#include<math.h>

#define PI 2*acos(0.0)

void main()
{

	long test,r1,r2,t;
	char ch;
	double ans;


	scanf("%ld",&test);

	while(test--)
	{
		scanf("%d",&t);
		scanf("%c",&ch);

		if(ch!='\n')
		{
			r1 = t;
			scanf("%ld",&r2);
			ans = (double) 2*PI*r1*r2;
		}
		else
		{
			ans = (double) (PI*t*t)/8;
		}

		printf("%.4lf\n",ans);




	}

}