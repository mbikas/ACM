//acm392 Polynomial Showdown
//solved by Bikas CSE SUST
#include<stdio.h>
#include<string.h>
#include<math.h>

void main()
{
	  int coef[9],count,flag,len=0,i,p;
	  char ans[100],temp[10];

	  while(scanf("%d %d %d %d %d %d %d %d %d",&coef[8],&coef[7],&coef[6],&coef[5],&coef[4],&coef[3],&coef[2],&coef[1],&coef[0])==9)
	  {
	  	flag=0;
		len=0;

		for(count=8;count>=1;count--)
		{
			if(coef[count]!=0)
			{
				if(coef[count]<0)
					//printf("-");
				    ans[len++]='-';
				    
				else
				{
					if(flag==1)
						//printf("+");
						ans[len++]='+';

				}
				if(flag==1)
					//printf(" ");
					ans[len++]=' ';

				if(coef[count]==1 || coef[count]==-1)
					//printf("x");
					ans[len++]='x';
				else
				{
					//printf("%dx",abs(coef[count]));
                    i = abs(coef[count]);
					sprintf(temp,"%d",i);
					p = strlen(temp);
					for(i=0;i<p;i++)ans[len++]=temp[i];					
					ans[len++]='x';

				}
				if(count!=1)
				{
					//printf("^%d ",count);
					ans[len++]='^';
					ans[len++]=count + 48;
					ans[len++]=' ';
				}
				else
					//printf(" ");
					ans[len++]=' ';
				flag=1;
			}
		}

		if(coef[0]>0)
		{
			if(flag==1)
			{	//printf("+ ");
				ans[len++]='+';
				ans[len++]=' ';
			}
			//printf("%d",coef[0]);
			i = coef[0];
			sprintf(temp,"%d",i);
			p = strlen(temp);
			for(i=0;i<p;i++)ans[len++]=temp[i];
			
		}
		else if(coef[0]<0)
		{
			//printf("-");
			ans[len++]='-';
			if(flag==1)
				//printf(" ");
				ans[len++]=' ';
			//printf("%d",abs(coef[0]));
			i = abs(coef[0]);
			sprintf(temp,"%d",i);
			p = strlen(temp);
			for(i=0;i<p;i++)ans[len++]=temp[i];

		}
		else
		{
			if(flag==0)
			//	printf("0");
				ans[len++]='0';
		}

		for(i=len-1;i>0;i--)
		{
			if(ans[i]==' ')len--;
			else break;
		}
		ans[len]='\0';




		printf("%s\n",ans);



	  }
}