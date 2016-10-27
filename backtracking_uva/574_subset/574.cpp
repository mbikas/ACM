#include<stdio.h>
#include<stdlib.h>

typedef struct{
	long old[15];
	long len;
}ANS;
ANS ans[10000];
long ct=0;

#define NMAX 15
#define MAXCANDIDATES 15


long num[15],total;



int comp(void const *A, void const *B)
{

	long *a = (long*)A;
	long *b = (long*)B;

	long p =  *b - *a;
	if(p>0)return 1;
	if(p<0)return -1;
	return 0;

}



bool is_a_solution(int a[], int k, int n);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void process_solution(int a[], int k);
void backtrack(int a[], int k,int n);
void generate_subsets(int n);



void main()
{	
	

	long n,i,j;
	

	

	while(scanf("%ld %ld",&total,&n)==2 && (total!=0 ||n>0))
	{
		
		for(i=0;i<n;i++)
		scanf("%ld",&num[i]);

		printf("Sums of %ld:\n",total);

		
		
		ct=0;

		qsort(num,n,sizeof(num[0]),comp);
		generate_subsets(n);
		
		if(ct==0)
			printf("NONE\n");
		else
		{
			for(i=0;i<ct;i++)
			{
				for(j=0;j<ans[i].len-1;j++)
					printf("%ld+",ans[i].old[j]);
				printf("%ld\n",ans[i].old[ans[i].len-1]);
			
			}
		
		}
	
	}
}


bool is_a_solution(int a[], int k, int n)
{
        return (k == n);                
}
void process_solution(int a[], int k)
{
        int i,j,temp[15],ind=0,f;                          
        long sum=0;
        
        for (i=1; i<=k; i++)
		{	if (a[i] == 1) 
			{
			    
			   
				temp[ind++]=i-1;
				sum = sum+num[i-1];
			}
		}
	

		
		

		
		if(sum==total )
		{
			f=1;
		
			for(i=0;i<ct;i++)
			{
				f=1;
				if(ind==ans[i].len)
				{
					f=0;
					for(j=0;j<ind;j++)
					{
						if(num[temp[j]]!= ans[i].old[j])
						{
							f=1;
							break;
						}						
					}
					if(f==0)break;
				
				}
			
			}

			if(f==1)
			{
				ans[ct].len = ind;
				for(i=0;i<ind;i++)
				{
					ans[ct].old[i]=num[temp[i]];
				}
				ct++;				
			}

			//for(i=0;i<ind-1;i++)
			//printf("%ld+",num[temp[i]]);
			//printf("%ld\n  f = %ld\n",num[temp[ind-1]],f);
			
			
		}
		

        
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
        c[0] = true;
        c[1] = false;
        *ncandidates = 2;
}
void backtrack(int a[], int k,int n)
{
        int c[MAXCANDIDATES];        /* candidates for next position */
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


void generate_subsets(int n)
{
        int a[NMAX],i; /* solution vector */

		for(i=0;i<NMAX;i++)
			a[i]=i;

        backtrack(a,0,n);
}

