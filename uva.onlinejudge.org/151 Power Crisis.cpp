#include<stdio.h>

int result[100];
bool flag[101];

void random_generate(void)
{
	int i, j, m, count, ans;
	
	for(i=13; i<100; i++)
	{
		if(i==13)
		{
			result[i] = 1;
			continue;
		}
		
		for(m=2; m<=i; m++)
		{
			for(j=1;j<=i;j++)
			flag[j] = true;

			count = 0;	flag[1] = false;	ans = 1;

			for(j=2;;j++)
			{
				if(flag[j] == true)
				{
					count++;
					
					if(count==m)
					{
						if(j==13)	break;
						ans++;
						
						flag[j] = false;

						if(ans==i-1)	break;
						
						count = 0;
					}
				}

				if(j==i)	j=1;
			}

			if(ans==i-1)	break;
		}

		result[i] = m;
	}
}

void main()
{
	random_generate();

	//freopen("b.in","r",stdin);

	int n;
	
	for(;scanf("%d",&n)==1;)
	{
		if(n==0)	break;

		printf("%d\n",result[n]);
	}
}