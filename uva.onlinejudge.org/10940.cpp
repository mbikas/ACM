#include<stdio.h>

int main()
{
	int n,x,result,s;
	while(scanf("%d",&n)==1 && n)
	{

		x = 1;

		while(x<=n)
		{
			
			x = x*2;
			s = x%n;
			result = n - s;	
		}

		printf("%d\n",result);
	
	
	}
	return 0;
}