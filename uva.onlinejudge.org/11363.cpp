#include <string.h>
#include<stdio.h>

#define M 10005
#define N 2

long graph[M][N];
bool seen[M];
long matchL[M], matchR[M];
long n, m;

bool bpm( long u )
{
    for( long v = 0; v < n; v++ ) 
	{
		if( seen[graph[u][v]] ) continue;
		seen[graph[u][v]] = true;
		
		if( matchR[graph[u][v]] < 0 || bpm( matchR[graph[u][v]] ) )
		{
			matchL[u] = graph[u][v];
			matchR[graph[u][v]] = u;
			return true;
		}
	}
	
	return false;
}

int main()
{
	long tcas,i,size,u,v;
	scanf("%ld",&tcas);
	while(tcas--)
	{
		memset( graph, 0, sizeof( graph ) );
		scanf("%ld %ld",&m,&size);
		for(i=0;i<m;i++)
		{
			scanf("%ld %ld",&u,&v);
			graph[i][0]=u;
			graph[i][1]=v;
		}
		n=2;
		memset( matchL, -1, sizeof( matchL ) );
		memset( matchR, -1, sizeof( matchR ) );
		long cnt = 0;
		for( long i = 0; i < m; i++ )
		{
			memset( seen, 0, sizeof( seen ) );
			if( bpm( i ) ) cnt++;
		}
		//printf("%ld\n",cnt);
		if(cnt==m)
		{
			printf("successful hashing\n");
		}
		else
		{
			printf("rehash necessary\n");
		}
	}
    return 0;
}