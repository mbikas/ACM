//11396
#include<stdio.h>
#include<string.h>
#define sz 505

int graph[sz][sz];
char color[sz];
bool finished = false;

void con_candidate(int a[],int k,int c[],int *ncan);
void dfs(int a[],int k);

int main()
{
	int nodes,edges,source,des,i,j,a[sz];

	while(scanf("%d",&nodes)==1 && nodes)
	{

		for(i=0;i<=nodes;i++)graph[i][0]=1;
		memset(color,'w',sizeof(color));

		
		while(scanf("%d %d",&source,&des)==2)
		{
			if(source==0 && des==0)break;
			graph[source][graph[source][0]++]=des;
			graph[des][graph[des][0]++]=source;
			j = source;
		
		}

		color[j]='b';
		a[1]=j;
		finished = false;
		dfs(a,1);	
		if(finished)
			printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}

void dfs(int a[],int k)
{
	int i,ncan,c[sz];

	k++;
	con_candidate(a,k,c,&ncan);

	for(i=0;i<ncan;i++)
	{
		a[k] = c[i];
		dfs(a,k);
		if(finished)return;
	}
}

void con_candidate(int a[],int k,int c[],int *ncan)
{
	int i;

	*ncan=0;
	
	for(i=1;i<graph[a[k-1]][0];i++)
	{
		if(color[a[k-1]]=='b')
		{
			if(color[graph[a[k-1]][i] ] == 'b')
			{
				finished = true;
				return;
			}
			if(color[graph[a[k-1]][i] ] == 'w')
			{
				c[(*ncan)++] = graph[a[k-1]][i];
				color[graph[a[k-1]][i] ] = 'g';	
			}
		}

		if(color[a[k-1]]=='g')
		{
			if(color[graph[a[k-1]][i] ] == 'g')
			{
				finished = true;
				return;
			}
			if(color[graph[a[k-1]][i] ] == 'w'){
				c[(*ncan)++] = graph[a[k-1]][i];
				color[graph[a[k-1]][i] ] = 'b';
			}
		}
	
	}
}