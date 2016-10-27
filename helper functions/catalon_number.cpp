#include<stdio.h>
#include<string.h>
#define swap(a,b) a^=b^=a^=b
#define sz 800

void multiply(char a[],char b[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);



typedef struct{
	char num[sz];
}CATALON;
CATALON catalon[303];



void catalon_number(long n)
{
	long i,j;
	char b[10],a[sz],result[sz];

	strcpy(catalon[1].num,"1");
	
	for(i=2;i<=n;i++)
	{
		strcpy(a,"1");
		for(j=2*i;j>=i+2;j--)
		{
			sprintf(b,"%ld",j);
			multiply(a,b,result);
			strcpy(a,result);	
		}
		strcpy(catalon[i].num,result);
	
	}


}



void main()
{

	catalon_number(301);

	long n;

	while(scanf("%ld",&n)==1 && n!=0)
	{
		printf("%s\n",catalon[n].num);
	
	}



}




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
