#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 105


long  Gcd(long a ,long b) 
{ 
        if(b==0) 
                return a; 
        else 
             return Gcd(b,a%b); 
} 
void backtrack(long a[],long k,long n,long num,long sum);
void con_candidate(long a[],long k,long n,long num,long c[],long *ncan,long sum);
bool gcd[102][102]={false};

void make_gcd_table()
{
	long i,j;
	for(i=1;i<=100;i++)
	{
		for(j=1;j<=100;j++)
		{
			if(Gcd(i,j)==1)
				gcd[i][j] = gcd[j][i] = true;		
		}
	
	}
}



void main()
{
	long test,num,n,a[MAX],cases=1,sum;

	make_gcd_table();

	scanf("%d",&test);

	while(test--)
	{
		scanf("%d %d",&num,&n);
		printf("Case %d:\n",cases++);
		sum=1;
		memset(a,0,sizeof(a));
		a[1] = 1;
		backtrack(a,1,n,num,sum);

	}
}

void backtrack(long a[],long k,long n,long num,long sum)
{
	long ncan,i,c[MAX],sum1; 

	if(k==n && sum==num)
	{
		for(i=1;i<k;i++)printf("%d ",a[i]);
		printf("%d\n",a[k]);	
	}
	else
	{
		k++;
		con_candidate(a,k,n,num,c,&ncan,sum);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];
			sum1 = sum + a[k];
			backtrack(a,k,n,num,sum1);
			//sum = 1;
		}	
	}
}
void con_candidate(long a[],long k,long n,long num,long c[],long *ncan,long sum)
{
	long i,j,diff,max;
	bool yes;

	*ncan = 0;

	if(sum>=num)return;

	if(k==n)
	{
		
		diff = num - sum;
		if(diff<a[k-1])return;
		for(i=1;i<k;i++)
		{
			if(gcd[a[i]][diff]==false)
				return;		
		}
		c[(*ncan)++] = diff;
		return;	
	}

	diff = n-k+1;
	if(diff<=0)
		max = 1;
	else
		max =  ((num-sum)/diff)  + 1;
	
	for(i=a[k-1];i<=max;i++)
	{
		yes = true;
		for(j=1;j<k;j++)
		{
			if(gcd[a[j]][i]==false)
			{
				yes = false;
				break;		
			}	
		}
		if(yes)
		c[(*ncan)++] = i;	
	}
}