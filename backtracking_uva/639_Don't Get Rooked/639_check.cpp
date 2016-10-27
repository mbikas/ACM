#include<stdio.h>
#include<string.h>
#define MAX 6

int max=0;
char board[MAX][MAX];
void backtrack(int a[MAX][MAX],int row,int col,int n);
void con_candidate(int a[MAX][MAX],int row,int col,int n,int c[],int *ncan);
void process_solution(int n,int a[MAX][MAX]);

void main()
{
	//freopen("639.out","w",stdout);

	int row,i,a[MAX][MAX];

	while(scanf("%d",&row)==1 && row)
	{

		for(i=0;i<row;i++)
		scanf(" %s",board[i]);

		memset(a,0,sizeof(a));
		max = 0;
		backtrack(a,0,-1,row);
		printf("%d\n",max);
	}
}

void backtrack(int a[MAX][MAX],int row,int col,int n)
{
	int i,ncan;

	int c[MAX];

	if(row==n-1 && col==n-1)
	{
		process_solution(n,a);
		//printf("ss\n");
	}
	else
	{
		col++;
		if(col>n-1)
		{	col=0;
			row++;
		}	
		con_candidate(a,row,col,n,c,&ncan);
		for(i=0;i<ncan;i++)
		{
			a[row][col] = c[i];
			backtrack(a,row,col,n);	
		}	
	}
}

void con_candidate(int a[MAX][MAX],int row,int col,int n,int c[],int *ncan)
{
	int i,j,f;
	bool possible = true;

	*ncan = 0;
	
	if(board[row][col]=='X')
	{
		c[(*ncan)++] = 0;
		return;
	}

	for(i=0;i<row;i++)
	{	if(a[i][col]==1)
		{
			f=0;
			for(j=i+1;j<row;j++)
			{
				if(board[j][col]=='X')
				{
					f=1;
					break;
				}			
			}
			if(f==0){
				possible = false;
				break;
			}
		}
	}
	for(i=0;i<col;i++)
	{	
		if(a[row][i]==1)
		{
			f=0;
			for(j=i+1;j<col;j++)
			{
				if(board[row][j]=='X')
				{
					f=1;
					break;
				}			
			}
			if(f==0){
				possible = false;
				break;
			}
		}
	}

	if(possible==false)
	{
		c[(*ncan)++]=0;
	}
	else
	{
		c[(*ncan)++]=1;
		//c[(*ncan)++]=0;	
	}
}


void process_solution(int n,int a[MAX][MAX])
{
	int i,j,sum=0;

	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	if(a[i][j]==1)
	sum++;
	

	if(sum>=max)
	{
		max = sum;

		/*for(i=0;i<n;i++)
		{for(j=0;j<n;j++)
		{printf("%d",a[i][j]);}
		printf("\n");
		}
		printf("----\n");
		*/
	}
}