#include<stdio.h>
#include<string.h>
#include<math.h>

////////////////////////
#define size 500
//////////////////////////


void separating_int(char a[]);
long m=0;
long num[size];
long prime_rep();

long cprime=0;
long prime[3550];
void sieve(long L,long U);

typedef struct{
	long num;
	long factor;
}Prime;
Prime primes[size];


void main()
{
	///////////////////
	char str[100000];
	///////////////////////

	long i,p,ct,len,n;
	

	sieve(1,32768);

	while(scanf(" %[^\n]",str)==1)
	{
		if(strcmp(str,"0")==0)
		break;

		separating_int(str);
	
		n = prime_rep();
		n = n-1;

		//printf("n = %ld\n",n);
		
		len=0;
		p=0;

		//////////////prime factors/////////////
		for(i=0;i<=cprime;i++)
		{
			    ct=0;
				while( n%prime[i]==0)
				{
						
						n=n/prime[i];
						ct++;				

				}
				if(ct>0)
				{	primes[len].num = prime[i];
				    primes[len].factor = ct;
					len++;
				}

				if(i>=sqrt(n) )
				{
					if(n!=1)
					{	
						//printf(" %ld\n",n);
						primes[len].num = n;
						primes[len].factor = 1;
						len++;

					}

					p=1;
					break;
				}

		}

		if(p!=1)
		{		//printf(" %ld\n",n);
				primes[len].num = n;
				primes[len].factor = 1;
				len++;
		}

 
		//////////////////////////////////////////
		
		for(ct=len-1;ct>=0;ct--)
		{
			if(ct==len-1)
				printf("%ld %ld",primes[ct].num,primes[ct].factor);
			else
				printf(" %ld %ld",primes[ct].num,primes[ct].factor);
		}	

		printf("\n");

		

		///////////////////////////////////////
		
	
	}
}



long prime_rep()
{
	long i,n=1,j;
	

	//////////////////////////////////////
	if(m==1)
		return num[0];
	////////////////////////////////////////



	for(i=0;i<m;i+=2)
	{
	  j = (long) (pow(num[i],num[i+1]));	
	  n = n*j;

	}

	return n;

}




 void separating_int(char a[])
 {
	  int p,x,i;
	  char temp[15];
	  p=strlen(a);
	  a[p]=' ';
	  m=0;

	  //separating A
	  /////////////////////////////////
	  x=0;
	  for(i=0;i<=p;i++)
		 {
			if(a[i]!=' ')
			 {
				temp[x]=a[i];
				x++;
			 }
			else
			 { while (a[i+1]==' ')i++;
				temp[x]=NULL;
				sscanf(temp,"%ld",&num[m]);
				m++;
				x=0;
			 }
		 }
		///////////////////////////////////////
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
     	  prime[cprime++] = L+i;
  }


}
