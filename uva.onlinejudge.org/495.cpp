#include<stdio.h>
#include<string.h>
#define swap(a,b) a^=b^=a^=b
#define sz 2100

void add(char x[],char y[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);

typedef struct{
  char fib[sz];
}FIBONACCI;
 
FIBONACCI fibo[5000];
void main()
{
  //freopen("424.in","r",stdin);
  //freopen("424.out","w",stdout);

  long i,num;
  char a[sz],b[sz],result[sz],temp[sz];
  strcpy(a,"0");
  strcpy(b,"1");
  strcpy(fibo[0].fib,"0");
  strcpy(fibo[1].fib,"1");


  for(i=2;i<=5000;i++)
  {
	 add(a,b,result);
	 strcpy(fibo[i].fib,result);

	 strcpy(temp,b);
	 strcpy(b,result);
	 strcpy(a,temp);


  }

  while(scanf("%ld",&num)==1)
  {

	  printf("The Fibonacci number for %ld is %s\n",num,fibo[num].fib);



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
