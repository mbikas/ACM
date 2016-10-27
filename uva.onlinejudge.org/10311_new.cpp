#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#define PRIME_RANGE 10030
#define PRIME_NUMBER 1250
#define CYCLE_RANGES 510510
#define KEY_NUMBER 7
#define KEY_RANGE 19
#define BIT 24
#define BIT_ARRAY PRIME_RANGE/BIT+1
#define MAXJUMP 27
char jumping[CYCLE_RANGES];
unsigned char flag[BIT_ARRAY];
long prime[PRIME_NUMBER],c=KEY_NUMBER;
int key[KEY_NUMBER]={2,3,5,7,11,13,17};
long add[MAXJUMP],bitCheck[9];
void jumpinging(void);
void sieve(void);
bool check_prime(long n);

void main()
{

	//freopen("10311.in","r",stdin);
	//freopen("out1.txt","w",stdout);
	sieve();	
	
	long long n,i,min,p,q,diff;
	//long n,i,p,q,diff;
	int f;	

	while(scanf("%lld",&n)==1)
	{

		if(n<=4)
		{
			printf("%lld is not the sum of two primes!\n",n);
			continue; 
		}

		if(n%2 != 0)
		{	if(check_prime(n-2))
				printf("%lld is the sum of 2 and %ld.\n",n,n-2);
			else
				printf("%ld is not the sum of two primes!\n",n);
			continue;
		}		


		
		f=0;
		for(i=n/2;i>=2;i--)
		{
			if(check_prime(i) && check_prime(n-i) )
			{
				diff = abs((n-i)-i);

				if(diff>0)
				{
					p=i;
					q = n-i;
					f=1;
					break;
				}
			}		
		}

		if(f==1)
		{   if(p>q)
				printf("%lld is the sum of %lld and %lld.\n",n,q,p);
		    else
				printf("%lld is the sum of %lld and %lld.\n",n,p,q);
		}
		else
			printf("%lld is not the sum of two primes!\n",n);	
		
		
	
	}
	


}



void sieve(void)
{
	jumpinging();
	long i,j,r,curMod,curMod2,root;
	curMod=KEY_RANGE;
	for(i=0;i<KEY_NUMBER;i++)
		prime[i]=key[i];
	   
	
	   
	bitCheck[0]=1;
	for(i=1;i<9;i++)
		bitCheck[i]=bitCheck[i-1]<<1;
	root=(long)sqrt(PRIME_RANGE)+1;
	for(i=KEY_RANGE;i<root;)
	{
		if((flag[i/BIT] & bitCheck[(i%BIT)/3]) ==false)
		{			
			prime[c++]=i;			
			r=i<<1;
			add[2]=r;
			for(j=4;j<MAXJUMP;j+=2)
				add[j]=add[j-2]+r;
			curMod2=i%CYCLE_RANGES;
			for(j=i*i;j<PRIME_RANGE;)
			{
				flag[j/BIT] |= bitCheck[(j%BIT)/3];
				j+=add[jumping[curMod2]];
				curMod2+=jumping[curMod2];
				if(curMod2>CYCLE_RANGES)
					curMod2=1;
			}
		}
		i+=jumping[curMod];
		curMod+=jumping[curMod];
		if(curMod>CYCLE_RANGES)
			curMod=1;
	}
	for(;i<PRIME_RANGE;)
	{
		if((flag[i/BIT] & bitCheck[(i%BIT)/3])==false)
		{ prime[c++]=i;
		 
		}
		i+=jumping[curMod];
		curMod+=jumping[curMod];
		if(curMod>CYCLE_RANGES)
			curMod=1;
	}
}

void jumpinging(void)
{
	long i,j,r;
	char ch;
	jumping[0]=1;
	for(i=1;i<KEY_NUMBER;i++)
	{
		r=key[i]<<1;
		jumping[key[i]]=1;
		for(j=key[i]*key[i];j<CYCLE_RANGES;j+=r)
			jumping[j]=1;
	}
	ch=2;
	for(i=CYCLE_RANGES-1;i>-1;i-=2)
	{
		char temp=jumping[i];
		jumping[i]=ch;
		ch+=2;
		if(temp==0) ch=2;
	}
}

bool check_prime(long n)
{
	long root,i;

	if(n<=1)
		return false;
	

	root = (long)sqrt(n);
	for(i=0;prime[i]<=root;i++)
	{
		if(n%prime[i]==0)return false;	
	}
	return true;
}