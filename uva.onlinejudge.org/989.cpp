#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 11


int num[sz][sz],x;
bool flag[sz][sz];
bool finished = false;
void construct_candidates(int a[sz][sz],int c[],int row,int col,int *ncandidates,int n);
void backtrack(int a[sz][sz],int row,int col,int n);
void process_solution(int a[sz][sz],int n);

void main()
{

	int i,j;
	int a[sz][sz],N,f=0;
	bool valid;

	while(scanf("%d",&x)==1 && x!=0)
	{
		
		if(f==1)printf("\n");
		else f=1;
		
		N=x*x;
		valid = true;

		for(i=0;i<=N;i++)
		for(j=0;j<=N;j++)
		flag[i][j]=false;
	
		for(i=0;i<N;i++)
		{	for(j=0;j<N;j++)
			{
				scanf("%d",&num[i][j]);
				if(num[i][j]!=0)
				flag[i][j] = true;
							
				a[i][j] = 0;
				if(num[i][j]>N)
					valid = false;

			}
		}

			
		if(valid==false)
		{
			printf("NO SOLUTION\n");
			continue;
		}
	
		//printf("------------\n");
		finished = false;
		backtrack(a,0,-1,N);
		
		if(finished==false)
			printf("NO SOLUTION\n");
		
	}
}

void backtrack(int a[sz][sz],int row,int col,int n)
{
	int ncandidates,i;
	int c[sz];

	if(row==n-1 && col==n-1)
	{
		process_solution(a,n);
		finished = true;
	
		
	}
	else
	{
		 
		col=col+1;  
		if(col>n-1)
		{
			col=0;
			row++;
		}
	
		construct_candidates(a,c,row,col,&ncandidates,n);
		for(i=0;i<ncandidates;i++)
		{
			a[row][col] = c[i];
			backtrack(a,row,col,n);
			if(finished)return;
		}	
	}
}

void process_solution(int a[sz][sz],int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
			printf("%d ",a[i][j]);
		printf("%d\n",a[i][n-1]);	

	}

	//printf("___________\n");

}

void construct_candidates(int a[sz][sz],int c[],int row,int col,int *ncandidates,int n)
{

	bool possible[sz];
	int i,j,row_lower,row_upper,col_lower,col_upper,p,q;  

	*ncandidates = 0;

	if(flag[row][col]==true)
	{
		c[(*ncandidates)++] = num[row][col];
		return;
	}

	for(i=1;i<=n;i++)
		possible[i] = true;


	

	for(i=0;i<row;i++)
		possible[a[i][col]] = false;
	for(i=row+1;i<n;i++)
		possible[num[i][col]] = false;
	
	
	for(i=0;i<col;i++)
		possible[a[row][i]] = false;
	for(i=col+1;i<n;i++)
		possible[num[row][i]] = false;




	

	p = row/x + 1;
	q = col/x + 1;

	row_upper = p*x;
	row_lower = p*x - x;
	col_upper = q*x;
	col_lower = q*x - x;

	for(i=row_lower;i<row;i++)
	{
		for(j=col_lower;j<col_upper;j++)
		{
			possible[a[i][j]]=false;		
		}
	}

	for(i=col_lower;i<col;i++)
		possible[a[row][i]]=false;


	for(i=col+1;i<col_upper;i++)
		possible[num[row][i]]=false;

	
	for(i=row+1;i<row_upper;i++)
	{
		for(j=col_lower;j<col_upper;j++)
		{
			possible[num[i][j]]=false;		
		}
	}

	
/*
	for(i=row_lower;i<row;i++)
	for(j=col_lower;j<col;j++)
	possible[a[i][j]]=false;

	
	for(i=row;i<row_upper;i++)
	for(j=col+1;j<col_upper;j++)
	possible[num[i][j]]=false;
*/
	for(i=1;i<=n;i++)
	//for(i=n;i>=1;i--)
	{	if(possible[i])
		c[(*ncandidates)++] = i;      
		
	}
	
}

