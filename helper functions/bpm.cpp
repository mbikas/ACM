#include<math.h>
#include<stdio.h>
#include <string.h>

#define M 128
#define N 128

int graph[M][N],edg[M];
bool seen[N];
int matchL[M], matchR[N];
int n, m;
double gop[110][2],hol[110][2];

void input(long d)
{
	long i,j;
	double dis,x,y;
	for(i=0;i<n;i++)
		scanf("%lf %lf",&gop[i][0],&gop[i][1]);
	for(i=0;i<m;i++)
		scanf("%lf %lf",&hol[i][0],&hol[i][1]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			x=gop[i][0]-hol[j][0];
			y=gop[i][1]-hol[j][1];
			dis=sqrt(x*x+y*y);
			if(d>dis||(dis-d)<=1e-10)
			{
				graph[j][edg[j]++]=i;			
			}
		}
	}	
}

bool bpm( int u )
{
	int i,v;
    for( i = 0; i < edg[u]; i++ ) 
	{
		v=graph[u][i];
		if( seen[v] ) continue;
		seen[v] = true;
			
		if( matchR[v] < 0 || bpm( matchR[v] ) )
		{
			matchL[u] = v;
			matchR[v] = u;
			return true;
		}
	}
    return false;
}

int main()
{
	//freopen("bpm.txt","r",stdin);
	long e,i,s,d;
    // Read input and populate graph[][]
    // Set m, n
	while(4==scanf("%d %d %ld %ld",&n,&m,&s,&d))
	{
		
		e=(n>m)?n:m;
		memset( edg, 0, sizeof(int ) *e );
		input(s*d);
		
		memset( matchL, -1, sizeof( int ) *m );
		memset( matchR, -1, sizeof( int ) *n );
		int cnt = 0;
		for( i = 0; i < m; i++ )
		{
			memset( seen, 0, sizeof( seen ) );
			if( bpm( i ) ) cnt++;
		}
		printf("%d\n",n-cnt);
	}

    // cnt contains the number of happy pigeons
    // matchL[i] contains the hole of pigeon i or -1 if pigeon i is unhappy
    // matchR[j] contains the pigeon in hole j or -1 if hole j is empty

    return 0;
}