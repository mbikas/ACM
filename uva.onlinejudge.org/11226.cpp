#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define sz 100

long func[500005]={0};

long generate_sofl(long n);
long get_prime_factor_sum(long n);
bool f[500055]={false};

#define PRIME_RANGE 500050
#define PRIME_NUMBER 42000
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
void get_value();




int main()
{
	long test,cases=1,low,high,i,temp,max,p;


	sieve();	
	

	//for(i=0;i<20;i++)if(f[i])printf("%d ",i);
	get_value();
//	printf("Total Prime = %ld\nLast Prime = %ld\n",c,prime[c-1]);



	scanf("%ld",&test);
	while(test--)
	{
		printf("Case #%ld:\n",cases++);
		scanf("%ld %ld",&low,&high);

		if(low>high)
		{
			temp = low;
			low = high;
			high = temp;
		}


		max=0;
		
		for(i=low;i<=high;i++)
		{
		
			if(func[i]>max)max = func[i];
			
		}
		printf("%ld\n",max);
		

/*
		max = 0;
		for(i=low;i<=high;i++)
		{
			//memset(used,false,sizeof(used));
			
			p = generate_sofl(8);
			if(p>max)max = p;	
			
			//printf("%ld = %ld\n",i,p);
		}

		printf("%ld\n",max);
*/
	
	}	

	return 0; 
}


void get_value()
{
	long i,j;
	for(i=2;i<=500000;i++)
	{
		if(f[i])func[i]=1;
		else
		{
			func[i] = generate_sofl(i);
		
		}

		//printf("%ld = %ld\n",i,func[i]);
	
	}


}

long generate_sofl(long n)
{
	long m,tot=1,x=0,store[sz],i;
	m = n;
	bool f1;
	
	//m = get_prime_factor_sum(m);

	if(n==4)return 1;

	while(1)
	{
	
		//long p = m;
		m = get_prime_factor_sum(m);
		//if(m==p)return 1;
		if(func[m]>0)
		{
			return func[m]+1;
		}		
	}
	
}





long get_prime_factor_sum(long n)
{

	long root,i,sum;
    
	sum=0;

	root = (long) sqrt(n) + 1;
	
	

	for(i=0;prime[i]<=root;i++)
	{
	
	
		while(n%prime[i]==0)
		{
		
			n = n / prime[i];
			sum+=prime[i];	
			
		}

		if(n==1)
			break;
	}

	if(n!=1)
	{
		sum+=n;
	}

	return sum;
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




