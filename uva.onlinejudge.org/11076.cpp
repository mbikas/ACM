//problem c
#include<stdio.h>

void main()
{
	long long fact[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
	long long sum,digit[15];
	long long i,n,temp;

	char result[1000];
		
	while(scanf("%lld",&n)==1 && n!=0)
	{
		for(i=0;i<10;i++)
			digit[i]=0;

		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&temp);

			digit[temp]++;
			sum+=temp;


		}

		if(sum==0)
			printf("0\n");

		else
		{
			//printf("%lu\n",sum);
			sum*=fact[n];
			//printf("%lu\n",sum);

			temp=1;
			
			for(i=0;i<10;i++)
			{
				if(digit[i]>1)
					temp*=fact[digit[i]];
			}

			sum/=temp;

			//printf("%lu\n",sum);

			sum/=n;
			//printf("%lu\n",sum);
			//i=0;
			temp=sum;
			for(i=0;i<n-1;i++)
			{
				result[i]=temp%10+'0';
				temp=temp/10;
				temp+=sum;
			}
			
			printf("%lld",temp);
			for(i=n-2;i>=0;i--)
				printf("%c",result[i]);

			printf("\n");
		}
	}


}
