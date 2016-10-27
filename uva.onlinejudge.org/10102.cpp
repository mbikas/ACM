#include<stdio.h>
#include<math.h>
#define sz 102
#define MAX 10000000L 

long tot=0;
int grid[sz][sz];

typedef struct{
	long x,y;
}THREE;
THREE three[sz*sz];


int main()
{
	char input[500];
	long i,j,k,min,max,diff,n;
	
	while(gets(input))
	{
		sscanf(input,"%ld",&n);
		
		tot=0;
		for(i=0;i<n;i++)
		{
			gets(input);
			for(j=0;j<n;j++)
			{
				grid[i][j]= input[j] - '0';
				if(grid[i][j]==3){
					three[tot].x = i;
					three[tot].y = j;
					tot++;
				}	
			}
		}
		
	
		max = 0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				min = MAX;
				if(grid[i][j]==1)
				{
					for(k=0;k<tot;k++)
					{
						diff = abs(i - three[k].x) + abs(j - three[k].y);
						if(diff<min)min = diff;
					}
					
					if(min>max)max = min;					
				}
			}	
		}
		
		printf("%ld\n",max);
		
		
	}
	
	
	return 0;
}