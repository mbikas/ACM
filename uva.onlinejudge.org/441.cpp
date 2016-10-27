#include<stdio.h>

void main()
{

	//freopen("441.in","r",stdin);
	//freopen("441.out","w",stdout);

	int x,j,k,l,m,n,o,lotto[15];
	int flag;



	//for printing blank line
	flag=1;

	while(scanf("%d",&x)==1 && x!=0)
	{
		if(flag==0)
		printf("\n");
		for(j=0;j<x;j++)
		scanf("%d",&lotto[j]);

		for (j=0;j<=x-5;j++)
		for (k=j+1;k<=x-4;k++)
		for (l=k+1;l<= x-3 ;l++)
		for (m=l+1;m<=x-2;m++)
		for (n=m+1;n<=x-1;n++)
		for (o=n+1;o<x;o++)
		printf("%d %d %d %d %d %d\n",lotto[j],lotto[k],lotto[l],lotto[m],lotto[n],lotto[o]);
        
		flag=0;
	}

}

/*
#include<stdio.h>

void main()
{

	int x,j,k,l,m,n,o,lotto[15];
	
	

	while(scanf("%d",&x)==1 && x!=0)
	{
		for(j=0;j<x;j++)
		scanf("%d",&lotto[j]);

		for (j=0;j<=x-5;j++)
		for (k=j+1;k<=x-4;k++)
		for (l=k+1;l<= x-3 ;l++)
		for (m=l+1;m<=x-2;m++)
		for (n=m+1;n<=x-1;n++)
		for (o=n+1;o<x;o++)
		printf("%d %d %d %d %d %d\n\n",lotto[j],lotto[k],lotto[l],lotto[m],lotto[n],lotto[o]);
        
		
	}

}
*/