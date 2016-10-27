#include<stdio.h>
#include<string.h>
#define MAX 102

int graph[MAX][MAX],degree[MAX],length[MAX];
int max,destination,start;
void backtrack(int a[],int k,int n);
void con_candidatee(int a[],int k,int c[],int *ncan);

void main()
{
	int nodes,s,d,a[MAX];
	long cases=1;
	
	while(scanf("%d",&nodes)==1 && nodes)
	{

		memset(a,0,sizeof(a));
		memset(graph,0,sizeof(graph));
		memset(degree,0,sizeof(degree));
		memset(length,0,sizeof(length));

		scanf("%d",&start);

		while(scanf("%d %d",&s,&d)==2 && (s||d))
		{
			graph[s][++degree[s]] = d;
			//graph[d][++degree[d]] = s;		
		}

		max = 0;
		destination = nodes+1; 
		a[1] = start;
		backtrack(a,1,nodes);
		
		if(max == 0) destination = start;
		printf("Case %ld: The longest path from %d has length %d, finishing at %d.\n",cases++,start,max,destination);
		
	
	}
}


void backtrack(int a[],int k,int n)
{
		int c[MAX],i,ncan;

		if(k==n)return;	
		else{
		k++;	
		con_candidatee(a,k,c,&ncan);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];
			backtrack(a,k,n);				
		}
		}
	
	
}

void con_candidatee(int a[],int k,int c[],int *ncan)
{
	int i;
	*ncan = 0;

	bool flag=false;

	if( k < length[a[k-1]])return;

	for(i=1;i<=degree[a[k-1]];i++)
	{
		if( k-1 >= length[ graph[a[k-1]][i] ])
		{
			c[(*ncan)++] = graph[a[k-1]][i];
			length[ graph[a[k-1]][i] ] = k-1;
			flag = true;

			if(k-1>=max)
			{	if(k-1==max)
				{	if(graph[a[k-1]][i]<destination)
						destination = graph[a[k-1]][i];
				}
				else destination = graph[a[k-1]][i];
				max = k-1;
			}
		}
	}	
}

