//Bellman ford

#include<stdio.h>

long flg,mat[1010][1010],cost[1010][1010],g[1010][1010],d[1010];


//return true if negative cycle found
bool Bellman(long n)
{
	long i,j;
	for(i=0;i<n;i++)
		d[i]=2147483647;
	d[0]=0;
	for(i=0;i<n;i++)
	{
		for(j=1;j<=g[i][0];j++)
		{
			if(d[g[i][j]]>d[i]+cost[i][g[i][j]])
				d[g[i][j]]=d[i]+cost[i][g[i][j]];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<=g[i][0];j++)
		{
			if(d[g[i][j]]>d[i]+cost[i][g[i][j]])
				return 1;
		}
	}
	return 0;
}

int main()
{
	long t,u,v,c,i,n,m;
	scanf("%ld",&t);
	while(t--)
	{
		flg++;
		scanf("%ld %ld",&n,&m);
		for(i=0;i<n;i++)
			g[i][0]=0;
		for(i=0;i<m;i++)
		{
			scanf("%ld %ld %ld",&u,&v,&c);
			if(mat[u][v]!=flg)
			{
				mat[u][v]=flg;
				cost[u][v]=c;
				g[u][0]++;
				g[u][g[u][0]]=v;
			}
		}
		if(Bellman(n))
			printf("possible\n");
		else
			printf("not possible\n");
	}
	return 0;
}