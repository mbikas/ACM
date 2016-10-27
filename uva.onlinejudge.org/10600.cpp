#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MIN 1000000
#define SIZE 105
#define SIZE2 SIZE*SIZE

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

int main()
{
	long n,ver,i,j,total1,total2,test,min,temp,pre_u,pre_v,pre_w,first;
	Edge first_mst[SIZE2];
	scanf("%ld",&test);
	while(test--)
	{
	

		scanf("%ld %ld",&ver,&n);
		input(n);
		min=MIN;
		qsort(edge_in,n,sizeof(Edge),comp);
		Kruskal(ver,n);
		total1=total2=0;
		for(i=0;i<edge_m;i++)
		{
			first_mst[i].u = edge_out[i].u;
			first_mst[i].v = edge_out[i].v;
			first_mst[i].w = edge_out[i].w;

			//printf("%ld %ld %ld\n",edge_out[i].u,edge_out[i].v,edge_out[i].w);
			total1+=edge_out[i].w;
		}
		//printf("Total Weight = %ld\n\n",total1);
	
		
		first=1;
		pre_u=pre_v=0;
		temp=edge_m;
		for(i=0;i<temp;i++)
		{
			if(first!=1)
			{
				for(j=0;j<n;j++)
				{
					if(edge_in[j].u==pre_u && edge_in[j].v==pre_v)
					{
						edge_in[j].w = pre_w;
						break;
					}			
				}
			}
			else first=2;

			for(j=0;j<n;j++)
			{
				if(edge_in[j].u==first_mst[i].u && edge_in[j].v==first_mst[i].v)
				{
					pre_u=first_mst[i].u;
					pre_v =first_mst[i].v;
					pre_w=first_mst[i].w;
					edge_in[j].w=MIN;
					break;
				}			
			}
			

			qsort(edge_in,n,sizeof(Edge),comp);

			//for(j=0;j<n;j++)printf("%ld %ld %ld\n",edge_in[j].u,edge_in[j].v,edge_in[j].w);
			Kruskal(ver,n);
			total2=0;
			for(j=0;j<edge_m;j++)
			{
				total2+=edge_out[j].w;
			}
			//printf("%ld\n",total2);
			if(total2<min)min=total2;			
		}

		//printf("Second Cost=%d\n",min);
		printf("%ld %ld\n",total1,min);
		


	}

	return 0;
}

