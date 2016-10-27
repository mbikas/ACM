#include<stdio.h>
#include<string.h>
#define MAX 17


int PRIME[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
bool prime[43];
void backtrack(int a[],int k,int n);
void con_candidate(int a[],int k,int n,int c[],int *ncan);
void set_prime();

void main()
{
	set_prime();
	int n,a[MAX],cases=1;

	while(scanf("%d",&n)==1)
	{

		printf("Case %d:\n",cases++);
		memset(a,0,sizeof(a));
		a[1] = 1;
		backtrack(a,1,n);
		printf("\n");
	}
}

void backtrack(int a[],int k,int n)
{
	int c[MAX],i,ncan;
	if(k==n)
	{
		for(i=1;i<k;i++)printf("%d ",a[i]);
		printf("%d\n",a[k]);
	}
	else
	{
		k++;
		con_candidate(a,k,n,c,&ncan);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];
			backtrack(a,k,n);		
		}	
	}
}

void con_candidate(int a[],int k,int n,int c[],int *ncan)
{
	int i,sum,sum1;
	bool choice[MAX];
	
	*ncan =0;
	
	for(i=1;i<=n;i++)choice[i]=true;
	for(i=1;i<k;i++)choice[a[i]]=false;

	if(a[k-1]%2==0)
	{
		for(i=2;i<=n;i+=2)
		choice[i]=false;
	}
	else
	{
		for(i=1;i<=n;i+=2)
		choice[i]=false;
	}


	if(k==n)
	{
		for(i=2;i<=n;i++)
		{
			if(choice[i])
			{
				sum1 = a[1]+i;
				sum = i + a[k-1];
				if(prime[sum] && prime[sum1])
				c[(*ncan)++]=i;
			}	
		}
	
	}
	else
	{
		for(i=2;i<=n;i++)
		{
			if(choice[i])
			{
				sum = i + a[k-1];
				if(prime[sum])
				c[(*ncan)++]=i;
			}	
		}
	}
}

void set_prime()
{
	int i;
	memset(prime,false,sizeof(prime));
	for(i=0;i<12;i++)
	prime[ PRIME[i] ] = true;
}