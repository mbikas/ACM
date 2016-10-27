/*567 -- Risk*/

#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NIL 0
#define sz 22
#define INF 100000

long path[sz][sz];

void FloydWarshall()
{
	long ind,jnd,knd,value;

	for(knd=1; knd<=20; knd++)
		for(ind=1; ind<=20; ind++)
			for(jnd=1; jnd<=20; jnd++)
			{
				value=path[ind][knd]+path[knd][jnd];
				if(path[ind][jnd]>value)
				{
					path[ind][jnd]=value;
				}
			}
}

void main()
{

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long i,j,kase=0,x,n,p;
	long source,des;

	for(i=1; i<=20; i++)
	for(j=1; j<=20; j++)
	path[i][j]=INF;

	while(scanf("%ld",&x)==1)
	{

		for(i=1;i<=x;i++)
		{
			scanf("%ld",&n);
			path[1][n]=1;
			path[n][1]=1;
		}
		p=2;
		while(p<20)
		{
			scanf("%ld",&x);
			for(i=1;i<=x;i++)
			{
				scanf("%ld",&n);
				path[p][n]=1;
				path[n][p]=1;
			}
			p++;
		}

		for(i=1; i<=20; i++)
		path[i][i]= 0;


		FloydWarshall();

		scanf("%ld",&x);

		printf("Test Set #%ld\n",++kase);

		for(i=0;i<x;i++)
		{
		  scanf("%ld %ld",&source,&des);
		  printf("%2ld to %2ld:%2ld\n",source,des,path[source][des]);

		}

		for(i=1;i<=20;i++)
		for(j=1;j<=20;j++)
		path[i][j]=INF;
		printf("\n");



	}
}