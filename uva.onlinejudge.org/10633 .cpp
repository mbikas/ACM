#include<stdio.h>
void main()
{
	unsigned long long n_m, m, n, mod;
	

	while(scanf("%llu",&n_m)==1 && n_m!=0)
	{
		
		mod = n_m % 9;

		m = ( n_m - mod)/9;

		n = 10*m + mod;

		if(mod==0)	printf("%llu ",n-1);

		printf("%llu\n",n);
	}
}