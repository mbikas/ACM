//11347 Multifactorials
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1e18
long long prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
long long factor[1005],freq[1005];

void get_prime_factor(long long n)
{

	long long root,i,count;
    int f=0;


	root = (long long) sqrt(n) + 1;


	for(i=0;prime[i]<=root;i++)
	{
		f=0;
		count=0;
		while(n%prime[i]==0)
		{
		
			n = n / prime[i];
			count++;
			f=1;
		}

		if(f==1)
		{
			//factor[total++]=prime[i];	
			freq[prime[i]]+=count;
		}
		if(n==1)
			break;
	}

	if(n!=1)
	{
		//factor[total++]=n;
		freq[n]+=1;
	}
}

int main()
{
	long long test,i,j,k,n,fac,len,p,t,cases=1;
	long long  dividors,temp2;
	bool flag;
	char input[1000],temp[25];

	scanf("%lld",&test);

	while(test--)
	{
		scanf(" %[^\n]",input);
		len = strlen(input);

		fac=0;
		p=0;
		for(i=0;i<len;i++)
		{
			if(input[i]>='0' && input[i]<='9')temp[p++]=input[i];
			else fac++;		
		}
		temp[p]='\0';
		sscanf(temp,"%lld",&n);

		//printf("%lld %lld\n",n,fac);
		dividors=1;
		for(i=1;i<=n;i++)
			freq[i]=0;

		t=n;

		while(t>1)
		{
			get_prime_factor(t);
			t-=fac;
		}
		flag=true;
		for(i=2;i<=n;i++)
		{
			if(freq[i]>0)
			{
				temp2=dividors*(freq[i]+1);
				if(  temp2 / (freq[i]+1) !=dividors || temp2>MAX)
				{
					flag=false;
					break;
				}
				dividors=temp2;
			}

			
		}

		if(flag)printf("Case %lld: %lld\n",cases++,dividors);
		else printf("Case %lld: Infinity\n",cases++);
	
	}

	return 0;
}