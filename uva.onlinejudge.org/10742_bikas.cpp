#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long ct=0;
long total[1000005];

#define PRIME_RANGE 1000002
#define PRIME_NUMBER 78500
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

void main()
{

	
	long n,num,cases=1;
	long long sum=0,i,j;	

	total[0]=0;
	total[1]=0;
	total[2]=1;
	sieve();	
	for(i=prime[c-1]+1;i<=1000002;i++)
	total[i]=c;	

	while(scanf("%ld",&num)==1 && num!=0)
	{

		n = total[num];	
		sum=0;
		
		////////////////////////////////////////
		for(i=0;i<n;i++)
		{
			if(prime[i]+prime[i+1]>num)
			{
				sum = ( i*(i+1) )/2 ;
				
				for(j = i+1;j<n;j++)
				sum += total[num - prime[j]];

				break;
			}			
		}

		printf("Case %ld: %lld\n",cases++,sum);

		

	}
}



void sieve(void)
{
	jumpinging();
	long i,j,k,r,curMod,curMod2,root;
	curMod=KEY_RANGE;
	for(i=0;i<KEY_NUMBER;i++)
	{	prime[i]=key[i];	    

		ct++;

		if(i>0)
		{
			for(k = prime[i-1];k<key[i];k++)
			total[k]=ct-1;
		}



		//ct++;
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
			//ct++;
			
			for(k = prime[c-2];k<i;k++)
				total[k]=c-1;
			
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
			
		  for(k = prime[c-2];k<i;k++)
		  total[k]=c-1;
		  
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