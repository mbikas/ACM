#include<stdio.h>
#include <stdlib.h>

long fib(long n)
{

	long i,j,k,h,t;

	i=h=1;
	j=k=0;

	while(n>0)
	{
		if(n%2==1)
		{
				t = j*h;
				j = i*h + j*k + t;
				i = i*k + t;
		}

		t = h*h;
		h = 2*k*h + t;
		k = k*k+t;
		n = long(n/2);

	}

	return j;
}

void main()
{
	long n,res;

	while(scanf("%ld",&n)==1)
	{
		res = fib(n);
		printf("%ld\n",res);
	
	}

}