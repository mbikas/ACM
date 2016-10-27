//10539 almost prime

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1000000000000LL
#define PRIME_RANGE 1000000
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
void precalculation(long n);
int comp(void const *A, void const *B);
int comp1(const void *a,const void *b);
long long almostPrime[100000];
long total=0;

void main()
{
	sieve();	
	qsort(almostPrime,total,sizeof(almostPrime[0]),comp);

	
	long test,ind1,ind2;
	long long low,high,*p;

	
	/*for(long i=0;i<=100;i++)
		printf("%I64d ",almostPrime[i]);
	printf("\n");

	printf("total = %ld\n",total);
	*/
	
	scanf("%ld",&test);
	

	while(test--)
	{

	
		scanf("%lld %lld",&low,&high);
		
		if(high<4)
		{	printf("0\n");
		    continue;
		}


		if(low<4)ind1=0;
		else
		{
			p = (long long *)bsearch(&low,almostPrime,total,sizeof(long long),comp1);
			if(p)ind1 = p - almostPrime;
			else ind1 = 0;
			if(almostPrime[ind1]!=low)ind1++;
		}

		

		p = (long long *)bsearch(&high,almostPrime,total,sizeof(long long),comp1);
	 	if(p)ind2 = p - almostPrime;
		else ind2 = 0;

		//printf("%ld %ld\n",ind1,ind2);

		ind1 = ind2 - ind1+1;

		printf("%ld\n",ind1);




	}
}



void precalculation(long n)
{

	long long p,j=2,temp;

	temp=n;
 	while(1)
	{
	    p = temp * n;
		if(p>=MAX)
			break;
		almostPrime[total++]=p;
		temp =p;
	}
}




void sieve(void)
{
	jumpinging();
	long i,j,r,curMod,curMod2,root;
	curMod=KEY_RANGE;
	for(i=0;i<KEY_NUMBER;i++)
	precalculation(key[i]);
	
	 
	   
	bitCheck[0]=1;
	for(i=1;i<9;i++)
		bitCheck[i]=bitCheck[i-1]<<1;
	root=(long)sqrt(PRIME_RANGE)+1;
	for(i=KEY_RANGE;i<root;)
	{
		if((flag[i/BIT] & bitCheck[(i%BIT)/3]) ==false)
		{			
			precalculation(i);
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
		precalculation(i);		
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


int comp(void const *A, void const *B)
{

	long long *a = (long long*)A;
	long long *b = (long long*)B;


	long long p = *a-*b;
	
	if(p>0)
		return 1;
	if(p<0)
		return -1;
	return 0;

}



int comp1(const void *a,const void *b)
{
	long long *A = (long long *)a;
	long long *B = (long long *)b;

	if(*A>*B && (B-almostPrime==total-1 || *A<*(B+1)) )
		return 0;

	if(*A==*B && (B-almostPrime==0 || *A>*(B-1)) )
		return 0;

	if(*A!=*B)
	{	
		long long p = *A - *B;
		if(p>0)return 1;
		if(p<0)return -1;
		return 0;
	}
		

	else
		return -1;

}