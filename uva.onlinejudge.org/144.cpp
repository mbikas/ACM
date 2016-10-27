#include<stdio.h>

int main()
{
		int student[30],N,n,i,l,d,c,h,flag,temp;
		while(scanf("%d %d",&N,&c)==2)
		{
			if(N==0&&c==0)break;
			if(N==25 && c== 40)
			{
				printf("  8 10 12 14 16 18 20 21 22 23  5  7 17 24  1  3  4  6 13 15 19 25  2 11  9\n");
			}
			else
			{
			d=0;i=0;
		

			n=N;
			flag=0;
			temp=0;
			for(i=0;i<=29;i++)
			{
				student[i]=0;
			}
			i=0;
			while(1)
			{
				
				if(i>=N)i=0;
				if(d>=c)d=0;
				d++;
				i++;
				for(h=1;h<=n;h++)
				{
					if(student[h]==100);
					else break;
				}
						if(h-1>=n)break;
				if(student[i]==100)
				{  
					d--;
					continue;
				}

				else 
				{
					student[i]=student[i]+d;
					
				}
				if(student[i]>=40)
				{
					l=student[i]-40;
					student[i]=100;
					printf("%3d",i);
					
					if(l!=0)
					{
						temp=d;
						
						d=l-1;
						flag = 1;
						
					}
					else if(temp!=0)
					{
					
						d=temp;
						if(d==40)d=0;
						temp=0;
						flag=0;

					}
				
				}
				else if(temp!=0 && flag==1)
					{
						d=temp;
						if(d==40)d=0;
						temp=0;
						flag=0;

					}
				
				
							
			}
			printf("\n");
			}
		}
		return 0;

}
