#include<stdio.h>
#include<string.h>

#define sz 1000
long long call_div(char *number,long long div,char *result);

void main()
{
		char num[sz],c,result[sz];
		long long div,rem;


		while(scanf(" %s %c %lld",num,&c,&div)==3)
		{

			//scanf(" %[^\n]",temp);	
			//sscanf(temp,"%s %c %lld",num,&c,&div);
			
			
			rem = call_div(num,div,result);

			if(c=='/')
				printf("%s\n",result);
			if(c=='%')
				printf("%lld\n",rem);
		
		
		
		}




}



long long call_div(char *number,long long div,char *result)
{

	long long len = strlen(number);
	long long now;
	long long extra;

	char res[sz];

	for(now=0,extra=0;now<len;now++)
	{
		extra = extra *10 + (number[now]-'0');
		res[now] = extra/div + '0';
		extra %= div;
	}

	res[now]='\0';
	for(now=0;res[now]=='0';now++);

	strcpy(result,&res[now]);
	if(strlen(result)==0)
		strcpy(result,"0");

	return extra;
}
