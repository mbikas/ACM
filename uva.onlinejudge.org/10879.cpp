#include<stdio.h>

void main()
{
	long i,j,p,n,div,count,cases;

	scanf("%ld",&cases);

	for(j=1;j<=cases;j++)
	{

		
		scanf("%ld",&n);
		
		printf("Case #%ld: %ld =",j,n);

		count=0;
		for(i=2; ;i++)
		{
			if(n%i==0 && count==0)
			{
				div = n/i;
				printf(" %ld * %ld =",i,div);
				count++;
			}
			else if(n%i==0 && count==1)
			{
				div = n/i;
				printf(" %ld * %ld\n",i,div);
				count++;
			}

			if(count==2)break;
		}
	
	}

}