#include<stdio.h>
#include<math.h>



int isPrime(long num);


void main()
{
  
  long n;

  while(scanf("%ld",&n)==1){

  if(isPrime(n)==0)
	  printf("%ld is not prime.\n",n);

  else
	  printf("%ld is prime.\n",n);

 }
}




	 // check a number returns 1 is Prime else 0 if NotPrime
	 int isPrime( long num){
		 

		  if (num<=1) return 0;         /* 1 is NOT a prime               */
		  if (num==2) return 1;         /* 2 is a prime                   */
		  if (num%2==0) return 0;       /* NO prime is EVEN, except 2     */

		  for (long i=3;i*i<=num;i+=2)  /* start from 3, jump 2 numbers   */
			 {	if (num%i==0)             /*  no need to check even numbers */
						return 0;
			 }
			return 1;
    }








