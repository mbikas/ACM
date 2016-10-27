//binary search
//first index from all repeats equal  to data
//previous data index for not available data


#include<stdio.h>
#include<stdlib.h>


long arr[100];
long n;

int comp(const void *a,const void *b);

void main()
{
	long key,index,i;
	long *p;

	while(scanf("%ld",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&arr[i]);


		while(scanf("%ld",&key)==1)
		{
			p = (long *)bsearch(&key,arr,n,sizeof(long),comp);
			if(p)index = p-arr;
			else index = -1;
			
			printf("Index = %ld\n",index);	
		}
	}
}



int comp(const void *a,const void *b)
{
	long *A = (long *)a;
	long *B = (long *)b;

	if(*A>*B && (B-arr==n-1 || *A<*(B+1)) )
		return 0;

	if(*A==*B && (B-arr==0 || *A>*(B-1)) )
		return 0;

	if(*A!=*B)
		return *A-*B;

	else
		return -1;

}

