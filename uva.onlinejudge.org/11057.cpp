#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


long min = 10000005;
long diff,x,y,arr[10005];




int comp(void const *A, void const *B)
{

	long *a = (long*)A;
	long *b = (long*)B;

	

	
	if(*a>*b)
		return 1;
	if(*a<*b)
		return -1;

		return 0;
	

}



void main()
{
	long n,i;
	long key,q,index;
	long *p;



	
	while(scanf("%ld",&n)==1)
	{
		min = 1000005;
	
		for(i=0;i<n;i++)
		scanf("%ld",&arr[i]);		
		
		
		scanf("%ld",&key);
		
		qsort(arr,n,sizeof(arr[0]),comp);

		for(i=0;i<n;i++)
		{
			
			if(arr[i]>=key)
				break;
			q = key - arr[i];


			p = (long *)bsearch(&q,arr,n,sizeof(long),comp);
			if(p)
			{  index = p-arr;
               diff = abs(arr[index] - arr[i]);
			   //printf("%ld %ld\n",arr[index],arr[i]);
			   if(diff<min)
			   {
				    min = diff;
					x = arr[i];
					y = arr[index];
			   }
			}		
		}

	
		if(y>x)
		printf("Peter should buy books whose prices are %ld and %ld.\n\n",x,y);
		else
		printf("Peter should buy books whose prices are %ld and %ld.\n\n",y,x);
	
	
	
	}


}