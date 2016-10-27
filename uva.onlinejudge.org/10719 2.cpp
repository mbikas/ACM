#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define sz 10005

void main()
{

	long k,ans[sz],num[sz],temp,i,total;
	int f=0;
	char a[100000];

	while(scanf("%ld\n",&k)==1)
	{
		//if(f==1)
		//	printf("\n");
		//else f=1;

		gets(a);

		total=0;
		char *p;
		p = strtok(a," ");
		while(p)
		{
			num[total++] = atol(p);
			p = strtok(0," ");
		}


		ans[0]=num[0];
		temp = num[1]- ans[0]*(-k);
		for(i=1;i<total-1;i++)
		{
			ans[i]=temp;
			temp = num[i+1]- ans[i]*(-k);
		}
		

		printf("q(x):");
		for(i=0;i<total-1;i++)
		{
			printf(" %ld",ans[i]);
		}
		printf("\nr = %ld\n\n",temp);		

		
		
		
	

	}
}