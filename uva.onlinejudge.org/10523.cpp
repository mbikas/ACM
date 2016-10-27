#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 200
#define swap(a,b) a^=b^=a^=b


void multiply(char a[],char b[],char result[]);
void add(char x[],char y[],char result[]);
void subtract(char x[],char y[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);

char keep[152][sz];

void main()
{

	long i,N,A;

	char a[sz],b[10],c[10],sum[sz],result[sz];

	while(scanf("%d %d",&N,&A)==2)
	{

		//memset(keep,'\0',sizeof(keep));

		
		
		strcpy(keep[0],"1");

		sprintf(b,"%ld",A);
			
		strcpy(sum,"0");

		for(i=1;i<=N;i++)
		{
			sprintf(c,"%ld",i);
			multiply(keep[i-1],b,result);
			strcpy(keep[i],result);
			multiply(result,c,a);
			add(a,sum,result);
			strcpy(sum,result);

			//printf("%s\n",keep[i]);
		}
	
		printf("%s\n",sum);
	
	
	}



}



/*MULTIPLICATION BY STRING*/
//STORES a*b IN result

void multiply(char a[],char b[],char result[])
{

	long i,j,k,index,carry,mul,len1,len2;

	if(strcmp(a,"0")==0 || strcmp(b,"0")==0)
	{
	  strcpy(result,"0");
	  return;
	}

	len1=strlen(a);
	len2=strlen(b);
	j = len1+len2;
	for(i=0;i<j;i++)
		result[i]='0';

	index=-1;

	for(i=len2-1;i>=0;i--)
	{
			index++;
			carry=0;
			for(j=len1-1,k=index;j>=0;j--,k++)
			{
					mul = toint(a[j])*toint(b[i]) + toint(result[k])+carry;
					carry = mul/10;
					result[k]=tochar(mul%10);

			}

			result[k]=tochar(carry%10);

	}

	if(carry!=0)
	  k++;
	result[k]='\0';
	reverse(result);

	return;

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

