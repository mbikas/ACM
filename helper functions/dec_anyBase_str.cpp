//DECIMAL TO ANYBASE

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define swap(a,b) a^=b^=a^=b
#define sz 1000   

void decimal_anybase(char n[], int base, char result[]); 
long call_div(char *number,long div,char *result);
void reverse(char x[]);

void main()
{  	
	long base;
	char result[sz],decimal[sz];
	while( scanf(" %s  %ld",decimal,&base) == 2 )
	{ 	
		decimal_anybase(decimal,base,result);
		printf ("%s base 10  --> %s base %ld\n", decimal , result , base);	  
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


void decimal_anybase(char n[], int base, char result[])
{
	
	long i=0,j,rem;	
	char res[sz];
	
	
	
	
	
	do{
		j = call_div(n,base,res);
		//j=n%base;
		result[i++]=(j<10) ? (j+'0'): ('A'+j-10);
		strcpy(n,res);
	}while(strcmp(n,"0")!=0);
	
	
	result[i]='\0';
	reverse(result);
}





long call_div(char *number,long div,char *result)
{

	int len = strlen(number);
	int now;
	long extra;

	char res[sz];

	for(now=0,extra=0;now<len;now++)
	{
		extra = extra *10 + (number[now]-'0');
		res[now] = extra/div + '0';
		extra %= div;
	}

	res[now]='\0';
	for(now=0;res[now]=='0';now++);

	strcpy(result,&res[now]);
	if(strlen(result)==0)
		strcpy(result,"0");

	return extra;
}