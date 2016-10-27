#include<stdio.h>
#include<string.h>
#define MAX 102


int flag[MAX][MAX];
long ans,max;
int board[MAX][MAX];

typedef struct{
	int row;
	int col;
}mytype;

void backtrack(mytype a[],int k,int total_row,int total_col);
void con_candidate(mytype a[],int k,int total_row,int total_col,mytype c[],int *ncan);
void flush(int row,int col);

mytype a[10009];

void main()
{
	
	int row,col,i,j,test;
	char name[1000];

	scanf("%d",&test);

	while(test--)
	{


		scanf(" %s %d %d",name,&row,&col);

		for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		scanf("%d",&board[i][j]);			
		
		memset(flag,0,sizeof(flag));
		ans = 0;	
		flush(row,col);

		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				max = 0;
				
				flush(row,col);
				//memset(a,0,sizeof(a));
				
				a[1].row = i;
				a[1].col = j;
				backtrack(a,1,row,col);

				if(max>ans)
					ans = max;	
			}	
		}
		
			
		printf("%s: %ld\n",name,ans);	
	
	}
}

void flush(int row,int col)
{
	int i,p;

	p = row*col+2;
	for(i=0;i<=p;i++)
	{
		a[i].row = 0;
		a[i].col = 0;	
	}
}

void backtrack(mytype a[],int k,int total_row,int total_col)
{	
	
	int i,ncan;
	mytype c[5];

	
	
	if(k>max)
	{
		max = k;
		//for(j=1;j<=k;j++)
		//printf("(%d) ",board[a[j].row][a[j].col]);
		//printf("\n---\n");	
	}

	if(k>(total_row*total_col))
		return;
	else
	{


		k++;
		con_candidate(a,k,total_row,total_col,c,&ncan);
		
		for(i=0;i<ncan;i++)
		{
			a[k].row = c[i].row;
			a[k].col = c[i].col;
		
			backtrack(a,k,total_row,total_col);
		
		}
	}
}

void con_candidate(mytype a[],int k,int total_row,int total_col,mytype c[],int *ncan)
{
	
	


	int rows,cols;
	
	rows  = a[k-1].row;
	cols  = a[k-1].col;

	if(k < flag[rows][cols])return; 
	
	

	*ncan = 0;

	//up
	if(rows>=1 && board[rows-1][cols]< board[rows][cols])
	{
		c[(*ncan)].row = rows-1;
		c[(*ncan)].col = cols;
		(*ncan)++;
		flag[rows-1][cols] = k;	
	}

	//down
	if(rows<(total_row-1) && board[rows+1][cols]< board[rows][cols])
	{
		c[(*ncan)].row = rows+1;
		c[(*ncan)].col = cols;
		(*ncan)++;
		flag[rows+1][cols] = k;
		
	}

	//right
	if(cols<(total_col-1) && board[rows][cols+1]< board[rows][cols])
	{
		c[(*ncan)].row = rows;
		c[(*ncan)].col = cols+1;
		(*ncan)++;
		flag[rows][cols+1] = k;
		
	}

	//left
	if(cols>=1 && board[rows][cols-1]< board[rows][cols])
	{
		c[(*ncan)].row = rows;
		c[(*ncan)].col = cols-1;
		(*ncan)++;
		flag[rows][cols-1] = k;	
	}

}