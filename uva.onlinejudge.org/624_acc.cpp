#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long str[100],x[100];
long arr[100];
long n,r,max,sum,msum;

int permutation(int i,int k);
int is_a_solution(long sum);
void process_solution(long k);

int main()
{
	int i;
	while(scanf("%ld",&max)==1)
	{
		if(1!=scanf("%ld",&n))
			return 0;
		for(i=0;i<n;i++)
			if(1!=scanf("%ld",&str[i]))
				return 0;
		//memset(pos,0,sizeof(int)*n);
		//memset(x,0,sizeof(char)*n);
		sum=msum=0;
		permutation(0,0);
		for(i=1;i<=arr[0];i++)
			printf("%ld ",arr[i]);
		printf("sum:%ld\n",msum);
	}
	return 0;
}

int is_a_solution(long sum)
{
	if(sum==max)
		return 1;
	if(sum>msum&&sum<max)
		return 2;
	if(sum>max)
		return 3;
	return 0;
}
void process_solution(long k)
{
	int i;
	arr[0]=k;
	for(i=0;i<k;i++)
		arr[i+1]=x[i];
}

int permutation(int i,int k)
{
	int j=is_a_solution(sum);
	if(j)
	{
		if(j==1)
		{
			msum=sum;
			process_solution(k);
			return 1;
		}
		else if(j==2)
		{
			msum=sum;
			process_solution(k);
		}
		else
			return 0;
	}
	for(;i<n;i++)
	{
		x[k]=str[i];
		sum+=x[k];
		if(permutation(i+1,k+1))
			return 1;
		sum-=x[k];
	}
	return 0;
}