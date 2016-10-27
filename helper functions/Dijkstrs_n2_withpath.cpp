#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 105
#define Inf 21456600

long parent[sz],flag[sz],cost[sz],graph[sz][sz];
void dijkstra(long start,long vertex);

void print(long i)
{
	if(parent[i]==-1)
		printf("%ld",i);
	else
	{
		print(parent[i]);
		printf(" %ld",i);
	}
}

int main()
{
	long i,j,test,vertex,edges,start,end,source,des,val;
	
	
	
	scanf("%ld",&test);
	
	while(test--)
	{
		scanf("%ld %ld %ld %ld",&vertex,&edges,&start,&end);
		
		for(i=0;i<vertex;i++)
		{
			for(j=0;j<vertex;j++)
			{
				graph[i][j]=Inf;				
			}
		}
		
		for(i=0;i<edges;i++)
		{
			scanf("%ld %ld %ld",&source,&des,&val);
			
			graph[source][des]=val;
			graph[des][source]=val;
			
			//p[source][des]=cost;
			//p[des][source]=cost;			
		}
		
		
		dijkstra(start,vertex);
		for(i=0;i<vertex;i++)
		{
			printf("From %ld to %ld, cost is %ld\npath is: ",start,i,cost[i]);
			print(i);
			printf("\n");
		}
		
	}
	
	return 0;
}

//parent indicate the path matrix
//cost[] indicate the shortest path cost from start node
//p[][] used for the gra 
void dijkstra(long start,long vertex)
{
	long i,j,temp,v;
	
	for(i=0;i<vertex;i++)
	{
		parent[i]=-1;
		cost[i]=Inf;
		flag[i]=0;
	}
	
	v=start;
	cost[v]=0;
	while(flag[v]==0)
	{
		flag[v]=1;
		for(i=0;i<vertex;i++)
		{
			if(graph[v][i]<Inf && flag[i]==0)
			{
				if(cost[i]>cost[v]+graph[v][i])
				{
					cost[i]=cost[v]+graph[v][i];
					parent[i]=v;
				}
			}
		}
		temp=Inf;
		for(i=0;i<vertex;i++)
		{
			if(temp>cost[i] && flag[i]==0)
			{
				temp=cost[i];
				v=i;
			}
		}
	}
	
}