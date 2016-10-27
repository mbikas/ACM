#include<stdio.h>
#include<stdlib.h>
long long p[20005];
int comp(void const *A,void const *B)
{
	long long *a=(long long *)A;
	long long *b=(long long *)B;

	if(*a<*b)return 1;
	if(*a>*b)return -1;
	return 0;
}
int main()
{
	long long test,n,i,sum,c;

	scanf("%lld",&test);
	while(test--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&p[i]);
		qsort(p,n,sizeof(p[0]),comp);
		sum=0;
		for(i=0,c=0;i<n;i++)
		{
			c++;
			if(c==3)
			{
				sum+=p[i];
				c=0;
			}
		}
		
		
		
		printf("%lld\n",sum);
	}
	return 0;
}