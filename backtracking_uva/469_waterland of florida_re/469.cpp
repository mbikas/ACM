#include<stdio.h>
#include<string.h>
#define sz 10000
#define MAX 105

typedef struct{
	int row;
	int col;
}mytype;

char grid[MAX][MAX];
int max=0;
char color[MAX][MAX];

void backtrack(mytype *a,int k,int row,int col);
void con_candidate(mytype *a,int k,int row,int col,mytype *c,int *ncan);

void main()
{
	int test,i,len,row,col,rows,cols,j;
	char str[sz];
	mytype a[sz];


	//gets(str);
	//]sscanf(str,"%d",&test);

	scanf("%d\n",&test);

	while(test--)
	{
		row=1;
		while(gets(str))
		{
			len = strlen(str);
			if(len==0)break;
			if(str[0]>='0' && str[0]<='9')
			{
				sscanf(str,"%d %d",&rows,&cols);

				if(rows<=0 || rows>=row || cols<=0 || cols>col || grid[rows][cols]!='W')
					max =0;
				else{

					for(i=0;i<=(row*col);i++)
					a[i].row = a[i].col = 0;
					for(i=0;i<=row;i++)
					for(j=0;j<=col;j++)
					color[i][j]='w';

					a[1].row = rows;
					a[1].col = cols;
					max = 0;
					backtrack(a,1,row,col);

					for(i=0;i<row;i++)
					for(j=0;j<col;j++)
					if(color[i][j]=='b')
					max++;
				}
				printf("%d\n",max);
			}
			else
			{
				for(i=0;i<len;i++)
				grid[row][i+1] = str[i];				
				row++;
				col = len;
			}	
		
		}
	
	}
}

void backtrack(mytype *a,int k,int row,int col)
{
	mytype c[sz];
	int i,ncan;

	k++;
	con_candidate(a,k,row,col,c,&ncan);
	for(i=0;i<ncan;i++)
	{
		a[k].row = c[i].row;
		a[k].col = c[i].col;

		backtrack(a,k,row,col);
	}
}

void con_candidate(mytype *a,int k,int row,int col,mytype *c,int *ncan)
{
	int r,C;

	*ncan = 0;
	r = a[k-1].row;
	C = a[k-1].col;

    if(color[r][C]=='w' && grid[r][C]=='W')
		color[r][C] = 'b';
	if(r-1>=1 && color[r-1][C]=='w' && grid[r-1][C]=='W')
	{
		c[(*ncan)].row = r-1;
		c[(*ncan)].col = C;
		color[r-1][C]='b';
		(*ncan)++;
	}
	if(r+1<row && color[r+1][C]=='w' && grid[r+1][C]=='W')
	{
		c[(*ncan)].row = r+1;
		c[(*ncan)].col = C;
		color[r+1][C]='b';
		(*ncan)++;
	}
	if( C+1<=col && color[r][C+1]=='w'  && grid[r][C+1]=='W' )
	{
		c[(*ncan)].row = r;
		c[(*ncan)].col = C+1;
		color[r][C+1]='b';
		(*ncan)++;
	}
	if(C-1>=1 && color[r][C-1]=='w' && grid[r][C-1]=='W')
	{
		
		c[(*ncan)].row = r;
		c[(*ncan)].col = C-1;
		color[r][C-1]='b';
		*ncan = *ncan +1;
	}

	//diagonal up-left
	if(C-1>=1 && r-1>=1 && color[r-1][C-1]=='w' && grid[r-1][C-1]=='W')
	{
		c[(*ncan)].row = r-1;
		c[(*ncan)].col = C-1;
		color[r-1][C-1]='b';
		(*ncan)++;
	}
	//diagonal up-right
	if(r-1>=1 && C+1<=col && color[r-1][C+1]=='w' && grid[r-1][C+1]=='W')
	{
		c[(*ncan)].row = r-1;
		c[(*ncan)].col = C+1;
		color[r-1][C+1]='b';
		(*ncan)++;
	}
	//diagonal down-left
	if(r+1<row && C-1>=1 && color[r+1][C-1]=='w' && grid[r+1][C-1]=='W')
	{
		c[(*ncan)].row = r+1;
		c[(*ncan)].col = C-1;
		color[r+1][C-1]='b';
		(*ncan)++;
	}
	//diagonal down-right
	if(r+1<row && C+1<col && color[r+1][C+1]=='w' && grid[r+1][C+1]=='W')
	{
		c[(*ncan)].row = r+1;
		c[(*ncan)].col = C+1;
		color[r+1][C+1]='b';
		(*ncan)++;
	}
}


