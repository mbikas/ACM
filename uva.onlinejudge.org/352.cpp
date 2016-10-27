#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 27
#define SZ 27*27

char grid[sz][sz];
int count=0,n,len=0;


void backtrack(int a[SZ][3],int k);
void con_candidate(int a[SZ][3],int k,int c[SZ][3],int *ncan);

void main()
{
	int i,j,a[SZ][3];
	long cases=1;

	while(scanf("%d",&n)==1)
	{
		
		
		
		for(i=0;i<n;i++)
		scanf(" %s",grid[i]);

		count=0;

	
		for(i=0;i<n;i++)
		{
			len = strlen(grid[i]);
			for(j=0;j<len;j++)
			{
				if(grid[i][j]=='1')
				{
					count++;
					a[1][0]=i;
					a[1][1]=j;
					grid[i][j]='0';
					backtrack(a,1);					
				}			
			}		
		}	

		printf("Image number %ld contains %d war eagles.\n",cases++,count);
	
	}//end of while
}//end of main

void backtrack(int a[SZ][3],int k)
{
	int c[SZ][3],i,ncan;

	k++;
	con_candidate(a,k,c,&ncan);
	for(i=0;i<ncan;i++)
	{
		a[k][0] = c[i][0];
		a[k][1] = c[i][1];
		backtrack(a,k);	
	}	

	
}

void con_candidate(int a[SZ][3],int k,int c[SZ][3],int *ncan)
{
	int row,col,c_row,c_col;

	*ncan = 0;
	
	row = a[k-1][0];
	col = a[k-1][1];

	c_row = row-1;
	c_col = col;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<len) )
	{
		if(grid[c_row][c_col]=='1')
		{
		
		c[(*ncan)][0] = c_row;
		c[(*ncan)][1] = c_col;
		grid[c_row][c_col]='0';
		(*ncan)++;	
		}
	}
	
	c_row = row-1;
	c_col = col-1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<len) )
	{
		if(grid[c_row][c_col]=='1')
		{
		
		c[(*ncan)][0] = c_row;
		c[(*ncan)][1] = c_col;
		grid[c_row][c_col]='0';
		(*ncan)++;	
		}	
	}
	c_row = row-1;
	c_col = col+1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<len) )
	{
		if(grid[c_row][c_col]=='1')
		{
		
		c[(*ncan)][0] = c_row;
		c[(*ncan)][1] = c_col;
		grid[c_row][c_col]='0';
		(*ncan)++;	
		}	
	}
	c_row = row;
	c_col = col-1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<len) )
	{
		if(grid[c_row][c_col]=='1')
		{
		
		c[(*ncan)][0] = c_row;
		c[(*ncan)][1] = c_col;
		grid[c_row][c_col]='0';
		(*ncan)++;	
		}	
	}
	c_row = row;
	c_col = col+1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<len) )
	{
		if(grid[c_row][c_col]=='1')
		{
		
		c[(*ncan)][0] = c_row;
		c[(*ncan)][1] = c_col;
		grid[c_row][c_col]='0';
		(*ncan)++;	
		}	
	}
	c_row = row+1;
	c_col = col-1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<len) )
	{
		if(grid[c_row][c_col]=='1')
		{
		
		c[(*ncan)][0] = c_row;
		c[(*ncan)][1] = c_col;
		grid[c_row][c_col]='0';
		(*ncan)++;	
		}	
	}
	c_row = row+1;
	c_col = col;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<len) )
	{
		if(grid[c_row][c_col]=='1')
		{
		
		c[(*ncan)][0] = c_row;
		c[(*ncan)][1] = c_col;
		grid[c_row][c_col]='0';
		(*ncan)++;	
		}	
	}
	c_row = row+1;
	c_col = col+1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<len) )
	{
		if(grid[c_row][c_col]=='1')
		{
		
		c[(*ncan)][0] = c_row;
		c[(*ncan)][1] = c_col;
		grid[c_row][c_col]='0';
		(*ncan)++;	
		}	
	}
	
}