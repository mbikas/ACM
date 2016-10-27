#include<stdio.h>
#include<math.h>
#define INF 1000000000
#define NMAX 25
#define MAXCANDIDATES 25


long num[NMAX],total;
long old[NMAX],p=0,flag=0;
long sum=0,oldval=INF;


bool finished= false;
bool is_a_solution(long a[], long k, long n);
void construct_candidates(long a[], long k, long n, long c[], long *ncandidates);
void process_solution(long a[], long k);
void backtrack(long a[], long k,long n);
void generate_subsets(long n);



void main()
{	
	

	long n,i;
	

	

	while(scanf("%ld %d",&total,&n)==2 && n>0)
	{
		
		for(i=1;i<=n;i++)
		scanf("%ld",&num[i]);

		

		p=0;
		flag=0;
		finished=false;
		oldval=INF;
		generate_subsets(n);
		
		if(flag==1 && (total-oldval)>0)
		{
			for(i=0;i<p;i++)
				printf("%ld ",old[i]);
			
		}
		printf("sum:%ld\n",(total-oldval));
	
	}
}


bool is_a_solution(long a[], long k, long n)
{
        return (k == n);                
}
void process_solution(long a[], long k)
{
        long i,temp[NMAX],ind=0; 
		sum=0;
		long val;
                
        for (i=1; i<=k; i++)
		{	if (a[i] == 1) 
			{
				temp[ind++]=i;
				sum = sum+num[i];
			}
		}
		
		//printf("sum = %ld\n",sum);

		if(sum<=total)
		{
			val = (long)abs(total-sum);

			if(val<oldval)
			{	p=0;
				for(i=0;i<ind;i++)
				//rintf("%ld ",num[temp[i]]);
				old[p++] = num[temp[i]];
				flag=1;
				if(val==0)
					finished=true;

				oldval=val;
			}
		}
		

        
}

void construct_candidates(long a[], long k, long n, long c[], long *ncandidates)
{
        c[0] = true;
        c[1] = false;
        *ncandidates = 2;
}
void backtrack(long a[], long k,long n)
{
        long c[MAXCANDIDATES];        /* candidates for next position */
        long ncandidates;             /* next position candidate count */
        long i;                       /* counter */

        if (is_a_solution(a,k,n))
                process_solution(a,k);

        else {
                k = k+1;
				//ncandidates =0;
                construct_candidates(a,k,n,c,&ncandidates);
                for (i=0; i<ncandidates; i++) {
                        a[k] = c[i];
                        backtrack(a,k,n);
                        if (finished) return;   /* terminate early */
                }
        }
}


void generate_subsets(long n)
{
        long a[NMAX],i; /* solution vector */

		for(i=0;i<NMAX;i++)
			a[i]=i;

        backtrack(a,0,n);
}

