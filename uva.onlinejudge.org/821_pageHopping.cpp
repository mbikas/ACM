#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define sz 105
#define INF 100000

long mat[sz][sz];
long warshall[sz][sz];

long vertex;





void FloydWarshall()
{
	long ind,jnd,knd,value;
		

	for(knd=1; knd<=vertex; knd++)
		for(ind=1; ind<=vertex; ind++)
			for(jnd=1; jnd<=vertex; jnd++)
			{
				value=warshall[ind][knd]+warshall[knd][jnd];
				if(warshall[ind][jnd]>value)
				{
					warshall[ind][jnd]=value;
					
				}
			}
}

void main(void)
{
	long source,des,cases=1;
	long i,j,totalPath,possiblePath;
	double average;


	for(i=0;i<101;i++)
	{for(j=0;j<101;j++)
		warshall[i][j]=INF;
	}
	for(i=0;i<=100;i++)warshall[i][i]=0;
	vertex=0;
		

	while(scanf("%ld %ld",&source,&des)==2)
	{
		if(source==0 && des==0)break;
		
		if(source!=des)warshall[source][des]=1;
		if(source>vertex)vertex=source;
		if(des>vertex)vertex=des;

		while(scanf("%ld %ld",&source,&des)==2)
		{
			if(source==0 && des==0)break;
			if(source!=des)warshall[source][des]=1;
			if(source>vertex)vertex=source;
			if(des>vertex)vertex=des;
		}


	
		FloydWarshall();
		
		totalPath=0;
		possiblePath=0;
		for(i=1;i<=vertex;i++)
		{
			for(j=1;j<=vertex;j++)
			{
				if(i!=j && warshall[i][j]!=0 && warshall[i][j]!=INF)
				{
					possiblePath++;
					totalPath+=warshall[i][j];
				}			
			}		
		}

		if(possiblePath==0)average=0;
		else
			average = (double) ((double)totalPath / (double)possiblePath);
		printf("Case %ld: average length between pages = %.3lf clicks\n",cases++,average);
		
			for(i=0;i<101;i++)
			{for(j=0;j<101;j++)
				warshall[i][j]=INF;
			}
			for(i=0;i<=100;i++)warshall[i][i]=0;
			vertex=0;

	}
}
