#include<stdio.h>
#include<string.h>
#define sz 205
#define SZ 10000

char board[sz][sz];
bool white[sz][sz],black[sz][sz],finished;
int cases=1;

void floodfill_white(int a[SZ][3],int k,int n);
void con_candidate_white(int a[SZ][3],int k,int n,int *ncan,int c[SZ][3]);

void floodfill_black(int a[SZ][3],int k,int n);
void con_candidate_black(int a[SZ][3],int k,int n,int *ncan,int c[SZ][3]);

int main()
{
	int i,j,n;
	int a[SZ][3];
	
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf(" %c",&board[i][j]);
			
			finished=false;
			memset(white,false,sizeof(white));
			for(i=0;i<n;i++)
			{
				if(board[i][0]=='w')
				{
					a[1][0]=i;
					a[1][1]=0;
					white[i][0]=true;
					floodfill_white(a,1,n);
					if(finished)break;
				}
			}
			if(finished)continue;
			
			memset(black,false,sizeof(black));
			for(i=0;i<n;i++)
			{
				if(board[0][i]=='b')
				{
					a[1][0]=0;
					a[1][1]=i;
					black[0][i]=true;
					floodfill_black(a,1,n);
					if(finished)break;
				}
			}
			
			
			
	}
	return 0;
}



void floodfill_black(int a[SZ][3],int k,int n)
{
	int c[SZ][3],ncan,i;
	
	
	k++;
	con_candidate_black(a,k,n,&ncan,c);
	for(i=0;i<ncan;i++)
	{
		a[k][0]=c[i][0];
		a[k][1]=c[i][1];
		if(c[i][0]==n-1)
		{
			printf("%d %c\n",cases++,'B');
			finished=true;
			return;				
		}	
		floodfill_black(a,k,n);
		if(finished)return;
	}
	
}

void con_candidate_black(int a[SZ][3],int k,int n,int *ncan,int c[SZ][3])
{
	
	int row,col,c_row,c_col;
	
	*ncan=0;
	
	row = a[k-1][0];
	col = a[k-1][1];
	
	c_row = row-1;
	c_col = col-1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) && board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		black[c_row][c_col]=true;
	}
	
	c_row = row-1;
	c_col = col;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		black[c_row][c_col]=true;
	}
	
	c_row = row;
	c_col = col-1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		black[c_row][c_col]=true;
	}
	
	c_row = row;
	c_col = col+1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		black[c_row][c_col]=true;
	}
	
	c_row = row+1;
	c_col = col;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		black[c_row][c_col]=true;
	}
	
	c_row = row+1;
	c_col = col+1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		black[c_row][c_col]=true;
	}
}

void floodfill_white(int a[SZ][3],int k,int n)
{
	int c[SZ][3],ncan,i;
	
	
	k++;
	con_candidate_white(a,k,n,&ncan,c);
	for(i=0;i<ncan;i++)
	{
		
		a[k][0]=c[i][0];
		a[k][1]=c[i][1];
		
		if(c[i][1]==n-1)
		{
			printf("%d %c\n",cases++,'W');
			finished=true;
			return;				
		}			
		floodfill_white(a,k,n);
		if(finished)return;
	}
	
}

void con_candidate_white(int a[SZ][3],int k,int n,int *ncan,int c[SZ][3])
{
	
	int row,col,c_row,c_col;
	
	*ncan=0;
	
	row = a[k-1][0];
	col = a[k-1][1];
	
	c_row = row-1;
	c_col = col-1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) && board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		white[c_row][c_col]=true;
	}
	
	c_row = row-1;
	c_col = col;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		white[c_row][c_col]=true;
	}
	
	c_row = row;
	c_col = col-1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		white[c_row][c_col]=true;
	}
	
	c_row = row;
	c_col = col+1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		white[c_row][c_col]=true;
	}
	
	c_row = row+1;
	c_col = col;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		white[c_row][c_col]=true;
	}
	
	c_row = row+1;
	c_col = col+1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		c[(*ncan)][0]=c_row;
		c[(*ncan)][1]=c_col;
		(*ncan)++;
		white[c_row][c_col]=true;
	}
}