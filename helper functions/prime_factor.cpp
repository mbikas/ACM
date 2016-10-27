#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PRIME_RANGE 100000000
#define PRIME_NUMBER 5761460
#define CYCLE_RANGES 510510//9699690//2*3*5*7*11*13*17
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
void get_prime_factor(__int64 n);

__int64 factor[10000];
__int64 total=0;

void main()
{
	sieve();	

	
	__int64 n,i;
	int f=0;
	
	while(scanf("%I64d",&n)==1 && n>0)
	{

		if(f==1)printf("\n");
		else f=1;

		total=0;

		get_prime_factor(n);


		for(i=0;i<total;i++)
		{
			printf("%4I64d\n",factor[i]);			
		}
			


	
	}
	


}




void get_prime_factor(__int64 n)
{

	__int64 root,i;
    int f=0;


	root = (__int64) sqrt(n) + 1;


	for(i=0;prime[i]<=root;i++)
	{
		f=0;
		while(n%prime[i]==0)
		{
		
			n = n / prime[i];
			f=1;
		}

		if(f==1)
			factor[total++]=prime[i];	
		if(n==1)
			break;
	}

	if(n!=1)
	{
		factor[total++]=n;
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
		 prime[c++]=i;
		  
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