#include<stdio.h>
#include<string.h>
#define sz 1000

char board[6][6];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char input[sz];
	bool found,end,illegal,start=false;
	int i,j,len,row,col,c_row,c_col,cases=1;
	
	
	while(gets(input))
	{
		if(strcmp(input,"Z")==0)break;
		strcpy(board[0],input);
		for(i=1;i<5;i++)gets(board[i]);
		
		found = false;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(board[i][j]==' ')
				{
					row=i;
					col=j;
					found = true;
					break;
				}
			}
			if(found)break;
		}
		
		end = illegal = false;
		while( gets(input))
		{

			
			len = strlen(input);			
			for(i=0;i<len;i++)
			{
				if(input[i]=='0')
				{
					end = true;
					break;
				}
				if(input[i]=='A')
				{

					c_row = row-1;
					c_col = col;

					if( (c_row>=0 && c_row<5) &&  (c_col>=0 && c_col<5) )
					{
					
						board[row][col]=board[c_row][c_col];
						board[c_row][c_col]=' ';
						row = c_row;
						col = c_col;
					}
					else
					{
						illegal = true;
						break;
					}
				}
				else if(input[i]=='B')
				{
					c_row = row+1;
					c_col = col;
					if( (c_row>=0 && c_row<5) &&  (c_col>=0 && c_col<5) )
					{
					
						board[row][col]=board[c_row][c_col];
						board[c_row][c_col]=' ';
						row = c_row;
						col = c_col;
					}
					else
					{
						illegal = true;
						break;
					}				
				}
				else if(input[i]=='R')
				{
					c_row = row;
					c_col = col+1;
					if( (c_row>=0 && c_row<5) &&  (c_col>=0 && c_col<5) )
					{
					
						board[row][col]=board[c_row][c_col];
						board[c_row][c_col]=' ';
						row = c_row;
						col = c_col;
					}
					else
					{
						illegal = true;
						break;
					}				
				}
				else if(input[i]=='L')
				{
					c_row = row;
					c_col = col-1;
					if( (c_row>=0 && c_row<5) &&  (c_col>=0 && c_col<5) )
					{
					
						board[row][col]=board[c_row][c_col];
						board[c_row][c_col]=' ';
						row = c_row;
						col = c_col;
					}
					else
					{
						illegal = true;
						break;
					}				
				}
				else
					illegal = true;
			}

			if(input[len-1]=='0' || end==true)
			{
				//print output;
				if(start)printf("\n");
				else start=true;
				printf("Puzzle #%d:\n",cases++);
				if(illegal)printf("This puzzle has no final configuration.\n");
				else
				{
					for(i=0;i<5;i++)
					{
						for(j=0;j<4;j++)
							printf("%c ",board[i][j]);
						printf("%c\n",board[i][j]);
					}				
				}				
				break;
			}
		}
		
		
		
	}
	
	
	return 0;
}