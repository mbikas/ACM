#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long t = 0;

typedef struct{
	int result[2885][15];
	long total;
}ANS;
ANS ans[15];

typedef struct{
	int result[81030][17];
	long total;
}ANS1;
ANS1 ans16[1];


int pri[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
bool prime[50];

#define MAX 50

void process_solution(int a[],int k);
bool is_a_solution(int k,int n);
void backtrack(int a[],int k,int n);
void construct_candidates(int a[],int k,int n,int c[],int *ncandidates);
void generate_prime();
void precalculation();


void main()
{
	int n,i,j,f=0;
	long cases=1;
	generate_prime();

	precalculation();

	while(scanf("%d",&n)==1)
	{
		//if(f==1)printf("\n");
		//else f=1;

		printf("Case %ld:\n",cases++);
		
		
	
		if(n<=14)
		{
			for(i=0;i<ans[n].total;i++)
			{
				for(j=1;j<n;j++)
				printf("%d ",ans[n].result[i][j]);
				printf("%d\n",ans[n].result[i][n]);
			}
		}
		else
		{
			for(i=0;i<ans16[0].total;i++)
			{
				for(j=1;j<n;j++)
				printf("%d ",ans16[0].result[i][j]);
				printf("%d\n",ans16[0].result[i][n]);
			}		
		}
		
		//printf("%ld\n",ans[n].total);
		printf("\n");
		

	}
}


void precalculation()
{
	int i,j,a[MAX];

	for(i=2;i<=16;i+=2)
	{
		t=0;
		for(j=0;j<=i;j++)
			a[j]=j;
		backtrack(a,0,i);
		if(i<=14)
		ans[i].total = t;
		else
			ans16[0].total = t;
	
	}




}

bool is_a_solution(int k,int n)
{
	return (k==n);
}

void process_solution(int a[],int k)
{
	int i;


	if(k<=14)
	{
		for(i=1;i<=k;i++)
		ans[k].result[t][i] =  a[i];	
		t++;
	}
	else
	{
		for(i=1;i<=k;i++)
		ans16[0].result[t][i] =  a[i];	
		t++;
	}


}

void backtrack(int a[],int k,int n)
{

	int c[MAX],i;
	int ncandidates;
	
	if(is_a_solution(k,n))
	{
		process_solution(a,k);
	
	}
	else
	{

		k=k+1;
		construct_candidates(a,k,n,c,&ncandidates);
		
		for(i=0;i<ncandidates;i++)
		{
			a[k]=c[i];
			backtrack(a,k,n);
		}
	}
}

void construct_candidates(int a[],int k,int n,int c[],int *ncandidates)
{
	//printf("k  =%d\n",k);
	int i,sum,sum1;
	bool in_perm[MAX];

	if(k==1)
	{	c[0]=1;
	    *ncandidates = 1;
		//return;		
	}

	else
	{
		*ncandidates = 0;

		for(i=0;i<=n;i++)
			in_perm[i] = false;
		for(i=0;i<k;i++)
		{
			in_perm[a[i]] =  true;
		}

		
		for(i=1;i<=n;i++)
		{
			if(in_perm[i]==false)
			{
				if(k==n)
				{	sum = a[1] + i;
				    sum1 = a[k-1]+i;
					if(prime[sum] && prime[sum1])
					{	
						c[ (*ncandidates) ] = i;
						*ncandidates = *ncandidates +1;
					}
				}

				    
				else
				{	sum = a[k-1] + i;
				 	if(prime[sum])
					{	
						c[ (*ncandidates) ] = i;
						*ncandidates = *ncandidates +1;
					}
				}
			}
			
		}//for
	
	}//else
}//end

void generate_prime()
{
	int i;
	for(i=0;i<=40;i++)
		prime[i] = false;
	for(i=0;i<12;i++)
		prime[pri[i]] = true;
}
