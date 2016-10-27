#include<stdio.h>
#define mod 2000000011

int main()
{
	long cases,n,i,j;

	long long sum;

	scanf("%ld",&cases);

	
	for(j=1;j<=cases;j++)
	{
		scanf("%ld",&n);

		sum=1;

		for(i=0;i<n-2;i++)
		{
			sum = (sum*n)%mod;		
		}

		printf("Case #%ld: %lld\n",j,sum);
	
	}
	
	return 0; 

}