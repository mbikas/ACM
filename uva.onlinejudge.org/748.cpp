#include<stdio.h>
#include<string.h>
#define sz 1000

#define swap(a,b) a^=b^=a^=b

void multiply(char a[],char b[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);


long double_int(char num[],char result[]);
void output(char result[],long ct,int n);

char str[sz];

void main()
{
	
	//freopen("748.in","r",stdin);
	//freopen("748.out","w",stdout);


	char R[20],num[20],result[sz];
	long ct,n,i;


	
	while(scanf(" %s %d",num,&n)==2)
	{
		
		ct = double_int(num,R);

		//printf("%s %d\n",R,ct);

		strcpy(str,R);
		strcpy(result,R);
		for(i=0;i<n-1;i++)
		{
            multiply(str,R,result);
			strcpy(str,result);			
		
		}

		//printf("%s\n",result);

		output(result,ct,n);
		
	}
}

void output(char result[],long ct,int n)
{
		long i,j,p,len,x;

		ct =  ct * n;
		x = strlen(result);
		
		//printf("%ld %ld\n",ct,x);
		if(x<ct)
		{
				p = ct - x;

				len=0;
				for(i=0;i<p;i++)			
				str[len++] = '0';

				for(i=0;i<x;i++)
				str[len++] = result[i];
				str[len]='\0';

				//printf("%s\n",str);
				strcpy(result,str);
				
		}
		else
		   len = x;
		
		p = len - ct;		

		for(i=0;i<p;i++)
			printf("%c",result[i]);
		printf(".");
		for(j = p;j<len;j++)
			printf("%c",result[j]);

		printf("\n");



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



long double_int(char num[],char result[])
{
	
	long len,ct,i,p,x;
	char temp[20];
	
	
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

	

	while(temp[x-1]=='0')
	{ x--;
	  ct--;
	}

	temp[x]='\0';

	

	for(i=0;i<x;i++)
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


