#include<stdio.h>


void main()
{

	int a[20],n,i,j;
	long cases=1;
	long long sum,max;
	

	while(scanf("%d",&n)==1)
	{	
	
		max=0;
		
		
		sum=1;
		

		for(i=0;i<n;i++)
		scanf("%d",&a[i]);

		for(i=0;i<n;i++)
		{
			sum = a[i];
			if(sum>max)
				max = sum;
			for(j=i+1;j<n;j++)
			{
				sum = sum * a[j];			
				
				if(sum>max)
					max = sum;
			}
		}

		


		printf("Case #%ld: The maximum product is %lld.\n\n",cases++,max);
	
	
	}




}