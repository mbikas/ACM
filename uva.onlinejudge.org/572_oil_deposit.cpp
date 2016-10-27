#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 102

typedef struct{
	int row;
	int col;
}mytype;

int val[MAX][MAX],p=0;
char color[MAX][MAX];
char oil[MAX][MAX];

void backtrack(mytype *a,int k,int rows,int cols,int ans1);
void con_candidate(mytype *a,int k,int rows,int cols,mytype *c,int *ncan,int ans);







void main()
{

    //freopen("572in.txt","r",stdin);
    //freopen("572out.txt","w",stdout);

	 int rows,cols,i,j,k,l;
	 char temp;
	 mytype a[MAX];

	 while(scanf("%d %d\n",&rows,&cols)==2 && rows)
	 {
		for(i=0;i<rows;i++)
		{ for(j=0;j<cols;j++)
			scanf("%c",&oil[i][j]) ;
			scanf("%c",&temp);
		}
		for(i=0;i<rows;i++)
		{
		  for(j=0;j<cols;j++)
		  { //printf("%c\t",oil[i][j]);
			 val[i][j]=0;
			 color[i][j]='w';
		  }
		  //printf("\n");
		}

		p=0;
		for(i=0;i<rows;i++)
		{
		  for(j=0;j<cols;j++)
		  {
			 if(oil[i][j]=='@' && color[i][j]=='w')
			 {
					p = p+1;

               //printf("p = %d\n",p);

               for(k=0;k<=MAX;k++)
					{  a[k].row=0;
						a[k].col =0;
					}              
					a[1].row = i;
					a[1].col = j;
					backtrack(a,1,rows,cols,p);

               /*
               for(k=0;k<rows;k++)
               {for(l=0;l<cols;l++)
               printf("%c",color[k][l]);
               printf("\n");
               }
               */
               


			  }
		  }
		}


      /*
		for(i=0;i<rows;i++)
		{for(j=0;j<cols;j++)
		printf("%d",val[i][j]);
		printf("\n");
		}
      */

      printf("%d\n",p);




	 } //while
}    //main


void backtrack(mytype *a,int k,int rows,int cols,int ans1)
{
	mytype c[MAX];
	int i,ncan;

   //printf("ans1 = %d\n",ans1);

	k++;
	con_candidate(a,k,rows,cols,c,&ncan,ans1);
	for(i=0;i<ncan;i++)
	{
		a[k].row = c[i].row;
		a[k].col = c[i].col;
		backtrack(a,k,rows,cols,ans1);
	}
}

void con_candidate(mytype *a,int k,int rows,int cols,mytype *c,int *ncan,int ans)
{
	int r,C;

	*ncan = 0;

	r = a[k-1].row;
	C = a[k-1].col;



	if(color[r][C]=='w')
	{
		  color[r][C] = 'b';
		  val[r][C]=ans;
	}
	if(r-1>=0 && oil[r-1][C]=='@' && color[r-1][C]=='w')
	{
		c[(*ncan)].row = r-1;
		c[(*ncan)].col = C;
		color[r-1][C]='b';
		val[r-1][C] = ans;
		(*ncan)++;
	}
	if(r+1<rows && oil[r+1][C]=='@' && color[r+1][C]=='w')
	{
		c[(*ncan)].row = r+1;
		c[(*ncan)].col = C;
		color[r+1][C]='b';
		val[r+1][C] = ans;
      (*ncan)++;
	}
	if( C+1<cols && oil[r][C+1]=='@' && color[r][C+1]=='w' )
	{
		c[(*ncan)].row = r;
		c[(*ncan)].col = C+1;
		color[r][C+1]='b';
		val[r][C+1] = ans;
     (*ncan)++;
	}
	if(C-1>=0 && oil[r][C-1]=='@' && color[r][C-1]=='w')
	{

		c[(*ncan)].row = r;
		c[(*ncan)].col = C-1;
		color[r][C-1]='b';
		val[r][C-1] = ans;
      *ncan = *ncan +1;
	}

	//diagonal up-left
	if(C-1>=0 && r-1>=0 && oil[r-1][C-1]=='@' && color[r-1][C-1]=='w')
	{
		c[(*ncan)].row = r-1;
		c[(*ncan)].col = C-1;
		color[r-1][C-1]='b';
		val[r-1][C-1] = ans;
     	(*ncan)++;
	}
	//diagonal up-right
	if(r-1>=0 && C+1<cols && oil[r-1][C+1]=='@' && color[r-1][C+1]=='w')
	{
		c[(*ncan)].row = r-1;
		c[(*ncan)].col = C+1;
		color[r-1][C+1]='b';
      val[r-1][C+1] = ans;
      (*ncan)++;
	}
	//diagonal down-left
	if(r+1<rows && C-1>=0 && oil[r+1][C-1]=='@' && color[r+1][C-1]=='w')
	{
		c[(*ncan)].row = r+1;
		c[(*ncan)].col = C-1;
		color[r+1][C-1]='b';
      val[r+1][C-1] = ans;
      (*ncan)++;
	}
	//diagonal down-right
	if(r+1<rows && C+1<cols && oil[r+1][C+1]=='@' && color[r+1][C+1]=='w')
	{
		c[(*ncan)].row = r+1;
		c[(*ncan)].col = C+1;
		color[r+1][C+1]='b';
		val[r+1][C+1] = ans;
      (*ncan)++;
	}
}
