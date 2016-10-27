#include<stdio.h>
#define MAX 105


int adj[MAX][MAX];
int max=0,destination;
int ans[MAX],length[MAX];

void backtrack(int a[],int k,int n);
void con_candidate(int a[],int n,int k,int c[],int *ncan);

void main()
{
	int node,i,source,des,start;
	int a[MAX];
	int cases=1;

	while( scanf("%d",&node)==1 && node)
	{
		scanf("%d",&start);

		for(i=0;i<=node;i++)
		adj[i][0] = 0;
		
	

		while(scanf("%d %d",&source,&des)==2 && (source!=0 || des!=0))
		{
			

			adj[source][0]++;
			adj[source][adj[source][0]] = des;	
		}

/*
		for(i=1;i<=5;i++)
		{
			for(j=1;j<=adj[i][0];j++)
			printf("%d %d\n",i,adj[i][j]);
		
		}
*/
	    for(i=0;i<=node;i++)
		{
			a[i]=1;
			length[i] = 0;
		}
		a[1] = start;
		max = 0;
		destination = node+1;
		backtrack(a,1,node);
		//printf("%d\n",max);
		//for(i=1;i<=max;i++)printf("%d ",ans[i]);
		//printf("\n");

		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",cases++,start,max-1,destination);
	}
}


void backtrack(int a[],int k,int n)
{
	int c[MAX],ncan,i;

	k++;
	con_candidate(a,n,k,c,&ncan);
	for(i=0;i<ncan;i++)
	{
			a[k] = c[i];
			backtrack(a,k,n);		
	}	

}

void con_candidate(int a[],int n,int k,int c[],int *ncan)
{

	int i;
	bool flag,choice[MAX];
	flag = false;

	*ncan = 0;

	for(i=0;i<=n;i++)choice[i]=true;
	for(i=1;i<k;i++)choice[a[i]]=false;

	for(i=1;i<=adj[a[k-1]][0];i++)
	{
		//if( choice[  adj[a[k-1]][i]  ] == true  && k >= length[ adj[a[k-1]][i] ])
		if( choice[  adj[a[k-1]][i]  ] == true  && k-1 >= length[ adj[a[k-1]][i] ])
		{
			c[(*ncan)++] =  adj[a[k-1]][i];
			flag = true;
			length[ adj[a[k-1]][i] ] = k-1;
		}
	}

	if(flag==false && k-1>=max)
	{
		max = k-1;		
		if(a[k-1]<destination)
		destination = a[k-1];
	}	
}
