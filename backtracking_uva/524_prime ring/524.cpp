#include<stdio.h>
#define NMAX 18

int isPrime( long num);


//bool finished = false;     /* found all solutions yet? */
bool is_a_solution(int a[], int k, int n);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void process_solution(int a[], int k);
void backtrack(int a[], int k,int n);
void generate_permutations(int n);



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

        if (is_a_solution(a,k,n) && a[1]==1 )//&& isPrime(a[1]+a[k]))
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
		//old=-1;
        for (i=1; i<=n; i++) 
		{       if (in_perm[i] == false)//for unique data 
				{
					legal=true;

					
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
						//printf("%d %d\n",sum,f);
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
		 

		  if (num<=1) return 0;         /* 1 is NOT a prime               */
		  if (num==2) return 1;         /* 2 is a prime                   */
		  if (num%2==0) return 0;       /* NO prime is EVEN, except 2     */

		  for (long i=3;i*i<=num;i+=2)  /* start from 3, jump 2 numbers   */
			 {	if (num%i==0)             /*  no need to check even numbers */
						return 0;
			 }
			return 1;
    }



