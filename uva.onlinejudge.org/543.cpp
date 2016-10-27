#include<stdio.h>
#include<stdlib.h>
#include<math.h>

bool f[1000001]={false};

#define PRIME_RANGE 1000015
#define PRIME_NUMBER 78502
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
int comp(const void *a,const void *b);

void jumpinging(void);
void sieve(void);

void main()
{
	sieve();	
	//printf("Total Prime = %ld\nLast Prime = %ld\n",c,prime[c-1]);

	long n,i,*p,index;
	bool found;

	while(scanf("%ld",&n)==1 && n!=0)
	{
		

		p = (long *)bsearch(&n,prime,c,sizeof(long),comp);
		if(p)index = p-prime;
		else index = -1;
		//printf("Index = %ld\n",index);	
		//printf("first=%ld\n",prime[index-1]);
		//printf("prime=%ld\n",prime[index]);
		//printf("second=%ld\n",prime[index+1]);
	
		found=false;
		for(i=index;i>=0;i--)
		{
			if(f[n-prime[i]])
			{
				printf("%ld = %ld + %ld\n",n,(n-prime[i]),prime[i]);
				found=true;
				break;
			}		
		}
		
		if(!found)
		printf("Goldbach's conjecture is wrong.\n");	
	
	}
}



int comp(const void *a,const void *b)
{
	long *A = (long *)a;
	long *B = (long *)b;

	if(*A>*B && (B-prime==c-1 || *A<*(B+1)) )
		return 0;

	if(*A==*B && (B-prime==0 || *A>*(B-1)) )
		return 0;

	if(*A!=*B)
		return *A-*B;

	else
		return -1;

}





void sieve(void)
{
	jumpinging();
	long i,j,r,curMod,curMod2,root;
	curMod=KEY_RANGE;
	for(i=0;i<KEY_NUMBER;i++)
	{	prime[i]=key[i];
	    f[key[i]]=true;
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
			f[i]=true;
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
		  f[i]=true;
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

