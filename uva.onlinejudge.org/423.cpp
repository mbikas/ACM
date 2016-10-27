#include<stdio.h>
#include<string.h>

#define INF 10000
#define NIL 0
#define sz 102

long warshall[sz][sz];
long path[sz][sz];

void PrintWarshall(long print[][sz],long vertex)
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


void FloydWarshall(long vertex)
{
	long ind,jnd,knd,value;


	for(ind=1; ind<=vertex; ind++)
		for(jnd=1; jnd<=vertex;jnd++)
		{
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




void main()
{
	 long i,j,n,cost;
	 char temp[10];

	 while(scanf("%ld",&n)==1)
	 {

		 for(i=1;i<=n;i++)
		 for(j=1;j<=n;j++)
		 warshall[i][j]=INF;


		 for(i=2;i<=n;i++)
		 {
				for(j=1;j<i;j++)
				{
					scanf(" %s",temp);

					if(strcmp(temp,"x")==0)
					{
						warshall[i][j] = INF;
						warshall[j][i] = INF;
					}
					else
					{
					  sscanf(temp,"%ld",&cost);
					  warshall[i][j] = cost;
					  warshall[j][i] = cost;
					}

				}
		 }
		 for(i=1;i<=n;i++)
		 warshall[i][i]=NIL;

		 /*
		 for(i=1;i<=n;i++)
		 {for(j=1;j<=n;j++)
		  printf("%ld ",warshall[i][j]);
		  printf("\n");
		 }
		 */

		 FloydWarshall(n);

		 /*
		 printf("-------------\n\n");

		 for(i=1;i<=n;i++)
		 {for(j=1;j<=n;j++)
		  printf("%ld ",warshall[i][j]);
		  printf("\n");
		 }

		 */
		 /*
		 printf("-------------\n\n");

		 printf("The path from node ind to jnd\n\n");
		 PrintWarshall(path,n);
		 printf("-------------\n\n");
		 for(i=1; i<=n; i++)
		 for(j=1; j<=n; j++)
			{
				printf("Thepath form node %ld to %ld :\n",i,j);
				PrintAllPairsShortestPath(i,j);
				printf("\n");
			}
	  */

		cost=0;

		for(i=1;i<=n;i++)
		{
		  if(warshall[1][i]>cost && warshall[1][i]<INF)
		  cost = warshall[1][i];
		}

		/*
		for(i=1;i<=n;i++)
		{
		  for(j=1;j<=n;j++)
		  {	if(warshall[i][j]>cost && warshall[i][j]<INF)
				cost = warshall[i][j];
		  }
		}
		*/

      printf("%ld\n",cost);









	 }
}