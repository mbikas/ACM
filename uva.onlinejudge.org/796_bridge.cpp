#include <stdio.h>
#include <string.h>

#define N 1005
#define M N*N
typedef struct edge
{
	int st, end;
};
edge tot[M];
int t[N][N], par[M], rank[M], visit[N], n, ed, out[M], pri[M];
bool all[N][N];

int min(int a, int b)
{
	if(b < a) return b;
	return a;
}
int findset(int key);
void union_(int u, int v);
int dfs(int x, int dep, int px);

int main()
{
	//freopen("br.txt", "r", stdin);
	int i, j, nn, u, v, r, cnt;
	while( scanf("%d",&n) == 1)
	{
		memset(visit, -1, sizeof(visit));
		memset(all, false, sizeof(all));

		ed = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d (%d)",&u,&nn);
			for(j=0; j<nn; j++)
			{		
				scanf("%d",&v);
				if(all[u][v]) continue;
				all[u][v] = all[v][u] = true;
				if(u < v)
				{
					tot[ed].st = u;
					tot[ed].end = v;
				}
				else
				{
					tot[ed].st = v;
					tot[ed].end = u;	
				} 
				t[u][v] = t[v][u] = ed;
				ed++;
			}
		}
		for(i=0; i<ed; i++)
		{
			par[i] = i;
			rank[i] = 0;
		}
		for(i=0; i<n; i++)
			if(visit[i] < 0) r = dfs(i,1,-1);
		cnt = 0;
		memset(out, 0, sizeof(out));
		for(i=0; i<ed; i++)
		{
			r = findset(i);
			out[r]++;
		}
		for(i=0; i<ed; i++)
			if(out[i] == 1)
			{
				pri[cnt] = i;
				cnt++;
			}
		printf("%d critical links\n", cnt);
		for(i=0; i<cnt; i++) 
			printf("%d - %d\n", tot[pri[i]].st, tot[pri[i]].end);
		printf("\n");
	}
	return 0;
}
int dfs(int x, int dep, int px)
{
	int rval, i, k;
	if( visit[x] >= 0) return visit[x];
	rval = dep;
	visit[x] = dep;
	for(i=0; i<n; i++)
	{
		if(all[x][i] )
		{
			k = dfs(i, dep+1, x);
			if(k < dep)
			{
				rval = min(rval, k);
				if(px >= 0 && t[x][i] != t[x][px])
					union_(t[x][i], t[x][px]);

			}
		}
	}
	return rval;
}
int findset(int key)
{
	if(key != par[key]) par[key] = findset(par[key]);
	return par[key];
}
void union_(int a, int b)
{
	int u, v;
	u = findset(a);
	v = findset(b);

	if( rank[u] > rank[v]) par[v] = u;
	else
	{
		par[u] = v;
		if(rank[u] == rank[v]) rank[v]++;		
	}
}
