#include<stdio.h>
#include<string.h>
#define sz 12

int num[sz][sz];
char grid[sz][sz];

int main()
{
	//freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	bool start = false;
	int i,j,k,row,col,counter,cases=1;


	while(scanf("%d",&row)==1 && row)
	{
		scanf("%d",&col);

		if(start)printf("\n");
		else start = true;

		for(i=0;i<row;i++)
			scanf(" %s",grid[i]);

		memset(num,0,sizeof(num));
		counter=1;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(i==0 && grid[i][j]!='*')
					num[i][j]=counter++;
				else if(j==0 && grid[i][j]!='*')
					num[i][j]=counter++;
				else if(i>=1 && j>=1 && grid[i][j]!='*')
				{
					if(grid[i][j-1]=='*' || grid[i-1][j]=='*')
						num[i][j]=counter++;
				}
			}
		}

		/*
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				printf("%d ",num[i][j]);
			}
			printf("\n");
		}
		*/

		printf("puzzle #%d:\n",cases++);
		printf("Across\n");
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(num[i][j]!=0)
				{
					printf("%3d.",num[i][j]);
					for(; ;j++)
					{
						if(grid[i][j]=='*' || j==col)break;
						printf("%c",grid[i][j]);
					}
					printf("\n");
				}
				//printf("%d ",num[i][j]);
			}
			//printf("\n");
		}

		
		printf("Down\n");
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(num[i][j]!=0)
				{
					printf("%3d.",num[i][j]);
					for(k=i;k<row;k++)
					{
						if(grid[k][j]=='*')break;
						printf("%c",grid[k][j]);
						num[k][j]=0;
					}
					printf("\n");
				}
				//printf("%d ",num[i][j]);
			}
			//printf("\n");
		}
	
	
	
	}

	return 0;
}