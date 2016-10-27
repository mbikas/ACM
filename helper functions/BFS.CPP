#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

#define sz 100
#define NIL 0
#define INF 32000

char color[sz];

int par[sz],dist[sz];
int graph[sz][sz];

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

void printPath(int start,int end)
{
	
	if(start==end)
		printf(" %ld",start);
	
	else if(par[end]==NIL)
		printf("\nNO PATH EXISTS.\n");
	
	else
    {
		printPath(start,par[end]);
		printf(" --> %ld",end);
    }
}


void BFS(int start)
{
	int i,adj,Unode,node;
	
	for(i=1;i<sz;i++)
	{
        color[i]='w';
		dist[i]=INF;
        par[i]=NIL;
	}
	
	/*initializing the starting node*/
	par[start]=NIL;
	dist[start]=0;
	
	/*each node that are to be processed colored gray*/
	color[start]='g';
	enqueue(start);
	
	/*dequeue() returns +ve value (node) when nonempty
	it returns -ve value when the que is empty*/
	
	while((Unode=dequeue())>=0)
	{
        for(adj=1;adj<=graph[Unode][0];adj++)
		{
			node = graph[Unode][adj];
			if(color[node]=='w')
			{
				
				par[node]=Unode;
				color[node]='g';
				dist[node]=dist[Unode]+1;					
				enqueue(node);
				
			}
		}		
		/*after the end processing Unode is colored black*/
		color[Unode]='b';        	
	}
}

void main()
{
	int i,start,end,edge,vert;
	
	
	
	while( scanf("%d",&edge)==1 && edge)
	{
		head = tail=0;
		//vert = 0;
		
		for(i=0;i<sz;i++)graph[i][0]=1;
		
		
		for(i=1;i<=edge;i++)
		{
			scanf("%d %d",&start,&end);
			graph[start][graph[start][0]++]=end;
		//	if(start>vert)vert = start;
		//	if(end>vert)vert = end;
		}

		
		while( scanf("%ld %ld",&start,&end)==2)
		{
			if(start==0 || end==0) break;
			
			//printf("Bikas");
			
			BFS(start);
			
			printf("\nThe distance from %ld to %ld is = %ld\n",start,end,dist[end]);
			
			printf("\nThe path is shown below :\n");
			
			printPath(start,end);
			printf("\n");
			
		}
	}
}
