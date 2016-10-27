#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


#define sz 30


int check_legal(char ch[],long base);



void main()
{


  long base;
  char a[sz];

  while(scanf("%ld %s",&base,a)==3)
  {
		
	    
		if(check_legal(a,base)==1)
		  printf("%s if legal base %ld number\n",a,base);
		else
				printf("%s is an illegal base %ld number\n",a,base);

  }
}

int check_legal(char num[],long base)
{
  long len,i,p;

  len = strlen(num);

  for(i=0;i<len;i++)
  {

	if(num[i]=='A' || num[i]=='a')
	  p =10;
	else if(num[i]=='B' || num[i]=='b')
	  p =11;
	else if(num[i]=='C' || num[i]=='c')
	  p =12;
		  else if(num[i]=='D' || num[i]=='d')
	  p =13;
	else if(num[i]=='E' || num[i]=='f')
	  p =14;
	else if(num[i]>='0' && num[i]<='9')
	  p = num[i]-'0';
	else
	  return 0;

	if(p>=base)
			 return 0;


  }
  return 1;
}
