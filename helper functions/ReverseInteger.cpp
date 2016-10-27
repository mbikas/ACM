#include<stdio.h>
#include<math.h>



int isPrime(long num);
long reverseInt(long num);

void main()
{
  long n,sum;

  while(scanf("%ld",&n)==1){

  if(isPrime(n)==0)
	  printf("%ld is not prime.\n",n);

  else{

		 sum= reverseInt(n);

		if(isPrime(sum)==1)
		  printf("%ld is emirp.\n",n);
		else
		  printf("%ld is prime.\n",n);


  }

 }
}




    // check a number returns 1 is Prime else 0 if NotPrime
	 int isPrime( long num){
		  long  i;
		  if(num<2)
			 return 0;

		  for(i=2;i<=( sqrt(num));i++)
			 {
				if(num%i==0)
				  return 0;
			 }

			  return 1;

		}


	long reverseInt(long num)
	 {
	  int p=0;
	  long reverse;

	  reverse=num;
	  while(reverse>0)
	  {
		reverse=reverse/10;
		p++;
	  }

	  p=p-1;
	  reverse=0;

	  while(num>0)
		 {
		  reverse+=   (num%10)* pow(10,p);
		  p--;
		  num=num/10;
		 }

	 //printf("%ld\n",reverse);
	 return reverse;

  }
