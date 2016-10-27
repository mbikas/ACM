                  //Acm10019 Funny Encryption Method
						//Solved By Bikas Cse Sust

#include<stdio.h>
#include<math.h>

void main()
{
  int testCase,n,bin,hex;

  scanf("%d",&testCase);

  while(testCase>0){


	scanf("%d",&n);

	hex=n;
	bin=0;

	// checking no of 1 when converting to Binary
	while(hex>0)
	{
	 if( hex%2==1)
		bin++;
	 hex=hex/2;

	}


	hex=0;


	// checking no of 1 when converting to Hexadecimal
	while(n>0)
	{
	  if( n%10==1 || n%10==2|| n%10==4|| n%10==8)hex=hex+1;
	  else if( n%10==3 || n%10==5|| n%10==6|| n%10==9|| n%10==10|| n%10==12)hex=hex+2;
	  else if( n%10==7 || n%10==11|| n%10==13|| n%10==14)hex=hex+3;
	  else if(n%10==15)hex=hex+4;

	  n=n/10;

	}


	printf("%d %d\n",bin,hex);






  testCase--;

 }
}