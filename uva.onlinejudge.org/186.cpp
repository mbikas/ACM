#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NIL 0
#define sz 105
#define INF 999999999

long mat[sz][sz];
long path[sz][sz];
long warshall[sz][sz];

long vertex,edges;
long print[1000],l;

struct cityname
{
	char name[1000];
}city[1000];

char route[100][50][10];

void PrintAllPairsShortestPath(long ind, long jnd)
{
	if(ind==jnd)
		print[l++]=ind;
	else
	{
		if(path[ind][jnd]==NIL)
		{
			
		}
		else
		{
			PrintAllPairsShortestPath(ind, path[ind][jnd]);
			print[l++]=jnd;
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

void initialize()
{
	long ind,jnd;
	for(ind=1; ind<=100; ind++)
	{
		for(jnd=1; jnd<=100;jnd++)
		{
			mat[ind][jnd]=INF;
		}
	}
}
int main(void)
{
	//freopen("out.txt","wt",stdout);
	long k,i,temp1,temp2,j,len,total;
	long cost;
	char string[1000],*p,rout[100];
	bool flag;
	
	initialize();
	k=1;
	while(gets(string) && strlen(string)!=0)
	{
		
		p=strtok(string,",\n");
		if(p)
		{
			
			flag=true;
			for(i=1;i<=k;i++)
			{
				if(strcmp(city[i].name,p)==0)
				{
					temp1=i;
					flag=false;
					break;
				}
			}
			if(flag)
			{
				strcpy(city[k].name,p);
				temp1=k;
				k++;
			}
		}
		
		p=strtok(NULL,",\n");
		if(p)
		{
			flag=true;
			for(i=1;i<=k;i++)
			{
				if(strcmp(city[i].name,p)==0)
				{
					temp2=i;
					flag=false;
					break;
				}
			}
			if(flag)
			{
				strcpy(city[k].name,p);
				temp2=k;
				k++;
			}
		}
		p=strtok(NULL,",\n");
		if(p)
		{
			strcpy(rout,p);
		}
		p=strtok(NULL,",\n");
		if(p)
		{
			cost=atoi(p);
			if(cost<mat[temp1][temp2])
			{
				mat[temp1][temp2]=cost;
				mat[temp2][temp1]=cost;
				strcpy(route[temp1][temp2],rout);
				strcpy(route[temp2][temp1],rout);
			}
		}		
		
	}
	vertex=k-1;
	FloydWarshall();
	flag=true;
	while(gets(string)){
		printf("\n\n");
		flag=false;
		p=strtok(string,",\n");
		if(p)
		{
			for(i=1;i<=k;i++)
			{
				if(strcmp(city[i].name,p)==0)
				{
					temp1=i;
					break;
				}
			}
		}
		p=strtok(NULL,",\n");
		if(p)
		{
			for(i=1;i<=k;i++)
			{
				if(strcmp(city[i].name,p)==0)
				{
					temp2=i;
					break;
				}
			}
		}
		for(i=0;i<1000;i++)
			print[i]=0;
		l=0;
		printf("From                 To                   Route      Miles\n");
		printf("-------------------- -------------------- ---------- -----\n");
		total=0;
		PrintAllPairsShortestPath(temp1,temp2);
		for(i=0;i<l-1;i++)
		{
			printf("%s",city[print[i]].name);
			len=strlen(city[print[i]].name);
			for(j=len;j<=20;j++)
				printf(" ");
			printf("%s",city[print[i+1]].name);
			len=strlen(city[print[i+1]].name);
			for(j=len;j<=20;j++)
				printf(" ");
			printf("%s",route[print[i]][print[i+1]]);
			len=strlen(route[print[i]][print[i+1]]);
			for(j=len;j<=10;j++)
				printf(" ");
			printf("%5ld\n",warshall[print[i]][print[i+1]]);
			total=total+warshall[print[i]][print[i+1]];
			
		}
		printf("                                                     -----\n");
		printf("                                          Total      %5d\n",total);
	}
	return 0;
}

