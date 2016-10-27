#include<stdio.h>
#include<math.h>



int isPrime( long num);
long reverseInt(long num);

void main()
{
	 long x,n;

	 while(scanf("%ld",&x)==1)
	 {


		if(isPrime(x)!=1)
		  printf("%ld is not prime.\n",x);

		else
		{
		 n=reverseInt(x);
		 if(isPrime(n)==1 && n!=x)
			printf("%ld is emirp.\n",x);
		 else
			printf("%ld is prime.\n",x);
		}
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



	long reverseInt(long num)
	 {
	  long p=0;
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
