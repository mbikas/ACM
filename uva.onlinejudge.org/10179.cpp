#include<stdio.h>
#include<math.h>


void sieve(long L,long U);
#define MAX 3415

long prime[MAX];
long num;

long relative_prime_n(long n);


void main()
{
	long n,total;
	sieve(1,31700);

	//printf("%ld\n",num);


	while(scanf("%ld",&n)==1 && n!=0)
	{

		total = relative_prime_n(n);		

		printf("%ld\n",total);
	
	
	
	}
}

long relative_prime_n(long n)
{
	
	long root,i,rel,ct=0;
	
	root = (long)sqrt(n);
	rel=1;

	for(i=0;prime[i]<=root;i++)
	{
		ct=0;	
		while(n%prime[i]==0)
		{
			ct++;
			n = n/prime[i];				
		}
		if(ct>0)
			rel *= (prime[i]-1) * (long)(pow(prime[i],(ct-1)));
		
		if(n==1)
			break;
	}

	if(n!=1)
		rel *= n-1;	
	
	return rel;
}

void sieve(long L,long U) {
  long i,j,d;
  num=0;
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

  /* output the result */
 // for (i=0;i<d;i++) if (flag[i]) cout << (L+i) << " ";
  //cout << endl;
  for (i=0;i<d;i++)
  {
   if(flag[i]==true)
    prime[num++]=(L+i);
  }

}