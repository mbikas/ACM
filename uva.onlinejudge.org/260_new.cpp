#include<stdio.h>
#include<string.h>
#define sz 205

char board[sz][sz];
bool white[sz][sz],black[sz][sz],finished;
int cases=1;

void floodfill_white(int n,int row,int col);
void floodfill_black(int n,int row,int col);

int main()
{
	int i,j,n;
	
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
					white[i][0]=true;
					floodfill_white(n,i,0);
					if(finished)break;
				}
			}
			if(finished)continue;
			
			memset(black,false,sizeof(black));
			for(i=0;i<n;i++)
			{
				if(board[0][i]=='b')
				{
					black[0][i]=true;
					floodfill_black(n,0,i);
					if(finished)break;
				}
			}
			
			
			
	}
	return 0;
}



void floodfill_black(int n,int row,int col)
{
	
	int c_row,c_col;
	
	if(finished)return;
	if(row==n-1)
	{
		printf("%d %c\n",cases++,'B');
		finished=true;
		return;		
	}
	
	c_row = row-1;
	c_col = col-1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) && board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		black[c_row][c_col]=true;
		floodfill_black(n,c_row,c_col);
	}
	
	c_row = row-1;
	c_col = col;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		black[c_row][c_col]=true;
		floodfill_black(n,c_row,c_col);
	}
	
	c_row = row;
	c_col = col-1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		black[c_row][c_col]=true;
		floodfill_black(n,c_row,c_col);
	}
	
	c_row = row;
	c_col = col+1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		black[c_row][c_col]=true;
		floodfill_black(n,c_row,c_col);
	}
	
	c_row = row+1;
	c_col = col;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		black[c_row][c_col]=true;
		floodfill_black(n,c_row,c_col);
	}
	
	c_row = row+1;
	c_col = col+1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='b' && black[c_row][c_col]==false )
	{
		black[c_row][c_col]=true;
		floodfill_black(n,c_row,c_col);
	}
}

void floodfill_white(int n,int row,int col)
{
	
	int c_row,c_col;
	
	if(finished)return;
	if(col==n-1)
	{
		printf("%d %c\n",cases++,'W');
		finished=true;
		return;		
	}
	
	c_row = row-1;
	c_col = col-1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) && board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		white[c_row][c_col]=true;
		floodfill_white(n,c_row,c_col);
	}
	
	c_row = row-1;
	c_col = col;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		white[c_row][c_col]=true;
		floodfill_white(n,c_row,c_col);
	}
	
	c_row = row;
	c_col = col-1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		white[c_row][c_col]=true;
		floodfill_white(n,c_row,c_col);
	}
	
	c_row = row;
	c_col = col+1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		white[c_row][c_col]=true;
		floodfill_white(n,c_row,c_col);
	}
	
	c_row = row+1;
	c_col = col;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		white[c_row][c_col]=true;
		floodfill_white(n,c_row,c_col);
	}
	
	c_row = row+1;
	c_col = col+1;
	if( (c_row>=0 && c_row<n) && (c_col>=0 && c_col<n) &&  board[c_row][c_col]=='w' && white[c_row][c_col]==false )
	{
		white[c_row][c_col]=true;
		floodfill_white(n,c_row,c_col);
	}
}