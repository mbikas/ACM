#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<math.h>

#define SIZE 100
#define SIZE2 SIZE*SIZE/2

typedef struct
{
	long u,v,w;
}Edge;

typedef struct
{
	long path[SIZE],n;
}Graph;

Edge edge_in[SIZE2],edge_out[SIZE2];
Graph g[SIZE];
long edge_n,edge_m;
bool flag[SIZE],flag_dfs[SIZE],mat[SIZE][SIZE];

void input(long n)
{
	long i,u,v,w;
	edge_n=0;
	for(i=0;i<n;i++)
	{
		scanf("%ld %ld %ld",&u,&v,&w);
		edge_in[edge_n].u=u;
		edge_in[edge_n].v=v;
		edge_in[edge_n].w=w;
		edge_n++;
	}	
}

bool Dfs(long s,long e)
{
	if(s==e)
		return 1;
	long i;
	//count++;
	for(i=0;i<g[s].n;i++)
	{
		if(flag_dfs[g[s].path[i]]==0)
		{
			flag_dfs[g[s].path[i]]=1;
			if(Dfs(g[s].path[i],e)==1)
				return 1;
		}
	}
	return 0;
}

void Kruskal(long ver,long n)
{
	long i,u,v,take;
	edge_m=0;
	for(i=1;i<=ver;i++)
	{
		memset(mat[i]+1,0,sizeof(bool)*ver);
		g[i].n=0;
		mat[i][i]=1;
	}
	take=0; //how many edges is taken
	for(i=0;i<n&&take<(ver-1);i++)
	{
		u=edge_in[i].u;
		v=edge_in[i].v;
		if(mat[u][v]==0)
		{
			mat[u][v]=1;
			mat[v][u]=1;
			if(flag[u]&&flag[v])
			{
				//u and v is taken but now we must check if we take u,v edge then is it a cycle
				memset(flag_dfs+1,0,sizeof(bool)*ver);
				if(Dfs(u,v)==0)
				{
					//That means there is no cycle
					edge_out[edge_m++]=edge_in[i];
					g[u].path[g[u].n++]=v;
					g[v].path[g[v].n++]=u;
					take++;
				}
			}
			else
			{
				edge_out[edge_m++]=edge_in[i];
				g[u].path[g[u].n++]=v;
				g[v].path[g[v].n++]=u;
				flag[u]=1;
				flag[v]=1;
				take++;
			}
		}
	}
}

int comp(const void *A,const void *B)
{
	Edge *a =(Edge*)A;
	Edge *b =(Edge*)B;
	return a->w-b->w;
}

void main()
{
	long n,ver,i,total;
	while(2==scanf("%ld %ld",&ver,&n)&&(ver||n))
	{
		input(n);
		qsort(edge_in,n,sizeof(Edge),comp);
		Kruskal(ver,n);
		total=0;
		for(i=0;i<edge_m;i++)
		{
			printf("%ld %ld %ld\n",edge_out[i].u,edge_out[i].v,edge_out[i].w);
			total+=edge_out[i].w;
		}
		printf("Total Weight = %ld\n\n",total);
	}
}

