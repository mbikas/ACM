#include<stdio.h>
#include<string.h>
#define swap(a,b) a^=b^=a^=b
#define sz 1000

void decimal_anybase(long n,int b,char result[]); 
void reverse(char x[]);
   

void main()
{
  //freopen("355.in","r",stdin);
  //freopen("355.out","w",stdout);

  
  char result[sz];
  long num;
  int len,i,ct;

  while(scanf("%ld",&num)==1 && num!=0)
  {
	  	
	    decimal_anybase(num,2,result);
		
		ct=0;
		len = strlen(result);
		for(i=0;i<len;i++)
		{
			if(result[i]=='1')
				ct++;
		}

		printf("The parity of %s is %d (mod 2).\n",result,ct);
		
	

  }
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



void reverse(char x[])
{

	int len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}