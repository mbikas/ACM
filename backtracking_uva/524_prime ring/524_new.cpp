#include<stdio.h>
#define NMAX 18

int prime[13]={2,3,5,7,11,13,17,19,23,29,31,37,41};



bool is_a_solution(int a[], int k, int n);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void process_solution(int a[], int k);
void backtrack(int a[], int k,int n);
void generate_permutations(int n);
int isPrime( long num);

void main()
{	
	
	int n,f=0;
	long cases=1;
	

	

	while(scanf("%d",&n)==1)
	{
		

		if(f==1)printf("\n");
		else f=1;			

		printf("Case %ld:\n",cases++);

		//if(n>1)
		if(n%2==0)
		generate_permutations(n);
		
		
	
	}
}


void process_solution(int a[], int k)
{
        int i;        /* counter */

		
		

	    for (i=1; i<k;i++) 
		printf("%d ",a[i]);		
		printf("%d\n",a[k]);		
}

bool is_a_solution(int a[], int k, int n)
{
        return (k == n);
}

void generate_permutations(int n)
{
        int a[NMAX],i;                    /* solution vector */

		for(i=0;i<NMAX;i++)
			a[i]=i;
        backtrack(a,0,n);
}



void backtrack(int a[], int k,int n)
{
        int c[NMAX];        /* candidates for next position */
        int ncandidates;             /* next position candidate count */
        int i;                       /* counter */

        if (is_a_solution(a,k,n))
                process_solution(a,k);
        else {
                k = k+1;
				//ncandidates =0;
                construct_candidates(a,k,n,c,&ncandidates);
                for (i=0; i<ncandidates; i++) {
                        a[k] = c[i];
                        backtrack(a,k,n);
                        //if (finished) return;   /* terminate early */
                }
        }
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
        int i,sum;                          /* counter */
        bool in_perm[NMAX],legal;             /* who is in the permutation? */

        for (i=1; i<NMAX; i++) in_perm[i] = false;
        for (i=0; i<k; i++) in_perm[ a[i] ] = true;

        *ncandidates = 0;
		for (i=1; i<=n; i++) 
		{       if (in_perm[i] == false)//for unique data 
				{
					legal=true;

					if(k==1)
					{
						if(i!=1)
							legal=false;				
					}
					
					if(k==n)
					{
						sum = a[1]+i;
						if( isPrime(sum)==0)
							legal=false;						
					}
					
					if(k>1)
					{
						sum = a[k-1]+i;
						if( isPrime(sum)==0)
							legal=false;				
					}					
					
					if(legal)					
                    {   c[ *ncandidates] = i;
                        *ncandidates = *ncandidates + 1;						
					}
                }
		}
		

}


 // check a number returns 1 is Prime else 0 if NotPrime
	 int isPrime( long num){
		 
		 int i;

		  for(i=0;i<=12;i++)
		  {
			  if(num==prime[i])
				  return 1;
			  if(prime[i]>num)
				  return 0;					  
		  }

		  return 0;
    }



