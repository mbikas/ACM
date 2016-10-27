#include<stdio.h>

long zero(long number,long factor)
{
	long total,deno;

	if(number==5)return 1;
	total=0;
	deno = factor;

	while(deno<=number)
	{
		total += number/deno;
		deno*=factor;
	
	}
	return total;
}

int main()
{
	long test,N,c2,c1;

	scanf("%ld",&test);
	while(test--)
	{
		scanf("%ld",&N);
		c1 = zero(N,2);
		c2 = zero(N,5);
		if(c1<c2)printf("%ld\n",c1);
		else printf("%ld\n",c2);
	
	}

	return 0;
}