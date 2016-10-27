#include<stdio.h>
#include<string.h>

int sum[30005];

void main()
{
	long n,cases=1,i,a[35],x,f,old,total,j,max;

	while(scanf("%ld",&n)==1)
	{
		printf("Case #%ld:",cases++);
		memset(sum,0,sizeof(sum));
		
		old=0;
		f=1;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);		
			if(a[i]<=old)
				f=0;
			old = a[i];
			printf(" %ld",a[i]);
		}
		printf("\n");

		if(f==0)
		{	printf("This is not an A-sequence.\n");
			continue;
		}

		max = a[n-1];

		total=0;
		for(i=0;i<n;i++)
		{
			total=a[i];
			//printf("total = %ld\n",total);

			for(j=max+1;j>=0;j--)
			{
				if(sum[j]>0)
				{
					x = total + j;
					sum[x]++;				
				}			
			}

			sum[total]++;
			
		}

		for(i=0;i<n;i++)
		{
			if(sum[a[i]]>1)
			{
				f=0;
				break;
			}
		
		}
		
		if(f==0)
			printf("This is not an A-sequence.\n");
		else
			printf("This is an A-sequence.\n");
	
	
	}
}