#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;


long primes[3600],prime_num =0;


void sieve(long L,long U);


int main()
{
  

  long n,i,j,p;

 sieve(1,32768);

 while(scanf("%ld",&n)==1 && n!=0)
	{
	  p=0;
 
	 for(i=0;i<prime_num;i++)
		{  
		  for (j=i;j<prime_num;j++)
		  {
		   if(primes[i]+primes[j]==n)
			p++;

		   if(primes[i]+primes[j]>n)
		      break;
		   
		  }

		  if(primes[i]>n )
			   break;

		 }

	  printf("%ld\n",p);
 
     

	}






return 0;

}







void sieve(long L,long U) {
  long i,j,d;

  d=U-L+1; /* from range L to U, we have d=U-L+1 numbers. */
  /* use flag[i] to mark whether (L+i) is a prime number or not. */
  bool *flag=new bool[d];
  for (i=0;i<d;i++) flag[i]=true; /* default: mark all to be true */

  for (i=(L%2!=0);i<d;i+=2) flag[i]=false; /* mark even numbers as false */

  /* sieve by prime factors staring from 3 till sqrt(U) */
  for (i=3;i<=sqrt(U);i+=2) {
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

 