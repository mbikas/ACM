// there are 3512 primes within 2^15

#include<stdio.h>
#include<math.h>
#define SIZE 3513


unsigned long  primes[SIZE];
long prime_num;


void find_all_primes_below(unsigned long num);
int  isPrime(unsigned long num);

void main()
{

  long n,i;


	//find_all_primes_below(   10000  );
  find_all_primes_below(  30000 );


  while(scanf("%ld",&n)==1)
	{

	 for(i=0;i<prime_num;i++)
		printf("%lu ",primes[i]);


	 printf(" \n*total Prime =%ld *\n",prime_num);





	}
}








void find_all_primes_below(unsigned long num)
{
	unsigned long i;

	prime_num = 0;
	primes[prime_num++] = 2;

	for(i = 3; i <= num; i += 2)
	{
		if (isPrime(i)) primes[prime_num++] = i;
	}

	return;
}



// check a number returns 1 is Prime else 0 if NotPrime
	 int isPrime( unsigned long num){
		 

		  if (num<=1) return 0;         /* 1 is NOT a prime               */
		  if (num==2) return 1;         /* 2 is a prime                   */
		  if (num%2==0) return 0;       /* NO prime is EVEN, except 2     */

		  for (long i=3;i*i<=num;i+=2)  /* start from 3, jump 2 numbers   */
			 {	if (num%i==0)             /*  no need to check even numbers */
						return 0;
			 }
			return 1;
    }


