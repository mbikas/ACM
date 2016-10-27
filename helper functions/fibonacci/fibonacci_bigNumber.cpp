#include<stdio.h>
#include<string.h>

#define swap(a,b) a^=b^=a^=b
#define sz 1005

void add(char x[],char y[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);

typedef struct{
	char num[sz];
	
}FIB;

FIB fib[1005];	
	
void fibnacci(long limit);
__int64 sum;


int main()
{

	sum=0;
	long n;
	fibnacci(1000);

	// n = 31;
   while(scanf("%ld",&n)==1)
   {
	   printf("%s\n",fib[n].num);
	   
	   
   }

	return 0;

}


void fibnacci(long limit)
{
	long tmp,i;
	char result[sz],str1[sz],str2[sz];
	strcpy(fib[0].num ,"1");
	strcpy(fib[1].num ,"2");
	

	for(i=2;i<=limit;i++)
	{
		
		strcpy(str1,fib[i-1].num);
		strcpy(str2,fib[i-2].num);
		add(str1,str2,result);
		
		strcpy(fib[i].num,result);
	
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

