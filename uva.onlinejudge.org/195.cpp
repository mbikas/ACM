#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NMAX 13
#define MAXCANDIDATES 13


char ch[20];
int comp(void const *A, void const *B)
{	char *a = (char*)A;
	char *b = (char*)B;
	return *a - *b;
}


//bool finished = false;     /* found all solutions yet? */
is_a_solution(int a[], int k, int n);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void process_solution(int a[], int k);
void backtrack(int a[], int k,int n);
void generate_permutations(int n);



void main()
{	
	//freopen("10098.in","r",stdin);
	//freopen("10098.out","w",stdout);

	int test,n;
	

	scanf("%d",&test);

	while(test--)
	{
		
		scanf(" %[^\n]",ch);
		
	
		n = strlen(ch);
		qsort(ch,n,sizeof(ch[0]),comp);

		generate_permutations(n);	
	
	}
}


void process_solution(int a[], int k)
{
        int i;                         /* counter */
		

		//for (i=1; i<=k; i++) 
		//	printf("%d",a[i]);
		//printf("\n");
        for (i=1; i<=k; i++) 
			printf("%c",ch[a[i]-1]);		
		printf("\n");		
}

is_a_solution(int a[], int k, int n)
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

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
        int i;                          /* counter */
        bool in_perm[NMAX];             /* who is in the permutation? */

        for (i=1; i<NMAX; i++) in_perm[i] = false;
        for (i=0; i<k; i++) in_perm[ a[i] ] = true;

        *ncandidates = 0;
		//old=-1;
        for (i=1; i<=n; i++) 
		{       if (in_perm[i] == false)//for unique data 
				{
					//f=1;
/*
					for(j=0;j < *ncandidates;j++)
					{
						if(ch[i-1]==ch[c[j]-1])
						{	f=0;
						    break;
						}
					
					}
					
*/					
					//printf("%d",i);
					//if(f==1)
					if(ch[i-1] != ch[c[*ncandidates-1]-1])
                    {    c[ *ncandidates] = i;
                        *ncandidates = *ncandidates + 1;
					}
                }
		}
		//printf("\n");

}



