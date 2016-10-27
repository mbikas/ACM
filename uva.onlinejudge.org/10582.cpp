#include<stdio.h>
#include<string.h>
#define MAX 10

int n[MAX][MAX];
typedef struct{
	int row;
	int col;
}mytype;
mytype a[70];
int sol=0;

void backtrack(mytype a[],int k,int t_row,int t_col);
void con_candidate(mytype a[],int k,int t_row,int t_col,mytype c[],int *ncan);

void main()
{
	int test,i,j,p,len,r,c;
	char str[1000];

	scanf("%d",&test);

	while(test--)
	{
		scanf("%d %d",&r,&c);
		
		for(i=0;i<r;i++)
		{
			scanf(" %[^\n]",str);
			scanf(" %[^\n]",str);
			
			scanf(" %[^\n]",str);			
			len = strlen(str);
			p=0;			
			for(j=1;j<len;j++)
			{
				//printf("%d = %c\n",j,str[j]);
				if(str[j]=='*' && str[j+1]=='*' &&str[j+2]=='*' )
				n[i][p] = 1;
				else if(str[j]=='*' && str[j+1] && str[j+2]==' ')
				n[i][p] = 2;
				else
				n[i][p]=0;
				j+=3;
				p++;
			}
			scanf(" %[^\n]",str);
		}
		scanf(" %[^\n]",str);

		//for(i=0;i<r;i++)
		////{	for(j=0;j<c;j++)
		//	printf("%d",n[i][j]);	
		//	printf("\n");
		//}

		for(i=0;i<=r*c;i++)
		{
			a[i].row = 0;
			a[i].col = 0;		
		}
		a[1].row = 0;
		a[1].col = 0;
		sol=0;
		backtrack(a,1,r,c);

		printf("Number of solutions: %d\n",sol);



	
	}//while
}//mstrin

void backtrack(mytype a[],int k,int t_row,int t_col)
{
	int i,ncan;
	mytype c[70];


	if(n[a[k].row][a[k].col]==0)return;

	if(a[k].row == t_row-1 && a[k].col == t_col-1)
	{
		//for(i=1;i<=k;i++)
		//printf("(%d %d) ",a[i].row,a[i].col);
		//printf("\n");
		sol++;	
		return;
	}
	
	
		k++;
		con_candidate(a,k,t_row,t_col,c,&ncan);
		for(i=0;i<ncan;i++)
		{
			a[k].row = c[i].row;
			a[k].col = c[i].col;
			backtrack(a,k,t_row,t_col);		
		}
	

}

void con_candidate(mytype a[],int k,int t_row,int t_col,mytype c[],int *ncan)
{

	int rows,cols,i,r1,c1;
	*ncan = 0;

	bool choice[MAX][MAX];

	rows = a[k-1].row;
	cols = a[k-1].col;


	if(cols<t_col-1)choice[rows][cols+1]=true;
	if(cols>=1)choice[rows][cols-1]=true;
	if(rows>=1)choice[rows-1][cols]=true;
	if(rows<t_row-1)choice[rows+1][cols]=true;

	for(i=1;i<k;i++)
		choice[a[i].row][a[i].col] = false;

	if(n[rows][cols]==1)
	{
		if(k==2)
		{
			//right
			if(cols<t_col-1 && n[rows][cols+1]!=0 && choice[rows][cols+1])
			{
				c[(*ncan)].row = rows;
				c[(*ncan)].col = cols+1;
				(*ncan)++;
			}
			//down
			if(rows<t_row-1 && n[rows+1][cols]!=0 && choice[rows+1][cols])
			{
				c[(*ncan)].row = rows+1;
				c[(*ncan)].col = cols;
				(*ncan)++;
			}
			return;
		}
		r1 = a[k-2].row;
		c1 = a[k-2].col;

		if(cols==c1)
		{
			//up
			if(rows>=1 && n[rows-1][cols]!=0 && choice[rows-1][cols])
			{
				c[(*ncan)].row = rows-1;
				c[(*ncan)].col = cols;
				(*ncan)++;
			}
			//down
			if(rows<t_row-1 && n[rows+1][cols]!=0 && choice[rows+1][cols])
			{
				c[(*ncan)].row = rows+1;
				c[(*ncan)].col = cols;
				(*ncan)++;
			}
			return;	
		}
		if(rows==r1)
		{
			//right
			if(cols<t_col-1 && n[rows][cols+1]!=0 && choice[rows][cols+1])
			{
				c[(*ncan)].row = rows;
				c[(*ncan)].col = cols+1;
				(*ncan)++;
			}
			//left
			if(cols>=1 && n[rows][cols-1]!=0 && choice[rows][cols-1])
			{
				c[(*ncan)].row = rows;
				c[(*ncan)].col = cols-1;
				(*ncan)++;
			}
			return;	
		}

	}

	if(n[rows][cols]==2)
	{
		if(k==2)
		{
			//right
			if(cols<t_col-1 && n[rows][cols+1]!=0 && choice[rows][cols+1])
			{
				c[(*ncan)].row = rows;
				c[(*ncan)].col = cols+1;
				(*ncan)++;
			}
			//down
			if(rows<t_row-1 && n[rows+1][cols]!=0 && choice[rows+1][cols])
			{
				c[(*ncan)].row = rows+1;
				c[(*ncan)].col = cols;
				(*ncan)++;
			}
			return;
		}
		r1 = a[k-2].row;
		c1 = a[k-2].col;

		if(rows==r1)
		{
			//up
			if(rows>=1 && n[rows-1][cols]!=0 && choice[rows-1][cols])
			{
				c[(*ncan)].row = rows-1;
				c[(*ncan)].col = cols;
				(*ncan)++;
			}
			//down
			if(rows<t_row-1 && n[rows+1][cols]!=0 && choice[rows+1][cols])
			{
				c[(*ncan)].row = rows+1;
				c[(*ncan)].col = cols;
				(*ncan)++;
			}
			return;	
		}
		if(cols==c1)
		{
			//right
			if(cols<t_col-1 && n[rows][cols+1]!=0 && choice[rows][cols+1])
			{
				c[(*ncan)].row = rows;
				c[(*ncan)].col = cols+1;
				(*ncan)++;
			}
			//left
			if(cols>=1 && n[rows][cols-1]!=0 && choice[rows][cols-1])
			{
				c[(*ncan)].row = rows;
				c[(*ncan)].col = cols-1;
				(*ncan)++;
			}
			return;	
		}

	}




}