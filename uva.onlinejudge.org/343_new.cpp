#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

#define sz 300

int minimum_base(char *number); 
unsigned long anyBase_decimal(char *n,int base); 

void main()
{
	char *base1,*base2,a[sz];
	int min_base1,min_base2,i,j,p;

	unsigned long num1,num2;

	while(scanf(" %[^\n]",a)==1)
	{
		base1=strtok(a," \t\b\r\n");
		base2=strtok(NULL," \t\b\r\n");

	
		min_base1 = minimum_base(base1);
		min_base2 = minimum_base(base2);

		//printf("%lu %lu\n",min_base1,min_base2);

		p=0;
		for(i=min_base1;i<=36;i++)
		{	
		
			num1 = anyBase_decimal(base1,i);
			for(j=min_base2;j<=36;j++)
			{				
					num2 = anyBase_decimal(base2,j);
					if(num1==num2)
					{
					  printf("%s (base %d) = %s (base %d)\n",base1,i,base2,j);
					  p=1;
					  break;
					}  
			}

			if(p==1)break;
		}

		if(p!=1)
			printf("%s is not equal to %s in any base 2..36\n",base1,base2);

	

	
	
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
