//acm 10164 Number game
#include<stdio.h>
typedef struct
{
	int nums[2100];
	int ind;
}mod;

mod mods[1030];

void main()
{

	int i,n,total,temp,rem,result[1050];

	while(scanf("%d",&n)==1 && n)
	{
		total=2*n-1;

		for(i=0;i<n;i++)
			mods[i].ind=0;

		for(i=0;i<total;i++)
		{
			scanf("%d",&temp);

			rem=temp%n;
			mods[rem].nums[mods[rem].ind]=temp;
			mods[rem].ind++;
		}

		total=0;
		for(i=0;i<mods[0].ind;i++)
		{
			result[total]=mods[0].nums[i];
			total++;
			if(total==n)
				break;
		}
		
		for(i=1;i<n;i++)
		{
			if(total==n)
				break;

			if(mods[i].ind>0)
			{
				temp=mods[i].ind;
				if(mods[n-i].ind>0)
				{
					if(temp>mods[n-i].ind)
						temp=mods[n-i].ind;

					for(int j=0;j<temp;j++)
					{
						result[total++]=mods[i].nums[j];
						result[total++]=mods[n-i].nums[j];
					}
				}
			}
		}

		if(total>=n)
		{
			printf("Yes\n");

			for(i=0;i<n;i++)
			{
				printf("%d ",result[i]);
			}
			printf("\n");
		}

		else
		{
			printf("No\n");
		}
	}
	
}