#include<stdio.h>
#include<stdlib.h>
#include<math.h>

bool Prime[1048585]={false};
bool composite[1048585] ={false};

#define PRIME_RANGE 1048580
#define PRIME_NUMBER 82050
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
bool check_composite(long k);

void main()
{
	sieve();
	
	long n,i,total,x=0;
	
	composite[4]=true;
	composite[6]=true;
	composite[9]=true;
	composite[10]=true;
	composite[14]=true;
	composite[15]=true;
	composite[21]=true;	
	/*
	long ct=0;

	for(i=0;i<1048580;i++)
		if(composite[i])
			ct++;
	printf("%ld\n",ct);
	*/
	while(scanf("%ld",&n)==1)
	{

		total=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&x);
			if(composite[x])
				total++;
		}
		printf("%ld\n",total);	
	
	}
	


}



void sieve(void)
{
	jumpinging();
	long i,j,k,r,curMod,curMod2,root;
	curMod=KEY_RANGE;
	for(i=0;i<KEY_NUMBER;i++)
	{	prime[i]=key[i];
	    Prime[key[i]]=true;
	}
	   
	bitCheck[0]=1;
	for(i=1;i<9;i++)
		bitCheck[i]=bitCheck[i-1]<<1;
	root=(long)sqrt(PRIME_RANGE)+1;
	for(i=KEY_RANGE;i<root;)
	{
		if((flag[i/BIT] & bitCheck[(i%BIT)/3]) ==false)
		{			
			prime[c++]=i;
			Prime[i]=true;

			///////////////////

			for(k = prime[c-2]+1;k<i;k++)
			{
				if(k%2==0)
				{
					if(Prime[k/2])composite[k]=true;
				}
				else
				{
					if(check_composite(k))
						composite[k]=true; 
				}
			}
			///////////////////////



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
		  Prime[i]=true;

	      ///////////////////////////////////////////
		  for(k = prime[c-2]+1;k<i;k++)
			{
				if(k%2==0)
				{
					if(Prime[k/2])composite[k]=true;
				}
				else
				{
					if(check_composite(k))
						composite[k]=true; 
				}
			}
		  ////////////////////////////////////////////



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



bool check_composite(long k)
{

	long root,i,p;
	root = (long)sqrt(k);
	for(i=0;prime[i]<=root;i++)
	{
	
		if(k%prime[i]==0)
		{
			p = k/prime[i];
			if(Prime[p])
				return true;
			else
				return false;			
		}	
	}
	return false;
}
