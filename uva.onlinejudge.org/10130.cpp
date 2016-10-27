#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SZ 1005

typedef struct{
	long value,weight;
}item;

item items[SZ];
long data[SZ][35];

long max(long a,long b);
long knapsack_0_1(item *items,long n,long mw);

void main()
{
	long n,i,test,g;
	long res,mxweight;
	long sum;
	
	scanf("%ld",&test);

	while(test--)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		scanf("%ld %ld",&items[i].value,&items[i].weight);
	
		scanf("%ld",&g);
		sum=0;

		for(i=0;i<g;i++)
		{
			scanf("%ld",&mxweight);
			res=knapsack_0_1(items,n,mxweight);
			sum = sum+res;
			//printf("%.ld\n",res);
		}
		printf("%ld\n",sum);
	}
}

long knapsack_0_1(item *items,long n,long mw)
{
	long i,w;
	for(i=0;i<=n;i++)
		data[i][0]=0;
	for(w=0;w<=mw;w++)
		data[0][w]=0;
	for(i=1;i<=n;i++)
	{
		for(w=0;w<=mw;w++)
		{
			if(items[i].weight>w)
				data[i][w]=data[i-1][w];
			else
				data[i][w]=max(data[i-1][w],data[i-1][w-items[i].weight]+items[i].value);
		}
	}
	return(data[n][mw]);
}

long max(long a,long b)
{
	return(a>b)?a:b;
}