#include<stdio.h>
#include<stdlib.h>
#include<math.h>

bool Prime[10000002]={false};

#define PRIME_RANGE 10000000
#define CYCLE_RANGES 510510//9699690//2*3*5*7*11*13*17
#define KEY_NUMBER 7
#define KEY_RANGE 19
#define BIT 24
#define BIT_ARRAY PRIME_RANGE/BIT+1
#define MAXJUMP 27

char jumping[CYCLE_RANGES];
unsigned char flag[BIT_ARRAY];
int key[KEY_NUMBER]={2,3,5,7,11,13,17};
long add[MAXJUMP],bitCheck[9];

void jumpinging(void);
void sieve(void);

void main()
{
	sieve();	
	
	long n,x,i;
	int f;
	

	while(scanf("%ld",&n)==1)
	{
		x = n;
		
		if(n<8)
		{
			printf("Impossible.\n");
			continue;
		}
		
		f=0;
		
		if( n%2 == 0 )
			n = n-4;
	
		else if(n%2 == 1)
			n = n-5;
	
		// now n is even so it can be written as the sum of two primes 
		for( i=2; i<=n; i++ ) 
		{
			if( Prime[i] && Prime[n-i] ) 
			{	
				if(x%2==0)
					printf("2 2 %ld %ld\n",i,n-i); 
				else
					printf("2 3 %ld %ld\n",i,n-i);

				f=1;
				break;
			}
		}

		if(f==0)
			printf("Impossible.\n");
	
	
	
	}
	


}



void sieve(void)
{
	jumpinging();
	long i,j,r,curMod,curMod2,root;
	curMod=KEY_RANGE;
	for(i=0;i<KEY_NUMBER;i++)
	    Prime[key[i]]=true;	
	   
	bitCheck[0]=1;
	for(i=1;i<9;i++)
		bitCheck[i]=bitCheck[i-1]<<1;
	root=(long)sqrt(PRIME_RANGE)+1;
	for(i=KEY_RANGE;i<root;)
	{
		if((flag[i/BIT] & bitCheck[(i%BIT)/3]) ==false)
		{			
			Prime[i]=true;
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
		  Prime[i]=true;		
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