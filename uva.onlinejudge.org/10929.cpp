#include<stdio.h>
#include<string.h>
#define sz 1010

void main()
{
	char num[sz];
	unsigned long sum;
	int i,len,x,y;
	
	while(scanf(" %s",num)==1)
	{
		if(strcmp(num,"0")==0)
			break;

		sum=0;
		len = strlen(num);

		if(len%2!=0)
		{		sum = sum + (num[0] - '0');
		        i=1;
		}
		else
			i=0;
		
	
		for( ;i<len;i+=2)
		{
					if(num[i]>='0' && num[i]<='9')
						x = num[i] - '0';
					else
						x=0;

					if(num[i+1]>='0' && num[i+1]<='9')
						y = num[i+1] - '0';
					else
						y=0;

					//printf("%d\n",(x*10 + y));
					sum = sum + (x*10 + y);
		}

					
			

		if(sum%11==0)
			printf("%s is a multiple of 11.\n",num);
		else
			printf("%s is not a multiple of 11.\n",num);

	
	
	}




}