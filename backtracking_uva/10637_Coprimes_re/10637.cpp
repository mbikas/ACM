#include<stdio.h>
#include<string.h>
#define MAX 50


int  Gcd(int a ,int b) 
{ 
        if(b==0) 
                return a; 
        else 
             return Gcd(b,a%b); 
} 
void backtrack(int a[],int k,int n,int num,int sum);
void con_candidate(int a[],int k,int n,int num,int c[],int *ncan,int sum);
bool gcd[102][102]={false};

void make_gcd_table()
{
	int i,j;
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
	int test,num,n,a[MAX],cases=1,sum;

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

void backtrack(int a[],int k,int n,int num,int sum)
{
	int ncan,i,c[MAX],sum1; 

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
void con_candidate(int a[],int k,int n,int num,int c[],int *ncan,int sum)
{
	int i,j,diff,sum1;
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
	for(i=a[k-1];i<num;i++)
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
		{
			sum1 = sum + i*diff;
			
			if(sum1<=num)
			c[(*ncan)++] = i;			
		}
	}



}