#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define swap(a,b) a^=b^=a^=b
#define sz 100


int anyBase_decimal(char ch[],int base);
int check_legal(char ch[],int base);
void decimal_anybase(long n,int b,char result[]); 
void reverse(char x[]);
   

void main()
{
  //freopen("355.in","r",stdin);
  //freopen("355.out","w",stdout);

  int base,decimal,convert;
  char a[sz],result[sz];

  while(scanf("%d %d %s",&base,&convert,a)==3)
  {
		//printf("%s",a);
	    
		if(check_legal(a,base)==1)
		{
			decimal=anyBase_decimal(a,base);
			decimal_anybase(decimal,convert,result);

			printf("%s base %d = %s base %d\n",a,base,result,convert);
			

	  }
	  else
	  {
		printf("%s is an illegal base %d number\n",a,base);
	  }


  }
}

void reverse(char x[])
{

	int len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}


void decimal_anybase(long n,int b,char result[]) 
{     
      int j,sign; 

      int i=0; 

      if( (sign=n) <0 ) 
      n= -n;
      
	  do{     
		  j=n%b; 
          result[i++]=(j<10) ? (j+'0'): ('A'+j-10); 
      }while((n/=b)!=0); 

		
	  if(sign < 0)result[i++]='-'; 
      result[i]='\0'; 

      reverse(result); 


} 