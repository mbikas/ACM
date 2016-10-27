//		  west
//	south	   north
//	      east

#include<stdio.h>
#include<string.h>



typedef struct{
    char col[55];
}ROW;
ROW row[55];

void main()
{
	//freopen("10377.in","r",stdin);
	//freopen("10377.out","w",stdout);


	int i,j,ir,ic,r,c,len,f;
	char dir;
	char a[110];

	

	scanf("%d %d\n",&r,&c);
	
	for(i=0;i<=r;i++)
		for(j=0;j<=c;j++)
			row[i].col[j]='0';


	while(scanf("%d %d %c",&ir,&ic,&dir)==3)
	{


		scanf(" %[^\n]",a);
		//gets(a);
		len = strlen(a);

		f=0;



		
		for(i=0;i<len;i++)
		{
			if(a[i]=='R'||a[i]=='L'||a[i]=='F')
			{
				if(a[i]=='R')
				{
					if(dir=='N')dir = 'E';
					else if(dir=='E')dir = 'S';
					else if(dir=='S')dir = 'W';
					else if(dir=='W')dir = 'N';
				}
				else if(a[i]=='L')
				{
					if(dir=='N')dir = 'W';
					else if(dir=='W')dir = 'S';
					else if(dir=='S')dir = 'E';
					else if(dir=='E')dir = 'N';
				}
				else
				{
					if(dir=='N')
					{
						if(ic==c)
						{
							if(row[ir].col[ic]!='1')
							{
								printf("%d %d %c LOST\n",ir,ic,dir);
								row[ir].col[ic]='1';
								f=1;
								break;
							}
						}
						else
						{
							ir = ir;
							ic = ic+1;
							
						}					
					}

					else if(dir=='S')
					{
						if(ic==0)
						{
							if(row[ir].col[ic]!='1')
							{
								printf("%d %d %c LOST\n",ir,ic,dir);
								row[ir].col[ic]='1';
								f=1;
								break;
							}
						}
						else
						{
							ir = ir;
							ic = ic-1;
							
						}					
					}

					else if(dir=='W')
					{
						if(ir==0)
						{
							if(row[ir].col[ic]!='1')
							{
								printf("%d %d %c LOST\n",ir,ic,dir);
								row[ir].col[ic]='1';
								f=1;
								break;
							}
						}
						else
						{
							ir = ir-1;
							ic = ic;
							
						}					
					}
					else if(dir=='E')
					{
						if(ir==r)
						{
							if(row[ir].col[ic]!='1')
							{
								printf("%d %d %c LOST\n",ir,ic,dir);
								row[ir].col[ic]='1';
								f=1;
								break;
							}
						}
						else
						{
							ir = ir+1;
							ic = ic;							
						}					
					}
				}

				
				//printf("%d %d %c\n",ir,ic,dir);
				
			}
			else
			{}		
		}//for

		if(f==0)
			printf("%d %d %c\n",ir,ic,dir);

		//for(i=0;i<=r;i++)
		//{	for(j=0;j<=c;j++)
		//{	printf("%c",row[i].col[j]);}
		//	printf("\n");
		//}
	
	
	}//while
	
}//main
