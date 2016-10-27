//acm 10719 Quotient Ploynomial
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char coeff[150000];

int main()
{
	long k,n,x[10010],count,rem;

	while(scanf("%ld",&k)==1)
	{
		n=0;
		scanf(" %[^\n]",coeff);
		char *p=strtok(coeff," ");
		while(p)
		{
			x[n++]=atol(p);
			p=strtok(0," ");
		}

		printf("q(x): %ld",x[0]);
		rem=x[1]-(x[0]*(-k));
		for(count=1;count<n-1;count++)
		{
			printf(" %ld",rem);
			rem=x[count+1]-(rem*(-k));
		}
		printf("\nr = %ld\n\n",rem);
	}
	return 0;
}
