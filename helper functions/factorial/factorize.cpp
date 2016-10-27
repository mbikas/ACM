#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

long prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499};


long count=0;
void factorize(int n,int factors[],int freq[])
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

int main()

{
	int factors1[435],freq1[435];
	int factors2[435],freq2[435];
	int ct1,ct2;

	long i,n,k;
	__int64 val;

	while(scanf("%ld %ld",&n,&k)==2)
	{
		factorize(n,factors1,freq1);
		ct1 = count;

		
		
		factorize(k,factors2,freq2);
		ct2 = count;	
		
		//for(i=0;i<ct2;i++)
		//printf("%d %d\n",factors1[i],freq1[i]);
		//printf("-------------------------\n");

		for(i=0;i<ct1;i++)
		{
			if(ct2<=ct1 && factors1[i]==factors2[i])
			{

				freq1[i] = freq1[i] - freq2[i];
				freq2[i]=0;
			}		
		}

		//for(i=0;i<ct1;i++)
		//printf("%d %d\n",factors1[i],freq1[i]);
		//printf("-------------------------///\n");




		factorize(n-k,factors2,freq2);
		ct2 = count;		

		for(i=0;i<ct1;i++)
		{
			if(ct2<=ct1 && factors1[i]==factors2[i])
			{

				freq1[i] = freq1[i] - freq2[i];
				freq2[i]=0;
			}		
		}

		//for(i=0;i<ct1;i++)
		//	printf("%d %d\n",factors1[i],freq1[i]);

		val = 1;
		for(i=0;i<ct1;i++)
		{
		   val *= (freq1[i]+1);	
			freq1[i]=0;
		}

		printf("%I64d\n",val);




	
	
	}

	return 0;

}
