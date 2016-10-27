#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

#define city_sz 100
#define sz 30
#define NIL 0
#define INF 32000

char color[sz];

int par[sz];
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
	{
		printf("%c",(start-1)+'A');
	}
	
	else if(par[end]==NIL)
	{
		//printf("\nNO PATH EXISTS.\n");
	}
	
	else
    {
		printPath(start,par[end]);
		printf("%c",(end-1)+'A');
    }
}


void BFS(int start)
{
	int i,adj,Unode,node;
	
	for(i=1;i<sz;i++)
	{
        color[i]='w';
		par[i]=NIL;
	}
	
	/*initializing the starting node*/
	par[start]=NIL;

	/*each node that are to be processed colored gray*/
	color[start]='g';
	enqueue(start);
	
	/*dequeue() returns +ve value (node) when nonempty
	it returns -ve value when the que is empty*/
	
	while((Unode=dequeue())>=0)
	{
        for(adj=1;adj<graph[Unode][0];adj++)
		{
			node = graph[Unode][adj];
			if(color[node]=='w')
			{				
				par[node]=Unode;
				color[node]='g';
				enqueue(node);
				
			}
		}		
		/*after the end processing Unode is colored black*/
		color[Unode]='b';        	
	}
}

void main()
{
	int i,start,end,edge,cases,query;
	char source[city_sz],des[city_sz];
	bool f = false;
	
	scanf("%d",&cases);
	
	while(cases--)
	{
		if(f)printf("\n");
		else f=true;
		scanf("%d %d",&edge,&query);		
		head = tail=0;
		
		for(i=0;i<sz;i++)graph[i][0]=1;
		
		for(i=1;i<=edge;i++)
		{
			scanf(" %s %s",source,des);
			start = (source[0] - 'A')+1;
			end = (des[0] - 'A')+1;
			graph[start][graph[start][0]++]=end;
			graph[end][graph[end][0]++] = start;			
		}
		
	
		while(query--)
		{
			scanf(" %s %s",source,des);
			start = (source[0]-'A')+1;
			end = (des[0]-'A')+1;

			BFS(start);		
			printPath(start,end);
			printf("\n");			
		}
	}
}
