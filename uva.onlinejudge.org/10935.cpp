
#include<stdio.h>
#define sz 105

void main()
{
	int ct,n,x,p;
	int top[sz];

	while(scanf("%d",&n)==1 && n!=0)
	{	
		
		if(n==1)
		{
			printf("Discarded cards:\n");
			printf("Remaining card: 1\n");
		
		}

		else
		{
		
			printf("Discarded cards: ");
			p=0;		
			for(x=1;x<=n;x++)
			top[p++]=x;

			x=0;
			ct=0;
			while(ct<n-1)
			{	
				if(ct==n-2)
				printf("%d\n",top[x]);
				else
				printf("%d, ",top[x]);
				ct++;
				top[p++]=top[x+1];
				x+=2;
			}

			printf("Remaining card: %d\n",top[x]);

			//printf("%d\n",p);
		}

	
	
	
	}
}