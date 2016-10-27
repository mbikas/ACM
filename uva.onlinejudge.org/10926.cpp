/*10926*/

#include<stdio.h>


#define sz 1005
#define NIL 0
#define INF 1000000

char color[sz];
int graph[sz][sz];
int que[sz*sz],head=0,tail=0,m=0;


void enqueue(int data)
{
	que[tail]=data;
    tail=tail+1;
}

int dequeue()
{
	if(head==tail)
        return -1;
	
	head=head+1;
    return que[head-1];
}


void BFS(int start,int vert)
{
	int adj,Unode,node;
	bool reach[sz];

	m=0;

	
	
	for(Unode=1;Unode<=vert;Unode++)
	{
        color[Unode]='w';
		reach[Unode] = false;
	}

	color[start]='g';
	enqueue(start);

	while((Unode=dequeue())>=0)
	{
        for(adj=1;adj<graph[Unode][0];adj++)
		{
			node = graph[Unode][adj];
			if(color[node]=='w')
			{		
				reach[node]=true;
				color[node]='g';
				enqueue(node);
				
			}
		}		
		
		color[Unode]='b';        	
	}	

	for(adj=1;adj<=vert;adj++)
	{
		if(reach[adj])m++;	
	}
}

void main()
{
	int i,nodes,des,t,j,max,ans;
	


	while(scanf("%d",&nodes)==1 && nodes)
	{
		
		
		
		for(i=0;i<=nodes;i++)graph[i][0]=1;


		for(i=1;i<=nodes;i++)
		{
			scanf("%d",&t);
			for(j=0;j<t;j++)
			{
				scanf("%d",&des);
				graph[i][graph[i][0]++] = des;
			}		
		}

		max=0;
		for(i=1;i<=nodes;i++)
		{
			m = 0;
			BFS(i,nodes);
			if(m>max){
				max = m;
				ans = i;
			}

		
		} 

		printf("%d\n",ans);


	
	
	}
	
}

