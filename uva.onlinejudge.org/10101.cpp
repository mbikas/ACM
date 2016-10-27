#include<stdio.h>
#define kuti 10000000
#define lakh 100000
#define hajar 1000
#define shata 100

void get_number(long long n)
{
	long long rem;

	while(n>0)
	{
		if(n>=10000000)
		{
			rem = (long long)n/kuti;
			if(rem>0)
				get_number(rem);
			printf(" kuti");	
			n = (long long)n%kuti;
		}
		else if(n>=100000)
		{
			rem = (long long)n/lakh;
			if(rem>0)
				printf(" %lld lakh",rem);	
			n = (long long)n%lakh;
		}
		else if(n>=1000)
		{
			rem = (long long)n/hajar;
			if(rem>0)
				printf(" %lld hajar",rem);	
			n = (long long)n%hajar;
		}
		else if(n>=100)
		{
			rem = (long long)n/shata;
			if(rem>0)
				printf(" %lld shata",rem);	
			n = (long long)n%shata;
		}
		else if(n>0)
		{
			printf(" %lld",n);	
			n = 0;
		}
		//printf(" ");
	
	}
}

void main()
{
	//freopen("10101.in","r",stdin);
	//freopen("10101.out","w",stdout);

	long long n;
	long cases=1;

	while(scanf("%lld",&n)==1)
	{
		if(n==0)
		{
			printf("%4ld. 0\n",cases++);
			continue;
		}

		printf("%4ld.",cases++);	
		get_number(n);
		printf("\n");
	
	}



}