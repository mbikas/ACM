#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define swap(a,b) a^=b^=a^=b
#define sz 50

void add(char x[],char y[],char result[]);
long call_div(char number[],long div,char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);



void main()
{

	char money[sz],temp[sz],result[sz];
	int friends,items,i,remainder;
	long ct=1;

	while(scanf("%d %d",&items,&friends)==2 && (items!=0 || friends!=0))
	{
	
		
		strcpy(temp,"0");

		for(i=0;i<items;i++)
		{		
			scanf(" %s",money);
			
			add(temp,money,result);
			strcpy(temp,result);
		}

		strcpy(result,temp);
		//printf("%s\n",result);


		if(friends!=0)
		{

			remainder = call_div(result,friends,temp);
			//printf("%s  %d\n",temp,remainder);
			printf("Bill #%ld costs %s: each friend should pay %s\n\n",ct,result,temp);
			
		}


		ct++;
	
	}
}



//TAKES TWO STRINGS x AND y AND PUTS THERE SUM IN ANOTHER STRING result
void add(char x[],char y[],char result[])
{

	long i,j,k,t1,t2,carry,len1,len2;
	char tem[sz];
	len1 = strlen(x);
	len2 = strlen(y);
	carry=k=0;
	for(i=len1-1,j=len2-1;i>=0||j>=0;i--,j--)
	{
			t1=t2=0;
			if(i>=0)
			t1=toint(x[i]);
			if(j>=0)
			t2=toint(y[j]);
			tem[k++]=tochar((t1+t2+carry)%10);
			carry= (t1+t2+carry)/10;

	}

	while(carry!=0)
	{
			tem[k++]=tochar(carry%10);
			carry/=10;
	}
	tem[k]='\0';
	reverse(tem);
	strcpy(result,tem);

}


void reverse(char x[])
{

	long len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}

long toint(char x)
{
  return (x-'0');
}


long tochar(long x)
{
  return (x+'0');
}


long call_div(char number[],long div,char result[])
{

	int len = strlen(number);
	int now;
	long extra;

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

