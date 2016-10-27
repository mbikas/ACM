//677
#include<stdio.h>
#include<string.h>
#define MAX 11

int graph[MAX][MAX];
bool find = false;
void backtrack(int a[],int k,int n,int nodes);
void con_candidate(int a[],int k,int n,int c[],int *ncan,int nodes);

void main()
{
	char terminate[10];
	int a[MAX],i,j,nodes,length,f=0,path;

	while(scanf("%d %d",&nodes,&length)==2)
	{
		if(f==1)printf("\n");
		else f=1;

		memset(graph,0,sizeof(graph));
		memset(a,0,sizeof(a));		

		for(i=1;i<=nodes;i++)
		for(j=1;j<=nodes;j++)
		{
			scanf("%d",&path);
			if(path==1)
			graph[i][++graph[i][0]] = j;		
		}

		/*
		for(i=1;i<=nodes;i++)
		{
			for(j=1;j<=graph[i][0];j++)
			printf("%d ",graph[i][j]);
			printf("\n");	
		}
		*/

		find = false;
		a[1] = 1;
		backtrack(a,1,length+1,nodes);

		if(!find)printf("no walk of length %d\n",length);

		scanf(" %[^\n]",terminate);
		if(strcmp(terminate,"-9999")!=0)
			break;

	}
}

void backtrack(int a[],int k,int n,int nodes)
{
	int i,c[MAX],ncan;

	if(k==n)
	{
		find = true;
		printf("(");
		for(i=1;i<k;i++)
			printf("%d,",a[i]);
		printf("%d)\n",a[k]);	
		return;
	}
	else
	{
		k++;
		con_candidate(a,k,n,c,&ncan,nodes);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];
			backtrack(a,k,n,nodes);		
		}
	}
}

void con_candidate(int a[],int k,int n,int c[],int *ncan,int nodes)
{

	if(k>n)
		return;

	int i;
	bool choice[MAX];

	*ncan = 0;

	for(i=1;i<=nodes;i++)choice[i] = true;
	for(i=1;i<k;i++)choice[a[i]] = false;

	for(i=1;i<=graph[a[k-1]][0];i++)
	{
		if(choice[ graph[a[k-1]][i]])
			c[(*ncan)++] = graph[a[k-1]][i];
	}
}
