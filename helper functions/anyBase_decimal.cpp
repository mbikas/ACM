#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define sz 100
int minimum_base(char *number) ;
unsigned long anyBase_decimal(char *n,int base);
void main()
{

  long n,base;
  char a[100];

  while(scanf(" %s",a)==1)
  {
	  scanf("%ld",& base);

	  n=anyBase_decimal(a,base);
	  printf("%ld\n",n);
  }
}



int minimum_base(char *number) 
{ 
int max=0, temp; 
char *current=number; 
while(*current!='\0') 
{ 
if(*current>='0' && *current<='9') 
temp=(int)(*current-'0'); 
else 
temp=10+(int)(*current-'A'); 
if(temp>max) 
max=temp; 
current++; 
} 
if(max==0) 
return 2; 
return (max+1); 
} 



unsigned long anyBase_decimal(char *n,int base) 
{   unsigned long val=0; 
   unsigned long mult=1; 
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

/*
long anyBase_decimal(char ch[],long base)
{
	long num;

	char *start,*end;
	start=(char*)malloc(sz);

	start=ch;

	while(*start)
	  {
		  //Move past the non number char
		  while( *start && !isdigit(*start) && *start!='-'
					&&  !(*start>='A' && *start<='A'+base-11) )
				start++;

		  if(*start)
		  {
			  //Store decimal equivalent of (base) base number
			  //Store remaining string to (end)
			  num=strtol(start,&end,base);
			  start=end;
			  //printf("%ld\n",num);
		  }
	  }

	  return num;

}
*/


