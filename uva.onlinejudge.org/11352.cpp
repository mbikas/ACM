#include<stdio.h>
#include<string.h>
#define sz 105
#define SZ sz*sz

int m,n,min,move,total;

//bool visit[sz][sz];
char grid[sz][sz];
bool possible[sz][sz],found;
bool flag[sz][sz];
void floodfill(int row,int col);
int val[sz][sz];


int main()
{
	int test,i,j,c_row,c_col,r,c;
	
	scanf("%d",&test);

	while(test--)
	{
		scanf("%d %d",&n,&m);

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf(" %c",&grid[i][j]);
				possible[i][j]=true;
				flag[i][j]=true;
				val[i][j]=50000;
			}
		}
		total=0;
		//memset(possible,true,sizeof(possible));
		//memset(visit,false,sizeof(visit));
		//memset(val,50000,sizeof(val));

		//////////////////////////////////////
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(grid[i][j]=='Z')
				{
					r = i+2;
					c = j-1;
					if( r<n && c>=0)
					{
						possible[r][c]=false;
						
						
					}

					r = i+2;
					c = j+1;
					if( r<n && c<m )
					{
						possible[r][c]=false;
						
					}

					r = i-2;
					c = j+1;
					if( r>=0 && c<m )
					{
						possible[r][c]=false;
						
					}

					r = i-2;
					c = j-1;
					if( r>=0 && c>=0  )
					{
						possible[r][c]=false;
						
					}
					
					r = i-1;
					c = j-2;
					if(r>=0 && c>=0 )
					{
						possible[r][c]=false;
					}

					r = i-1;
					c = j+2;
					if(r>=0 && c<m )
					{
						possible[r][c]=false;
						
					}

					r = i+1;
					c = j-2;
					if(r<n && c>=0 )
					{
						possible[r][c]=false;
						
					}

					r = i+1;
					c = j+2;
					if( r<n && c<m )
					{
						possible[r][c]=false;
						
					}

					possible[i][j]=false;

				}
			}
		}
		/////////////////////////////////////////////

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(grid[i][j]=='A' || grid[i][j]=='B')
				{
					possible[i][j]=true;

				}
				if(grid[i][j]=='A')
				{	c_row = i;
					c_col=j;
				}
			}
		}
		/////////////////////////////////////

		//memset(flag,true,sizeof(flag));
		
		flag[c_row][c_col]=false;
		found = false;
		move=0;
		
		min = 100000;
		floodfill(c_row,c_col);

		if(found)
		{
			printf("Minimal possible length of a trip is %d\n",min);
		}
		else
		{
			printf("King Peter, you can't go now!\n");
		}
		
	}

	return 0;
	
}

void floodfill(int row,int col)
{
	
	int c_row,c_col;
	

	if(val[row][col]<=move)return;	
	if(move>=min)return;
	val[row][col]=move;

		
	if(grid[row][col]=='B')
	{
		if(move<min)min = move;
		found = true;
		return;
	}
	
	
	c_row = row-1;
	c_col = col-1;
	if( (c_row>=0 && c_col>=0 )  && possible[c_row][c_col] && flag[c_row][c_col])
	{
		move++;
		flag[c_row][c_col] = false;
		floodfill(c_row,c_col);
		move--;
		flag[c_row][c_col] = true;
	}
	
	c_row = row-1;
	c_col = col;
	if( c_row>=0 && possible[c_row][c_col] && flag[c_row][c_col])
	{
		move++;
		flag[c_row][c_col] = false;
		floodfill(c_row,c_col);
		move--;
		flag[c_row][c_col] = true;
	}
	
	c_row = row;
	c_col = col-1;
	if( c_col>=0  && possible[c_row][c_col] && flag[c_row][c_col])
	{
		move++;
		flag[c_row][c_col] = false;
		floodfill(c_row,c_col);
		move--;
		flag[c_row][c_col] = true;
	}
	
	c_row = row;
	c_col = col+1;
	if( c_col<m && possible[c_row][c_col] && flag[c_row][c_col])
	{
		move++;
		flag[c_row][c_col] = false;
		floodfill(c_row,c_col);
		move--;
		flag[c_row][c_col] = true;
	}
	c_row = row+1;
	c_col = col;
	if( c_row<n &&  possible[c_row][c_col] && flag[c_row][c_col])
	{
		move++;
		flag[c_row][c_col] = false;
		floodfill(c_row,c_col);
		move--;
		flag[c_row][c_col] = true;
	}
	
	c_row = row+1;
	c_col = col+1;
	if( (c_row<n && c_col<m) && possible[c_row][c_col] && flag[c_row][c_col])
	{
		move++;
		flag[c_row][c_col] = false;
		floodfill(c_row,c_col);
		move--;
		flag[c_row][c_col] = true;
	}
	c_row = row-1;
	c_col = col+1;
	if( (c_row>=0 && c_col<m)  && possible[c_row][c_col] && flag[c_row][c_col])
	{
		move++;
		flag[c_row][c_col] = false;
		floodfill(c_row,c_col);
		move--;
		flag[c_row][c_col] = true;
	}
	c_row = row+1;
	c_col = col-1;
	if( ( c_row<n && c_col>=0) && possible[c_row][c_col] && flag[c_row][c_col])
	{
		move++;
		flag[c_row][c_col] = false;
		floodfill(c_row,c_col);
		move--;
		flag[c_row][c_col] = true;
	}
}
//(grid[c_row][c_col]=='.' || grid[c_row][c_col]=='B') &&
