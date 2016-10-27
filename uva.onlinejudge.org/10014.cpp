#include<stdio.h>

void main()
{
	
	long n,p,i,test;
	double x,sum,ci,a0,an_1;

	scanf("%ld",&test);
	
	while(test--)
	{
			scanf("%ld",&n);
			scanf("%lf %lf",&a0,&an_1);

			sum=0;
			
			for(i=n;i>=1;i--)
			{
				scanf("%lf",&ci);
				sum = sum + (i*ci);
				p--;
			}

			sum = sum *2;

			x = (n*a0) + (an_1) -sum;
			x = x/(n+1);

			printf("%.2lf\n",x);

			if(test>0)
				printf("\n");

	}
}