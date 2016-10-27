#include<stdio.h>


void main()
{
	long long test,a,b;


	scanf("%lld",&test);


	while(test--)
	{
		scanf("%lld %lld",&a,&b);
		p = a-b;

		if(p>0)
			printf(">\n");
		else if(p<0)
		printf("<\n");
		else if(p==0)
		printf("=\n");
		
		
	}


}