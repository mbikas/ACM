//acm 10948 The primary problem.
#include<stdio.h>
#include<math.h>
#define SIZE 1000000

long total,prime[100000];
int flag[SIZE+1];

void seive(long s)
{
	long i,j,root;
	
	for(i=3;i<=s;i+=2)
	{
		flag[i]=1;
	}
	root=sqrt(s);
	for(i=3;i<=root;i+=2)
	{
		if(flag[i]==0)
			continue;

		for(j=i*i;j<=s;j+=i)
			flag[j]=0;
	}
	
	total=1;
	for(i=3;i<=s;i+=2)
	{	
		if(flag[i]==1)
			prime[total++]=i;

	}
	
} 
void main()
{
	long n,count,flag2,temp;

	seive(1000000);

	while(scanf("%ld",&n)==1 && n>0)
	{
		printf("%ld:\n",n);
		if(n==4)
			printf("2+2\n");
		else if(n%2==1)
		{
			if(flag[n-2]==1)
			{
				printf("2+%ld\n",n-2);
			}
			else
				printf("NO WAY!\n");
		}

		else
		{
			flag2=0;
			temp=n/2;
			for(count=1;prime[count]<=temp;count++)
			{
				if(flag[n-prime[count]]==1)
				{
					printf("%ld+%ld\n",prime[count],n-prime[count]);
					flag2=1;
					break;
				}
			}

			if(flag2==0)
				printf("NO WAY!\n");
		}
	}
}