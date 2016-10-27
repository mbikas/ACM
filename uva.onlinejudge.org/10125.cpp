#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define sz 1000005

typedef struct{
	long long sum;
	long long a;
	long long b;
}PLUS;
PLUS plus[sz];

long long a[1005],n;

int comp1(const void *c,const void *d);
int comp(const void *c,const void *d);



void main()
{
	long long i,j,k,index,*p,total,key;
	int f=0;

	while(scanf("%lld",&n)==1 && n)
	{
		for(i=0;i<n;i++)scanf("%lld",&a[i]);

		qsort(a,n,sizeof(a[i]),comp);

		total=0;

		for(i=0;i<n-1;i++)
		{	for(j=i+1;j<n;j++)
			{
				plus[total].sum  = a[i]+a[j];
				plus[total].a    = i;
				plus[total].b  = j;
				total++;
			}
		}

		f=0;
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<total;j++)
			{
				if(i!=plus[j].a &&  i!=plus[j].b)
				{	
					
						key = a[i]-plus[j].sum;
						p = (long long *)bsearch(&key,a,n,sizeof(long long),comp1);
						if(p)index = p-a;
						else index = -1;
					
					if(  (index>=0 && index<=n) && a[index]==key)
					{
						for(k=index;k<n;k++)
						{	if(a[k]!=key)break;
							if(index!=i && index!=plus[j].a && index!=plus[j].b)
							{
								//printf("%ld + %ld + %ld = ",a[plus[j].a],a[plus[j].b],key);
								printf("%lld\n",a[i]);
								f=1;
								break;							
							}						
						}
					}			
				}
				if(f==1)break;
			}
			if(f==1)break;	
		}

		if(f==0)printf("no solution\n");	
	}
}


int comp1(const void *c,const void *d)
{
	long long *A = (long long *)c;
	long long *B = (long long *)d;

	if(*A>*B && (B-a==n-1 || *A<*(B+1)) )
		return 0;

	if(*A==*B && (B-a==0 || *A>*(B-1)) )
		return 0;

	if(*A!=*B)
		return *A-*B;

	else
		return -1;

}

int comp(const void *c,const void *d)
{
	long long *A = (long long *)c;
	long long *B = (long long *)d;

	long long p = *A - *B;
	if(p>0)return 1;
	if(p<0)return -1;
	return 0;
}
