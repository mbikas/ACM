#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define sz 11005
#define PRIME_RANGE 10030
#define PRIME_NUMBER 5000
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
void flush(long factors[],long freq[]);
long get_prime_factor(long n);


long count=0;
void factorize(long n,long factors[],long freq[])
{
	long pri_pow,i;
	count=0;

	for(i=0;prime[i]<=n;i++)
	{
		factors[count]=prime[i];
		freq[count]=0;
		pri_pow = prime[i];
		while(pri_pow<=n)
		{
			freq[count] += n/pri_pow;
			pri_pow*=prime[i];
		}

		count++;
	}
}

bool flag1[12000];
long freq[sz];
void main()
{

	//freopen("10780.in","r",stdin);
	//freopen("out1.txt","w",stdout);

	sieve();
	long test,m,n,i,p,cases=1;
	long factors[sz],freq1[sz];
	
	scanf("%ld",&test);

	while(test--)
	{
		
		scanf("%ld %ld",&m,&n);
		count=0;		

		for(i=0;i<sz-1;i++)
		flag1[i]=false;

		factorize(n,factors,freq1);
		for(i=0;i<count;i++)
		{	flag1[factors[i]]=true;
			freq[factors[i]]=freq1[i];		
		}

		p = get_prime_factor(m);

		if(p==-1)
		{	
			printf("Case %ld:\nImpossible to divide\n",cases++);
			continue;
		}
		printf("Case %ld:\n%ld\n",cases++,p);
		flush(factors,freq);
		
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


void flush(long factors[],long freq[])
{
	long i;
	for(i=0;i<count;i++)
	{
		factors[i]=0;
		freq[i]=0;		
	}
}




long get_prime_factor(long n)
{

	long root,i,ct,min,p;
    int f=0;

	root = (long)sqrt(n) + 1;
	min = 100000;


	for(i=0;prime[i]<=root && i<c;i++)
	{
		ct=0;
		while(n%prime[i]==0)
		{
			n = n / prime[i];
			ct++;
		}

		if(ct>0)
		{	if(flag1[prime[i]]==false || ct>freq[prime[i]])
				return -1;
			p = freq[prime[i]]/ct;
			if(p<min)
				min = p;
		}
		if(n==1)
			break;
	}

	if(n!=1)
	{
		ct=1;		
		if(flag1[n]==false || ct>freq[n])
		 return -1;
		p = freq[n]/ct;
		if(p<min)
		min = p;
	}

	return min;

}


