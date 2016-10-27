#include<stdio.h>

void main()
{
	long a,b,I,z;

	while(scanf("%ld %ld",&a,&b)==2)
	{
		I= a/b;

		printf("[%ld;",I);

		a=a-b*I;

		while(a!=1)
		{
			z=a;
			a=b;
			b=z;
			I=a/b;
			printf("%ld,",I);

			a=a-b*I;
		}

		printf("%ld]\n",b);

	}
}

/* 
#include<stdio.h>

void main()
{
	long long int a,b,I,z;

	while(scanf("%lld %lld",&a,&b)==2)
	{
		I= a/b;

		printf("[%lld;",I);

		a=a-b*I;

		while(a!=1)
		{
			z=a;
			a=b;
			b=z;
			I=a/b;
			printf("%lld,",I);

			a=a-b*I;
		}

		printf("%lld]\n",b);

	}
}

  */