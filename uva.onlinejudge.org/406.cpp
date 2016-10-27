#include<stdio.h>
#include<math.h>



int primes[200],prime_num =1;



void sieve(int L,int U);


int main()
{

 int n,i,ct,c,j,x,c1,c2;
 primes[0]=1;
 sieve(1,1005);

	while(scanf("%d %d",&n,&c)==2)
	{
            printf("%d %d:",n,c); 
			ct=0;
			for(i=0;i<prime_num && primes[i]<=n;i++)
			{   ct++; 
				//printf("%d ",primes[i]);
			}

			if(ct%2==0)
			{   
				x = c*2;
				c1 = (ct/2)-1;
				c2 = ct/2;
				c = (x-2)/2;
				c1 = c1-c;
				c2 = c2+c;
				
				
			}
			else
			{	
				
				x = (c*2)-1;
				c = (ct-1)/2;
				c1 = c-( (x-1)/2);
				c2 = c+( (x-1)/2);
				//printf("%d %d  **\n",c1,c2);
			}
	 
			if(x>ct)
			{
					
					j=0;
					while(j<ct)
					{
						printf(" %d",primes[j]);
						j++;
					}					
			}
			else
			{
					for(i=c1;i<=c2;i++)
					printf(" %d",primes[i]);
			}

			printf("\n\n");



	



	}






return 0;

}







void sieve(int L,int U) {
  int i,j,d;

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

  //long v=0;
  
  /* output the result */
  //for (i=0;i<d;i++) {
	  
//	  if (flag[i]) //cout << (L+i) << " ";
//	   v++;
  //}
  //cout << v;
  
  for (i=0;i<d;i++) 
  {
	  if (flag[i]) 
     	  primes[prime_num++] = L+i;
  }


}

 