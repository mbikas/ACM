#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 105
#define Inf 1e99

char names[sz][1005];
int path[sz],len;
int parent[sz],flag[sz];
void dijkstra(int start,int vertex);
double cost[sz],graph[sz][sz],weight[sz];

void print(int i)
{
	if(parent[i]==-1)
	{
		//printf("%d",i);
		path[len++]=i;
	}
	else
	{
		print(parent[i]);
		//printf(" %d",i);
		path[len++]=i;
	}
}

int main()
{
	
	

	int node1,node2,cases=1,passenger,query,qr=1,j;
	int  start,end,i,edges,test,vertex;
	double total,stationCost;
	char src[1000],des[1000];
	bool f=false;
	double val;

	
	
	scanf("%d",&test);
	
	while(test--)
	{

		if(f)printf("\n");
		else f=true;
	
		printf("Map #%d\n",cases++);
		scanf("%d",&vertex);

		for(i=0;i<=vertex;i++)
		{
			for(j=0;j<=vertex;j++)
			{
				graph[i][j]=Inf;				
			}
		}
		

		

		for(i=1;i<=vertex;i++)
		{
			scanf(" %s %lf",names[i],&weight[i]);
			graph[i][0]=1;
		}
		scanf("%d",&edges);
		for(i=1;i<=edges;i++)
		{
			scanf(" %s %s %lf",src,des,&val);
			for(j=1;j<=vertex;j++)
			{
				if(strcmp(names[j],src)==0)node1=j;
				else if(strcmp(names[j],des)==0)node2=j;
			}
			val = (double)val*2.0;

			graph[node1][node2]=val;
			graph[node2][node1]=val;
			
		}
		scanf("%d",&query);

		qr=1;
		while(query--)
		{
			scanf(" %s %s %d",src,des,&passenger);
			for(i=1;i<=vertex;i++)
			{
				if(strcmp(names[i],src)==0)start=i;
				else if(strcmp(names[i],des)==0)end=i;
				
			}
			dijkstra(start,vertex);
			total = cost[end];
			len=0;
			print(end);
			//printf("\n");
			//findPath(start,end);
			stationCost=0.0;
			for(i=0;i<len;i++)
				stationCost+=weight[path[i]];
			
			total += stationCost;
			total += total*0.10;

			total = (double)(total/(double)passenger);

			
			printf("Query #%d\n",qr++);
			printf("%s",names[path[0]]);
			for(i=1;i<len;i++)
				printf(" %s",names[path[i]]);
		
			printf("\nEach passenger has to pay : %.2lf taka\n",total);

		}

		
		
	}
	
	return 0;
}

//parent indicate the path matrix
//cost[] indicate the shortest path cost from start node
//p[][] used for the gra 
void dijkstra(int start,int vertex)
{
	int i,v;
	double temp;
	
	for(i=0;i<=vertex;i++)
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
		for(i=1;i<=vertex;i++)
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
		for(i=1;i<=vertex;i++)
		{
			if(temp>cost[i] && flag[i]==0)
			{
				temp=cost[i];
				v=i;
			}
		}
	}
	
}