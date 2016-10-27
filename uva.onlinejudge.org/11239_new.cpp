#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define sz 1000015
long start[sz],num[sz];
long mod[sz]={0};



int main()
{
	long i,ct,m,n,j,p;
	bool found;
	long long sum;

	ct=1;
	while(scanf("%ld %ld",&m,&n)==2)
	{
		if(m==0 && n==0)break;
		
		
		sum=0;
		found = false;
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&num[i]);

			if(!found)
			{
			
				sum = sum+num[i];
				p = sum %m;

				if(num[i]%m==0)
				{
					printf("%ld\n",i);
					found = true;
					continue;
				}
				if(sum%m==0)
				{
					printf("%ld",1);
					for(j=2;j<=i;j++)printf(" %ld",j);
					printf("\n");
					found = true;
					continue;			
				}

				if(mod[p]==ct)
				{
						printf("%ld",start[p]+1);
						for(j=start[p]+2;j<=i;j++)printf(" %ld",j);
						printf("\n");
						found = true;
						continue;				
				}
				
				mod[p]=ct;
				start[p] = i;
							
			
			}		
		}
		
		ct++;
		if(!found)
			printf("no sweets\n");
		
	}

	return 0;
}