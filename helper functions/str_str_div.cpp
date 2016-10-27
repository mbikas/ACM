#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define max 1000

long call_div(char *number,long div,char *result)
{

	int len = strlen(number);
	int now;
	long extra;

	char res[max];

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

void main()
{

	char fir[max],res[max];

	long sec,remainder;

	while(scanf(" %s %d",fir,&sec)==2)
	{
		if(sec==0) printf("divide by zero error\n");
		else
		{
			remainder = call_div(fir,sec,res);
			printf("result=%s\nremainder=%ld\n",res,remainder);
		
		
		}
	
	
	
	}


}