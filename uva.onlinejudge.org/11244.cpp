#include<stdio.h>
#define sz 105

char star[sz][sz];
bool check(int rows,int cols);
int row,col;

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);

	int count,i,j;
	while(scanf("%d %d\n",&row,&col)==2)
	{
		if(row==0 && col==0)break;

		for(i=0;i<row;i++)
		gets(star[i]);

		count=0;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				
				if(star[i][j]=='*')
				{
					
					if(check(i,j)==false)count++;
				}
			}		
		}
		
		printf("%d\n",count);
	
	}


	return 0; 
}

bool check(int rows,int cols)
{
	int crow,ccol;
	

	crow = rows-1;
	ccol = cols;
	if( crow>=0 && star[crow][ccol]=='*') 
	{
		return true;
	}
	crow = rows+1;
	ccol = cols;
	if( crow<row && star[crow][ccol]=='*') 
	{
		return true;
	}
	crow = rows;
	ccol = cols+1;
	if( ccol<col && star[crow][ccol]=='*') 
	{
		return true;
	}
	crow = rows;
	ccol = cols-1;
	if( ccol>=0 && star[crow][ccol]=='*') 
	{
		return true;
	}
	crow = rows+1;
	ccol = cols+1;
	if( crow<row && ccol<col && star[crow][ccol]=='*') 
	{
		return true;
	}
	crow = rows+1;
	ccol = cols-1;
	if( crow<row && ccol>=0 && star[crow][ccol]=='*' ) 
	{
		return true;
	}
	crow = rows-1;
	ccol = cols+1;
	if( crow>=0 && ccol<col && star[crow][ccol]=='*' ) 
	{

		return true;
	}
	crow = rows-1;
	ccol = cols-1;
	if( crow>=0 && ccol>=0 && star[crow][ccol]=='*' ) 
	{
		return true;
	}
	return false;

}