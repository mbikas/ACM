#include<stdio.h>
#include<math.h>

void main()
{

	long long k,root,p,diff,test;

	int f=0;
	scanf("%lld",&test);

	while(test--)
	{

		if(f==1)printf("\n");
		else f=1;
		scanf("%lld",&k);
		if(k==0)
		{
			printf("3\n");
			continue;
		}
		if(k<0)
			k = k*-1;

		root = 1*1 + (4 * k * 2);
		root = (long long)sqrt(root);
		root = root - 1;
		root = (long long)(root/2);	
		//printf("%ld\n",root);

		p = (root * (root+1) ) /2;
		if(p==k)
		{	printf("%lld\n",root);
			continue;
		}

		else if(p<k)
		{
			while(1)
			{
				root++;
				p = (root * (root+1) ) /2;	
				diff =p - k;
				if(diff%2==0)
					break;					
			}
			printf("%lld\n",root);
		}
	
	}
}