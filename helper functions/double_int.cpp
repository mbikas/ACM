#include<stdio.h>
#include<string.h>

int double_int(char num[],char result[]);
long before,after;

void main()
{
	
	char num[50],result[50];
	int point;

	
	while(scanf(" %s",num)==1)
	{
		
		point =  double_int(num,result);

		printf("%s %ld %ld\n",result,before,after);
		
	


	
	}
}


int double_int(char num[],char result[])
{
	
	int len,ct,i,p,x;
	char temp[sz];
	
	
	len = strlen(num);
	p=0;
	ct=0;
	
	x=0;
	for(i=0;i<len;i++)
	{
		if(p==1)
			ct++;
		if(num[i]!='.')
			temp[x++]=num[i];
		else
			p=1;	
	
	}


	//while(temp[x-1]=='0')
	//{ x--;
	//  ct--;
	//}
	//if(x==0)
	//	temp[x++]='0';

	temp[x]='\0';
	
	

	for(i=0;i<x-1;i++)
	{
		if(temp[i]!='0')
			break;
	}

	len=0;
	for(p=i;p<x;p++)
	{
	  result[len++] = temp[p];	
	}
	result[len] = '\0';	

	//printf("%s\n",result);



	return ct;
}

