#include<stdio.h>
long primes[675],num =0;


void sieve(long L,long U);


int main()
{

	long test,n,i,p,ans;

	sieve(1,5010);
	//printf("%ld",num);

	while(scanf("%ld",&test)==1)
	{
 
	 //for(i=0;i<prime_num;i++)
	//	 printf("%ld ",primes[i]);

	 //max = 0;

		while(test>0)
		{
			scanf("%ld",&n);
			p=1;

			for(i=0;i<num;i++)
			{ 
			
					ans = primes[i] * p;
					if((p+1)*primes[i] >n)
						break;
		
			}


			printf("%ld\n",ans);

		
			test--;
		}



	}






return 0;

}







void sieve(long L,long U) {
  long i,j,d;

  d=U-L+1; /* from range L to U, we have d=U-L+1 numbers. */
  bool *flag=new bool[d];/* use flag[i] to mark whether (L+i) is a prime number or not. */

  
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
     	  primes[num++] = L+i;
  }


}

 