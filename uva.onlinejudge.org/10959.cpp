/*10959*/

#include<stdio.h>


#define sz 1005
#define NIL 0
#define INF 1000000

char color[sz];
long dist[sz],graph[sz][sz];
long que[sz*sz],head=0,tail=0;


void enqueue(long data)
{
	que[tail]=data;
    tail=tail+1;
}

long dequeue()
{
	if(head==tail)
        return -1;
	
	head=head+1;
    return que[head-1];
}


void BFS(long start,long vert)
{
	long adj,Unode,node;
	
	for(Unode=1;Unode<=vert;Unode++)
	{
        color[Unode]='w';
		dist[Unode]=INF;        
	}

	dist[start]=0;

	color[start]='g';
	enqueue(start);

	while((Unode=dequeue())>=0)
	{
        for(adj=1;adj<graph[Unode][0];adj++)
		{
			node = graph[Unode][adj];
			if(color[node]=='w')
			{				
				color[node]='g';
				dist[node]=dist[Unode]+1;
				enqueue(node);
				
			}
		}		
		
		color[Unode]='b';        	
	}	
}

void main()
{
	long i,edges,nodes,source,des,cases;
	bool f=false;

	scanf("%ld",&cases);

	while(cases--)
	{
		if(f)printf("\n");
		else f = true;
		
		scanf("%ld %ld",&nodes,&edges);
		
		for(i=0;i<=nodes;i++)graph[i][0]=1;


		for(i=0;i<edges;i++)
		{
			scanf("%ld %ld",&source,&des);			
			graph[source][graph[source][0]++] = des;
			graph[des][graph[des][0]++] = source;
		}

		 BFS(0,nodes);

		 for(i=1;i<nodes;i++)
			 printf("%ld\n",dist[i]);


	
	
	}
	
}

