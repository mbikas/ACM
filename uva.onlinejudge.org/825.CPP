#include<stdio.h>
#include<string.h>
#define sz 205

long path[sz][sz];
void separating_int(char a[],long num[],long *count);


void main()
{
	
	char input[1000];
	
	long i,j,num[sz],ct,source,test,row,col;
	bool newLine=false;
	
	scanf("%ld",&test);
	
	while(test--)
	{
		if(newLine)printf("\n");
		else newLine=true;

		scanf("%ld %ld",&row,&col);

		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
				path[i][j]=-1;
		}
		path[1][1]=1;

		for(i=0;i<row;i++)
		{
			scanf(" %[^\n]",input);
			separating_int(input,num,&ct);
			source=num[0];
			for(j=1;j<ct;j++)
			{
				path[source][num[j]]=0;
			}		
		}

		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				if(path[i][j]==-1)
				{
					path[i][j] = path[i-1][j]+path[i][j-1];
				}
			}
		}
		/*
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				printf("%ld ",path[i][j]);
				
			}
			printf("\n");
		}
		*/

		printf("%ld\n",path[row][col]);
		
	}
	
	
}




void separating_int(char a[],long num[],long *count)
{
	long m,p,x,i;
	char temp[15];
	*count=0;
	p=strlen(a);
	a[p]=' ';
	m=0;
	
	//separating A
	/////////////////////////////////
	x=0;
	for(i=0;i<=p;i++)
	{
		if(a[i]!=' ')
		{
			temp[x]=a[i];
			x++;
		}
		else
		{ while (a[i+1]==' ')i++;
		  temp[x]=NULL;
		  sscanf(temp,"%ld",&num[m]);
		  m++;
		  x=0;
		}
	}
	*count=m;
	///////////////////////////////////////
}
