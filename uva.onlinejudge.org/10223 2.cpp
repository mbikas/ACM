#include<stdio.h>

long tree[] = { 1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,
2674440,9694845,35357670,129644790,477638700,1767263190 };

void main()
{
	long trees;
	int i;
	while(scanf("%ld",&trees)==1)
	{

		for(i=0;i<19;i++)
		{
			if(trees==tree[i])
			{
				printf("%d\n",(i+1));
				break;
			}		
		}
	}
}