//problem E
#include<stdio.h>

void main()
{
	
	long test,i,j,num[100010],n,min,max,diff;
	scanf("%ld",&test);

	for(i=0;i<test;i++)
	{
		scanf("%ld",&n);

		for(j=0;j<n;j++)
		{
			scanf("%ld",&num[j]);
		}

		max=num[n-2]-num[n-1];

		min=num[n-1];

		for(j=n-2;j>=0;j--)
		{
			diff=num[j]-min;

			if(diff>max)
				max=diff;

			if(num[j]<min)
				min=num[j];
			
		}

		printf("%ld\n",max);

	}
}