//		north
//	west	  east
//	    south

#include<stdio.h>
#include<string.h>

#define north -4
#define east -3
#define south -2
#define west -1


typedef struct{
    char col[70];
}ROW;
ROW row[65];

void main()
{
	//freopen("10377.in","r",stdin);
	//freopen("10377.out","w",stdout);


	long test;
	int i,j,ir,ic,r,c,dir,f=0;
	char a[100];


	scanf("%ld",&test);

	while(test--)
	{
		if(f==1)
			printf("\n");
		else
			f=1;
		scanf("%d %d\n",&r,&c);		

		for(i=1;i<=r;i++)
		{

			gets(a);

			for(j=0;j<c;j++)
				row[i].col[j+1]=a[j];
		}


		//for(i=1;i<=r;i++)
		//{for(j=1;j<=c;j++)
		//  			printf("%c",row[i].col[j]);
		//  printf("\n");
		//}
		scanf("%d %d",&ir,&ic);	
		dir  = north;

		//printf("%d %d\n",ir,ic);

		while(scanf("%c",&c)==1)
		{
			if(c=='Q')
			{
				
				printf("%d %d ",ir,ic);
				if(dir==north)printf("N\n");
				else if(dir==east)printf("E\n");
				else if(dir==west)printf("W\n");
				else if(dir==south)printf("S\n");
				break;
			}
			else if(c=='R'||c=='L'||c=='F')
			{
				if(c=='R')
				{
					if(dir==north)dir = east;
					else if(dir==east)dir = south;
					else if(dir==south)dir = west;
					else if(dir==west)dir = north;
				}
				else if(c=='L')
				{
					if(dir==north)dir = west;
					else if(dir==west)dir = south;
					else if(dir==south)dir = east;
					else if(dir==east)dir = north;
				}
				else
				{
					if(dir==north && ir!=1)
					{
						if(row[ir-1].col[ic]!='*')
						{
							ir = ir-1;
							ic = ic;
						}					
					}
					else if(dir==south && ir!=r)
					{
						if(row[ir+1].col[ic]!='*')
						{
							ir = ir+1;
							ic = ic;
						}	
					}
					else if(dir==east && ic!=c)
					{
						if(row[ir].col[ic+1]!='*')
						{
							ir = ir;
							ic = ic+1;
						}	
					}
					else if(dir==west && ic!=1)
					{
						if(row[ir].col[ic-1]!='*')
						{
							ir = ir;
							ic = ic-1;
						}	
					}
				
				}

				/*
				printf("%d %d ",ir,ic);
				if(dir==north)printf("N\n");
				else if(dir==east)printf("E\n");
				else if(dir==west)printf("W\n");
				else if(dir==south)printf("S\n");
				*/
			}
			else
			{}		
		}
	
	
	}//while
	
}//main
