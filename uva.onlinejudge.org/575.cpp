// acm 575 Skew Binary
//solved by Bikas CSE SUST

#include<stdio.h>
#include<math.h>
#include<string.h>

void main()
{
 int i,j,m;   // if not try with long
 char ch[1000];
 long sum;   // unsigned long long lldu

 while( scanf(" %s",ch)==1){

	m=strlen(ch);
	if(m==1 && ch[0]==48)
	  break;


	j=m;
	sum=0;
	for(i=0;i<m;i++)
	{
	 sum+=  ( (int)ch[i]-48 ) * ( pow(2,j)-1 );
	 j--;

	}

	printf("%lu\n",sum);



 }
}