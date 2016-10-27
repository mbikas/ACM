#include<stdio.h>

void main()
{
		long long int s,d,total,i;


		while(scanf("%lld %lld",&s,&d)==2)
		{
			i=s+1;
			total=s;

			while(total<d)
			{
				total = total + i;
				i = i + 1 ;
			}

			printf("%lld\n",i-1);

		}


}