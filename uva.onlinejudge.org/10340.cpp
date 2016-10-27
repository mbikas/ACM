//Acm 10340 All in All
//solved by Bikas CSE SUST
#include<stdio.h>
#include<string.h>
#define size 1000000    

void main()
{

 char a[size],b[size];

 unsigned long m,i,j,p;

 while(scanf(" %s %s",a,b)==2){

	m=strlen(a);


	p=0;
	j=0;
	for(i=0;b[i]!='\0';i++)
	{
	 if(a[j]==b[i])
	  { p++;
		 j++;

	  }

	 if(j==m)
	  break;

	}


  if(p>=m)
	printf("Yes\n");
  else
	printf("No\n");


}











}
