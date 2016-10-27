#include<stdio.h>
//#include<math.h>

#define sz 10001

int isPrime(long num);
long divisor(long n);
long divisors[sz],ct;




void main()
{
	long n,sum,i;

	
	while( scanf("%ld",&n)==1 && n!=0)
	{
		sum = divisor(n);

		for(i=0;i<ct;i++)
			printf("%ld ",divisors[i]);

		printf("\nSUM= %ld\n",sum);
	}

}

long divisor(long n)
{
		long i;
		long sum=0;
		ct=0;


		if(isPrime(n))
		{
			divisors[ct++]=1;
			divisors[ct++]=n;
			return (1+n);
		}

		for(i=1;i*i<n;i++)
		{
			if(n%i==0)
			{
				sum = sum + i;
				divisors[ct++]=i;
				
				sum = sum + (n/i);
				divisors[ct++]=n/i;
			}
		}


		if(i*i==n)
		{
			sum += i;
			divisors[ct++]=i;
		}
		
		return sum;
}





	 // check a number returns 1 is Prime else 0 if NotPrime
 int isPrime( long num){
		 long i;

		  if (num<=1) return 0;         /* 1 is NOT a prime               */
		  if (num==2) return 1;         /* 2 is a prime                   */
		  if (num%2==0) return 0;       /* NO prime is EVEN, except 2     */

		  for (i=3;i*i<=num;i+=2)  /* start from 3, jump 2 numbers   */
			 {	if (num%i==0)             /*  no need to check even numbers */
						return 0;
			 }
			return 1;
    }





