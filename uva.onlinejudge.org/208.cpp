#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NIL 0
#define sz 23
#define INF 32000

int mat[sz][sz];
int path[sz][sz];
int warshall[sz][sz];
int vertex;
void FloydWarshall();

int total_path,max;
bool taken[sz];
int graph[sz][sz],degree[sz];
void backtrack(int a[],int k,int des);
void con_candidate(int a[],int k,int c[],int *ncan,int des);
int comp(void const *A, void const *B);



void main(void)
{
	int des,cases=1;
	int row,col,i,j,a[sz];

	while(scanf("%d",&des)==1)
	{
		
		//initialization
		memset(a,0,sizeof(a));
		memset(graph,0,sizeof(graph));
		memset(degree,0,sizeof(degree));
		memset(taken,false,sizeof(taken));
		memset(path,0,sizeof(path));
		memset(mat,INF,sizeof(mat));
		
		max=0;
		while(scanf("%d %d",&row,&col)==2 )
		{
			if(row==0 && col==0)break;

			mat[row][col]=1;
			mat[col][row]=1;
			
			graph[row][++degree[row]] = col;
			graph[col][++degree[col]] = row;
			if(row>max)max = row;
			if(col>max)max = col;
		}
		
		vertex=max;

		FloydWarshall();

		for(i=1;i<=max;i++)
		qsort(graph[i]+1,degree[i],sizeof(graph[i][0]),comp);
	
		printf("CASE %d:\n",cases++);
		total_path = 0;
		a[1] = 1;
		
		taken[1]=true;
		backtrack(a,1,des);	
		printf("There are %d routes from the firestation to streetcorner %d.\n",total_path,des);
		
	
	}
}


void backtrack(int a[],int k,int des)
{
	int i,ncan,c[sz];

	if(a[k]==des)
	{
		for(i=1;i<k;i++)printf("%d ",a[i]);
		printf("%d\n",a[k]);
		total_path++;	
	}
	else
	{
		k++;
		con_candidate(a,k,c,&ncan,des);
		for(i=0;i<ncan;i++)
		{
			a[k] = c[i];
			taken[a[k]]=true;
			backtrack(a,k,des);
			taken[a[k]]=false;
		}
	}
}

void con_candidate(int a[],int k,int c[],int *ncan,int des)
{
	int i;
	*ncan = 0;

	if(degree[a[k-1]]==0)return;
	
	if(path[a[k-1]][des]==0)return;


	for(i=1;i<=degree[a[k-1]];i++)
	{

			if(taken[ graph[a[k-1]][i] ]==false)
				c[(*ncan)++] = graph[a[k-1]][i];						
				
	}	
}




int comp(void const *A, void const *B)
{

	int *a = (int*)A;
	int *b = (int*)B;


	return *a-*b;
	
}





void FloydWarshall()
{
	int ind,jnd,knd,value;
	
	for(ind=1; ind<=vertex; ind++)
		for(jnd=1; jnd<=vertex;jnd++)
		{
			if(ind!=jnd)
				warshall[ind][jnd]=mat[ind][jnd];
			else
				warshall[ind][jnd]=0;

			if(ind==jnd || warshall[ind][jnd]>=INF)
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
