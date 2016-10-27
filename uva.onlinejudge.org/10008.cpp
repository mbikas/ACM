//Acm 10008  What's Cryptonalaysis
//solved by Bikas CSE SUST
#include<stdio.h>

void main()
{
 int i,j,n,number[26],max;
 char c;

 for(i=0;i<26;i++)
	number[i]=0;


 scanf("%d",&n);
 while(n>=0)
 { while((c=getchar())!='\n')
	{ if(c>=97&&c<=122)
		 c=c-32;
	  if(c>=65&&c<=90)
		 number[c-65]++;
	}
	n--;
 }


 for(i=0;i<26;i++)
	{ 	max=0;
		for(j=0;j<26;j++)
		  { if(number[j]>max)
			  { max=number[j];
				 c=j+65;
				 n=j;
			  }
		  }
		if(max>0)
		 {
		  printf("%c %d\n",c,max);
		  number[n]=0;
		 }

  }

}
