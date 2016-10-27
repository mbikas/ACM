#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define sz 15
#define INF 100000
#define NIL 0

char color[sz];
int mat[sz][sz],par[sz],dist[sz];
int vertices,edges,start,end,Unode;
int head=0,tail=0;
int que[sz*sz];

void enqueue(int data);
long dequeue();
void BFS();
void printpath(int Vnode);


void  main()
{
	int i;
	while(scanf("%d",&vertices)==1)
	{
		scanf("%d",&edges);

		for(i=0;i<edges;i++)
		{
			scanf("%d %d",&start,&end);
			mat[start][end] = 1;	
		}

		scanf("%d %d",&start,&end);
	
			BFS();

			printf("The distance = %d\n",dist[end]);
			printf("Path = ");
			printpath(end);
			printf("\n");
	

	}
}


void enqueue(int data)
{
	que[tail]=data;
	tail = tail + 1;
}
long dequeue()
{
	if(head==tail)return -1;

	head= head +1;
	return que[head-1];
}

void BFS()
{
	long adj;

	for(Unode;Unode<=vertices;Unode++)
	{
		color[Unode] = 'w' ;
		dist[Unode]  = INF ;
		par[Unode]  =  NIL ;	
	}

	par[start]=NIL;
	dist[start]=0;

	color[start]='g';	
	enqueue(start);

	while( (Unode = dequeue()) >=0)
	{
		for(adj = 1;adj<=vertices;adj++)
		{
			if(mat[Unode][adj]==1)
			{
				if(color[adj]=='w')
				{
					color[adj] = 'g';
					par[adj] = Unode;
					dist[adj] = dist[Unode]+1;
					
					enqueue(adj);			
				}			
			}		
		}
		color[Unode]='b';	
	}

}


void printpath(int Vnode)//Vnode represent end node
{
	if(start == Vnode)
		printf("%d",start);
	else if(par[Vnode]==NIL)
		printf("No Such Path Exists\n");	
	else
	{
		printpath(par[Vnode]);
		printf("-->%d",Vnode);
	
	}

}