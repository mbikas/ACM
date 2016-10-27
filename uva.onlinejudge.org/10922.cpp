#include<stdio.h>
#include<string.h>

void main()
{
	
	char num[1005];
	int i,ct,p,sum=0;


	while( scanf(" %s",num)==1)
	{
		if(strcmp(num,"0")==0)break;

		p = strlen(num);

		ct=1;
		sum=0;
		for(i=0;i<p;i++)
		{
			sum += num[i]-'0';		
		}

		while(1)
		{
		
			if(sum<10)
			{
				if(sum%9==0)
					printf("%s is a multiple of 9 and has 9-degree %d.\n",num,ct);
				else
					printf("%s is not a multiple of 9.\n",num);
				break;
			
			}

			
			p = sum;
			sum=0;
			while(p>0)
			{
				sum = sum + (p%10);
				p = p/10;				
			}
			
			ct++;
			
		}
	
	
	}

}