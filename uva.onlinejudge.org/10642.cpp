#include<stdio.h>

void main()
{
	long long p,q;
	long cases=1,x,y,test;

	scanf("%ld",&test);

	while(test--)
	{

		scanf("%ld %ld",&x,&y);

		p = (1+(y+x))*(y+x)/2 + x;


		scanf("%ld %ld",&x,&y);

		q = (1+(y+x))*(y+x)/2 + x;

		if(p>q)
			printf("Case %ld: %lld\n",cases++,(p-q));
		else
			printf("Case %ld: %lld\n",cases++,(q-p));



	}


}