#include<stdio.h>
#include<string.h>
#define MAX 102

int ans[MAX];
int degree[MAX],graph[MAX][MAX];
char color[MAX];
void backtrack(int a[],int k,int remain);
void con_candiadate(int a[],int k,int c[],int *ncan);
int max,node,iteration;
bool finished = false;

void main()
{
	int test,a[MAX],i,edge,source,des;

	scanf("%d",&test);
	while(test--)
	{
		//memset(path,false,sizeof(path));
		memset(a,0,sizeof(a));
		memset(color,'w',sizeof(color));
		memset(degree,0,sizeof(degree));
		memset(graph,0,sizeof(graph));
			
		scanf("%d %d",&node,&edge);

		for(i=1;i<=edge;i++)
		{
			scanf("%d %d",&source,&des);
			graph[source][++degree[source]] = des;
			graph[des][++degree[des]] = source;
		}

		finished = false;
		iteration=0;
		max = 0;
		backtrack(a,0,node);
		
		printf("%d\n",max);
		for(i=1;i<max;i++)printf("%d ",ans[i]);
		printf("%d\n",ans[max]);	
	
	}
}

void backtrack(int a[],int k,int remain)
{
	int i,ncan,c[MAX],j,taken;
	int temp[MAX],tmp;

	//if(k==n)return;

	if(remain==0)
	{
		if(k>max)
		{	max = k;
		    for(j=1;j<=k;j++)ans[j] = a[j];
			iteration++;
			if(iteration==100)
				finished = true;
		}
	}

	else
	{
		k++;
		con_candiadate(a,k,c,&ncan);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];
			tmp=1;
			taken = 0;

			for(j=1;j<=degree[c[i]];j++)
			{
				if(color[ graph[c[i]][j] ] =='w')
				{
					taken++;
					temp[tmp++] = graph[c[i]][j];
					color[graph[c[i]][j]]='g';				
				}			
			}
			if(color[c[i]]=='w')
			{
				temp[tmp++] = c[i];
				taken++;			
			}
			color[c[i]]='b';
			remain = remain - taken;

			backtrack(a,k,remain);
			for(j=1;j<tmp;j++)color[temp[j]]='w';
			remain +=taken;
			if(finished)return;					
		}
	
	
	}
}

void con_candiadate(int a[],int k,int c[],int *ncan)
{
	int i;
	*ncan = 0;
	for(i=1;i<=node;i++)
	{
		if(color[i]=='w')
		c[(*ncan)++] = i;
	}
}
