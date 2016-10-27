#include<stdio.h>

int main()
{
	int n,m,k;
	while(scanf("%d %d %d",&n,&m,&k)==3)
	{
		if(n==0 && m==0 && k==0)break;

		if (m%2==0) 
			printf("Gared\n");
		else
			printf("Keka\n");
	
	}
	return 0;
}