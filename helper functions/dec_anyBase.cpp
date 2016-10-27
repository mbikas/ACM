//DECIMAL TO ANYBASE

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define swap(a,b) a^=b^=a^=b
#define sz 1000   

void decimal_anybase(unsigned long decimal, int base, char result[]); 
void reverse(char x[]);

void main()
{  	long base, decimal ;
  		char result[sz];
  		while( scanf("%ld  %ld",&decimal,&base) == 2 )
  		{ 	decimal_anybase(decimal,base,result);
			printf ("%ld base 10  --> %s base %ld\n", decimal , result , base);	  
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


void decimal_anyBase(long n,int base,char result[])
{

		long sign,i=0,j;		



		if( (sign=n) <0 )
		  n= -n;

	  do{

		  j=n%base;
			 result[i++]=(j<10) ? (j+'0'): ('A'+j-10);
	  }while((n/=base)!=0);


	  if(sign < 0) result[i++]='-';

		result[i]='\0';
		reverse(result);
}




