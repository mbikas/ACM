#include<stdio.h>
#include<math.h>

long long fib(long long n,long long mod)
{
	long long i,j,h,k,t;

	i = h = 1;
	j = k = 0;

	while(n>0)
	{
		if(n%2==1){
			t = (j*h) % mod;
			j = (i*h + j*k + t)%mod;
			i = (i*k + t)%mod;
		}

		t = (h*h)%mod;
		h = (2*k*h + t)%mod;
		k = (k*k + t)%mod;
		n = (long long)(n/2);		
	}

	return j;	
}

void main()
{

	long long n,m,p,mod;
	while(scanf("%lld %lld",&n,&m)==2)
	{
		mod = (long long ) pow(2,m);
		p = fib(n,mod);

		printf("%lld\n",p);
		
	}


}