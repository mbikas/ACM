//11348 I - Exhibition

#include<stdio.h>

long stamp[10005];

int main()
{
	
	long test,n,i,j,temp,total,t[55],cases=1,m;
	double per;
	scanf("%ld",&test);
	
	while(test--)
	{
		for(i=0;i<=10000;i++)
			stamp[i]=0;
		scanf("%ld",&n);
		
		for(i=1;i<=n;i++)
		{
			t[i]=0;
			scanf("%ld",&m);
			for(j=0;j<m;j++)
			{
				scanf("%ld",&temp);
				
				if(stamp[temp]==0 || stamp[temp]==i)
				{
					stamp[temp]=i;
				}
				else
					stamp[temp]=100;
				
			}
		}

		total=0;

		for(i=0;i<=10000;i++)
		{
			if(stamp[i]>0 && stamp[i]<100)
			{
				total++;
				t[stamp[i]]++;
			}
		}
		printf("Case %ld:",cases++);
		for(i=1;i<=n;i++)
		{
			if(t[i]==0)per=0.0;
			else
			per=100.0*((double)t[i]/total);

			/*if(total==0)
			{
				per=100.0/n;
			}*/
			printf(" %.6lf%c",per,'%');

		}
		printf("\n");
	}
	
	return 0;
}