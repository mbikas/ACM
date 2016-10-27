#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NIL 0
#define sz 10
#define INF 100000

long mat[sz][sz];
long path[sz][sz];
long warshall[sz][sz];

long vertex,edges;

void PrintWarshall(long print[][sz])
{
	long ind, jnd;

	printf("All Pairs Shortest Path : \n\n");

	for(ind=1;ind<=vertex; ind++)
	{
		for(jnd=1;jnd<=vertex; jnd++)
		{
			printf("%ld\t",print[ind][jnd]);
		}
		printf("\n");
	}
		
}

void PrintAllPairsShortestPath(long ind, long jnd)
{
	if(ind==jnd)
		printf("%ld",ind);
	else
	{
		if(path[ind][jnd]==NIL)
		{
			printf("NO Path From I to J exists.\n");
		}
		else
		{
				PrintAllPairsShortestPath(ind, path[ind][jnd]);
				printf("->%ld",jnd);
		}
	}
}

void FloydWarshall()
{
	long ind,jnd,knd,value;
	
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

void main(void)
{
	long ind,jnd,kase=0;
	long row,col,cost;

	while(scanf("%ld",&vertex)==1)
	{
		scanf("%ld",&edges);

		for(ind=1; ind<=vertex; ind++)
			for(jnd=1; jnd<=vertex;jnd++)
				mat[ind][jnd]=INF;
		
		for(ind=1; ind<=edges; ind++)
		{
			scanf("%ld %ld",&row,&col);
			scanf("%ld",&cost);
			mat[row][col]=cost;
		}

		printf("Graph %ld : The Calcultaion From The Floyd Warshall :\n",++kase);
		FloydWarshall();
		
		PrintWarshall(warshall);
		
		printf("The path from node ind to jnd\n\n");
		PrintWarshall(path);

		for(ind=1; ind<=vertex; ind++)
			for(jnd=1; jnd<=vertex; jnd++)
			{
				printf("The path form node %ld to %ld :\n",ind,jnd);
				PrintAllPairsShortestPath(ind,jnd);
				printf("\n");
			}
	}
}
