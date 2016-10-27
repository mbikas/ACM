#include<stdio.h>
#define max 70000

long long nway[max+1];

int coin[13]={10000,5000,2000,1000,500,200,100,50,20,10,5};

int main()
{
	int i,j,v,c,n;
    	double taka;
	    v=11;
		nway[0]=1;
		for(i=0;i<v;i++)
		{
			c=coin[i];
			for(j=c;j<=max;j++)nway[j]+=nway[j-c];
		}
	while(scanf("%lf",&taka)==1)
	{
		if(taka==0)break;
		n=(taka*100+1e-5);
		printf("%6.2lf%17lld\n",taka,nway[n]);
	}
	return 0;
}