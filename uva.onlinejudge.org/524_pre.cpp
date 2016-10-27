#include<stdio.h>
#include<string.h>
#define MAX 17
#define sz 85035
//2:1+4:2+6:2+8:4+10:96+12:1024+14:2880+16:81024
typedef struct{
	int x[17];
}ANS;
ANS ans[sz];
long start[MAX];
long end[MAX];
long total=0;


bool prime[MAX][MAX];
void backtrack(int a[],int k,int n);
void con_candidate(int a[],int k,int n,int c[],int *ncan);

void set_prime_matrix();
void precalculation();
void main()
{
	set_prime_matrix();
	precalculation();
	int n,cases=1;
	long i,j;

	while(scanf("%d",&n)==1)
	{

		printf("Case %d:\n",cases++);


		
		for(i=start[n];i<end[n];i++)
		{
			for(j=1;j<n;j++)
				printf("%d ",ans[i].x[j]);
			printf("%d\n",ans[i].x[n]);
		
		}

		//printf("total = %ld\n",end[n]-start[n]);

		printf("\n");
	}

}

void precalculation()
{

	int n,a[MAX];
	for(n=2;n<=16;n+=2)
	{
		start[n]=total;
		memset(a,0,sizeof(a));
		a[1]=1;
		backtrack(a,1,n);	
	}
}

void backtrack(int a[],int k,int n)
{
	int c[MAX],i,ncan;
	if(k==n)
	{
		for(i=1;i<=k;i++)
		ans[total].x[i] = a[i]; 
		total++;
		end[n]=total;
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
	int i;
	bool choice[MAX];
	
	*ncan =0;
	
	for(i=1;i<=n;i++)choice[i]=true;
	for(i=1;i<k;i++)choice[a[i]]=false;	


	if(k==n)
	{
		for(i=2;i<=n;i++)
		{
			if(choice[i] && prime[i][a[k-1]] && prime[i][1])
			c[(*ncan)++]=i;		
		}	
	}
	else
	{
		for(i=2;i<=n;i++)
		{
			if(choice[i] && prime[i][a[k-1]])
			c[(*ncan)++]=i;			
		}
	}
}


void set_prime_matrix()
{
	int i,j,sum;
	int PRIME[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
	bool Prime[43];
	memset(Prime,false,sizeof(Prime));
	memset(prime,false,sizeof(prime));
	for(i=0;i<12;i++)
	Prime[ PRIME[i] ] = true;

	for(i=1;i<=16;i++)
	{
		for(j=1;j<=16;j++)
		{
			sum = i+j;
			if(Prime[sum])
			prime[i][j] = prime[j][i]=true;		
		
		}
	}
}