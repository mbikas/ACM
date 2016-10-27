//		  north
//	  west	   east
//	      south

#include<stdio.h>
#include<string.h>



typedef struct{
    char col[12];
}ROW;
ROW row[12];
int a[11][11];

void main()
{
	int i,j,r,c,rown,coln,f,exit,n,pos,step;
	char str[12];
	
	while(scanf("%d %d %d",&r,&c,&pos)==3 && (r!=0 || c!=0 || pos!=0) )
	{

		for(i=0;i<=r;i++)
			for(j=0;j<=c;j++)
			 a[i][j]=-1;
		
		for(i=1;i<=r;i++)
		{	scanf(" %s",str);
	        for(j=1;j<=c;j++)
				row[i].col[j]=str[j-1];
		}


		f=0;
		exit=0;

		rown = 1;
		coln = pos;
		step=0;
		a[rown][coln]=0;

		//printf("%d %d %c\n",rown,coln,row[rown].col[coln]);
		
		while(1)
		{
			//dir = east(right)
			if(row[rown].col[coln]=='E')
			{
				step++;
				//printf("%d %d\n",rown,coln+1);
				if(coln==c)
				{
					exit=1;
					break;
				}
				coln = coln+1;
				if(a[rown][coln]==-1)a[rown][coln] = step;
				else
				{
					n = step - a[rown][coln];
					f=1;
					break;
				}						
			}
			//dir = west(left)
			else if(row[rown].col[coln]=='W')
			{
				step++;
				//printf("%d %d\n",rown,coln-1);
				if(coln==1)
				{
					exit=1;
					break;
				}
				coln = coln-1;
				if(a[rown][coln]==-1)a[rown][coln] = step;
				else
				{
					n = step - a[rown][coln];
					f=1;
					break;
				}						
			}
			//dir = north(top)
			else if(row[rown].col[coln]=='N')
			{
				step++;
				//printf("%d %d\n",rown-1,coln);
				if(rown==1)
				{
					exit=1;
					break;
				}
				rown = rown-1;
				if(a[rown][coln]==-1)a[rown][coln] = step;
				else
				{
					n = step - a[rown][coln];
					f=1;
					break;
				}						
			}
			//dir = south(down)
			else if(row[rown].col[coln]=='S')
			{
				step++;
				//printf("%d %d\n",rown+1,coln);
				if(rown==r)
				{
					exit=1;
					break;
				}
				rown = rown+1;
				if(a[rown][coln]==-1)a[rown][coln] = step;
				else
				{
					n = step - a[rown][coln];
					f=1;
					break;
				}						
			}	
		}

		if(exit==1 && f==0)
			printf("%d step(s) to exit\n",step);
		else if(f==1 && exit==0)
			printf("%d step(s) before a loop of %d step(s)\n",(step-n),n); 
	
		
		


	
	}//while
	
}//main
