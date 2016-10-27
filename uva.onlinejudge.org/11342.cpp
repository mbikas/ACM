#include<stdio.h>
#include<math.h>

int main()
{
	long test,i,j,rem,n,temp,sq;
	bool found;

	scanf("%ld",&test);

	
	while(test--)
	{
		scanf("%ld",&n);
		found = false;

		for(i=0;i<=50000; i++)
		{
			if(i*i>n)break;
			for(j=i;j<=50000; j++)
			{
				sq = i*i + j*j;
				if(sq>n)break;
				rem = n - sq;
				temp=int(sqrt(rem));
				if((temp*temp) == rem)
				{

				   found = true;
				   printf("%ld %ld %ld\n",i,j,temp);
				   break;
				}

			}

			if(found)break;		
		}

		if(!found)printf("-1\n");
	
	}


	return 0;
}