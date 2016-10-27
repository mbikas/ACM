/*Generates all primes within range 1e8(10 crore)*/
/*Memory:(1e8)/24 unsigned char array for flaging*/
/*
Key->Max jump:
8->34,7->26,6->22,5->14,4->10,3->6,2->4,1->2
*/

//Started  : 24.11.2004
//Finalized: 26.11.2004
//Updated  : 12.07.2006
//Running time = 2.40 sec(In 1.5GHz Pentium4,Linux OS)

//Sumon(SUST)

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define PRIME_RANGE 31630
#define PRIME_NUMBER 3500
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
long get_divisors(long n);


int main()
{	
	sieve();	
	//printf("Total Prime = %ld\nLast Prime = %ld\n",c,prime[c-1]);

	long test,i,lower,upper,max,divisors,num,temp;

	scanf("%ld",&test);

	while(test--)
	{
		scanf("%ld %ld",&lower,&upper);

		if(upper<lower)
		{
			temp = upper;
			upper = lower;
			lower = temp;
		}


		max=0;
		for(i=lower;i<=upper;i++)
		{
		
			divisors = get_divisors(i);

			if(divisors>max)
			{
				max = divisors;
				num=i;
			
			}		
		}

		printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n",lower,upper,num,max);

	


	}


	return 0;
}



long get_divisors(long n)
{

	long i,root,x,div=1;
	int f;

	root = (long)sqrt(n);


	for(i=0;i<c;i++)
	{
		x=0;
		f=0;
		while(n%prime[i]==0)
		{
			n = n/prime[i];
			x++;
			f=1;
		}
		if(f==1)
			div = div * (x+1);

		if(n==1 || prime[i]>root)
			break;
	}

	if(n!=1)
		div = div * 2;

	return div;






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