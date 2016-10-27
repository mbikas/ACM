
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NIL 0
#define sz 102
#define INF 32000

int mat[sz][sz];
int path[sz][sz];
int warshall[sz][sz];
int vertex;
int ans[sz];
void FloydWarshall();


void main()
{

	//freopen("280.out","w",stdout);

	int nodes,i,j,k,des,m,start,total,p;

	while(scanf("%d",&nodes) && nodes)
	{
	
		memset(path,0,sizeof(path));
	
		
		for(i=0;i<=nodes;i++)
		for(j=0;j<=nodes;j++)
		warshall[i][j]=INF;



		while(scanf("%d",&start)==1 && start)
		{
			while(scanf("%d",&des)==1 && des)
			warshall[start][des]=1;
		}

		
		vertex=nodes;
		FloydWarshall();


		scanf("%d",&m);
	
		for(k=1;k<=m;k++)
		{
			scanf("%d",&start);
			total=p=0;

				
			for(i=1;i<=nodes;i++)
			{
				if(path[start][i]==0)
				{
					ans[p++]=i;
					total++;
				}
							
			}


			printf("%d",total);
			for(i=0;i<p;i++)
			printf(" %d",ans[i]);
			printf("\n");


		
		}
	
	}
}


void FloydWarshall()
{
	int ind,jnd,knd,value;
	
	for(ind=1; ind<=vertex; ind++)
		for(jnd=1; jnd<=vertex;jnd++)
		{
			
			if(warshall[ind][jnd]>=INF)
				path[ind][jnd]=NIL;
			else
				path[ind][jnd]=ind;
		
		}

	for(knd=1; knd<=vertex; knd++)
		for(ind=1; ind<=vertex; ind++)
			for(jnd=1; jnd<=vertex; jnd++)
			{
				value=warshall[ind][knd]+warshall[knd][jnd];
				if(warshall[ind][jnd]>value)
				{
					warshall[ind][jnd]=value;
					path[ind][jnd]=path[knd][jnd];
				}
			}
}
