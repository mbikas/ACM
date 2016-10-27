#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ans[9][9];

int access[8][8] = {{2,3,4,4,4,4,3,2},{3,4,6,6,6,6,4,3},{4,6,8,8,8,8,6,4},
              {4,6,8,8,8,8,6,4},{4,6,8,8,8,8,6,4},{4,6,8,8,8,8,6,4},
          {3,4,6,6,6,6,4,3},{2,3,4,4,4,4,3,2}};


bool color[9][9];
bool possible=false,finished;

void backtrack(int a[66][3],int move,int row,int col);
void con_cadidate(int a[66][3],int move,int row,int col,int x[66][3],int *ncan);

void main()
{
	int row,col,i,j,move;
	int a[66][3];

	while(scanf("%d %d",&row,&col)==2)
	{
		memset(ans,0,sizeof(ans));
		memset(color,false,sizeof(color));
		move=1;
		color[row][col]=true;
		possible = true;
		finished=false;
		ans[row][col]=move;
		a[1][0]=row;
		a[1][1]=col;
		backtrack(a,move,row,col);

		printf("move = %d\n",move);
		

		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				printf("%d ",ans[i][j]);			
			}
			printf("\n");
		
		}


	}
}

void backtrack(int a[66][3],int move,int row,int col)
{
	int x[66][3],i,R,C,ncan;

	if(move==64)
	{
		for(i=2;i<=64;i++)
		{
			R = a[i][0];
			C = a[i][1];
			ans[R][C] = i;
		}
		finished=true;		
	}
	else
	{
		move++;
		con_cadidate(a,move,row,col,x,&ncan);

		//if(finished)
		//printf("move = %d\nncan=%d\n",move,ncan);
		for(i=0;i<ncan;i++)
		{
			a[move][0]=x[i][0];
			a[move][1]=x[i][1];
			row = x[i][0];
			col = x[i][1];
			color[row][col]=true;
			backtrack(a,move,row,col);
			color[row][col]=false;

			
		}	
		if(finished)return;
	}

}

void con_cadidate(int a[66][3],int move,int row,int col,int x[66][3],int *ncan)
{

	int r,c,min,choice[9][3],i,tot=0;
	


	*ncan = 0;
	min = 10;
	


	r = row-2;
	c = col-1;
	if((r>=0 && r<=7) && (c>=0 && c<=7) && color[r][c]==false)
	{	if(access[r][c]<min)
		{	min = access[r][c];
			tot=0;
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
		else if(access[r][c]==min)
		{	min = access[r][c];
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
	
	}

	r = row-2;
	c = col+1;
	if((r>=0 && r<=7) && (c>=0 && c<=7) && color[r][c]==false)
	{	if(access[r][c]<min)
		{	min = access[r][c];
			tot=0;
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
		else if(access[r][c]==min)
		{	min = access[r][c];
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
	
	}

	r = row-1;
	c = col+2;
	if((r>=0 && r<=7) && (c>=0 && c<=7) && color[r][c]==false)
	{	if(access[r][c]<min)
		{	min = access[r][c];
			tot=0;
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
		else if(access[r][c]==min)
		{	min = access[r][c];
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
	
	}

	r = row-1;
	c = col-2;
	if((r>=0 && r<=7) && (c>=0 && c<=7) && color[r][c]==false)
	{	if(access[r][c]<min)
		{	min = access[r][c];
			tot=0;
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
		else if(access[r][c]==min)
		{	min = access[r][c];
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
	
	}
	
	r = row+1;
	c = col-2;
	if((r>=0 && r<=7) && (c>=0 && c<=7) && color[r][c]==false)
	{	if(access[r][c]<min)
		{	min = access[r][c];
			tot=0;
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
		else if(access[r][c]==min)
		{	min = access[r][c];
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
	}
	
	r = row+2;
	c = col-1;
	if((r>=0 && r<=7) && (c>=0 && c<=7) && color[r][c]==false)
	{	if(access[r][c]<min)
		{	min = access[r][c];
			tot=0;
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
		else if(access[r][c]==min)
		{	min = access[r][c];
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
	}
	
	r = row+2;
	c = col+1;
	if((r>=0 && r<=7) && (c>=0 && c<=7) && color[r][c]==false)
	{	if(access[r][c]<min)
		{	min = access[r][c];
			tot=0;
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
		else if(access[r][c]==min)
		{	min = access[r][c];
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
	}

	r = row+1;
	c = col+2;
	if((r>=0 && r<=7) && (c>=0 && c<=7) && color[r][c]==false)
	{	if(access[r][c]<min)
		{	min = access[r][c];
			tot=0;
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
		else if(access[r][c]==min)
		{	min = access[r][c];
			choice[tot][0]=r;
			choice[tot][1]=c;
			tot++;
		}
	}





	 for(i=0;i<tot;i++)
	 {
	
		x[(*ncan)][0] = choice[i][0];
		x[(*ncan)][1] = choice[i][1];
		(*ncan)++;
	 }
	
	//printf("row = %d col = %d min = %d move=%d ncan=%d\n",pos_r,pos_c,min,move,(*ncan));
}

