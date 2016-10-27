#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAX 10005

long min = MAX;
void backtrack(long a[],long k,long n);
void con_candidate(long a[],long n,long k,long c[],long *ncandidate);
long ans[MAX];
bool f = false;

void main()
{
	long a[MAX],n,i;

	while(scanf("%ld",&n)==1 && n)
	{

		for(i=0;i<=n;i++)a[i] = i;

		f = false;
		min = MAX;
		a[1] = 1;
		backtrack(a,1,n);
		
		for(i=1;i<min;i++)printf("%ld ",ans[i]);
		printf("%d\n",ans[min]);
	}
}

void backtrack(long a[],long k,long n)
{
	long c[MAX],ncandidate,i;
	if(a[k]==n)
	{
		if(k<min)
		{
			min = k;
			f = true;
			for(i=1;i<=k;i++)ans[i] = a[i];		
		}
	
	}
	else
	{
		k++;
		con_candidate(a,n,k,c,&ncandidate);
		for(i=0;i<ncandidate;i++)
		{
			a[k] = c[i];
			backtrack(a,k,n);		
		}	
	}
}

void con_candidate(long a[],long n,long k,long c[],long *ncan)
{

	long i,j;
	long max,sum=0;
	bool choice[MAX];

	*ncan = 0;

	if(k>=min)return;

	// prune if we cannot reach target using last depth 
	if(f)
	{
		max = (a[k-1] * pow(2,(min - k)) ) ;
		if(max<n)return;
	}

	for(i=0;i<=n;i++)choice[i]=true;
	for(i=1;i<k;i++) choice[a[i]] = false;


	for(i=k-1;i>=1;i--)
	{	for(j=k-1;j>=1;j--)
		{
			sum = a[i] + a[j];
			if(sum==n)
			{
				c[(*ncan)++]=n;
				return; 			
			}
			if(sum<=n && choice[sum] && sum>a[k-1])
			{	c[(*ncan)++] = sum;	
			    choice[sum] = false;
			}
			if(i==j && sum<a[k-1]) return;
		}
	}

}
