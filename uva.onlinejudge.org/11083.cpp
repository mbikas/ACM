#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317};


long  prime_factor(long long num)
{
	long max,base,i;
	
	base=(long)sqrt(num);
	max=0;

	for(i=0;prime[i]<=base;i++)
	{
		if (num%prime[i]==0)
		{
			max=prime[i];
			while(num%prime[i]==0)
				num/=prime[i];
		}
	}
	
	if(num>1)  
		max = num;
	return max;
}

void main(){
	
	
	long long i,total,n,p;	
	long base,maxbase;
	
	while(scanf("%lld %ld",&n,&base)==2 && (n!=0 || base!=0) )
	{
		maxbase = prime_factor(base);

		total=0;
		for(i=maxbase; i<n ; i*=maxbase)
		{
			p = n/i;
			total +=  ( (n+1)*p ) - ( (p*(p+1)/2)*i ) ;
		}
		printf("%lld\n",total);
	}
}