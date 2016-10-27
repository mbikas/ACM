#include<stdio.h>
#include<string.h>
#define swap(a,b) a^=b^=a^=b

void multiply(char a[],char b[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);


void main()
{
	//freopen("623.in","r",stdin);
	//freopen("623.out","w",stdout);

	char str2[800],result[800],str1[20];
	long num,i;
	int fact[10],index;

  while(scanf("%ld",&num)==1 && num!=0)
  {

	 for(i=0;i<10;i++)
			fact[i]=0;

	 str2[0]='1';
	 str2[1]='\0';
	 for(i=num;i>=2;i--)
	 {
			sprintf(str1,"%ld",i);

			multiply(str2,str1,result);
			strcpy(str2,result);
	 }

	 index = strlen(result);
	 for(i=0;i<index;i++)
		fact[toint(result[i])]++;

/*
3! --
	(0)    0    (1)    0    (2)    0    (3)    0    (4)    0
	(5)    0    (6)    1    (7)    0    (8)    0    (9)    0
*/
	 printf("%ld! --\n",num);
	 for(i=0;i<10;i++)
	 {
			printf("   (%ld)%5d",i,fact[i]);
			if(i==4)
			  printf("\n");
	 }

	 printf("\n");
	 //printf("%ld!= %s\n",num,result);


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



