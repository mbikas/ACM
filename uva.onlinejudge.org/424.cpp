#include<stdio.h>
#include<string.h>
#define swap(a,b) a^=b^=a^=b
#define sz 500

void add(char x[],char y[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);

void main()
{
  freopen("424.in","r",stdin);
  freopen("424.out","w",stdout);

  char a[105],b[105],result[sz];

  strcpy(b,"0");
  while(scanf( "%s",a)==1)
  {

	 if(strcmp(a,"0")==0)
	 {
	  printf("%s\n",result);
	  break;
	 }


	 add(a,b,result);
	 strcpy(b,result);


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
