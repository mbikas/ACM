/*ACM 10048 -- Audiophobia*/

#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NIL 0
#define sz 102
#define INF 100000

long mat[sz][sz];
long warshall[sz][sz];

long vertex,edges;

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
		}

	for(knd=1; knd<=vertex; knd++)
		for(ind=1; ind<=vertex; ind++)
			for(jnd=1; jnd<=vertex; jnd++)
			{
				if(warshall[ind][knd]>warshall[knd][jnd])value = warshall[ind][knd];
				else value = warshall[knd][jnd];

				if(value<warshall[ind][jnd])
				{
					warshall[ind][jnd]=value;
				}
			}
}

void main()
{
	long kase=0,query,i,j;
	long row,col,cost,flag=0;

	while(scanf("%ld %ld %ld",&vertex,&edges,&query)==3)
	{


		if(vertex==0 && edges==0 && query==0)break;

		if(flag==1)printf("\n");
      else flag=1;

		for(i=1; i<=vertex;i++)
			for(j=1; j<=vertex;j++)
				mat[i][j]=INF;

		for(i=1; i<=edges; i++)
		{
			scanf("%ld %ld %ld",&row,&col,&cost);
			mat[row][col] = cost;
			mat[col][row] = cost;

		}

		printf("Case #%ld\n",++kase);
		FloydWarshall();
		for(i=1;i<=query;i++)
		{
			scanf("%ld %ld",&row,&col);

			if(warshall[row][col]==INF)
				printf("no path\n");
			else
				printf("%ld\n",warshall[row][col]);
		}
	}
}
