#include<stdio.h>
#include<string.h>
#define swap(a,b) a^=b^=a^=b
#define sz 1000

void multiply(char a[],char b[],char result[]);
void add(char x[],char y[],char result[]);
void subtract(char x[],char y[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);

void main()
{
	char n[sz],b[sz],result[sz];

	while(scanf(" %s",n)==1)
	{

		//result = n*n - n + 2 

		
		if(strcmp(n,"0")==0)
		{
			printf("1\n");
			continue;
		}
		

		strcpy(b,n);	

		multiply(n,b,result);

		subtract(result,n,b);

		add(b,"2",result);

		printf("%s\n",result);
		 
	
	
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

// STORES THE RESULT x-y IN STRING result
// x SHOULD BE GREATER THAN y
void subtract(char x[],char y[],char result[])
{

	long i,j,k,t1,t2,rem,len1,len2,len;
	char tem[sz],tem2[sz];

	strcpy(tem2,y);
	len2 = strlen(tem2);
	reverse(tem2);
	len1 = strlen(x);
	for(i=len2;i<len1;i++)
	tem2[i]='0';

	for(i=len1-1,j=0,k=0;i>=0;i--,j++)
	{
			rem=0;
			if(j>=0)
				rem = toint(tem2[j]);
			if(rem>toint(x[i]))
			{
					tem[k++] = tochar(10+toint(x[i])-rem);
					tem2[j+1]= tem2[j+1]+1;

			}
			else
					tem[k++]=tochar(toint(x[i])-rem);

	}
	tem[k] = '\0';
	len = strlen(tem);
	for(i=len-1;tem[i]=='0';i--)
			tem[i]='\0';
	reverse(tem);
	strcpy(result,tem);
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