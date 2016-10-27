#include<stdio.h>

void main()
{
	long long n;

	while(scanf("%lld",&n)==1 && n>=0)
	{
		if(n==0)
		{	printf("0%%\n");
		    continue;
		}
	
		if(n==1)n=0;
		else n = n*25;

		printf("%lld%%\n",n);
	
		
	}
}