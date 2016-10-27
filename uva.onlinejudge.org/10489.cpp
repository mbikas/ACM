#include<stdio.h>

void main()
{
	long test,sum,box,i,R,friends,m,p;

	scanf("%ld",&test);

	while(test--)
	{
		scanf("%ld %ld",&friends,&box);

		sum=0;
		for(i=0;i<box;i++)
		{
			R=1;
			scanf("%ld",&m);
			while(m--)
			{
				scanf("%ld",&p);
				R = (R *p)%friends;
			}
			sum = sum + R;
		}

		sum = sum %friends;

		printf("%ld\n",sum);
	
	
	
	}
}