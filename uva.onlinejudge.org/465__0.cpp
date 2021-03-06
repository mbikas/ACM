#include<stdio.h>
#include<string.h>
#include<math.h>
#define swap(a,b) a^=b^=a^=b
#define sz 210

void multiply(char a[],char b[],char result[]);
void add(char x[],char y[],char result[]);
void reverse(char x[]);
int toint(char x);
int tochar(int x);
void delete_leadingzero(char x[]);

char oper='+';
int minus1=0,minus2=0;
#define max  2147483647

int chech_max_or_not(char num[]);
void tokenize(char str[],char first[],char second[]);

void main()
{

	//freopen("465.in","r",stdin);
	//freopen("465.out","w",stdout);

	char first[sz],second[sz],result[sz];
	char str[sz];
	int firs,sec,answ;

	while(gets(str))
	{
		firs=0;
		sec=0;
		answ=0;	

		tokenize(str,first,second);

		

		delete_leadingzero(first);
		delete_leadingzero(second);

		
		if(oper=='+')
		   add(first,second,result);
		else
			multiply(first,second,result);

		//printf("result = %s  oper = %c\n",result,oper);

		//printf("%s\n%s\n%s\n",first,second,result);

		firs=  chech_max_or_not(first);
		sec =  chech_max_or_not(second);
		answ = chech_max_or_not(result);


		if(firs==0 && sec==0 && answ==0)
			printf("%s\n",str);
		
		else
		{
		   printf("%s\n",str);
		   if(firs>=1)
				printf("first number too big\n");
		   if(sec>=1)
				printf("second number too big\n");
		   if(answ>=1)
				printf("result too big\n");
		
		}
	
	
	}

}



void tokenize(char str[],char first[],char second[])
{
	int len,i,j,x;
	char temp[sz];
	//oper = '+';
	
	len = strlen(str);
	x=0;

	for(i=0;i<len;i++)
	{
		
		if(str[i]=='+' || str[i]=='*')
		{
			temp[x]='\0';
			strcpy(first,temp);	
			oper = str[i];
			break;
		}
		else
		{
			if(str[i]>='0' && str[i]<='9')
				temp[x++]=str[i];
		}	
	
	}

	x=0;

	for(j=i+1; j<len;j++)
	{
		if(str[j]>='0' && str[j]<='9')
		temp[x++]=str[j];
	
	}
	temp[x]='\0';
	strcpy(second,temp);
	

	//printf("fir = %s\nsec = %s\n",first,second);

}



int chech_max_or_not(char num[])
{

	int len;
	//2147483647
	
	len = strlen(num);

	if(len<10)return -1;
	if(len>10)return 1;

	return strcmp(num,"2147483647");

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

	int i,j,k,t1,t2,carry,len1,len2;
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

	int i,j,k,rem,len1,len2,len;
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

	int len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}

int toint(char x)
{
  return (x-'0');
}


int tochar(int x)
{
  return (x+'0');
}



void delete_leadingzero(char x[])
{

	int p,len,i,j;
	char temp[sz];

	p= strlen(x);
	
	if(p==1)
		return;
	len =0;
	for(i=0;i<p-1;i++)
	{
				if(x[i]!='0')
				break;		
	}
	for(j=i;j<p;j++)
	{
		temp[len++] = x[j];	
	}

	temp[len] = '\0';		
	strcpy(x,temp);


}
