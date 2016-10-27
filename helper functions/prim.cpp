#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<math.h>

#define SIZE 100
#define SIZE2 SIZE*SIZE/2
#define MAXINT (1<<(sizeof(long)*8-1))-1

typedef struct
{
	long u,v,w;
}Edge;

typedef struct
{
	long path[SIZE],weight[SIZE],n;
}Graph;

Graph g[SIZE];
long parent[SIZE],mat[SIZE][SIZE];

void input(long n)
{
	long i,u,v,w;
	for(i=0;i<n;i++)
	{
		scanf("%ld %ld %ld",&u,&v,&w);
		mat[u][v]=w;
		mat[v][u]=w;
		g[u].path[g[u].n]=v;
		g[u].weight[g[u].n]=w;
		g[u].n++;
		g[v].path[g[v].n]=u;
		g[v].weight[g[v].n]=w;
		g[v].n++;
	}	
}

void Prim(long vert,long start)
{
	long i;
	bool intree[SIZE];
	long distance[SIZE];
	long v,w,weight,dist;
	for(i=1;i<=vert;i++)
	{
		intree[i]=false;
		distance[i]=MAXINT;
		parent[i]=-1;
	}
	distance[start]=0;
	v=start;
	while(intree[v]==false)
	{
		intree[v]=true;
		for(i=0;i<g[v].n;i++)
		{
			w=g[v].path[i];
			weight=g[v].weight[i];
			if(distance[w]>weight&&intree[w]==false)
			{
				distance[w]=weight;
				parent[w]=v;
			}
		}
		v=1;
		dist=MAXINT;
		for(i=2;i<=vert;i++)
		{
			if(intree[i]==false&&dist>distance[i])
			{
				dist=distance[i];
				v=i;
			}
		}
	}
}

void main()
{
	freopen("input.txt","r",stdin);
	long n,ver,i,cost;
	while(2==scanf("%ld %ld",&ver,&n)&&(ver||n))
	{
		for(i=1;i<=ver;i++)
			g[i].n=0;
		input(n);
		Prim(ver,1);
		cost=0;
		for(i=1;i<=ver;i++)
		{
			if(parent[i]!=-1)
			{
				printf("%d %d %d\n",parent[i],i,mat[parent[i]][i]);
				cost+=mat[parent[i]][i];
			}
			
		}
		printf("Total Weight = %ld\n\n",cost);
	}
}

