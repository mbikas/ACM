/*Articulation point*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define sz 1001

int index=0,count=0;
char color[sz];
int mat[sz][sz];

void DFS_Visit(int knd)
{
	int ind;
	
	color[knd]='g';
	for(ind=1;ind<=index;ind++)
	{
		if(mat[knd][ind]==1 && color[ind]=='w')
			DFS_Visit(ind);
	}
	color[knd]='b';
}

void ArticulationPoint()
{
	int ind,jnd,knd;
	int subnet,flag=1;
	
	for(ind=1;ind<=index;ind++)
	{
		if(!mat[ind][0])
			continue;
		
		subnet=0;
		
		for(jnd=1;jnd<=index;jnd++)
			color[jnd]='w';
		color[ind]='b';
		
		for(knd=1;knd<=index;knd++)
		{
			if(mat[knd][0] && color[knd]=='w')
			{
				subnet=subnet+1;
				
				DFS_Visit(knd);
			}
		}
		
		if(subnet>1)
		{
			count++;
			flag=0;
			//printf("  SPF node %d leaves %d subnets\n",ind,subnet);
		}
	}
	
	if(flag)
	{
		//printf("  No SPF nodes\n");
	}
}



void main(void)
{
	
	int node1,node2,n,i,j;
	char *p,str[10000];
	
	while(scanf(" %[^\n]",str)==1)
	{
		sscanf(str,"%d",&n);
		if(n==0)break;
		index=count=0;
				
		for(j=0;j<n;j++)
		{
			scanf(" %[^\n]",str);
			if(str[0]=='0')
			{
				ArticulationPoint();				
				printf("%d\n",count);
				index=0;
				memset(mat,0,sizeof(mat));
				break;
			}
			i=1;
			p = strtok(str," \n");
			while(p)
			{
				if(i==1)
				{
					node1 = atoi(p);					
					i=2;
				}
				else
				{
					node2 = atoi(p);
					mat[node1][node2]=1;
					mat[node1][0]=mat[node2][0]=1;
					mat[node2][node1]=1;
				
					if(index<node1) index=node1;
					if(index<node2) index=node2;
				}
					
				p = strtok(NULL," \n");
			}
		}
		
		
	}	
	
	
}

