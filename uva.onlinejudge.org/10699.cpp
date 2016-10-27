#include<stdio.h>

long primes[42000],prime_num =0;


void sieve(long L,long U);
int isPrime( long num);


int main()
{


	//freopen("10699.in","r",stdin);
	//freopen("10699.out","w",stdout);
	long n,i,p;

	sieve(1,500000);

	//printf("%ld\n",prime_num);
  
 
	
	while(scanf("%ld",&n)==1 && n!=0)
	{


		p=0;

		if(isPrime(n)==1)
			p=1;
		else
		{

			for(i=0;i<prime_num;i++)
			{
				if(primes[i]>n/2)
				 break;

				if(n%primes[i]==0)
				  p++;
			}


		}


		printf("%ld : %ld\n",n,p);



	}






return 0;

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



void sieve(long L,long U) {
  long i,j,d;

  d=U-L+1; /* from range L to U, we have d=U-L+1 numbers. */
  /* use flag[i] to mark whether (L+i) is a prime number or not. */
  bool *flag=new bool[d];
  for (i=0;i<d;i++) flag[i]=true; /* default: mark all to be true */

  for (i=(L%2!=0);i<d;i+=2) flag[i]=false; /* mark even numbers as false */

  /* sieve by prime factors staring from 3 till sqrt(U) */
  for (i=3;i*i<=U;i+=2) {
    if (i>L && !flag[i-L]) continue;

    /* choose the first number to be sieved -- >=L,
       divisible by i, and not i itself! */
    j=L/i*i;
    if (j<L) j+=i;
    if (j==i) j+=i; /* if j is a prime number, have to start form next one */

    /* now start sieving */
    j-=L; /* change j to the index representing j */
    for (;j<d;j+=i) flag[j]=false;
  }

  /* mark 1 as false, 2 as true */
  if (L<=1) flag[1-L]=false;
  if (L<=2) flag[2-L]=true;

  
  
  for (i=0;i<d;i++) 
  {
	  if (flag[i]) 
     	  primes[prime_num++] = L+i;
  }


}
