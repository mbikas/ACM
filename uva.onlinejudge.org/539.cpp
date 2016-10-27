#include<stdio.h>
#define MAX 30

bool path[MAX][MAX];
long max;
void backtrack(int a[],int k,int n,int node);
void con_candidate(int a[],int k,int n,int node,int c[],int *ncan);

//int ans[MAX];
void main()
{
	int a[MAX];
	int node,edge,i,j,x,y;

	while(scanf("%d %d",&node,&edge)==2 && (node!=0 || edge!=0))
	{

		for(i=0;i<=node;i++)
			for(j=0;j<=node;j++)
				path[i][j] = false;

		for(i=0;i<edge;i++)
		{
			scanf("%d %d",&x,&y);
			path[x][y] = path[y][x] = true;		
		}
		
		for(i=0;i<=node;i++)a[i]=i;
		max=0;
		backtrack(a,0,edge,node);

		if(max<=0)max=1;

		printf("%ld\n",max-1);
		//for(i=1;i<=max;i++)
		//	printf("%d ",ans[i]);
		//printf("\n");
	}
}

void backtrack(int a[],int k,int n,int node)
{
	int i,c[MAX],ncan;

	if(k>max)
	{
		//for(i=1;i<=k;i++)ans[i]=a[i];
		max = k;
	}
	k++;
	con_candidate(a,k,n,node,c,&ncan);
	for(i=0;i<ncan;i++)
	{
		a[k] = c[i];
		backtrack(a,k,n,node);		
	}
}

void con_candidate(int a[],int k,int n,int node,int c[],int *ncan)
{
	int i,j;
	bool flag[MAX][MAX];
	*ncan=0;

	if(k>n+1)return;

	if(k==1)
	{
		for(i=0;i<node;i++)
		c[(*ncan)++] = i;
		return;
	}

	for(i=0;i<=node;i++)
		for(j=0;j<=node;j++)
			flag[i][j] =false;

	for(i=2;i<k;i++)
		flag[a[i-1]][a[i]] = flag[a[i]][a[i-1]]= true;

	for(i=0;i<node;i++)
	{
		if(path[i][a[k-1]] && flag[i][a[k-1]]==false)
		{
			c[(*ncan)++] = i;			
		}
	}



}