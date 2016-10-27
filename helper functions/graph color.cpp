#include<stdio.h>
#include<string.h>

#define node 100

int graph[node+1][node+1],degree[node+1],co_ver[node+1],x[node+1];
int min_col,col,ver,edge,fcol;

int color_it(int vertex);
void init();

void main()
{
	int i,j,k;
	while(2==scanf("%d %d",&ver,&edge))
	{
		init();
		for(i=0;i<edge;i++)
		{
			scanf("%d %d",&j,&k);
			degree[j]++;
			degree[k]++;
			graph[j][degree[j]]=k;
			graph[k][degree[k]]=j;
		}
		min_col=0;
		for(i=1;i<=ver;i++)
		{
			if(min_col<degree[i])
				min_col=degree[i];
		}
		color_it(2);
		printf("%d\n",min_col);
	}
}

void init()
{
	memset(degree,0,sizeof(int)*(ver+1));
	col=1;
	memset(x,0,sizeof(int)*(ver+1));
	x[1]=1;
}

int color_it(int vertex){
	int i;
	if(vertex>ver)
	{
		for(i=1;i<=ver;i++)
			co_ver[i]=x[i];
		min_col=col;
		return 1;
	}
	int j;
	for(i=1;i<=min_col;i++)
	{
		for(j=1;j<=degree[vertex];j++)
		{
			if(x[graph[vertex][j]]==i)
				break;
		}
		if(j>degree[vertex])
		{
			x[vertex]=i;
			if(i>col)
			{
				col=i;
				fcol=vertex;
			}
			if(color_it(vertex+1))
			{
				if(vertex==fcol)
					return 0;
				else
					return 1;
			}
		}
	}
	return 0;
}

