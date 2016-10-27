/*BFS code by chormen*/

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

#define sz 10
#define NIL 0
#define INF 1000000

char color[sz];

long mat[sz][sz];
long par[sz],dist[sz];

long que[sz*sz],head=0,tail=0;
long vert,edge,start,end,Unode;

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

void printPath(long Vnode)
{
	
	if(start==Vnode)
		printf(" %ld",start);
	
	else if(par[Vnode]==NIL)
		printf("\nNO PATH EXISTS.\n");
	
	else
    {
		printPath(par[Vnode]);
		printf(" --> %ld",Vnode);
    }
}


void BFS()
{
	long adj;
	
	for(Unode=1;Unode<=vert;Unode++)
	{
        color[Unode]='w';
		dist[Unode]=INF;
        par[Unode]=NIL;
	}

	par[start]=NIL;
	dist[start]=0;

	color[start]='g';
	enqueue(start);

	while((Unode=dequeue())>=0)
	{
        
		for(adj=1;adj<=vert;adj++)
		{
			
			if(mat[Unode][adj]==1)
			{
				
				if(color[adj]=='w')
				{
                    
					par[adj]=Unode;
					color[adj]='g';
					dist[adj]=dist[Unode]+1;
					
                    enqueue(adj);
				}
			}
		}

		color[Unode]='b';        	
	}
}

void main()
{
	long i;

	printf("give the number of vertices and edges:\n");
	
	printf("vertices = ");
	scanf("%ld",&vert);
	
	printf("edges = ");
	scanf("%ld",&edge);

	printf("\nGive start point & end point of each edges:\n");

	for(i=1;i<=edge;i++)
	{
		printf("Edge %ld :",i);
		scanf("%ld%ld",&start,&end);
        
		mat[start][end]=1;  
	}

	printf("\nEnter 0 for start or end to terminate.");
	
	do
	{
		printf("\nGive the starting and ending vertex to find the distance:\n");
		printf("Starting vertex : ");
		scanf("%ld",&start);
		printf("Ending vertex : ");
		scanf("%ld",&end);

		if(start==0 || end==0) break;

		BFS();

		printf("\nThe distance from %ld to %ld is = %ld\n",start,end,dist[end]);

		printf("\nThe path is shown below :\n");

		printPath(end);
		printf("\n");

	}while(1);
}
