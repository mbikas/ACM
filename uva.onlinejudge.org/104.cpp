#include<stdio.h>

#define NIL 0
#define sz 30
#define INF 999999L

double mat[sz][sz][sz];
long path[sz][sz][sz];

long vertex,edges;
bool finished;
long first;
long print[30],count;
double warshall[sz][sz][sz];

void PrintAllPairsShortestPath(long ind, long jnd,long step)
{
	if(step==-1)
	{
		finished=true;
		return;
	}
	if(finished)
		return;
	print[count++]=jnd;
	PrintAllPairsShortestPath(ind, path[ind][jnd][step],step-1);
	
}

void FloydWarshall()
{
	long ind,jnd,knd,step;
	double value;
	for(step=1;step<=vertex;step++)
	{
		for(ind=1; ind<=vertex; ind++)
		{
			for(jnd=1; jnd<=vertex;jnd++)
			{
				mat[ind][ind][1]=1;
				path[ind][jnd][1]=ind;			
			}
		}
	}
	for(step=2;step<=vertex;step++)
	{
		for(knd=1; knd<=vertex; knd++)
		{
			for(ind=1; ind<=vertex; ind++)
			{
				for(jnd=1; jnd<=vertex; jnd++)
				{
					value=mat[ind][knd][step-1]*mat[knd][jnd][1];
					if(value>mat[ind][jnd][step])
					{
						mat[ind][jnd][step]=value;
						path[ind][jnd][step]=knd;
					}
				}
			}
		}
	}
}

int main()
{
	long ind,jnd,step,tempstep;
	bool flag;
	long min;
	while(scanf("%ld",&vertex)==1)
	{
		finished=false;
		count=0;
		for(step=1;step<=vertex;step++)
		{
			for(ind=1; ind<=vertex; ind++)
			{
				for(jnd=1; jnd<=vertex;jnd++)
				{
					warshall[ind][jnd][step]=0;
					mat[ind][jnd][step]=0;
				}
			}
		}
		for(ind=1; ind<=vertex; ind++)
		{
			for(jnd=1;jnd<=vertex;jnd++)
			{
				if(ind==jnd)
				{
				}
				else
				{
					scanf("%lf",&mat[ind][jnd][1]);
				}
			}
		}
		
		FloydWarshall();
		flag=true;
		min=9999999L;
		for (step = 2; step <= vertex; step++) 
		{
			for (ind = 1; ind <= vertex; ind++)
			{
				if (mat[ind][ind][step] > 1.01 && step<min) 
				{ 
					min=step;
					flag=false;
					first=tempstep;
					PrintAllPairsShortestPath(ind,ind,step);
					printf("%ld",print[count-1]);
					for(ind=count-2;ind>=0;ind--)
					{
						printf(" %ld",print[ind]);
					}
					printf("\n");
					break;
				}
				
			}
			if(!flag)
				break;
		}
		if(flag)
		{
			printf("no arbitrage sequence exists\n");
		}
	}

	return 0;
}