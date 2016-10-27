/*Transitive Closure by chormen*/

#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NIL 0

#define sz 100
#define INF 100000

long mat[sz][sz];
long tClosure[sz][sz];

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
	
	for(ind=1; ind<=vertex; ind++)
		for(jnd=1; jnd<=vertex;jnd++)
		{
			if(ind==jnd || mat[ind][jnd]!=0)
				tClosure[ind][jnd]=1;
			else
				tClosure[ind][jnd]=0;
		}

	for(knd=1; knd<=vertex; knd++)
		for(ind=1; ind<=vertex; ind++)
			for(jnd=1; jnd<=vertex; jnd++)
			{
				tClosure[ind][jnd] = tClosure[ind][jnd]|
									 (tClosure[ind][knd]&tClosure[knd][jnd]);
			}
}

void main(void)
{

	long ind,jnd,kase=0;
	long row,col,cost;

	while(scanf("%ld",&vertex)==1)
	{
		scanf("%ld",&edges);

		memset(mat,0,sizeof(0));
		memset(tClosure,0,sizeof(0));
		
		for(ind=1; ind<=edges; ind++)
		{
			scanf("%ld %ld",&row,&col);
			scanf("%ld",&cost);

			mat[row][col]=cost;
		}

		TransitiveClosure();
		printf("Graph %ld : The Calcultaion From The Transitive Closure :\n",++kase);
		PrintTransitiveClosure();
		
	}
}