#include<stdio.h>
#include<math.h>


void main()
{
  int n;

  double p;

  while(scanf("%d",&n)==1 && n!=0){


	if(n==2||n==3||n==5||n==7||n==13||n==17||n==19||n==31)
	  { 	 p= pow(2,(n-1)) * ( pow(2,n)-1 );
			 printf("Perfect: %.lf!\n",p);

	  }

	else if(n==11 || n==23 || n==29 )
		  printf("Given number is prime. But, NO perfect number is available.\n");
	else
		 printf("Given number is NOT prime! NO perfect number is available.\n");

 }
}










