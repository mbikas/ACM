#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define sz 1000000


long sum[sz],n;

int comp1(const void *a,const void *b);
long get_min(long index,long key);
int comp(void const *A, void const *B)
{
	long *a = (long*)A;
	long *b = (long*)B;

	long p = *a-*b;	
	
	if(p>0)
		return 1;
	if(p<0)
		return -1;
	return 0;
}

void main()
{
	//freopen("10487.in","r",stdin);
	//freopen("10488.out","w",stdout);


	long a[1005],i,j,m;
	long *x,index,query,min,key,cases=1;


	while(scanf("%ld",&m)==1 && m!=0)
	{
		n=0;
		for(i=0;i<m;i++)
		{	
			scanf("%ld",&a[i]);

			if(i>0)
			{
				for(j=i-1;j>=0;j--)
					sum[n++]=a[i]+a[j];				
			}
		}

		qsort(sum,n,sizeof(sum[0]),comp);

		//for(i=0;i<n;i++)
		//printf("%ld ",sum[i]);
		//printf("\n");

		printf("Case %ld:\n",cases++);
		scanf("%ld",&query);

		while(query--)
		{
			scanf("%ld",&key);

			x = (long *)bsearch(&key,sum,n,sizeof(long),comp1);
			if(x)
				index = x-sum;
			else
				index=0;

			//printf("%ld\n",index);

			min = get_min(index,key);

			printf("Closest sum to %ld is %ld.\n",key,min);


		}	
	
	}
}



long get_min(long index,long key)
{
	long p,q;
	
	if(n==1)return sum[0];

	if(key==sum[index])return key;
	if(index==n-1)
		return sum[index];

	//else
	p = abs(key - sum[index]);
	q = abs(key - sum[index+1]);

	if(p<=q)
		return sum[index];
	return sum[index+1];		
	
	
}


int comp1(const void *a,const void *b)
{
	long *A = (long *)a;
	long *B = (long *)b;

	if(*A>*B && (B-sum==n-1 || *A<*(B+1)) )
		return 0;

	if(*A==*B && (B-sum==0 || *A>*(B-1)) )
		return 0;

	long p;
	if(*A!=*B)
	{	
		p = *A-*B;
		if(p>0)return 1;
		if(p<0)return -1;
		return 0;
	}	
	else
		return -1;

}
