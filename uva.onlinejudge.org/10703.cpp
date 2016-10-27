#include<stdio.h>

bool a[502][502];

void main()
{
	long col,row,n,i,j,k,total,x1,x2,y1,y2,temp;


	while(scanf("%ld %ld %ld",&row,&col,&n)==3)
	{
		if(col==0 && row==0 && n==0)break;

		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
				a[i][j]=true;
		}

		for(i=0;i<n;i++)
		{
			scanf("%ld %ld %ld %ld",&x1,&y1,&x2,&y2);

			if(x1>x2){
				temp = x1;
				x1 = x2;
				x2 = temp;
			}
			if(y1>y2){
				temp = y1;
				y1 = y2;
				y2 = temp;
			}
			for(j=x1;j<=x2;j++)
			{	for(k=y1;k<=y2;k++)
				a[j][k]=false;
			}
		}

		total=0;
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				if(a[i][j]==true)
					total++;
			}
		}

		if(total==0)
			printf("There is no empty spots.\n");
		else if(total==1)
			printf("There is one empty spot.\n");
		else
			printf("There are %ld empty spots.\n",total);
	
	}
}
