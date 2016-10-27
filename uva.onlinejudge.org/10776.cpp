#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NMAX 35


char ch[NMAX];
int comp(void const *A, void const *B)
{	char *a = (char*)A;
	char *b = (char*)B;
	return *a - *b;
}


bool is_a_solution(int a[], int k, int r);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates,int r);
void process_solution(int a[], int k);
void backtrack(int a[], int k,int n,int r);
void generate_permutations(int n,int r);



void main()
{	
	
	int n,f=0,r;	

	while(scanf(" %s %ld",ch,&r)==2)
	{
		n = strlen(ch);
		qsort(ch,n,sizeof(ch[0]),comp);

		generate_permutations(n,r);	
	
	}
}


void process_solution(int a[], int k)
{
        int i;                         
		
       for (i=1; i<=k; i++) 
	   printf("%c",ch[a[i]-1]);		
	    printf("\n");		
}

bool is_a_solution(int a[], int k, int r)
{
        return (k == r);
}

void generate_permutations(int n,int r)
{
        int a[NMAX],i;                    /* solution vector */

		for(i=0;i<NMAX;i++)
			a[i]=i;
        backtrack(a,0,n,r);
}



void backtrack(int a[], int k,int n,int r)
{
        int c[NMAX];        
        int ncandidates;             
        int i;                       

        if (is_a_solution(a,k,r))
                process_solution(a,k);
        else {
                k = k+1;				
                construct_candidates(a,k,n,c,&ncandidates,r);
			
			
                for (i=0; i<ncandidates; i++) 
				{
                        a[k] = c[i];
                        backtrack(a,k,n,r);                        
                }
        }
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates,int r)
{
        int i,f,j,st;                         
        


		if(k==1)
			st = 1;
		else
			st = a[k-1]+1;
        *ncandidates = 0;
		
        for (i=st; i<=n; i++) 
		{     
				
					f=1;
/*
					for(j=0;j < *ncandidates;j++)
					{
						if(ch[i-1]==ch[c[j]-1])
						{	f=0;
						    break;
						}
					
					}
					
*/					
				
					//if(f==1)
					if(ch[i-1] != ch[c[*ncandidates-1]-1])
                    {   

					
								c[ *ncandidates] = i;
								*ncandidates = *ncandidates + 1;
						
						
					}
              
		}

	

}



