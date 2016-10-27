#include<stdio.h>
#include<string.h>


void main()
{
	
	int n,north,south,east,west,top,bottom;
	char command[15];

	while(scanf("%d",&n)==1 && n!=0)
	{
		north = 2;
		south = 5;
		top = 1;
		west = 3;
		east = 4;
		bottom = 6; 
	
		while(n>0)
		{
		
			scanf(" %s",command);

			if(strcmp(command,"north")==0)
			{
				north = top;
				top = south;				
				south = bottom;
				bottom = 7 - top;
				west= west;
				east = east;
			
			}
			else if(strcmp(command,"east")==0)
			{
				east = top;
				top = west;
				west = bottom;
				bottom = 7 - top;
				south = south;
				north = north;			
			}
			else if(strcmp(command,"south")==0)
			{
				south = top;
				top = north;
				north = bottom;
				bottom = 7 - top;
				west = west;
				east = east;		
			}
			else if(strcmp(command,"west")==0)
			{
				west = top;
				top = east;
				east = bottom;
				bottom = 7 - top;
				north = north;
				south = south;			
			}		
			n--;
		}

		printf("%d\n",top);
		

	
	}

}
