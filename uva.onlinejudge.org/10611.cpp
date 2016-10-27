#include<stdio.h>
#include<stdlib.h>
#define sz 50005

long n,arr[sz];
int comp(const void *a,const void *b);

void main()
{
	long i,key,query,*p,index,beg,end,f;


	scanf("%ld",&n);
	for(i=0;i<n;i++)scanf("%ld",&arr[i]);
	
	scanf("%ld",&query);

	while(query--)
	{
		scanf("%ld",&key);
		p = (long *)bsearch(&key,arr,n,sizeof(long),comp);
		if(p)index = p-arr;
		else index = -1;

		//printf("index = %ld\n",index);

		if(index==-1) 
		{
			beg = -1;
			end =  0;
		}

		else if(arr[index]==key)
		{
			if(index==0) beg = -1;
			else beg = index-1;

			f=0;
			for(i=index;i<n;i++)
			{	if(arr[i]!=key)
				{	end = i;
					f=1;
					break;
				}
			}
			if(f==0)end = -1;
			
			
		}
		else
		{
			if(index==n-1)
			{
				beg = n-1;
				end = -1;
			}
			else if(index==0)
			{
				beg = -1;
				end = index;
			}
			else
			{
				beg = index;
				end = index+1;
			}		
		}

		if(beg==-1)
			printf("X ");
		else
			printf("%ld ",arr[beg]);
		if(end==-1)
			printf("X\n");
		else
			printf("%ld\n",arr[end]);	
	
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