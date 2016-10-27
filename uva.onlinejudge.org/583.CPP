#include<stdio.h>
#include<math.h>
 // 2^31 = 2147483648
 // sqrt 2147483648= 46340
	long cprime = 0;
	long prime[46340];//46340

	void primes_below(long num);




void main()
{
 int p;
 long int n;
 long i;
 primes_below(46340);

 while(scanf("%ld",&n)==1 && n!=0)

  {
	p=0;

	if(n>0)
	 printf("%ld =",n);

	else
	 { printf("%ld = -1 x",n);
			n=n*-1;
	 }

	for(i=0;i<=cprime;i++)
	{
	  while( n%prime[i]==0)
		 {
		  n=n/prime[i];

		  if(n!=1)
			printf(" %ld x",prime[i]);
		  else
			printf(" %ld\n",prime[i]);

		 }


		if(i>=sqrt(n) )
		 {
		  if(n!=1)
			printf(" %ld\n",n);

		  p=1;
		  break;
		 }

	 }

	if(p!=1)
	 printf(" %ld\n",n);





  }
}







	//GENERATING PRIMES UPTO 46342
	void primes_below(long num)
	{
	 long i,k;
	  prime[cprime ++] = 2;
	 for (k=3; k<=num; k+=2)
	 { for (i=0; prime[i]*prime[i] < k; i++)
		  { if (k % prime[i] == 0)
			  break;
		  }
		 if (prime[i]*prime[i] > k)
			prime[cprime++] = k;

	 }
	}


