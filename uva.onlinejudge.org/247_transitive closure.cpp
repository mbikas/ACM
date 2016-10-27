/*Transitive Closure by chormen*/

#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NIL 0
#define sz 100
#define INF 100000

char names[sz][30];
long tClosure[sz][sz];
bool present[sz];

long vertex,edges;

void PrintTransitiveClosure()
{
	long ind, jnd;

	printf("All Pairs Shortest Path : \n\n");

	for(ind=1;ind<=vertex; ind++)
	{
		for(jnd=1;jnd<=vertex; jnd++)
		{
			printf("%ld\t",tClosure[ind][jnd]);
		}
		printf("\n");
	}
		
}

void TransitiveClosure()
{
	long ind,jnd,knd;
	
	for(knd=1; knd<=vertex; knd++)
		for(ind=1; ind<=vertex; ind++)
			for(jnd=1; jnd<=vertex; jnd++)
			{
				tClosure[ind][jnd] = tClosure[ind][jnd]|
									 (tClosure[ind][knd]&tClosure[knd][jnd]);
			}
}

int main()
{

	long ind,jnd,kase=0,n,i,knd,j;
	char node1[sz],node2[sz];
	bool used[sz],f=false;

	while(scanf("%ld",&vertex)==1)
	{
		scanf("%ld",&edges);

		if(vertex==0 && edges==0)break;

		if(f)printf("\n");
		else f=true;

		memset(present,false,sizeof(present));
		memset(tClosure,0,sizeof(tClosure));
		for(i=0;i<=vertex;i++)
			strcpy(names[i]," ");

		n=1;
		for(knd = 1; knd <= edges; knd++)
		{
			scanf(" %s %s", node1, node2);
			ind=jnd=-1;
			for(i=1;i<n;i++)
			{
				if(strcmp(node1,names[i])==0)ind=i;
				if(strcmp(node2,names[i])==0)jnd=i;
			}
			if(ind==-1){
				strcpy(names[n],node1);
				ind=n++;
			}
			if(jnd==-1){
				strcpy(names[n],node2);
				jnd=n++;
			}
			
			tClosure[ind][jnd]=1;
			present[ind]=present[jnd]=true;
		}
		TransitiveClosure();
		printf("Calling circles for data set %d:\n",++kase);
		//PrintTransitiveClosure();
		memset(used,false,sizeof(used));
		for(i=1;i<=vertex;i++)
		{
			if(!used[i] && present[i])
			{	
				printf("%s",names[i]);
				for(j=1;j<=vertex ;j++)
				{
					if( (tClosure[i][j]==tClosure[j][i]) && tClosure[j][i]==1 && i!=j )
					{
						used[j]=true;
						printf(", %s",names[j]);
					}
				}
				printf("\n");	
				used[i]=true;
			}		
		}
	}
	return 0;
}