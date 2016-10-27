#include<stdio.h>
#include<math.h>

void main()
{

	long long n,p,diagonal,cases=1;

	while(scanf("%lld",&diagonal)==1 && diagonal)
	{


		// n*n - 4*n +3 - 2*diagonal =0;

		p =  ( (2*diagonal - 3) * 4) + 16;
		
		p = ceil(sqrt(p));
		p = p+4;

		n = p/2;

		printf("Case %lld: %lld\n",cases++,n);
	
	
	
	}


}