#include<stdio.h>
#include<math.h>

int str[9][9],a[10];
long max,sum;

void backtrack(int k);
void construct_candidate(int a[],int k,int n,int c[],int *ncandidate);

void main()
{
	int test,i,j;
	scanf("%d",&test);
	while(test--)
	{
		for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		scanf("%ld",&str[i][j]);
		
		
		max=sum=0;
		backtrack(0);
		printf("%5ld\n",max);
	}
}

void construct_candidate(int a[],int k,int n,int c[],int *ncandidate)
{
	int i,j;
	bool legal;
	for(i=0;i<n;i++)
	{
		legal=true;
		for(j=0;j<k;j++)
		{
			if(abs(k-j)==abs(i-a[j]))
			{
				legal=false;
				break;
			}
			if(i==a[j])
			{
				legal=false;
				break;
			}
		}
		if(legal)
			c[(*ncandidate)++]=i;
	}
}

void backtrack(int k)
{
	int i,c[10],ncandidate=0;
	if(k==8)
	{
		if(sum>max)
			max=sum;
		return;
	}
	construct_candidate(a,k,8,c,&ncandidate);
	for(i=0;i<ncandidate;i++)
	{		
		a[k]=c[i];
		sum+=str[k][c[i]];
		backtrack(k+1);
		sum-=str[k][c[i]];
	}
}