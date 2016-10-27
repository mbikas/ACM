#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define swap(a,b) a^=b^=a^=b
#define sz 1000

long long anyBase_decimal(char ch[],int base);
void decimal_anyBase(long long n,int base);
int check_legal(char ch[],int base);
void reverse(char x[]);

char result[sz];


void main()
{
  //freopen("355.in","r",stdin);
  //freopen("355.out","w",stdout);

  int base,convert,len,negative,i;
  long long decimal;
  char a[sz];

  while(scanf("%d %d %s",&base,&convert,a)==3)
  {
		negative=0;
	    
	    if(a[0]=='-')
		{
			negative=1;
			len=strlen(a);
			for(i=0;i<len-1;i++)
				a[i]=a[i+1];
			a[len-1]='\0';
		}
		
	    
		if(check_legal(a,base)==1 && (base>=2 && base<=16) && (convert>=2 && convert<=16) )
		{
			decimal=anyBase_decimal(a,base);
			decimal_anyBase(decimal,convert);

			if(negative==0)
			printf("%s base %d = %s base %ld\n",a,base,result,convert);
			else
			printf("-%s base %d = -%s base %d\n",a,base,result,convert);
			
	  }
	  else
	  	printf("%s is an illegal base %d number\n",a,base);
	  


  }
}


long long anyBase_decimal(char *n,int base) 
{ long long val=0; 
  long long mult=1; 
   int i; 
   for( i=strlen(n)-1 ; i>=0 ; i--){ 
      if ( n[i] >= '0' && n[i] <= '9' ) 
         val += (n[i]-'0')*mult; 
      else if ( n[i] >= 'A' && n[i] <= 'Z' )    
         val += (n[i]-'A' + 10) *mult; 
      mult *= base; 
   } 
   return val; 
} 



int check_legal(char num[],int base)
{
  int len,i,p,x=0;

  len = strlen(num);

  

  for(i=x;i<len;i++)
  {

	if(num[i]=='A')
	  p =10;
	else if(num[i]=='B')
	  p =11;
	else if(num[i]=='C')
	  p =12;
	else if(num[i]=='D')
	  p =13;
	else if(num[i]=='E')
	  p =14;
	else if(num[i]=='F')
	  p =15;
	else if(num[i]>='0' && num[i]<='9')
	  p = num[i]-'0';
	else
	  return 0;

	if(p>=base)
			 return 0;


  }
  return 1;



}



void decimal_anyBase(long long n,int base)
{

		long long sign,i=0,j;		



		if( (sign=n) <0 )
		  n= -n;

	  do{

		  j=n%base;
			 result[i++]=(j<10) ? (j+'0'): ('A'+j-10);
	  }while((n/=base)!=0);


	  if(sign < 0) result[i++]='-';

		result[i]='\0';
		reverse(result);

	  //printf("%s\n",num);


}

void reverse(char x[])
{

	int len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}