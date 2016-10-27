//10160 Servicing stations
// solved by bikas cse sust

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 36

typedef struct{
	int node;
	int edges;
}TREE;
TREE tree[MAX];

int graph[MAX][MAX];
int degree[MAX],count,min;
char dfs_color[MAX],color[MAX];
void dfs(int start,int n);
void backtrack(int a[],int k,int remain);
void con_candidate(int a[],int k,int remain,int c[],int *ncan);
int comp(void const *A, void const *B);

void main()
{
	//freopen("10160.in","r",stdin);


	int i,m,n,a[MAX],ans,s,d;

	while( scanf("%d %d",&n,&m)==2 && (m||n) )
	{
		memset(a,0,sizeof(a));
		memset(degree,0,sizeof(degree));
		memset(dfs_color,'w',sizeof(dfs_color) );
		memset(color,'w',sizeof(color));
		


		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&s,&d);
			graph[s][++degree[s]] = d;
			graph[d][++degree[d]] = s;		
		}

		ans = 0;

		//the graph can be forset
		for(i=1;i<=n;i++)
		{
			if( dfs_color[i]=='w')
			{
				count = 1;
				dfs(i,n);
				qsort(tree+1,count-1,sizeof(TREE),comp);
				
				min = count-1;
				backtrack(a,0,count-1);
				ans +=min;			
			}	
		}
		printf("%d\n",ans);
	
	}//end of while
}//end of main

void dfs(int start,int n)
{
	int i;
	tree[count].node  = start;
	tree[count].edges = degree[start];
	count++;
	dfs_color[start] = 'g';
	for(i=1;i<=degree[start];i++)
	{
		if( dfs_color[ graph[start][i] ] == 'w' )
		dfs(graph[start][i],n);		
	}
}

void backtrack(int a[],int k,int remain)
{
	int i,j,c[MAX],ncan;
	int temp[MAX],tmp,taken;

	if(k==min)return;
	
	//if all the nodes are taken this is now the least
	if(remain==0)min = k;
	else
	{
		k++;
		con_candidate(a,k,remain,c,&ncan);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];

			taken = 0;
			tmp = 1;

			//coloring all the adjacent of c[i] as 'g'   
			for(j=1;j<=degree[c[i]];j++)
			{
				if(color[ graph[c[i]][j] ]=='w')
				{
					taken++;
					temp[tmp++] = graph[c[i]][j];
					color[graph[c[i]][j]] = 'g';				
				}		
			}
			if(color[c[i]]=='w')
			{
				taken++;
				temp[tmp++] = c[i];			
			}
			color[c[i]] = 'b';
			remain = remain - taken;

			backtrack(a,k,remain);

			//releasing the color after each path choice
			for(j=1;j<tmp;j++)
				color[temp[j]]='w';	
			remain += taken;
		}	
	}
}


void con_candidate(int a[],int k,int remain,int c[],int *ncan)
{
	int i,j;
	*ncan = 0;

	for(i=1;i<count;i++)
	{
		if(color[tree[i].node]=='w')
		{
			c[(*ncan)++] = tree[i].node;

			for(j=1;j<=degree[tree[i].node];j++)
			c[(*ncan)++] = graph[tree[i].node][j];
			
			return;
		}		
	}
}


int comp(void const *A, void const *B)
{
	TREE *a = (TREE*)A;
	TREE *b = (TREE*)B;

	return (a->edges - b->edges);
}