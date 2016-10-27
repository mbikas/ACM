                  //Acm10591 Happy Number
						//Solved By Bikas Cse Sust

#include<stdio.h>

void main()
{
 int testcase,cases=1;
 unsigned long m,n,x;

 scanf("%d",&testcase);

 while(testcase>0)
 {

  scanf("%lu",&n);
  printf("Case #%d: %lu ",cases,n);
  cases++;

  if( n==1)
	printf("is a Happy number.\n");

  else if( n==0)
	printf("is a Unhappy number.\n");     //printf("is a Happy number.\n");

  else
	{

	 if(n<10)
	  n = (n*n);


	 while(n>=10)
	  { m=n;
		 n=0;

		 while(m>0)
		 {
		  n+=( (m%10) * (m%10) );

		  m=m/10;
		 }
		 
	  }

	 if(n==1)
	  printf("is a Happy number.\n");
	 
	 else
	  printf("is an Unhappy number.\n");


	}




  testcase--;
 }
}
