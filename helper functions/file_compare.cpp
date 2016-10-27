#include<stdio.h>
#include<string.h>

void main()
{

	long n,x,total=0;
	bool flag[12000]={false};

	freopen("bikas.txt","r",stdin);
	freopen("out.txt","w",stdout);


	while(scanf("%ld",&x)==1)
	{	
        flag[x]=true;		
	}
	
	freopen("piklu.txt","r",stdin);


	while(scanf("%ld",&n)==1)
	{
		if(flag[n]==false)
		{	printf("%ld\n",n);
		    total++;
		}
	}

	printf("have to solve = %ld\n",total);
		





}